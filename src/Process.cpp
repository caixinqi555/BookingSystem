#include "Process.h"
DataSystem* Process::data = nullptr;

long long Process::getOpr(const string& info, long long min, long long max)
{
	cout << info;
	int idx;
	cin >> idx;
	while (idx<min || idx>max) {
		cout << "illegal input,try again!\n";
		cin >> idx;
	}
	return idx;
}
