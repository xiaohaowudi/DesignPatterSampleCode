#include "Proxy.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void CRealSubject::request() {
	cout << "CRealSubject::request" << endl;
}

void CProxy::request() {
	if (m_real_request_ptr != NULL) {
		m_real_request_ptr->request();
	}
}