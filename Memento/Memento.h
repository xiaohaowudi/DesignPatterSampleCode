#ifndef MEMENTO_H
#define MEMENTO_H

typedef unsigned int STATE;

// ����¼��
class CMemento {
public:
	CMemento(STATE state) { m_state = state; }
	~CMemento() { }

	STATE get_state() const { return m_state; }
	void set_state(STATE state) { m_state = state; }

private:
	STATE m_state;
};

// ״̬�᲻�ϱ仯�ķ�������
class COriginator {
public:
	COriginator() : m_state(0) { }
	~COriginator() { }

	// ���ݵ�ǰ��״̬��������¼
	CMemento create_memento();
	// �ָ�״̬
	void restore_state(const CMemento& memento);

	void print_state();
	void change_state();

private:
	// �Լ����еĵ�ǰ״̬
	STATE m_state;
};

#endif
