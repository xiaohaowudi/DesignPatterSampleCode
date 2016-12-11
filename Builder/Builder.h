#ifndef BUILDER_H

#include <stdio.h>
#include <iostream>
using namespace std;


// 产品的抽象类
class IProduct {
public:
	IProduct() : a(0), b(0.0) { }
	virtual ~IProduct() { }

	// 产品功能的抽象接口
	virtual void operation() = 0;
	virtual void set_a(int a) = 0;
	virtual void set_b(double b) = 0;

protected:
	// 假定产品具有两段属性,需要分成两段先后进行构建
	int a;
	double b;
};

// 产品实现类1
class CProduct1 : public IProduct {
public:
	CProduct1() { }
	~CProduct1() { }
	void operation();
	void set_a(int a) { this->a = a; }
	void set_b(double b) { this->b = b; }
};

// 产品实现类1
class CProduct2 : public IProduct {
public:
	CProduct2() { }
	~CProduct2() { }
	void operation();
	void set_a(int a) { this->a = a; }
	void set_b(double b) { this->b = b; }
};


// 构造者类抽象接口类，规定构造需要哪些步骤
class IBuilder{
public:
	IBuilder() {}
	virtual ~IBuilder() {}
	
	// 规定构建分为A和B两个步骤
	virtual void build_part_a(IProduct* p_product) = 0;
	virtual void build_part_b(IProduct* p_product) = 0;
	virtual IProduct* init_instance() = 0;
};

// 两种builder的实现类
class CBuilder1 : public IBuilder {
public:
	CBuilder1() { cout << "CBuilder1::CBuilder1" << endl; }
	~CBuilder1() { cout << "CBuilder1::~CBuilder1" << endl; }
	void build_part_a(IProduct* p_product);
	void build_part_b(IProduct* p_product);
	IProduct* init_instance();
};

// 两种builder的实现类
class CBuilder2 : public IBuilder {
public:
	CBuilder2() { cout << "CBuilder2::CBuilder2" << endl; }
	~CBuilder2() { cout << "CBuilder2::~CBuilder2" << endl; }
	void build_part_a(IProduct* p_product);
	void build_part_b(IProduct* p_product);
	IProduct* init_instance();
};


// 规定每个构建步骤的顺序
class CDirector {
public:
	CDirector() : m_builder_ptr(NULL) {}
	virtual ~CDirector() {}

	// 构建函数，调用IBuilder衍生类提供的构造每个部分的方法
	IProduct* construct();

	// 设置builder函数
	void set_builder(IBuilder* p_builder);

private:
	IBuilder* m_builder_ptr;
};

#define BUILDER_H
#endif
