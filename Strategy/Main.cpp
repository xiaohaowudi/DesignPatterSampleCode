#include "Strategy.h"
#include <stdio.h>

int main(void) {
	IStrategy *p_strategy = NULL;
	CContext *p_context = NULL;

	// 算法1的调用点
	p_strategy = new CConcreteStrategy1();
	p_context = new CContext(p_strategy);
	p_context->ContextInterface();
	delete p_strategy;
	delete p_context;

	// 算法2的调用点
	p_strategy = new CConcreteStrategy2();
	p_context = new CContext(p_strategy);
	p_context->ContextInterface();
	delete p_strategy;
	delete p_context;

	return 0;
}