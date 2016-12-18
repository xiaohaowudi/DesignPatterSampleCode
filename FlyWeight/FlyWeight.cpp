#include "FlyWeight.h"
#include <iostream>
using namespace std;

void ConcreteFlyWeight::operation() {
	cout << "ConcreteFlyWeight::operation" << "key = " << m_key << endl;
}

FlyWeightFactory::FlyWeightFactory() {
	m_flyweight_pool.clear();
}

FlyWeightFactory::~FlyWeightFactory() {
	IFlyWeight* p_flyweight;

	for (auto itr = m_flyweight_pool.begin(); itr != m_flyweight_pool.end(); itr++) {
		p_flyweight = (IFlyWeight*)(itr->second);
		if (p_flyweight == NULL) {
			continue;;
		}

		delete p_flyweight;
	}
	m_flyweight_pool.clear();
}

IFlyWeight* FlyWeightFactory::get_flyweight(unsigned int key) {
	if (m_flyweight_pool.find(key) != m_flyweight_pool.end()) {
		return m_flyweight_pool[key];
	}

	IFlyWeight *p_flyweight = new ConcreteFlyWeight(key);
	m_flyweight_pool[key] = p_flyweight;

	return p_flyweight;
}
