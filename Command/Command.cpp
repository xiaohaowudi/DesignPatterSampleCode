#include "Command.h"
#include <iostream>
using namespace std;

void CReceiver1::action() {
	cout << "CReceiver1::action" << endl;
}

void CReceiver2::action() {
	cout << "CReceiver2::action" << endl;
}

void CReceiver3::action() {
	cout << "CReceiver3::action" << endl;
}

void CCommand1::execute() {
	cout << "CCommand1::execute" << endl;
	m_receiver_ptr->action();
}

void CCommand2::execute() {
	cout << "CCommand2::execute" << endl;
	m_receiver_ptr->action();
}

void CCommand3::execute() {
	cout << "CCommand2::execute" << endl;
	m_receiver_ptr->action();
}

void Invoker::add_command(COMMAND_INDEX index, ICommand* p_command) {
	if (m_index2cmd.find(index) == m_index2cmd.end()) {
		m_index2cmd[index] = p_command;
	}
}

void Invoker::dispatch_run_command(COMMAND_INDEX index) {
	ICommand* p_command = NULL;
	if (m_index2cmd.find(index) != m_index2cmd.end()) {
		p_command = m_index2cmd[index];
		if (p_command) {
			p_command->execute();
		}
	}
	else {
		cout << "command index error" << endl;
	}
}