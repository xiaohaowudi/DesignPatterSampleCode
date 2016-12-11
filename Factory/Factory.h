#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"

class IFactory {
public:
    IFactory() {}
    virtual ~IFactory() {};

    // 抽象的工厂方法，子类实现此方法，用于构造不同的产品对象(工厂方法)
    virtual IProduct* create_product() = 0;

	// 抽象的析构产品的方法
	virtual void destroy_product(IProduct *p_product) = 0;
};

// 两种工厂都实现一样的抽象接口，但是创建不同类型的产品对象

class CFactory1 : public IFactory {
public:
    CFactory1();
    ~CFactory1();

	// 具体工厂方法实现
    IProduct* create_product();
	void destroy_product(IProduct *p_product);
};

class CFactory2 : public IFactory {
public:
    CFactory2();
    ~CFactory2();

	// 具体工厂方法实现
    IProduct* create_product();
	void destroy_product(IProduct *p_product);
};

#endif