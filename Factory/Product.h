#ifndef PRODUCT_H
#define PRODUCT_H

// �������ߵĳ�����
class IProduct {
public:
    IProduct() {}
    virtual ~IProduct() {};

    // ��������������ɵ�ĳ���
    virtual void operation() = 0;
};

// ������Ʒ���̳г������Ʒ�ӿڣ����ǹ���ķ�����ͬ

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