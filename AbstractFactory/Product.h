#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class IProductA {
public:
    IProductA() {}
    virtual ~IProductA() {}
    // A类商品的功能函数
    virtual void operation_a() = 0;
};

class IProductB {
public:
    IProductB() {}
    virtual ~IProductB() {}
    // B类商品的功能函数
    virtual void operation_b() = 0;
};

class CProductA1 : public IProductA {
public:
    CProductA1() {
        cout << "CProductA1::CProductA1" << endl;
    }

    ~CProductA1() {
        cout << "CProductA1::~CProductA1" << endl;
    }

    void operation_a();
};

class CProductA2 : public IProductA {
public:
    CProductA2() {
        cout << "CProductA2::CProductA2" << endl;
    }

    ~CProductA2() {
        cout << "CProductA2::~CProductA2" << endl;
    }

    void operation_a();
};

class CProductB1 : public IProductB {
public:
    CProductB1() {
        cout << "CProductB1::CProductB1" << endl;
    }

    ~CProductB1() {
        cout << "CProductB1::~CProductB1" << endl;
    }

    void operation_b();
};

class CProductB2 : public IProductB {
public:
    CProductB2() {
        cout << "CProductB2::CProductB2" << endl;
    }

    ~CProductB2() {
        cout << "CProductB2::~CProductB2" << endl;
    }

    void operation_b();
};

#endif