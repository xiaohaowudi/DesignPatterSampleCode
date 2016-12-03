#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"
#include <iostream>
using namespace std;

class IFactory {
public:
    IFactory() {}
    virtual ~IFactory() {}
    virtual IProductA* create_product_a() = 0;
    virtual IProductB* create_product_b() = 0;
};

class CFactory1 : public IFactory {
public:
    CFactory1() { cout << "CFactory1::CFactory1" << endl; }
    ~CFactory1() { cout << "CFactory1::~CFactory1" << endl; }
    IProductA* create_product_a();
    IProductB* create_product_b();
};

class CFactory2 : public IFactory {
public:
    CFactory2() { cout << "CFactory2::CFactory2" << endl; }
    ~CFactory2() { cout << "CFactory2::~CFactory2" << endl; }
    IProductA* create_product_a();
    IProductB* create_product_b();
};

#endif