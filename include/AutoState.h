#pragma once
#include "UIobserver.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class AutoState
{
public:
	AutoState(const string& label="default tag");
	void play();
	virtual void loop() { system("pause"); }
	void addSubState(AutoState *subState);
	int addObserver(UIobserver* newOb);;
	AutoState* getSubState(int idx);

	vector<AutoState*> m_subStates;
	vector<UIobserver*>  m_observers;
	void exit() { m_iterFlag = false; }//�ص���Ŀ¼
	bool m_iterFlag = false;
	string m_label;
	static vector<AutoState*> m_autoStates;
protected:
};



// �ࣺAutoUI
// ��Ա����
// 
// 
// public:
// AutoUI() ���캯�� 
// play() ���ű�UI,�����������UI
// int addObserver(UIobserver* newOb) ����µĹ۲��ߣ�ʹ�÷������ȼ̳�UIobserver����дcall�������ٴ�������ʵ��������ӵ���UI�Ĺ۲����б�
// AutoUI* createSubUI(const string &label, const int &priority)  ������ui��Ŀ����Ŀ���ֱ�ǩ�����ȼ���
// 
// 
// 
// private:
// ��Ա����
// vector<AutoUI*> subUIvector �����ӽ����ָ��
// vector<UIobserver*> UIobsVector �洢�۲���
// 
// 
// 
// 
// �ࣺUIobserver
// ��Ա����
// virtual call(){}; �麯������ͨ���̳б��ಢ��д�ú���ʵ�ֵ��á�
//
