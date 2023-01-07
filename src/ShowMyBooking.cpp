#include "ShowMyBooking.h"

void ShowMyBooking::loop()
{
	system("cls");
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
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
	exit();
}
