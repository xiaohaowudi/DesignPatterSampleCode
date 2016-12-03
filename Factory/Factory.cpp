#include "Factory.h"
#include <iostream>
using namespace std;

CFactory1::CFactory1() {
    cout << "CFactory1::CFactory1" << endl;
}

CFactory1::~CFactory1() {
    cout << "CFactory1::~CFactory1" << endl;
}

IProduct* CFactory1::create_product() {
    return new CProduct1(100);
}

CFactory2::CFactory2() {
    cout << "CFactory2::CFactory2" << endl;
}

CFactory2::~CFactory2() {
    cout << "CFactory2::~CFactory2" << endl;
}

IProduct* CFactory2::create_product() {
    return new CProduct2(100.789);
}
