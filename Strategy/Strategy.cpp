#include "Strategy.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void CContext::ContextInterface() {
	if (m_strategy_ptr != NULL) {
		m_strategy_ptr->AlgorithmInterface();
	}
}

// ��������㷨ʵ�ֺ���
void CConcreteStrategy1::AlgorithmInterface() {
	cout << "CConcreteStrategy1::AlgorithmInterface" << endl;
}

// ��������㷨ʵ�ֺ���
void CConcreteStrategy2::AlgorithmInterface() {
	cout << "CConcreteStrategy2::AlgorithmInterface" << endl;
}


