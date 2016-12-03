#ifndef BUILDER_H

#include <stdio.h>
#include <iostream>
using namespace std;

// 构造者类抽象接口类，规定构造需要哪些步骤
class IBuilder{
public:
	IBuilder() {}
	virtual ~IBuilder() {}
	
	// 规定构建分为A和B两个步骤
	virtual void build_part_a() = 0;
	virtual void build_part_b() = 0;
};

// 两种builder的实现类
class CBuilder1 : public IBuilder {
public:
	CBuilder1() { cout << "CBuilder1::CBuilder1" << endl; }
	~CBuilder1() { cout << "CBuilder1::~CBuilder1" << endl; }
	void build_part_a();
	void build_part_b();
};

// 两种builder的实现类
class CBuilder2 : public IBuilder {
public:
	CBuilder2() { cout << "CBuilder2::CBuilder2" << endl; }
	~CBuilder2() { cout << "CBuilder2::~CBuilder2" << endl; }
	void build_part_a();
	void build_part_b();
};


// 规定每个构建步骤的顺序
class CDirector {
public:
	CDirector() : m_builder_ptr(NULL) {}
	virtual ~CDirector() {}

	// 构建函数，调用IBuilder衍生类提供的构造每个部分的方法
	void construct();

	// 设置builder函数
	void set_builder(IBuilder* p_builder);

private:
	IBuilder* m_builder_ptr;
};

#define BUILDER_H
#endif
