#include "Booking.h"

void Booking::loop()
{
	system("cls");
	cout << "avalable from Mon. to Fri. !\n";
	cout << "choose which day to book:\n";
	cout << "1.Mon\n";
	cout << "2.Tus\n";
	cout << "3.Weds\n";
	cout << "4.thr\n";
	cout << "5.Fri\n";
	int day;
	cin >> day;
	while (day > 5 || day < 1) {
		cout << "illegal input ,try again!\n";
		cin >> day;
	}

	cout << "choose which interval to book:\n";
	cout << "1.AM\n";
	cout << "2.PM\n";
	int interval;
	cin >> interval;
	while (interval > 2 || interval < 1) {
		cout << "illegal input ,try again!\n";
		cin >> interval;
	}

	cout << "choose which room to book:\n";
	int roomID;
	cin >> roomID;
	while (roomID > 3 || interval < 1) {
		cout << "illegal input ,try again!\n";
		cin >> roomID;
	}
	if (data->addBookingItem(day, interval, roomID)) {
		cout << "success!please wait for checking by your teacher\n";
	}
	else {
		cout << "oops!it's been booked by others\n";
	}
	system("pause");
	exit();
}
