#ifndef _CUTTING_PHOTOS__
#define _CUTTING_PHOTOS__

#include "cocos2d.h"
#include <vector>
#include <map>
using namespace std;
USING_NS_CC;

class CuttingPhotos : public Layer
{
public:
	static CuttingPhotos* create(const char* photo, unsigned int rows=3, unsigned int columns=3);

	virtual bool initWithPhoto(const char* photo,unsigned int rows,unsigned int columns);

	bool initSlice(const char* photo);//��ʼ����Ƭ����

	void initTouchEventlistener();//��ʼ�������¼�

	void move(int x,int y);//�ƶ�ָ��λ�õĿ�Ƭ
	void movewithdir(char dir);
	void restart();//������ÿ�Ƭ
	bool judge(int num);
	bool isWin();
	void setWin();
	void nextScene();

	bool iswin;
	int _rows; //����
	int _columns; //����
	int _sliceWidth; //���ӿ��
	int _sliceHeight; //���Ӹ߶�
	//int _blocknumber; //��������
	Vec2 start;
	Vec2 end;
	bool beginismove;
	std::vector<std::vector<Sprite*>> _slices;
	std::vector<int> blocknum;
	std::vector<int> placenum;
	int randnum[101];
	
};

#endif