#include "AutoUI.h"

AutoUI::AutoUI(const string& label):
	AutoState(label)
{
}

void AutoUI::loop()
{	

	system("cls");
	cout << "\n===========================================================================================" << endl;
	cout << "\t\t\t\t\t\n";
	for (int i = 0; i < m_subStates.size(); i++) {
		cout << "\t" << i + 1 << "." << m_subStates[i]->m_label <<"\t\t\n\n";
	}
	cout << "\t0.返回\n\n";
	cout << "===========================================================================================" << endl;

	cout << m_operaTip<<"\n";
	int idx;
	cin >> idx;
	while (idx<0 || idx>m_subStates.size()) {
		cout << "输入不合法，请重新输入\n";
		cin >> idx;
	}
	//处理输入
	if (idx != 0) {
		m_subStates[idx - 1]->play();
	}
	else {
		exit();
	}
	system("cls");
}

void AutoUI::setTip(const string& tip)
{
	m_operaTip = tip;
}