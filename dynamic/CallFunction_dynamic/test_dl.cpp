

#include <stdio.h>  

#include <stdlib.h>  

#include <dlfcn.h>  



int main(int argc, char **argv)

{

	if (argc != 2)
	{

		printf("Argument Error! You must enter like this:\n");

		printf("./test_dl test_so1.so\n");

		exit(1);

	}



	void *handle;

	char *error;

	//typedef void(*pf_t)();   //声明函数指针类型  

	typedef void(*pf_t)(int );   //声明函数指针类型  

	handle = dlopen(argv[1], RTLD_NOW);     //打开argv[1]指定的动态库  



	if (!handle)

	{

		fprintf(stderr, "%s\n", dlerror());

		exit(1);

	}



	dlerror(); //清除之前存在的错误

	pf_t pf = (pf_t)dlsym(handle, "test");    //指针pf指向test在当前内存中的地址  

	if ( (error = dlerror()) != NULL)

	{

		fprintf(stderr, "%s\n", error);

		exit(1);

	}

	pf(3);        //通过指针pf的调用来调用动态库中的test函数  

	dlclose(handle);      //关闭调用动态库句柄  

	return 0;

}