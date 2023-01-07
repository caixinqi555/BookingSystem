#include "Login.h"


Login::Login(const string& label, int type):
	Process(label),
	m_type(type)
{
}
//jajajajajajajahhhhhhh
void Login::loop()
{
	system("cls");
	long long id; string passwd;
	cout << "plz input ID:\n";
	cin >> id;
	cout << "plz input password:\n";
	cin >> passwd;
	if (!data->verifyID(id, passwd, m_type)) {
		cout << "error passwd,try again? 1.yes / 2.no\n";
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
