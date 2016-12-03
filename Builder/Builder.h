#ifndef BUILDER_H

#include <stdio.h>
#include <iostream>
using namespace std;

// �����������ӿ��࣬�涨������Ҫ��Щ����
class IBuilder{
public:
	IBuilder() {}
	virtual ~IBuilder() {}
	
	// �涨������ΪA��B��������
	virtual void build_part_a() = 0;
	virtual void build_part_b() = 0;
};

// ����builder��ʵ����
class CBuilder1 : public IBuilder {
public:
	CBuilder1() { cout << "CBuilder1::CBuilder1" << endl; }
	~CBuilder1() { cout << "CBuilder1::~CBuilder1" << endl; }
	void build_part_a();
	void build_part_b();
};

// ����builder��ʵ����
class CBuilder2 : public IBuilder {
public:
	CBuilder2() { cout << "CBuilder2::CBuilder2" << endl; }
	~CBuilder2() { cout << "CBuilder2::~CBuilder2" << endl; }
	void build_part_a();
	void build_part_b();
};


// �涨ÿ�����������˳��
class CDirector {
public:
	CDirector() : m_builder_ptr(NULL) {}
	virtual ~CDirector() {}

	// ��������������IBuilder�������ṩ�Ĺ���ÿ�����ֵķ���
	void construct();

	// ����builder����
	void set_builder(IBuilder* p_builder);

private:
	IBuilder* m_builder_ptr;
};

#define BUILDER_H
#endif
