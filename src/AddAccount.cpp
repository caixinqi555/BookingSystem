#include "AddAccount.h"

void AddAccount::loop()
{
	system("cls");
	int choice = getOpr("����������˺����ͣ�\n1.�����ʦ\n2.���ѧ��\n3.��ӹ���Ա\n", 1, 3), type = 0;
	long long IDnum = 0;
	if (choice == 1) {
		IDnum = getOpr("�����빤�ţ�\n", 0, 9999999999);
		type = ID::teacher;
	}
	else if (choice == 2) {
		IDnum = getOpr("������ѧ�ţ�\n", 0, 9999999999);
		type = ID::student;
	}
	else if (choice == 3) {
		IDnum = getOpr("�����빤�ţ�\n", 0, 9999999999);
		type = ID::admin;
	}
	string name;
	cout << "������������\n";
	cin >> name;
	string passwd;
	cout << "���������룺\n";
	cin >> passwd;
	data->addID(name, IDnum, passwd, type);
	cout << "��ӳɹ�\n";
	system("pause");
	exit();
}
