#include "UI.h"
UI::UI(DataSystem *d):data(d){
}

void  UI::login() {
	int type;
	long long id;
	string passwd;
	system("cls");
	cout << "\t\t ------------------------- \n" ;
	cout << "\t\t|       请选择登录身份：  | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        1.学生代表       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        2.老    师       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        3.管 理 员       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        4.退    出       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t ------------------------- \n";
	cin >> type;



	switch (type) {
		//学生
	case 1:
		system("cls");
		cout << "请输入帐号：\n";
		cin >> id;
		cout << "请输入密码：\n";
		cin >> passwd;
		if (!data->verifyID(id, passwd,ID::student)) {
			cout << "密码错误\n";
			system("pause");
			return;
		}
		studentMenu();
		break;
		//老师
	case 2:
		system("cls");
		cout << "请输入帐号：\n";
		cin >> id;
		cout << "请输入密码：\n";
		cin >> passwd;
		if (!data->verifyID(id, passwd, ID::teacher)) {
			cout << "密码错误\n";
			system("pause");
			return;
		}
		teacherMenu();
		break;
		//管理员
	case 3:
		system("cls");
		cout << "请输入帐号：\n";
		cin >> id;
		cout << "请输入密码：\n";
		cin >> passwd;
		if (!data->verifyID(id, passwd, ID::admin)) {
			cout << "密码错误\n";
			system("pause");
			return;
		}
		managerMenu();
		break;
		//退出
	case 4:
		data->save();
		system("cls");
		cout << "欢迎下次使用！\n";
		system("pause");
		exit(0);
		break;
		//输入不合法
	default:
		cout << "输入不合法，请重新输入!\n";
		system("pause");
		return;
		break;
	}

}
void UI::studentMenu() {
	loginFlag = true;
	while (1) {
		system("cls");
		cout << "\t\t ------------------------- \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        1.预约机房       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        2.查看我的预约   | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        3.查看所有预约   | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        4.取消预约       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        0.注销登录       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t ------------------------- \n";
		int type;
		cin >> type;

		switch (type) {
			//登陆预约
		case 1:
			booking();
			break;
			//查看我的预约
		case 2:
			showMyBooking();
			break;
			//查看所有预约
		case 3:
			showAllBooking();
			break;
			//取消预约
		case 4:
			cancelBooking();
			break;
			//注销登录
		case 0:
			loginFlag = false;
			break;
		}
		if(loginFlag==false)break;
	}

}

void UI::teacherMenu() {
	loginFlag = true;
while(1){
	system("cls");
	cout << "\t\t ------------------------- \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        1.查看所有预约   | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        2.审核预约       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t|        0.注销登录       | \n";
	cout << "\t\t|                         | \n";
	cout << "\t\t ------------------------- \n";
	int type;
	cin >> type;

	switch (type) {
		//查看所有预约
	case 1:
		showAllBooking();
		break;
		//审核预约
	case 2:
		checkBooking();
		break;
		//注销登录
	case 0:
		loginFlag = false;
		break;
	}

		if (loginFlag == false)break;
	}	
}
void UI::managerMenu() {
	loginFlag = true;
	while (1) {
		system("cls");
		cout << "\t\t ------------------------- \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        1.添加账号       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        2.查看账号       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        3.查看机房       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        4.清空预约       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t|        0.注销登录       | \n";
		cout << "\t\t|                         | \n";
		cout << "\t\t ------------------------- \n";
		int type;
		cin >> type;

		switch (type) {
			//添加账号
		case 1:
			addAccount();
			break;
			//查看账号
		case 2:
			checkAccount();
			break;
			//查看机房
		case 3:
			checkRooms();
			break;
			//清空预约
		case 4:
			clearBooking();
			break;
			//注销登录
		case 0:
			loginFlag = false;
			break;
		}
		if (loginFlag == false)break;
	}
}
void UI::booking() {
	system("cls");
	cout << "机房开放时间为周一至周五!\n";
	cout << "请输入申请预约的时间：\n";
	cout << "1、周一\n";
	cout << "2、周二\n";
	cout << "3、周三\n";
	cout << "4、周四\n";
	cout << "5、周五\n";
	int day;
	cin >> day;
	while (day > 5 || day < 1) {
		cout << "输入不合法，请重新输入\n";
		cin >> day;
	}

	cout<< "请选择预约时段：\n";
	cout << "1.上午\n";
	cout << "2.下午\n";
	int interval;
	cin >> interval;
	while (interval > 2 || interval < 1) {
		cout << "输入不合法，请重新输入\n";
		cin >> interval;
	}

	cout << "请选择机房：\n";
	int roomID;
	cin >> roomID;
	while (roomID > 3 || interval < 1) {
		cout << "输入不合法，请重新输入\n";
		cin >> roomID;
	}
	if (data->addBookingItem(day, interval, roomID)) {
		cout << "预约成功，请等待老师审核\n";
	}
	else {
		cout << "预约失败，该时段已被预约\n";
	}
	system("pause");
	return;
}

