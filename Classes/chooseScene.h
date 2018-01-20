
#ifndef __CHOOSESCENE__
#define __CHOOSESCENE__

#include <iostream>
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class chooseScene : public cocos2d::Layer
{
public:  
	static cocos2d::Scene*createscene();
    virtual bool init();  
	CREATE_FUNC(chooseScene);

	bool onTouchBegan(Touch *touch, Event  *event);
	void onTouchEnded(Touch *touch, Event  *event);
	void goToCurrNode();
	Size size();
	void donghua();

	Sprite* sprite1;
	int page_node_; 
	int cur_page_node_; //��ǰҳ��
	Point start;//���ʱΪֹ
	Point end; //̧��ʱΪֹ
	float size_x;//ҳ���
	float size_y;//��
	Layer* layer;
 	Label* btn_label;
	Label* bac;
	//������Ϸ�����ж�
 	bool ismenu;
 	bool isendmenu;
	Rect rect;
	Size menusize;
	//�˳����˵������ж�
	Size menuend;
	Rect endrect;
	bool ismenuwithend;
	bool isendmenuwithend;
	

}; 
#endif
