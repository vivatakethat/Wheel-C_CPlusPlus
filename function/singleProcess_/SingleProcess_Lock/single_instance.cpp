/*

https://blog.csdn.net/LEON1741/article/details/77982236

*/
#include"single_instance.h"
#include<string.h>
#include<stdio.h>
 #include <sys/file.h>
 #include <stdlib.h>
    #include <unistd.h>
    #include<errno.h>


bool is_single_proc_inst_running(const char *process_name);
static void single_proc_inst_lockfile_cleanup(void);

static int g_single_proc_inst_lock_fd = -1;



static void single_proc_inst_lockfile_cleanup(void)
{
    if (g_single_proc_inst_lock_fd != -1) {
        close(g_single_proc_inst_lock_fd);
        g_single_proc_inst_lock_fd = -1;
    }
}




bool is_single_proc_inst_running(const char *process_name)
{
    char lock_file[128];
    snprintf(lock_file, sizeof(lock_file), "/var/tmp/%s.lock", process_name);

 //   g_single_proc_inst_lock_fd = open(lock_file, O_CREAT|O_RDWR, 0644);//take_mark:这样写如果后面有fork,子进程会复制父进程fd
     g_single_proc_inst_lock_fd = open(lock_file, O_CREAT|O_RDWR|O_CLOEXEC, 0644);   //take_mark:在fork进程前清理fd(O_CLOEXEC标记在linu2.6.23才开始支持此标记)
    if (-1 == g_single_proc_inst_lock_fd) {
        fprintf(stderr, "Fail to open lock file(%s). Error: %s\n",
                lock_file, strerror(errno));
        return false;
    }

    if (0 == flock(g_single_proc_inst_lock_fd, LOCK_EX | LOCK_NB)) {
        atexit(single_proc_inst_lockfile_cleanup);

//        int flags=fcntl(g_single_proc_inst_lock_fd,F_GETFD);  //
//flags|=FD_CLOEXEC;
//fcntl(g_single_proc_inst_lock_fd,F_SETFD,flags);
        return true;
    }

    close(g_single_proc_inst_lock_fd);
    g_single_proc_inst_lock_fd = -1;
    return false;

}




 

















