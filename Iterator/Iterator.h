#ifndef ITERATOR_H
#define ITERATOR_H

typedef unsigned int DATA;

#include <assert.h>
#include <vector>
using namespace std;

// 容器抽象类
class IIterator {
public:
	IIterator() { }
	~IIterator() { }

	// 子类实现接口
	virtual void first() = 0;
	virtual void next() = 0;
	virtual DATA current() = 0;
	virtual bool is_done() = 0;
};


class IAggregate {
public:
	IAggregate() { }
	virtual ~IAggregate() { }

	// 获取迭代器接口
	virtual IIterator* get_iterator() = 0;
};

class CAggregate : public IAggregate {
	friend class CIterator;
public:
	CAggregate() {
		// 假设容器有10个成员
		m_data_set.push_back(0);
		m_data_set.push_back(1);
		m_data_set.push_back(2);
		m_data_set.push_back(3);
		m_data_set.push_back(4);
		m_data_set.push_back(5);
		m_data_set.push_back(6);
		m_data_set.push_back(7);
		m_data_set.push_back(8);
		m_data_set.push_back(9);
	}

	~CAggregate() { }

	IIterator* get_iterator();
private:
	vector<DATA> m_data_set;
};

class CIterator : public IIterator {
public:
	CIterator(CAggregate* p_aggregate) : m_aggregate_ptr(p_aggregate), m_index(0) {
		assert(p_aggregate != NULL);
		p_aggregate->m_data_set.size();
	}

	~CIterator() { }

	void first();
	void next();
	DATA current();
	bool is_done();
private:
	CAggregate* m_aggregate_ptr;
	unsigned int m_index;
};

#endif