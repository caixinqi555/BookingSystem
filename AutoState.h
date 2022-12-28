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
	void exit() { m_iterFlag = false; }//回到父目录
	bool m_iterFlag = false;
	string m_label;
	static vector<AutoState*> m_autoStates;
protected:
};



// 类：AutoUI
// 成员函数
// 
// 
// public:
// AutoUI() 构造函数 
// play() 播放本UI,并允许调用子UI
// int addObserver(UIobserver* newOb) 添加新的观察者（使用方法：先继承UIobserver并重写call函数，再创建子类实例，并添加到本UI的观察者列表）
// AutoUI* createSubUI(const string &label, const int &priority)  创建子ui条目（条目文字标签，优先级）
// 
// 
// 
// private:
// 成员变量
// vector<AutoUI*> subUIvector 储存子界面的指针
// vector<UIobserver*> UIobsVector 存储观察者
// 
// 
// 
// 
// 类：UIobserver
// 成员函数
// virtual call(){}; 虚函数，可通过继承本类并重写该函数实现调用。
//
