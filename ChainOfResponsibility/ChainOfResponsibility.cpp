#include "ChainOfResponsibility.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// 往下传递责任的逻辑在抽象类进行实现，因为此逻辑对于每个子类都是一样的
void IHandler::call_handle_func(REQUEST_TYPE req_type) {
	if (can_handle_request(req_type) == true) {
		handle_request(req_type);
	}
	else {
		// 传给后继节点继续执行
		if (m_successor_ptr != NULL) {
			m_successor_ptr->call_handle_func(req_type);
		}
		else {
			cout << "end of chain, find no proper node!!!" << endl;
		}
	}
}

//每个子类在下面自己实现判断能否处理请求和实际处理请求的方法
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
