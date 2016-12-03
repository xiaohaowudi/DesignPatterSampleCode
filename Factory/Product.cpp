#include "Product.h"
#include <iostream>
using namespace std;

CProduct1::CProduct1(int num) {
    cout << "CProduct1::CProduct1, num = " << num << endl;
}

CProduct1::~CProduct1() {
    cout << "CProduct1::~CProduct1" << endl;
}

void CProduct1::operation() {
    cout << "CProduct1::operation" << endl;
}

CProduct2::CProduct2(double num) {
    cout << "CProduct2::CProduct2, num = " << num << endl;
}

CProduct2::~CProduct2() {
    cout << "CProduct2::~CProduct2" << endl;
}

void CProduct2::operation() {
    cout << "CProduct2::operation" << endl;
}

