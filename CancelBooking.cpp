#include "CancelBooking.h"
void CancelBooking::loop()
{
	system("cls");
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
	vector<BookingItem*>list;

	cout << "当前可取消的预约有：\n";
	int j = 0;
	for (int i = 0; i < allItem.size(); i++) {
		BookingItem* item = allItem[i];
		if (item->userID == data->m_curID->IDnum && (item->state == 0 || item->state == 3)) {
			++j;
			cout << j << '.'
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
	exit();
}
