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
	AutoState *roleChoose = new AutoUI("选择身份菜单");
	Process::data = data;


	AutoState* stuLogin = new Login("学生",ID::student);
	AutoState* tchLogin = new Login("教师",ID::teacher);
	AutoState* adminLogin = new Login("管理员",ID::admin);
	roleChoose->addSubState(stuLogin);
	roleChoose->addSubState(tchLogin);
	roleChoose->addSubState(adminLogin);

	//初始化Process流程功能
	AutoState* showAllBooking = new ShowAllBooking("查看所有预约");
	AutoState* showMyBooking = new ShowMyBooking("查看我的预约");
	AutoState* cancelBooking = new CancelBooking("取消预约");
	AutoState* booking = new Booking("预约机房");
	AutoState* checkBooking = new CheckBooking("审核预约");
	AutoState* addAccount = new AddAccount("添加账户");
	AutoState* checkAccount = new CheckAccount("查看所有账户");
	AutoState* clearBooking = new ClearBooking("清空预约信息");
	AutoState* addModule = new AddModule("添加功能模块");

	//登录流程连入学生菜单，为学生菜单添加功能
	AutoState* stuMenu = new AutoUI("学生菜单");
	stuLogin->addSubState(stuMenu);
	stuMenu->addSubState(booking);
	stuMenu->addSubState(showAllBooking);
	stuMenu->addSubState(showMyBooking);
	stuMenu->addSubState(cancelBooking);

	//登录流程连入教师菜单，为教师菜单添加功能
	AutoState* tchMenu = new AutoUI("教师菜单");
	tchLogin->addSubState(tchMenu);
	tchMenu->addSubState(booking);
	tchMenu->addSubState(showMyBooking);
	tchMenu->addSubState(showAllBooking);
	tchMenu->addSubState(cancelBooking);
	tchMenu->addSubState(checkBooking);


	//登录流程连入管理员菜单，为管理员菜单添加功能
	AutoState* adminMenu = new AutoUI("管理员菜单");
	adminLogin->addSubState(adminMenu);
	adminMenu->addSubState(addAccount);
	adminMenu->addSubState(checkAccount);
	adminMenu->addSubState(clearBooking);
	adminMenu->addSubState(addModule);

	
	//执行程序
	roleChoose->play();
	data->save();
}

