#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <map>
#include <iostream>
using namespace std;

class IFlyWeight {
public:
	// ����ʵ�ֵľ��幦��
	virtual void operation() = 0;

	// ��ȡkey
	unsigned int get_key() { return m_key; }

	virtual ~IFlyWeight() { }

protected:
	// ���캯���ⲿ���ܵ��ã�ֻ��ͨ��������ȡ���󣬵���������Ե���
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

	// ��ȡflyweight����
	IFlyWeight* get_flyweight(unsigned int key);

private:
	// �����
	map<unsigned int, IFlyWeight*> m_flyweight_pool;
};

#endif