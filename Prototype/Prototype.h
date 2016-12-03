#ifndef PROTOTYPEY_H
#define PROTOTYPE_H

#include <iostream>
using namespace std;

// ԭ�ͳ�����
class IPrototype {
public:
	IPrototype() {};
	virtual ~IPrototype() {};

	// ԭ�ͳ������й涨ÿ���������ʵ��clone�ӿ�
	virtual IPrototype* clone() = 0;
};

// ԭ��ʵ����1
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

// ԭ��ʵ����1
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