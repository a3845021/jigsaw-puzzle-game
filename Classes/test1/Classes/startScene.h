#ifndef __STARTSCENE_H__
#define __STARTSCENE_H__

#include "cocos2d.h"

USING_NS_CC;

using namespace std;
class startScene:public cocos2d::Layer
{
public:
	static cocos2d::Scene*createscence();
	virtual bool init();
	CREATE_FUNC(startScene);
public:
	void start(Ref*ref);//��ʼ��Ϸ��ť
	void exit(Ref*ref);//�˳���Ϸ��ť
	void setting(Ref*ref);//�˳���Ϸ��ť
	void about(Ref*ref);//����
	Layer*aboutlayer;
	MenuItemLabel*backmenu;
};

#endif