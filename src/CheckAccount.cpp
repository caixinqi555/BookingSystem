#include "CheckAccount.h"

void CheckAccount::loop()
{
	system("cls");
	vector<ID*> list = data->m_IDVector;
	for (auto& i : list) {
		cout << "\taccount: " << i->IDnum
			<< "\tname: " << i->name
			<< "\tpasswd: " << i->passwd
			<< "\ttype:" << i->stringType()
			<< endl;
	}
	system("pause");
	exit();
}
