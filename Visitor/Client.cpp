#include "Visitor.h"

int main(void) {
	IVisitor* p_visitor_a = new CVisitorA();
	IVisitor* p_visitor_b = new CVisitorB();

	CElement1 element1(100);
	CElement2 element2(100.12345);
	CElement3 element3("100");

	// 调用针对element的操作
	element1.accept(p_visitor_a);
	element2.accept(p_visitor_a);
	element3.accept(p_visitor_a);
	element1.accept(p_visitor_b);
	element2.accept(p_visitor_b);
	element3.accept(p_visitor_b);

	delete p_visitor_a;
	delete p_visitor_b;

	return 0;
}