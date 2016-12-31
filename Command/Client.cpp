#include "Command.h"

int main(void) {
	IReceiver *p_receiver1 = new CReceiver1();
	IReceiver *p_receiver2 = new CReceiver2();
	IReceiver *p_receiver3 = new CReceiver3();
	ICommand *p_command1 = new CCommand1(p_receiver1);
	ICommand *p_command2 = new CCommand2(p_receiver2);
	ICommand *p_command3 = new CCommand3(p_receiver3);
	
	Invoker invoker;
	invoker.add_command(1, p_command1);
	invoker.add_command(2, p_command2);
	invoker.add_command(3, p_command3);

	/* 
		ǰ�涼�ǳ�ʼ�����֣���������ִ�������ʱ��
		ʹ�����ǲ���֪�������������Ǹ���ʵ�ֵ�
		����Ҳ��֪����˭���õ��Լ������߽����˽���
	*/
	invoker.dispatch_run_command(1);
	invoker.dispatch_run_command(2);
	invoker.dispatch_run_command(3);
	invoker.dispatch_run_command(4);

	delete p_command1;
	delete p_command2;
	delete p_command3;
	delete p_receiver1;
	delete p_receiver2;
	delete p_receiver3;

	return 0;
}