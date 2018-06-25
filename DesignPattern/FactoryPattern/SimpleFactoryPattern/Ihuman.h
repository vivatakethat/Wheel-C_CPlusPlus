
#include<iostream>

class IHuman                    //抽象基类，不能创建该类型的对象，但是可以创建
								//向该类型对象的指针或者引用
{
public:
	IHuman(void)
	{

	}
	~IHuman()                 //用作基类的类需要定义虚析构函数
	{

	}
	virtual void Laugh() = 0;   //纯虚函数，派生类中必须重新声明，定义自己的版本
	virtual void Cry() = 0;
	virtual void Talk() = 0;
 

};

class WhiteHuman : public IHuman
{
public:
	WhiteHuman(void)
	{

	}
	~WhiteHuman(void)
	{

	}
	void Laugh()
	{
		std::cout << "白种人笑！" << std::endl;
	}
	void Cry()
	{
		std::cout << "白种人哭！" << std::endl;
	}
	void Talk()
	{
		std::cout << "白种人说话！" << std::endl;
	}
};

class YellowHuman : public IHuman
{
public:
	YellowHuman(void)
	{

	}
	~YellowHuman(void)
	{

	}
	void Laugh()
	{
		std::cout << "黄种人笑！" << std::endl;
	}
	void Cry()
	{
		std::cout << "黄种人哭！" << std::endl;
	}
	void Talk()
	{
		std::cout << "黄种人说话！" << std::endl;
	}
};

class BlackHuman : public IHuman
{
public:
	BlackHuman(void)
	{

	}
	~BlackHuman(void)
	{

	}
	void Laugh()
	{
		std::cout << "黑种人笑！" << std::endl;
	}
	void Cry()
	{
		std::cout << "黑种人哭！" << std::endl;
	}
	void Talk()
	{
		std::cout << "黑种人说话！" << std::endl;
	}
};
class IHumanFactory                          //抽象工厂基类
{
public:
	IHumanFactory(void)
	{

	}
	~IHumanFactory(void)
	{

	}
	virtual IHuman* CreateHuman() = 0;   //抽象基类的创建函数，内部一般含有new创建的对
										 //象

};

class WhiteHumanFactory : public IHumanFactory
{
public:
	WhiteHumanFactory(void)
	{

	}
	~WhiteHumanFactory(void)
	{

	}
	IHuman *CreateHuman()           //具体实现类的创建函数，用于创建具体的对象
	{
		return new WhiteHuman();
	}

};


class YellowHumanFactory : public IHumanFactory
{
public:
	YellowHumanFactory(void)
	{

	}
	~YellowHumanFactory(void)
	{

	}
	IHuman *CreateHuman()
	{
		return new YellowHuman();
	}

};
class BlackHumanFactory : public IHumanFactory
{
public:
	BlackHumanFactory(void)
	{

	}
	~BlackHumanFactory(void)
	{

	}
	IHuman *CreateHuman()
	{
		return new BlackHuman();
	}
};
