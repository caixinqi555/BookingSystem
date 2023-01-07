#include "AutoState.h"

AutoState::AutoState(const string& label):
	m_observers(vector<UIobserver*>()),
	m_subStates(vector<AutoState*>()),
	m_label(label)
{
	m_autoStates.push_back(this);
}

vector<AutoState*> AutoState::m_autoStates;

void AutoState::play()
{
	m_iterFlag = true;
	//通知所有观察者
	for (auto& i : m_observers) {
		if (!m_iterFlag) return;//出口1
		i->call();
	}
	//进入主循环
	while (m_iterFlag) {
		loop();
	}
}

void AutoState::addSubState(AutoState* subState)
{
	m_subStates.push_back(subState);
}

int AutoState::addObserver(UIobserver* newOb)
{
	m_observers.push_back(newOb);
	return 0;
}

AutoState* AutoState::getSubState(int idx)
{
	if (idx < 0 || idx >= m_subStates.size()) {
		return nullptr;
	}
	return m_subStates[idx];
}

