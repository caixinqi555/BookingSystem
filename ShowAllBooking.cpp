#include "ShowAllBooking.h"

void ShowAllBooking::loop()
{
	system("cls");
	const vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
	for (auto& i : allItem) {
		cout << " 日期：" << i->day
			<< " 时间段：" << itv[i->interval]
			<< " 编号：" << i->userID
			<< " 姓名：" << i->userName
			<< " 机房：" << i->roomID
			<< " 状态：" << sta[i->state]
			<< endl;
	}
	system("pause");
	exit();
}
