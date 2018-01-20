#include "startScene.h"
#include "chooseScene.h"
#include"about.h"


USING_NS_CC;

cocos2d::Scene*startScene::createscence()
{
	auto scene=Scene::create();
	auto layer=startScene::create();
	scene->addChild(layer);
	return scene;
}

bool startScene::init()
{
	if(!Layer::init())
		return false;

	Size visibleSize=Director::getInstance()->getVisibleSize();
	auto spr_bg=Sprite::create("start.jpg");//��Ϸ�ı���
	spr_bg->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	this->addChild(spr_bg);

	auto dic=Dictionary::createWithContentsOfFile("fonts/text.xml");//��ȡxml(����ֱ����ʾ����)

	auto pl=(String*)(dic->objectForKey("start"));//���ѡ��ؿ���ť
	auto pla=Label::create(pl->getCString(),"fonts/fenshu.ttf",45);
	pla->setColor(Color3B(109,133,90));  
	auto start_menu=MenuItemLabel::create(pla,CC_CALLBACK_1(startScene::start,this));
	start_menu->setPosition(Point(visibleSize.width/2,visibleSize.height/2)); 

	auto abou=(String*)(dic->objectForKey("about"));//��ӹ��ڰ�ť
	auto ab=Label::create(abou->getCString(),"fonts/fenshu.ttf",45);
	ab->setColor(Color3B(109,133,90));  
	auto abo=MenuItemLabel::create(ab,CC_CALLBACK_1(startScene::about,this));
	abo->setPosition(Point(visibleSize.width/2,visibleSize.height*3/8)); 

	auto sett=(String*)(dic->objectForKey("setting"));//������ð�ť
	auto se=Label::create(sett->getCString(),"fonts/fenshu.ttf",45);
	se->setColor(Color3B(109,133,90));  
	auto setti=MenuItemLabel::create(se,CC_CALLBACK_1(startScene::setting,this));
	setti->setPosition(Point(visibleSize.width/2,visibleSize.height/4)); 

	auto ex=(String*)(dic->objectForKey("exit"));//���˳���Ϸ��ť
	auto exi=Label::create(ex->getCString(),"fonts/fenshu.ttf",45);
	exi->setColor(Color3B(109,133,90));  
	auto exi2=MenuItemLabel::create(exi,CC_CALLBACK_1(startScene::exit,this));
	exi2->setPosition(Point(visibleSize.width/2,visibleSize.height/8)); 

	auto menu=Menu::create(start_menu,exi2,abo,setti,NULL);
	menu->setPosition(Point::ZERO);  //λ��
	this->addChild(menu);

	return true; 
} 

void startScene::start(Ref*ref)
{
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3,chooseScene::create()));	//�л���ѡ��ؿ�����
}

void startScene::exit(Ref*ref)
{
	Director::getInstance()->end();
}

void startScene::about(Ref*ref)
{
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3,aboutScene::createscence()));	//�л���ѡ��ؿ�����
 }

void startScene::setting(Ref*ref)
{

 }