#include "Product.h"
#include "Factory.h"
#include <stdio.h>


/*
	��Ʒ��ʹ���߲���֪����Ĳ�Ʒ��Ĺ��췽ʽ�;�����ʲô��Ʒ�ֻ࣬����ĳ���ض��Ĺ�����
	�ܹ�����ʵ����ĳ�ֹ��ܵĲ�Ʒ��ʵ�����ɣ���Ʒ�Ĺ��췽ʽ�仯�ˣ���Ʒʹ���ߵĴ��벻��
	���κ��޸ģ����ڲ�Ʒ���췽ʽ�ı���޸Ķ���յ��˾��幤�����ʵ������,��Ʒ����Ϊ����
	�仯������func�����еĴ���һ�ж����ø�
*/
void func(IFactory *p_factory) {
	if (p_factory == NULL) {
		return;
	}

	IProduct *p_product = p_factory->create_product();
	if (p_product == NULL) {
		return;
	}
	
	for (int i = 3; i < 10; i++) {
		p_product->operation();
	}

	p_factory->destroy_product(p_product);
}


int main(void) {
    IFactory *p_factory1 = new CFactory1();
    IFactory *p_factory2 = new CFactory2();

	func(p_factory1);
	func(p_factory2);
    /*
        ��Ʒ��ʹ���߲���֪����Ĳ�Ʒ��Ĺ��췽ʽ�;�����ʲô��Ʒ�ֻ࣬����ĳ���ض��Ĺ�����
        �ܹ�����ʵ����ĳ�ֹ��ܵĲ�Ʒ��ʵ�����ɣ���Ʒ�Ĺ��췽ʽ�仯�ˣ���Ʒʹ���ߵĴ��벻��
        ���κ��޸ģ����ڲ�Ʒ���췽ʽ�ı���޸Ķ���յ��˾��幤�����ʵ������
    */
	return 0;
}