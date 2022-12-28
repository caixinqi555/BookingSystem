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
	int day=0;//����
	int interval=0;//ʱ���
	int roomID=0;//������
	int state=0;//0������У�1����ȡ��ԤԼ��2�����δͨ����3��ԤԼ�ɹ�

	//state״̬��ʶ
	static constexpr int checking = 0;
	static constexpr int cancelled = 1;
	static constexpr int denied = 2;
	static constexpr int checked = 3;
	
};


