#include "Product.h"
#include "Factory.h"
#include <iostream>
using namespace std;

IProductA* CFactory1::create_product_a() {
    return new CProductA1();
}

IProductB* CFactory1::create_product_b() {
    return new CProductB1();
}

IProductA* CFactory2::create_product_a() {
    return new CProductA2();
}

IProductB* CFactory2::create_product_b() {
    return new CProductB2();
}
