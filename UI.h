#pragma once
#include <iostream>
#include <vector>
#include "DataSystem.h"
using namespace std;

class UI
{
public:
	UI(DataSystem* data);
	void login();
	void studentMenu();
	void teacherMenu();
	void managerMenu();
	void booking();
	void showMyBooking();
	void showAllBooking();
	void cancelBooking();
	void checkBooking();
	void addAccount();
	void checkAccount();
	void checkRooms();
	void clearBooking();
	long long getOpr(const string& info, long long min, long long max);
private:
	DataSystem* data;
	bool loginFlag = false;
};

