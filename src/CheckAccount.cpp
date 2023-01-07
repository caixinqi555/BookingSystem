#include "CheckAccount.h"

void CheckAccount::loop()
{
	system("cls");
	vector<ID*> list = data->m_IDVector;
	for (auto& i : list) {
		cout << "\tÕËºÅ£º " << i->IDnum
			<< "\tÐÕÃû£º " << i->name
			<< "\tÃÜÂë£º " << i->passwd
			<< "\tÕËºÅÀàÐÍ£º" << i->stringType()
			<< endl;
	}
	system("pause");
	exit();
}
