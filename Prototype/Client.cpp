#include "Prototype.h"

int main(void) {
	IPrototype *p_prototype1 = new CPrototype1();
	IPrototype *p_prototype2 = new CPrototype2();

	// ͨ��ԭ�͵�clone������ȡʵ����������ʹ��new�����
	IPrototype* p_prototype_clone1 = p_prototype1->clone();
	IPrototype* p_prototype_clone2 = p_prototype2->clone();

	delete p_prototype1;
	delete p_prototype2;

	dynamic_cast<CPrototype1*>(p_prototype_clone1)->show();
	dynamic_cast<CPrototype2*>(p_prototype_clone2)->show();

	delete p_prototype_clone1;
	delete p_prototype_clone2;

	return 0;
}