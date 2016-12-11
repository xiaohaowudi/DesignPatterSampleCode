#ifndef STRATEGY_H
#define STRATEGY_H

// 抽象策略基类
class IStrategy {
public:
	IStrategy() { }
	virtual ~IStrategy() { }

	// 具体算法实现接口，子类进行实现
	virtual void AlgorithmInterface() = 0;
};

class CConcreteStrategy1 : public IStrategy {
public:
	CConcreteStrategy1() { }
	~CConcreteStrategy1() { }
	void AlgorithmInterface();
};

class CConcreteStrategy2 : public IStrategy {
public:
	CConcreteStrategy2() { }
	~CConcreteStrategy2() { }
	void AlgorithmInterface();
};


class CContext {
public:
	CContext(IStrategy* p_strategy) {
		m_strategy_ptr = p_strategy;
	}

	~CContext() {}

	// 对具体算法进行实际调用的函数，用算法实现一套稳定不变的流程
	void ContextInterface();
private:
	IStrategy* m_strategy_ptr;
};

#endif

