#ifndef STATE_H
#define STATE_H

#include <map>
using namespace std;

typedef unsigned int STATE;

#define STATE_INIT		0
#define STATE1			1
#define STATE2			2
#define STATE3			3

// 状态基类接口
class IState {
public:
	IState() { }
	virtual ~IState() { }

	// 子类实现接口
	virtual void handle() = 0;

	// 获取下个状态接口
	virtual STATE get_next_state() = 0;
};

// 负责状态转换的上下文类
class CContext {
public:
	CContext();
	virtual ~CContext();

	// 上下文功能接口
	void request();

private:
	// 组合一个状态实例
	IState *m_state_ptr;

	// 当前的状态
	STATE m_state;
	// 状态和状态实现类的对应关系
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