void UI::showAllBooking() {
	const vector<BookingItem*> allItem=data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
	for (auto& i : allItem) {
		cout << " 日期："<<i->day
			<< " 时间段：" << itv[i->interval]
			<< " 编号：" << i->userID
			<< " 姓名：" << i->userName
			<< " 机房：" << i->roomID
			<< " 状态：" << sta[i->state]
			<<endl;
	}
	system("pause");
}
void UI::showMyBooking() {
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta={ {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv={ {1, "上午"}, { 2,"下午" }};
	for (auto& i : allItem) {
		if (i->userID == data->m_curID->IDnum) {
			cout << " 日期：" << i->day
				<< " 时间段：" << itv[i->interval]
				<< " 编号：" << i->userID
				<< " 机房：" << i->roomID
				<< " 状态：" << sta[i->state]
				<< endl;
		}
	}
	system("pause");
}
void UI::cancelBooking() {
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
	vector<BookingItem*>list;

	cout << "当前可取消的预约有：\n";
	for (int i = 0; i < allItem.size();i++) {
		BookingItem* item=allItem[i];
		if (item->userID == data->m_curID->IDnum &&(item->state==0 || item->state == 3)) {
			cout <<i+1<<'.'
				<< " 日期：" << item->day
				<< " 时间段：" << itv[item->interval]
				<< " 编号：" << item->userID
				<< " 机房：" << item->roomID
				<< " 状态：" << sta[item->state]
				<< endl;
			list.push_back(item);
		}
	}

	int idx = getOpr("请选择要取消的记录：\n", 1, list.size());
	list[idx - 1]->state = BookingItem::cancelled;
	system("pause");
}

void UI::checkBooking() {
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
	bool checkingFlag = true;
	while (checkingFlag) {
		cout << "待审核的预约有：\n";
		vector<BookingItem*>list;
		for (int i = 0; i < allItem.size(); i++) {
			BookingItem* item = allItem[i];
			int idx = 1;
			if (item->state == BookingItem::checking) {
				cout << idx << '.'
					<< " 日期：" << item->day
					<< " 时间段：" << itv[item->interval]
					<< " 编号：" << item->userID
					<< " 姓名：" << item->userName
					<< " 机房：" << item->roomID
					<< " 状态：" << sta[item->state]
					<< endl;
				list.push_back(item);
				idx++;
			}
		}
		if (list.size() == 0) {
			cout << "当前没有待审核的申请\n";
			checkingFlag = false;
			break;
		}
		int idx = getOpr("请选择要审核的记录(输入0退出审核)：\n", 1, list.size());
		if (idx == 0) {
			checkingFlag = false;
			break;
		}
		int check = getOpr("请选择是否批准：\n1.批准\n2.不批准\n", 1, 2);
		if (check == 1) {
			list[idx - 1]->state = BookingItem::checked;
		}
		else {
			list[idx - 1]->state = BookingItem::denied;
		}
		system("pause");
	}
}
void UI::addAccount() {
	int choice=getOpr("请输入添加账号类型：\n1.添加老师\n2.添加学生\n3.添加管理员\n",1,3),type=0;
	long long IDnum=0;
	if (choice == 1) {
		IDnum = getOpr("请输入工号：\n", 0, 9999999999);
		type = ID::teacher;
	}
	else if (choice == 2) {
		IDnum = getOpr("请输入学号：\n", 0, 9999999999);
		type = ID::student;
	}
	else if (choice == 3) {
		IDnum = getOpr("请输入工号：\n", 0, 9999999999);
		type = ID::admin;
	}
	string name;
	cout << "请输入姓名：\n";
	cin >> name;
	string passwd;
	cout << "请输入密码：\n";
	cin >> passwd;
	data->addID(name,IDnum, passwd, type);
	cout << "添加成功\n";
	system("pause");
}
void UI::checkAccount() {
	vector<ID*> list = data->m_IDVector;
	for (auto& i : list) {
		cout << "\t账号： " << i->IDnum
			<< "\t姓名： " << i->name
			<< "\t密码： " << i->passwd 
			<<"\t账号类型：" <<i->stringType()
			<< endl;
	}
	system("pause");
}
void UI::checkRooms() {

}
void UI::clearBooking() {
	data->clearBooking();
	cout << "已清空预约记录\n";
	system("pause");
}

long long UI::getOpr(const string& info, long long min, long long max)
{
	cout << info;
	int idx;
	cin >> idx;
	while (idx<min || idx>max) {
		cout << "输入不合法，请重新输入\n";
		cin >> idx;
	}
	return idx;
}
