#include "Decorator.h"
#include <iostream>
using namespace std;

// 原始Component实现类的行为方法
void CConcreteComponent::operation() {
	cout << "CConcreteComponent::operation" << endl;
}

// 装饰者1行为
void CConcreteDecorator1::operation() {
	m_component_ptr->operation();
	add_operation();
}

// 装饰者1附加行为
void CConcreteDecorator1::add_operation() {
	cout << "CConcreteDecorator1::add_operation" << endl;
}

// 装饰者2行为
void CConcreteDecorator2::operation() {
	m_component_ptr->operation();
	add_operation();
}

// 装饰者2附加行为
void CConcreteDecorator2::add_operation() {
	cout << "CConcreteDecorator2::add_operation" << endl;
}

// 装饰者3行为
void CConcreteDecorator3::operation() {
	m_component_ptr->operation();
	add_operation();
}

// 装饰者3附加行为
void CConcreteDecorator3::add_operation() {
	cout << "CConcreteDecorator3::add_operation" << endl;
}

