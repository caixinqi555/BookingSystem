#include "AddModule.h"

void AddModule::loop()
{
	system("cls");
	// ѡ��yҪ�༭��ģ��
	int idx = 0;
	for (auto& i : m_autoStates) {
		++idx;
		cout << idx << "."
			<< i->m_label
			<<endl;
	}
	idx = getOpr("\n��ѡ��Ҫ�༭��ģ�飺\n", 1, m_autoStates.size());
	AutoState* curMod = m_autoStates[idx-1];


	// ѡ��Ե�ǰģ����ӵ���ģ��
	system("cls");
	cout << "��ǰ�༭��ģ��Ϊ��" << curMod->m_label<<endl<<endl;
	idx = 0;
	for (auto& i : m_autoStates) {
		++idx;
		cout << idx << "."
			<< i->m_label
			<< endl;
	}
	idx = getOpr("\n��ѡ��Ҫ��ӵ��ӹ���ģ�飺\n", 1, m_autoStates.size());
	curMod->addSubState(m_autoStates[idx-1]);
	cout << "��ӳɹ�\n";
	system("pause");
	exit();
}
