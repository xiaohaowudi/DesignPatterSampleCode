#ifndef COMMAND_H
#define COMMAND_H

#include <map>
using namespace std;

typedef unsigned int COMMAND_INDEX;


class IReceiver {
public:
	IReceiver() { }
	virtual ~IReceiver() { }
	// ����ʵ�ֵ�ʵ������ܵĽӿ�
	virtual void action() = 0;
};

class ICommand {
public:
	ICommand(IReceiver* p_receiver) : m_receiver_ptr(p_receiver) { }
	virtual ~ICommand() { }
	// ����ʵ�ֵ�ִ������ӿ�
	virtual void execute() = 0;
protected:
	// �����౾�����һ������������ִ�����ʵ��
	IReceiver* m_receiver_ptr;
};

// �ۺ�������࣬����ȷ��ʲô���͵�������ʲô�������ִ��
class Invoker {
public:
	Invoker() { m_index2cmd.clear(); }
	virtual ~Invoker() { }

	// ����һ���������
	void add_command(COMMAND_INDEX index, ICommand* p_command);
	// �ֱ�ִ��һ���������
	void dispatch_run_command(COMMAND_INDEX index);

private:
	map<COMMAND_INDEX, ICommand*> m_index2cmd;
};


class CReceiver1 : public IReceiver {
public:
	CReceiver1() { }
	~CReceiver1() { }
	void action();
};

class CReceiver2 : public IReceiver {
public:
	CReceiver2() { }
	~CReceiver2() { }
	void action();
};

class CReceiver3 : public IReceiver {
public:
	CReceiver3() { }
	~CReceiver3() { }
	void action();
};

class CCommand1 : public ICommand {
public:
	CCommand1(IReceiver* p_receiver) : ICommand(p_receiver) { }
	~CCommand1() { }
	void execute();
};

class CCommand2 : public ICommand {
public:
	CCommand2(IReceiver* p_receiver) : ICommand(p_receiver) { }
	~CCommand2() { }
	void execute();
};

class CCommand3 : public ICommand {
public:
	CCommand3(IReceiver* p_receiver) : ICommand(p_receiver) { }
	~CCommand3() { }
	void execute();
};

#endif