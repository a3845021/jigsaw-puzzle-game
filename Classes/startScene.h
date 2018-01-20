#ifndef __STARTSCENE_H__
#define __STARTSCENE_H__

#include "cocos2d.h"

USING_NS_CC;

using namespace std;
class startScene:public cocos2d::Layer
{
public:
	static cocos2d::Scene*createscene();
	virtual bool init();
	CREATE_FUNC(startScene);
public:
	void start(Ref*ref);//��ʼ��Ϸ��ť
	void exit(Ref*ref);//�˳���Ϸ��ť
	void setting(Ref*ref);//����
	void about(Ref*ref);//����
	Layer*aboutlayer;
	Sprite*aboutsprite;
	//Sprite*backBtn;
	MenuItemLabel*backmenu;
	
	void remov();
};

#endif