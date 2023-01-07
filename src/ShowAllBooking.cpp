#include "ShowAllBooking.h"

void ShowAllBooking::loop()
{
	system("cls");
	const vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "checking"}, { 1,"cancelled" }, { 2,"denied" }, { 3,"OK" } };
	map<int, string>itv = { {1, "AM"}, { 2,"PM" } };
	for (auto& i : allItem) {
		cout << " date:" << i->day
			<< " interval:" << itv[i->interval]
			<< " ID:" << i->userID
			<< " name:" << i->userName
			<< " roomID:" << i->roomID
			<< " status:" << sta[i->state]
			<< endl;
	}
	system("pause");
	exit();
}
