#include "AddAccount.h"

void AddAccount::loop()
{
	system("cls");
	int choice = getOpr("请输入添加账号类型：\n1.添加老师\n2.添加学生\n3.添加管理员\n", 1, 3), type = 0;
	long long IDnum = 0;
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
	data->addID(name, IDnum, passwd, type);
	cout << "添加成功\n";
	system("pause");
	exit();
}
