#pragma once
#include "UIobserver.h"
#include "AutoState.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class AutoUI:public AutoState
{
public:
	AutoUI(const string& label = "tag default");
	void loop();

	string m_operaTip;
	void setTip(const string& tip);
private:
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
