#ifndef COMMAND_H
#define COMMAND_H

#include <map>
using namespace std;

typedef unsigned int COMMAND_INDEX;


class IReceiver {
public:
	IReceiver() { }
	virtual ~IReceiver() { }
	// 子类实现的实现命令功能的接口
	virtual void action() = 0;
};

class ICommand {
public:
	ICommand(IReceiver* p_receiver) : m_receiver_ptr(p_receiver) { }
	virtual ~ICommand() { }
	// 子类实现的执行命令接口
	virtual void execute() = 0;
protected:
	// 命令类本身组合一个命令真正的执行类的实例
	IReceiver* m_receiver_ptr;
};

// 聚合命令的类，负责确定什么类型的命令用什么命令对象执行
class Invoker {
public:
	Invoker() { m_index2cmd.clear(); }
	virtual ~Invoker() { }

	// 增加一个命令对象
	void add_command(COMMAND_INDEX index, ICommand* p_command);
	// 分别发执行一个命令对象
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