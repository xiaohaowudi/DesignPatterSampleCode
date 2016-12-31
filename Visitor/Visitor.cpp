#include "visitor.h"
#include <iostream>
using namespace std;

// 注入visitor对象实现
void CElement1::accept(IVisitor* p_visitor) {
	p_visitor->visit_element1(this);
}

void CElement2::accept(IVisitor* p_visitor) {
	p_visitor->visit_element2(this);
}

void CElement3::accept(IVisitor* p_visitor) {
	p_visitor->visit_element3(this);
}

void CVisitorA::visit_element1(CElement1* p_element) {
	cout << "CVisitorA, value = " << p_element->get_value() << endl;
}

void CVisitorA::visit_element2(CElement2* p_element) {
	cout << "CVisitorA, value = " << p_element->get_value() << endl;
}

void CVisitorA::visit_element3(CElement3* p_element) {
	cout << "CVisitorA, value = " << p_element->get_value() << endl;
}

void CVisitorB::visit_element1(CElement1* p_element) {
	cout << "CVisitorB, value = " << p_element->get_value() + 100 << endl;
}

void CVisitorB::visit_element2(CElement2* p_element) {
	cout << "CVisitorB, value = " << p_element->get_value() +100.0 << endl;
}

void CVisitorB::visit_element3(CElement3* p_element) {
	cout << "CVisitorB, value = " << p_element->get_value() + "100" << endl;
}




