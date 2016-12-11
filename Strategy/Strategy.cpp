#include "Strategy.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void CContext::ContextInterface() {
	if (m_strategy_ptr != NULL) {
		m_strategy_ptr->AlgorithmInterface();
	}
}

// 具体类的算法实现函数
void CConcreteStrategy1::AlgorithmInterface() {
	cout << "CConcreteStrategy1::AlgorithmInterface" << endl;
}

// 具体类的算法实现函数
void CConcreteStrategy2::AlgorithmInterface() {
	cout << "CConcreteStrategy2::AlgorithmInterface" << endl;
}


