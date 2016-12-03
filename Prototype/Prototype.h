#ifndef PROTOTYPEY_H
#define PROTOTYPE_H

#include <iostream>
using namespace std;

// 原型抽象类
class IPrototype {
public:
	IPrototype() {};
	virtual ~IPrototype() {};

	// 原型抽象类中规定每个子类必须实现clone接口
	virtual IPrototype* clone() = 0;
};

// 原型实现类1
class CPrototype1 : public IPrototype {
private:
	int item;

public:
	CPrototype1() : item(100) {
		cout << "CPrototype1::CPrototype1" << endl;
	}

	CPrototype1(const CPrototype1& prototype) {
		this->item = prototype.item;
	}

	~CPrototype1() {
		cout << "CPrototype1::~CPrototype1" << endl;
	}

	IPrototype* clone();
	void show();
};

// 原型实现类1
class CPrototype2 : public IPrototype {
private:
	double item;

public:
	CPrototype2() : item(100.998) {
		cout << "CPrototype2::CPrototype2" << endl;
	}

	CPrototype2(const CPrototype2& prototype) {
		this->item = prototype.item;
	}

	~CPrototype2() {
		cout << "CPrototype2::~CPrototype2" << endl;
	}

	IPrototype* clone();
	void show();
};

#endif