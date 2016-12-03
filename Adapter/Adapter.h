#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
using namespace std;

// 上层调用者希望使用的功能接口
class ITarget {
public:
	ITarget() {}
	virtual ~ITarget() {}

	// 上层调用者希望使用的函数接口
	virtual void request() = 0;
};

// 已经实现了某种功能的类，该类的功能能够被复用，但是使用方式和调用者希望的接口不同
class Adaptee {
public:
	// 实现了某种功能的不兼容接口
	void special_request();
};

// 适配器的实现类，利用和调用者希望使用的接口不兼容的现有功能实现调用者希望使用的形式的接口
class CAdapter : public ITarget {
public:
	CAdapter(Adaptee *p_adapter) : m_adaptee_ptr(p_adapter) { cout << "CAdapter::CAdapter" << endl; }
	~CAdapter() { cout << "CAdapter::~CAdapter" << endl; }

	// 对调用者希望的request接口的实现
	void request();
private:
	Adaptee* m_adaptee_ptr;
};

#endif