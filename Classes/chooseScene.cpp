#include "chooseScene.h"//�����ͷ�ļ�
#include "startScene.h"
#include "gamelayer.h"
USING_NS_CC;


cocos2d::Scene*chooseScene::createscene()
{
	auto scene=Scene::create();
	auto layer=chooseScene::create();
	scene->addChild(layer);
	return scene;
}

bool chooseScene::init()
{
    if (!Layer::init())
	{
		return false;
	}
    
	
	//��ӿɻ�������

	page_node_ = 0;
	cur_page_node_ = 0;

	for(int page=1; page<=6; page++)
	{
		layer = Layer::create();
		
		//����
		auto sprite =Sprite::create("choose.jpg");
		sprite->setPosition(Point(size().width / 2, size().height / 2 ));
		layer->addChild(sprite);


		auto animation = Animation::create();
		for (int i = 1; i <= 2; ++i)
		{
			auto spr_name = String::createWithFormat("Card%d_%d.png", page,i);
			animation->addSpriteFrameWithFile(spr_name->getCString());
		}

		animation->setDelayPerUnit(0.2f);
		animation->setLoops(-1);

		auto spr_name = String::createWithFormat("Card%d_%d.png", page, 1);
		auto card_sprite = Sprite::create(spr_name->getCString());
		card_sprite->setPosition(size().width / 2, 2*size().height / 3);
		card_sprite->setScale(2);
		layer->addChild(card_sprite);
		//����
		auto animate = Animate::create(animation);
		card_sprite->runAction(animate);

/*
 *	����ÿһ��Layer�ϵ������ٰ�ť����Ӧ�Ķ���
 */
		auto dictionary = Dictionary::createWithContentsOfFile("fonts/text.xml");
		auto lab=(String*)(dictionary->objectForKey("choose"));
		btn_label = Label::createWithTTF(lab->getCString(),"fonts/fenshu.ttf",45);
		btn_label->setColor(Color3B(196,171,188));
		btn_label->setPosition(Point(size().width/2,size().height/3)); 
		layer->addChild(btn_label);

		auto ba=(String*)(dictionary->objectForKey("back"));//���ѡ��ؿ���ť
		bac=Label::createWithTTF(ba->getCString(),"fonts/fenshu.ttf",45);
		bac->setColor(Color3B(196,171,188));  
		bac->setPosition(Point(size().width/2,size().height/5));
		layer->addChild(bac,2);

/*
 *	����layer����
 */
		layer->setContentSize(Size(size().width, size().width));
		layer->setPosition(Point(size().width * page_node_, 0));
		this->addChild(layer);

		page_node_++;
	}
	   

	

	auto touchListener = EventListenerTouchOneByOne::create();//����һ�����㴥������
	touchListener->setSwallowTouches(true);//����Ϊtrue�����ô������´���
	//��ص�������
	touchListener->onTouchBegan = CC_CALLBACK_2(chooseScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(chooseScene::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(chooseScene::onTouchEnded, this);
	//��Ӽ��������¼��ַ�����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), btn_label);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), bac);

    return true;
}  
  
bool chooseScene::onTouchBegan(Touch *touch, Event  *event)
{
	
	ismenu = false;
	isendmenuwithend = false;
	start = touch->getLocation();//����ȥ���Ǹ��㣻
 	menusize = btn_label->getContentSize();
 	rect = Rect(size().width/2 - menusize.width/2, size().height/3 - menusize.height/2, menusize.width, menusize.height);
 	if(rect.containsPoint(start))
 	{
 		log("start");
 		ismenu = true;
 	}

	menuend = bac->getContentSize();
	endrect = Rect(size().width/2 - menuend.width/2, size().height/5 - menuend.height/2, menuend.width, menuend.height);
	if(endrect.containsPoint(start))
	{
		log("exitstart");
		ismenuwithend = true;
	}
	return true;
}


void chooseScene::onTouchEnded(Touch *touch, Event  *event)
{
	isendmenu = false;
	isendmenuwithend = false;
	end = touch->getLocation();//��굯��ʱ��λ��

	//dis��ʾ���Ӱ���ȥ���������Ϲ��ľ���
	auto dis = end.getDistance(start);

	if (dis >= 20 )//���������ڻ������С�������룬��ʾ������Ч
	{
		ismenu = false;
		isendmenu = false;
		if (start.x > end.x) {//����ȥ�ĵ��x����������ĵ��x��
			//��¼��ǰҳ
			++cur_page_node_;//��ʾ�����󻬣�����cur_page_node_��1��
			if (page_node_ - 1 < cur_page_node_)
				cur_page_node_ = page_node_ - 1;//����ͷ�˾Ͳ����ˣ�cur_page_node_����Ϊ���һҳ
		}
		else if (start.x < end.x) {
			//��¼��ǰҳ	
			--cur_page_node_;//��֮��һ
			if (cur_page_node_ < 0)
				cur_page_node_ = 0;//����ͷ�˾Ͳ����ˣ�cur_page_node_����Ϊ��һҳ��
		}
		//���Ź�������
		goToCurrNode();//ִ�л�������
	}

 	if(rect.containsPoint(end))
 	{
 		log("end");
 		isendmenu = true;
 	}
 	if(dis<=20 && ismenu && isendmenu)
 	{
		log("cur_page_node_:%d",cur_page_node_);
  		GameScene::setLevel(cur_page_node_+1);
		//donghua();
		Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3,GameScene::createScene()));
	}

	if(endrect.containsPoint(start))
	{
		log("exitend");
		isendmenuwithend = true;
	}
	if(dis<=20 && ismenuwithend && isendmenuwithend)
	{
		//donghua();
		Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3,startScene::createscene()));
	}
}

void chooseScene::donghua()
{
// 	log("donghua");
// 	auto blink=Blink::create(3.0f,5);  
// 	auto scaleto = ScaleTo::create(0.2f,1.5f);
// 	auto scalere = ScaleTo::create(0.5f,0.5f);
// 	auto delay = DelayTime::create(1.0f);
// 	auto sequence = Sequence::create(blink, scaleto, scalere, delay, NULL);
// 	btn_label->runAction(sequence);
}


void chooseScene::goToCurrNode()
{
	//����Ч��
	this->runAction(MoveTo::create(0.4f, Point(-cur_page_node_ * Director::getInstance()->getWinSize().width, 0)));
}


Size chooseScene::size()
{
	return Director::getInstance()->getWinSize();
}