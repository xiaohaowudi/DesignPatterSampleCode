#include "ChainOfResponsibility.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// ���´������ε��߼��ڳ��������ʵ�֣���Ϊ���߼�����ÿ�����඼��һ����
void IHandler::call_handle_func(REQUEST_TYPE req_type) {
	if (can_handle_request(req_type) == true) {
		handle_request(req_type);
	}
	else {
		// ������̽ڵ����ִ��
		if (m_successor_ptr != NULL) {
			m_successor_ptr->call_handle_func(req_type);
		}
		else {
			cout << "end of chain, find no proper node!!!" << endl;
		}
	}
}

//ÿ�������������Լ�ʵ���ж��ܷ��������ʵ�ʴ�������ķ���
bool CConcreteHandler0::can_handle_request(REQUEST_TYPE req_type) {
	return (req_type == TYPE0);
}

void CConcreteHandler0::handle_request(REQUEST_TYPE req_type) {
	cout << "CConcreteHandler0 handling request" << req_type << endl;
}



bool CConcreteHandler1::can_handle_request(REQUEST_TYPE req_type) {
	return (req_type == TYPE1);
}

void CConcreteHandler1::handle_request(REQUEST_TYPE req_type) {
	cout << "CConcreteHandler1 handling request" << req_type << endl;
}



bool CConcreteHandler2::can_handle_request(REQUEST_TYPE req_type) {
	return (req_type == TYPE2);
}

void CConcreteHandler2::handle_request(REQUEST_TYPE req_type) {
	cout << "CConcreteHandler2 handling request" << req_type << endl;
}
