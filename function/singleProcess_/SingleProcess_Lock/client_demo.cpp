#include<iostream>
#include"single_instance.h"
#include<unistd.h>
using namespace std;

int main()
{


if(is_single_proc_inst_running("client.out")==false)
{
    cout<<"Fail~,Could not start two same process"<<endl;
    return -1;
}

sleep(1000);




    return 0;
}