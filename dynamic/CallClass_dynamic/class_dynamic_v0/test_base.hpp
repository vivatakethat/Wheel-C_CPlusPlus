#ifndef _TEST_BASE_HPP
#define _TEST_BASE_HPP


#include<iostream>

using namespace std;
class test_base {


public:
	test_base() {}
	virtual ~test_base() {}
	void call_base()
	{
		cout << "call base" << endl;
	}

	virtual void  display() const = 0;

};

	


	typedef test_base* create_t();

	typedef void destory_t(test_base*);


#endif



