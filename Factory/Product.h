#ifndef PRODUCT_H
#define PRODUCT_H

// 商品的抽象定义
class IProduct {
public:
    IProduct() {}
    virtual ~IProduct() {};

    // 商品自身完成的某项功能
    virtual void operation() = 0;
};

// 两种商品都继承抽象的商品接口，但是构造的方法不同

class CProduct1 : public IProduct {
public:
    CProduct1(int num);
    ~CProduct1();
    void operation();
};

class CProduct2 : public IProduct {
public:
    CProduct2(double num);
    ~CProduct2();
    void operation();
};

#endif