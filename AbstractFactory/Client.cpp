#include <stdio.h>
#include "Product.h"
#include "Factory.h"

void func(IFactory *p_factory) {
	if (p_factory == NULL) {
		return;
	}

	IProductA* p_product_a = NULL;
	IProductB* p_product_b = NULL;

	/*
		����һϵ����صĹ��ܶ�������һ������Ķ��󣬾�����Щʵ���౻��ϵ���һ��
		��IFactory������������ʹ���߲����ľ��幹��������Щ��������ص����ʵ����
		��Ʒ�����Ϲ�ϵ�б仯��ֻ��Ҫ���ӹ������ʵ�֣�func�����е����д��벻���޸�һ��
	*/
	p_product_a = p_factory->create_product_a();
	p_product_b = p_factory->create_product_b();

	for (int i = 0; i < 3; i++) {
		p_product_a->operation_a();
		p_product_b->operation_b();
	}

	delete p_product_a;
	delete p_product_b;
}


int main(void) {
    IFactory* p_factory = NULL;
    
	cout << "##################### process 1 start ###########################" << endl;
	// ��1�����������
    p_factory = new CFactory1();
	func(p_factory);
	delete p_factory;
	p_factory = NULL;
	cout << "##################### process 1 end ###########################" << endl << endl;

	cout << "##################### process 2 start ###########################" << endl;
	// ��2�����������
	p_factory = new CFactory2();
	func(p_factory);
	delete p_factory;
	p_factory = NULL;
	cout << "##################### process 2 start ###########################" << endl << endl;

    return 0;
}