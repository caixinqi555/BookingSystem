#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "ID.h"
#include "BookingItem.h"
#include "GlobalFile.h"
using namespace std;
class DataSystem
{
public:
	DataSystem();
	bool verifyID(long long ID, string passwd,int type);
	bool addBookingItem(int day, int interval, int roomID);
	int addID(string name, long long IDnum, string passwd, int type);
	int clearBooking();

	const vector<BookingItem*> & getBookingItemVector() ;
	ID *m_curID;
	void save();
	vector<BookingItem*> m_bookingItemVector;
	vector<ID*> m_IDVector;
};
