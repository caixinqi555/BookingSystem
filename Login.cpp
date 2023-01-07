#include "Login.h"


Login::Login(const string& label, int type):
	Process(label),
	m_type(type)
{
}
//jajajajajajajajajajaja
void Login::loop()
{
	system("cls");
	long long id; string passwd;
	cout << "ÇëÊäÈëÕÊºÅ£º\n";
	cin >> id;
	cout << "ÇëÊäÈëÃÜÂë£º\n";
	cin >> passwd;
	if (!data->verifyID(id, passwd, m_type)) {
		cout << "ÃÜÂë´íÎó£¬ÊÇ·ñÖØÐÂÊäÈë£¿1 ÊÇ  /  2 ·ñ\n";
		int idx = 0;
		cin >> idx;
		if (idx == 1) {
			return;
		}
		else {
			exit();
		}
	}
	else {
		if (m_subStates.size() > 0) {
			m_subStates[0]->play();
		}
		exit();
	}

}
