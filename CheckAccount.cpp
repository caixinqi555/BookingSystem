#include "CheckAccount.h"

void CheckAccount::loop()
{
	system("cls");
	vector<ID*> list = data->m_IDVector;
	for (auto& i : list) {
		cout << "\t�˺ţ� " << i->IDnum
			<< "\t������ " << i->name
			<< "\t���룺 " << i->passwd
			<< "\t�˺����ͣ�" << i->stringType()
			<< endl;
	}
	system("pause");
	exit();
}
