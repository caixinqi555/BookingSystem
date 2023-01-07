#include "Booking.h"

void Booking::loop()
{
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

	cout << "请选择预约时段：\n";
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
	exit();
}
