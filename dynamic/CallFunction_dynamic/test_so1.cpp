

#include "test_so1.h"  

int test(int a)
{
	printf("argument a is :%d\n", a);

	printf("USING TEST_SO1.SO NOW!\n");//注意此处与test_so2.cpp中的  

									   //test函数的不同  

	return 1;

}