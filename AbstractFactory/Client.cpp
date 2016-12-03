#include <stdio.h>
#include "Product.h"
#include "Factory.h"


int main(void) {
    IProductA* p_product_a = NULL;
    IProductB* p_product_b = NULL;
    IFactory* p_factory = NULL;
        
    p_factory = new CFactory1();
    p_product_a = p_factory->create_product_a();
    p_product_b = p_factory->create_product_b();
    p_product_a->operation_a();
    p_product_b->operation_b();

    delete p_factory;
    p_factory = NULL;
    delete p_product_a;
    p_product_a = NULL;
    delete p_product_b;
    p_product_b = NULL;

    cout << "############################################" << endl;
    p_factory = new CFactory2();
    p_product_a = p_factory->create_product_a();
    p_product_b = p_factory->create_product_b();
    p_product_a->operation_a();
    p_product_b->operation_b();

    delete p_factory;
    p_factory = NULL;
    delete p_product_a;
    p_product_a = NULL;
    delete p_product_b;
    p_product_b = NULL;

    return 0;
}