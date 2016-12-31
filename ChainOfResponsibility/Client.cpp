#include "ChainOfResponsibility.h"

int main(void) {
	IHandler *p_handler0 = new CConcreteHandler0();
	IHandler *p_handler1 = new CConcreteHandler1(p_handler0);
	IHandler *p_handler2 = new CConcreteHandler2(p_handler1);

	IHandler* p_chain_head = p_handler2;
	p_chain_head->call_handle_func(TYPE0);
	p_chain_head->call_handle_func(TYPE1);
	p_chain_head->call_handle_func(TYPE2);
	p_chain_head->call_handle_func(TYPE3);

	delete p_handler0;
	delete p_handler1;
	delete p_handler2;

	return 0;
}