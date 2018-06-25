



#include"Ihuman.h"



int main()
{

	IHumanFactory    * factory_ptrl = new WhiteHumanFactory();

	IHuman * object_ptr = factory_ptrl->CreateHuman();
	object_ptr->Cry();
 





	return 0;
}