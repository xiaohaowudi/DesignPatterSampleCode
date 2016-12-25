#ifndef MEMENTO_H
#define MEMENTO_H

typedef unsigned int STATE;

// 备忘录类
class CMemento {
public:
	CMemento(STATE state) { m_state = state; }
	~CMemento() { }

	STATE get_state() const { return m_state; }
	void set_state(STATE state) { m_state = state; }

private:
	STATE m_state;
};

// 状态会不断变化的发生器类
class COriginator {
public:
	COriginator() : m_state(0) { }
	~COriginator() { }

	// 根据当前的状态创建备忘录
	CMemento create_memento();
	// 恢复状态
	void restore_state(const CMemento& memento);

	void print_state();
	void change_state();

private:
	// 自己持有的当前状态
	STATE m_state;
};

#endif
