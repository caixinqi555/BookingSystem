#include "DataSystem.h"
//读取booking item、账号信息
DataSystem::DataSystem()
{
	//读取ID列表
	ifstream ifs1(ID_FILE, ios::in);
	ID* id = new ID;
	while (ifs1 >> id->IDnum >> id->name >> id->passwd >> id->type) {
		m_IDVector.push_back(id);
		id = new ID;
	}
	ifs1.close();

	//读取item
	ifstream ifs2(BOOKING_ITEM_FILE, ios::in);
	BookingItem* item = new BookingItem;
	while (ifs2 >> item->day >> item->interval >> item->userID >> item->userName >> item->roomID >> item->state){
		m_bookingItemVector.push_back(item);
		//cout << item->day << item->interval << item->userID << item->userName << item->roomID << item->state<<endl; 
		item = new BookingItem;
	}
	ifs2.close();
}
//
bool DataSystem::verifyID(long long ID, string passwd,int type)
{
	for (auto &i : m_IDVector) {
		if (i->IDnum == ID && i->passwd == passwd && i->type==type) {
			m_curID = i;
			return true;
		}
	}
	return false;
}

bool DataSystem::addBookingItem(int day, int interval, int roomID)
{
	BookingItem* item = new BookingItem(m_curID->name, m_curID->IDnum,  day,  interval,  roomID,  BookingItem::checking);
	m_bookingItemVector.push_back(item);
	return true;
}

int DataSystem::addID(string name, long long IDnum, string passwd, int type)
{
	ID* id = new ID(name, IDnum, passwd, type);
	m_IDVector.push_back(id);
	return 0;
}

int DataSystem::clearBooking()
{
	for (auto& i : m_bookingItemVector) {
		delete i;
	}
	m_bookingItemVector.clear();
	return 0;
}

const vector<BookingItem*>& DataSystem::getBookingItemVector()
{
	return m_bookingItemVector;
}

void DataSystem::save()
{
	ofstream ofs1(BOOKING_ITEM_FILE, ios::out|ios::trunc);
	for (auto& i : m_bookingItemVector) {
		ofs1<< i->day<<' '
			<< i->interval << ' '
			<< i->userID << ' '
			<< i->userName << ' '
			<< i->roomID << ' '
			<< i->state<< endl;
	}
	ofs1.close();

	ofstream ofs2(ID_FILE, ios::out | ios::trunc);
	for (auto& i : m_IDVector) {
		ofs2 << i->IDnum << ' '
			<< i->name << ' '
			<< i->passwd << ' '
			<< i->type <<endl;
	}
	ofs2.close();
}

