#include "Prototype.h"
#include <iostream>
using namespace std;

IPrototype* CPrototype1::clone() {
	IPrototype* p_prototype_tmp = new CPrototype1(*this);
	return p_prototype_tmp;
}

void CPrototype1::operation() {
	cout << "CPrototype1.item = " << item << endl;
}

IPrototype* CPrototype2::clone() {
	IPrototype* p_prototype_tmp = new CPrototype2(*this);
	return p_prototype_tmp;
}

void CPrototype2::operation() {
	cout << "CPrototype2.item = " << item << endl;
}
