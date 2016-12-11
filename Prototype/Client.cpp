#include "Prototype.h"

int main(void) {
	IPrototype *p_prototype1 = new CPrototype1();
	IPrototype *p_prototype2 = new CPrototype2();

	// 通过原型的clone方法获取实例，而不是使用new运算符
	IPrototype* p_prototype_clone1 = p_prototype1->clone();
	IPrototype* p_prototype_clone2 = p_prototype2->clone();

	delete p_prototype1;
	delete p_prototype2;

	p_prototype_clone1->operation();
	p_prototype_clone2->operation();

	delete p_prototype_clone1;
	delete p_prototype_clone2;

	return 0;
}