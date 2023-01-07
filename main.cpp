#include<iostream>
#include <string>
#include "UI.h"
#include "AutoUI.h"
#include "Process.h"
#include "Login.h"
#include "Booking.h"
#include "ShowAllBooking.h"
#include "ShowMyBooking.h"
#include "CancelBooking.h"
#include "CheckBooking.h"
#include "AddAccount.h"
#include "CheckAccount.h"
#include "ClearBooking.h"
#include "AddModule.h"
using namespace std;
int main() {
	DataSystem *data = new DataSystem;
	AutoState *roleChoose = new AutoUI("ѡ����ݲ˵�");
	Process::data = data;


	AutoState* stuLogin = new Login("ѧ��",ID::student);
	AutoState* tchLogin = new Login("��ʦ",ID::teacher);
	AutoState* adminLogin = new Login("����Ա",ID::admin);
	roleChoose->addSubState(stuLogin);
	roleChoose->addSubState(tchLogin);
	roleChoose->addSubState(adminLogin);

	//��ʼ��Process���̹���
	AutoState* showAllBooking = new ShowAllBooking("�鿴����ԤԼ");
	AutoState* showMyBooking = new ShowMyBooking("�鿴�ҵ�ԤԼ");
	AutoState* cancelBooking = new CancelBooking("ȡ��ԤԼ");
	AutoState* booking = new Booking("ԤԼ����");
	AutoState* checkBooking = new CheckBooking("���ԤԼ");
	AutoState* addAccount = new AddAccount("����˻�");
	AutoState* checkAccount = new CheckAccount("�鿴�����˻�");
	AutoState* clearBooking = new ClearBooking("���ԤԼ��Ϣ");
	AutoState* addModule = new AddModule("��ӹ���ģ��");

	//��¼��������ѧ���˵���Ϊѧ���˵���ӹ���
	AutoState* stuMenu = new AutoUI("ѧ���˵�");
	stuLogin->addSubState(stuMenu);
	stuMenu->addSubState(booking);
	stuMenu->addSubState(showAllBooking);
	stuMenu->addSubState(showMyBooking);
	stuMenu->addSubState(cancelBooking);

	//��¼���������ʦ�˵���Ϊ��ʦ�˵���ӹ���
	AutoState* tchMenu = new AutoUI("��ʦ�˵�");
	tchLogin->addSubState(tchMenu);
	tchMenu->addSubState(booking);
	tchMenu->addSubState(showMyBooking);
	tchMenu->addSubState(showAllBooking);
	tchMenu->addSubState(cancelBooking);
	tchMenu->addSubState(checkBooking);


	//��¼�����������Ա�˵���Ϊ����Ա�˵���ӹ���
	AutoState* adminMenu = new AutoUI("����Ա�˵�");
	adminLogin->addSubState(adminMenu);
	adminMenu->addSubState(addAccount);
	adminMenu->addSubState(checkAccount);
	adminMenu->addSubState(clearBooking);
	adminMenu->addSubState(addModule);

	
	//ִ�г���
	roleChoose->play();
	data->save();
}

