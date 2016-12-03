#include "Decorator.h"

int main(void) {
	// һ��һ���װ�κ͹�����ϣ���ֹ�౬ը
	IComponent *p_component = new CConcreteComponent();
	IComponent *p_component1 = new CConcreteDecorator1(p_component);
	IComponent *p_component2 = new CConcreteDecorator2(p_component1);
	IComponent *p_component3 = new CConcreteDecorator3(p_component2);

	p_component3->operation();

	delete p_component3;
	delete p_component2;
	delete p_component1;
	delete p_component;

	return 0;
}