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
	cout << "�������ʺţ�\n";
	cin >> id;
	cout << "���������룺\n";
	cin >> passwd;
	if (!data->verifyID(id, passwd, m_type)) {
		cout << "��������Ƿ��������룿1 ��  /  2 ��\n";
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
