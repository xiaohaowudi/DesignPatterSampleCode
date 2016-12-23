#include <stdio.h>
#include "Proxy.h"

int main(void) {
	CRealSubject* p_real_subject = new CRealSubject();
	ISubject* p_subject = new CProxy(p_real_subject);

	/*	
		代理类使用者不感知具体实现类是谁，也不感知功能接口
		实现方式的修改，代理相当于中间加了一层,将功能的实现
		者和使用者相互隔离开
	*/
	p_subject->request();
	p_subject->request();
	p_subject->request();

	delete p_subject;
	delete p_real_subject;
	return 0;
}