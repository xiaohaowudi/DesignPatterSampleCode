#include "Mediator.h"
#include <iostream>
using namespace std;

int main(void) {
	CColleague1* p_colleague1 = new CColleague1();
	CColleague2* p_colleague2 = new CColleague2();

	IMediator* p_mediator = new CMediator(p_colleague1, p_colleague2);
	p_colleague1->set_mediator(p_mediator);
	p_colleague2->set_mediator(p_mediator);
	
	// 两个同事类相互简洁调用合作完成了功能，但是没有直接耦合
	cout << "###################################" << endl;
	p_colleague1->function();
	cout << "###################################" << endl << endl;

	cout << "###################################" << endl;
	p_colleague2->function();
	cout << "###################################" << endl << endl;

	delete p_mediator;
	delete p_colleague1;
	delete p_colleague2;

	return 0;
}