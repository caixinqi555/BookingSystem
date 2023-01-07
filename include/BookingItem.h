#pragma once
#include <string>
#include <map>
using namespace std;
class BookingItem {
public:

	BookingItem(){}
	BookingItem(string uName, long long uID, int day, int interval, int roomID, int state) :
		userName(uName), 
		userID(uID), 
		day(day), 
		interval(interval), 
		roomID(roomID), 
		state(state) {}

	string userName="";
	long long userID=0;
	int day=0;//日期
	int interval=0;//时间段
	int roomID=0;//机房号
	int state=0;//0：审核中；1：已取消预约；2：审核未通过；3：预约成功

	//state状态标识
	static constexpr int checking = 0;
	static constexpr int cancelled = 1;
	static constexpr int denied = 2;
	static constexpr int checked = 3;
	
};


