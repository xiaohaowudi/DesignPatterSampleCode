#ifndef STATE_H
#define STATE_H

#include <map>
using namespace std;

typedef unsigned int STATE;

#define STATE_INIT		0
#define STATE1			1
#define STATE2			2
#define STATE3			3

// ״̬����ӿ�
class IState {
public:
	IState() { }
	virtual ~IState() { }

	// ����ʵ�ֽӿ�
	virtual void handle() = 0;

	// ��ȡ�¸�״̬�ӿ�
	virtual STATE get_next_state() = 0;
};

// ����״̬ת������������
class CContext {
public:
	CContext();
	virtual ~CContext();

	// �����Ĺ��ܽӿ�
	void request();

private:
	// ���һ��״̬ʵ��
	IState *m_state_ptr;

	// ��ǰ��״̬
	STATE m_state;
	// ״̬��״̬ʵ����Ķ�Ӧ��ϵ
	map<STATE, IState*> m_state2impl;
};

class CStateInit : public IState {
public:
	CStateInit() { }
	~CStateInit() { }
	void handle();
	STATE get_next_state();
};

class CState1 : public IState {
public:
	CState1() { }
	~CState1() { }
	void handle();
	STATE get_next_state();
};

class CState2 : public IState {
public:
	CState2() { }
	~CState2() { }
	void handle();
	STATE get_next_state();
};

class CState3 : public IState {
public:
	CState3() { }
	~CState3() { }
	void handle();
	STATE get_next_state();
};


#endif