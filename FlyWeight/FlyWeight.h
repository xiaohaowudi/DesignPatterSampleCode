#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <map>
#include <iostream>
using namespace std;

class IFlyWeight {
public:
	// 子类实现的具体功能
	virtual void operation() = 0;

	// 获取key
	unsigned int get_key() { return m_key; }

	virtual ~IFlyWeight() { }

protected:
	// 构造函数外部不能调用，只能通过工厂获取对象，但是子类可以调用
	IFlyWeight(unsigned int key) : m_key(key) { }
	unsigned int m_key;
};

class ConcreteFlyWeight : public IFlyWeight{
	friend class FlyWeightFactory;
public:
	void operation();
	virtual ~ConcreteFlyWeight() { cout << "ConcreteFlyWeight::~ConcreteFlyWeight" << endl; }
private:
	ConcreteFlyWeight(unsigned int key) : IFlyWeight(key) { cout << "ConcreteFlyWeight::ConcreteFlyWeight" << endl; }
};

class FlyWeightFactory {
public:
	FlyWeightFactory();
	virtual ~FlyWeightFactory();

	// 获取flyweight对象
	IFlyWeight* get_flyweight(unsigned int key);

private:
	// 对象池
	map<unsigned int, IFlyWeight*> m_flyweight_pool;
};

#endif