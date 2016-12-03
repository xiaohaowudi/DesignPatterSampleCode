#include "Decorator.h"

int main(void) {
	// 一层一层的装饰和功能组合，防止类爆炸
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