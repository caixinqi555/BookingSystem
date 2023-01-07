#include "CheckBooking.h"

void CheckBooking::loop()
{
	vector<BookingItem*> allItem = data->getBookingItemVector();
	map<int, string>sta = { {0, "审核中"}, { 1,"已取消" }, { 2,"未通过" }, { 3,"预约成功" } };
	map<int, string>itv = { {1, "上午"}, { 2,"下午" } };
	bool checkingFlag = true;
	while (1) {
		system("cls");
		cout << "待审核的预约有：\n";
		vector<BookingItem*>list;
		int idx = 1;
		for (int i = 0; i < allItem.size(); i++) {
			BookingItem* item = allItem[i];
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
			break;
		}
		idx = getOpr("请选择要审核的记录(输入0退出审核)：\n", 0, list.size());
		if (idx == 0) {
			break;
		}
		int check = getOpr("请选择是否批准：\n1.批准\n2.不批准\n", 1, 2);
		if (check == 1) {
			list[idx - 1]->state = BookingItem::checked;
		}
		else {
			list[idx - 1]->state = BookingItem::denied;
		}
	}
	system("pause");
	exit();
}
