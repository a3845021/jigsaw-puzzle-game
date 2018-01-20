#include "startScene.h"
#include"about.h"


USING_NS_CC;

cocos2d::Scene*aboutScene::createscence()
{
	auto scene=Scene::create();
	auto layer=aboutScene::create();
	scene->addChild(layer);
	return scene;
}

bool aboutScene::init()
{
	if(!Layer::init())
		return false;

	Size visibleSize=Director::getInstance()->getVisibleSize();
	auto spr_bg=Sprite::create("about.jpg");//��Ϸ�ı���
	spr_bg->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	this->addChild(spr_bg);

	auto dic=Dictionary::createWithContentsOfFile("fonts/text.xml");//��ȡxml(����ֱ����ʾ����)

	auto ba=(String*)(dic->objectForKey("back"));//���ѡ��ؿ���ť
	auto bac=Label::create(ba->getCString(),"fonts/fenshu.ttf",45);
	bac->setColor(Color3B(77,126,138));  
	auto bac1=MenuItemLabel::create(bac,CC_CALLBACK_1(aboutScene::backto,this));
	bac1->setPosition(Point(visibleSize.width/2,visibleSize.height/5));

	auto menu=Menu::create(bac1,NULL);
	menu->setPosition(Point::ZERO);  //λ��
	this->addChild(menu);

	return true; 
} 

void aboutScene::backto(Ref*ref)
{
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3,startScene::createscence()));	//�л����׽���
}
