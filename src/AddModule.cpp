#include "AddModule.h"

void AddModule::loop()
{
	system("cls");
	// 选择y要编辑的模块
	int idx = 0;
	for (auto& i : m_autoStates) {
		++idx;
		cout << idx << "."
			<< i->m_label
			<<endl;
	}
	idx = getOpr("\n请选择要编辑的模块：\n", 1, m_autoStates.size());
	AutoState* curMod = m_autoStates[idx-1];


	// 选择对当前模块添加的子模块
	system("cls");
	cout << "当前编辑的模块为：" << curMod->m_label<<endl<<endl;
	idx = 0;
	for (auto& i : m_autoStates) {
		++idx;
		cout << idx << "."
			<< i->m_label
			<< endl;
	}
	idx = getOpr("\n请选择要添加的子功能模块：\n", 1, m_autoStates.size());
	curMod->addSubState(m_autoStates[idx-1]);
	cout << "添加成功\n";
	system("pause");
	exit();
}
