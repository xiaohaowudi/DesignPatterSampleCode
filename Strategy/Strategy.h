#ifndef STRATEGY_H
#define STRATEGY_H

// ������Ի���
class IStrategy {
public:
	IStrategy() { }
	virtual ~IStrategy() { }

	// �����㷨ʵ�ֽӿڣ��������ʵ��
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

	// �Ծ����㷨����ʵ�ʵ��õĺ��������㷨ʵ��һ���ȶ����������
	void ContextInterface();
private:
	IStrategy* m_strategy_ptr;
};

#endif

