#pragma once
#include<string>
using namespace std;
class ID
{
public:
	ID() {};
	ID(string name, long long IDnum, string passwd, int type) :
		name(name),
		IDnum(IDnum),
		passwd(passwd),
		type(type) {};

	string name;
	long long IDnum;
	string passwd;
	string stringType();
	int type;//0:admin; 1:student; 2:teacher;
	static constexpr int admin = 0;
	static constexpr int student = 1;
	static constexpr int teacher = 2;
};

