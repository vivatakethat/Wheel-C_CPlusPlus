
#include"test_base.hpp"

class  test1 :public test_base {
public:
	virtual void display() const {

		cout << "Running in test1.so Now" << endl;

	}
};



//	the class factories

extern "C" test_base* create()
{
	return new test1;

}



extern "C" void destroy(test_base* p) {
	
	delete p;
}













