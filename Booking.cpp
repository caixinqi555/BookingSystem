#include "Booking.h"

void Booking::loop()
{
	system("cls");
	cout << "��������ʱ��Ϊ��һ������!\n";
	cout << "����������ԤԼ��ʱ�䣺\n";
	cout << "1����һ\n";
	cout << "2���ܶ�\n";
	cout << "3������\n";
	cout << "4������\n";
	cout << "5������\n";
	int day;
	cin >> day;
	while (day > 5 || day < 1) {
		cout << "���벻�Ϸ�������������\n";
		cin >> day;
	}

	cout << "��ѡ��ԤԼʱ�Σ�\n";
	cout << "1.����\n";
	cout << "2.����\n";
	int interval;
	cin >> interval;
	while (interval > 2 || interval < 1) {
		cout << "���벻�Ϸ�������������\n";
		cin >> interval;
	}

	cout << "��ѡ�������\n";
	int roomID;
	cin >> roomID;
	while (roomID > 3 || interval < 1) {
		cout << "���벻�Ϸ�������������\n";
		cin >> roomID;
	}
	if (data->addBookingItem(day, interval, roomID)) {
		cout << "ԤԼ�ɹ�����ȴ���ʦ���\n";
	}
	else {
		cout << "ԤԼʧ�ܣ���ʱ���ѱ�ԤԼ\n";
	}
	system("pause");
	exit();
}
