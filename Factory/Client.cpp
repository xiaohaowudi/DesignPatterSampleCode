#include "Product.h"
#include "Factory.h"
#include <stdio.h>

int main(void) {
    IProduct* p_product = NULL;

    IFactory *p_factory1 = new CFactory1();
    IFactory *p_factory2 = new CFactory2();

    /*
        ��Ʒ��ʹ���߲���֪����Ĳ�Ʒ��Ĺ��췽ʽ�;�����ʲô��Ʒ�ֻ࣬����ĳ���ض��Ĺ�����
        �ܹ�����ʵ����ĳ�ֹ��ܵĲ�Ʒ��ʵ�����ɣ���Ʒ�Ĺ��췽ʽ�仯�ˣ���Ʒʹ���ߵĴ��벻��
        ���κ��޸ģ����ڲ�Ʒ���췽ʽ�ı���޸Ķ���յ��˾��幤�����ʵ������
    */
    p_product = p_factory1->create_product();
    p_product->operation();
    delete p_product;

    p_product = p_factory2->create_product();
    p_product->operation();
    delete p_product;

    delete p_factory1;
    delete p_factory2;
}