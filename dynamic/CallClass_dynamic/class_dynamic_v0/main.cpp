

#include"test_base.hpp"
#include<iostream>

#include<dlfcn.h>


int main(int argc, char** argv) {


	//load the test library

	if (argc != 2)
	{
		cout << "Argument Error!You must enter like this: " << '\n';
		cout << "./a.out test_1.so" << '\n';
		return 1;
	}






	void * test_index = dlopen(argv[1], RTLD_NOW);
	if (!test_index) {

		cerr << "Cannot load library: " << dlerror() << '\n';
		return 1;
	}


	//reset errors
	dlerror();

	//load the symbols

	create_t* create_test = (create_t*)dlsym(test_index, "create");

	const char*  dlsym_error = dlerror();
	if (dlsym_error) {
		 
		cerr << "Cannot load symbol create: " << dlsym_error << '\n';
		return 1;

	}


	destory_t* destory_test = (destory_t *)dlsym(test_index, "destroy");

	dlsym_error = dlerror();
	if (dlsym_error) {


		cerr << "Cannot load symbol destory:" << dlsym_error << '\n';
		return 1;
	}

	// create an instance of the class
	test_base* c_test = create_test();


	//use the class
	c_test->display();

	destory_test(c_test);

	// unload the test library
	dlclose(test_index);



}