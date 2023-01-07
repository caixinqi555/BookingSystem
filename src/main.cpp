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
	AutoState *roleChoose = new AutoUI("choose your role");
	Process::data = data;


	AutoState* stuLogin = new Login("student",ID::student);
	AutoState* tchLogin = new Login("teacher",ID::teacher);
	AutoState* adminLogin = new Login("admin",ID::admin);
	roleChoose->addSubState(stuLogin);
	roleChoose->addSubState(tchLogin);
	roleChoose->addSubState(adminLogin);

	//初始化Process流程功能
	AutoState* showAllBooking = new ShowAllBooking("showAllBooking");
	AutoState* showMyBooking = new ShowMyBooking("showMyBooking");
	AutoState* cancelBooking = new CancelBooking("cancelBooking");
	AutoState* booking = new Booking("booking");
	AutoState* checkBooking = new CheckBooking("checkBooking");
	AutoState* addAccount = new AddAccount("addAccount");
	AutoState* checkAccount = new CheckAccount("checkAllAccount");
	AutoState* clearBooking = new ClearBooking("clearBooking");
	AutoState* addModule = new AddModule("addModule");

	//登录流程连入学生菜单，为学生菜单添加功能
	AutoState* stuMenu = new AutoUI("stuMenu");
	stuLogin->addSubState(stuMenu);
	stuMenu->addSubState(booking);
	stuMenu->addSubState(showAllBooking);
	stuMenu->addSubState(showMyBooking);
	stuMenu->addSubState(cancelBooking);

	//登录流程连入教师菜单，为教师菜单添加功能
	AutoState* tchMenu = new AutoUI("tchMenu");
	tchLogin->addSubState(tchMenu);
	tchMenu->addSubState(booking);
	tchMenu->addSubState(showMyBooking);
	tchMenu->addSubState(showAllBooking);
	tchMenu->addSubState(cancelBooking);
	tchMenu->addSubState(checkBooking);


	//登录流程连入管理员菜单，为管理员菜单添加功能
	AutoState* adminMenu = new AutoUI("adminMenu");
	adminLogin->addSubState(adminMenu);
	adminMenu->addSubState(addAccount);
	adminMenu->addSubState(checkAccount);
	adminMenu->addSubState(clearBooking);
	adminMenu->addSubState(addModule);

	
	//执行程序
	roleChoose->play();
	data->save();
}

