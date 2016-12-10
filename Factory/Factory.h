#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"

class IFactory {
public:
    IFactory() {}
    virtual ~IFactory() {};

    // ����Ĺ�������������ʵ�ִ˷��������ڹ��첻ͬ�Ĳ�Ʒ����(��������)
    virtual IProduct* create_product() = 0;

	// �����������Ʒ�ķ���
	virtual void destroy_product(IProduct *p_product) = 0;
};

// ���ֹ�����ʵ��һ���ĳ���ӿڣ����Ǵ�����ͬ���͵Ĳ�Ʒ����

class CFactory1 : public IFactory {
public:
    CFactory1();
    ~CFactory1();

	// ���幤������ʵ��
    IProduct* create_product();
	void destroy_product(IProduct *p_product);
};

class CFactory2 : public IFactory {
public:
    CFactory2();
    ~CFactory2();

	// ���幤������ʵ��
    IProduct* create_product();
	void destroy_product(IProduct *p_product);
};

#endif