#include "LoadLayer.h"
#include <string.h>
#include "SimpleAudioEngine.h"
#include "LoadAndSave.h"

using namespace cocos2d;
//ʵ��LoadLayer���е�init��������ʼ������
bool LoadLayer::init(){
	//���ø���ĳ�ʼ��
	if (!CCLayer::init()){
		return false;
	}
	//��ȡ�ɼ�����ߴ�
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//��ȡ�ɼ�����ԭ������
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//���ӱ�������
	CCSprite* background = CCSprite::create("gameBackground.png");
	//���þ����λ��
	background->setPosition(ccp(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	//���������ӵ�����
	this->addChild(background);
	//�������ؾ���
	CCSprite* load = CCSprite::create("load.png");
	//���ü��ؾ����λ��
	load->setPosition(ccp(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 5));
	//����ɫ�����Ӿ���
	this->addChild(load);
	//���������
	int count = rand() % 3 + 1;
	//���־���ִ�ж���



	load->runAction
		(
		CCSequence::create
		(
		CCBlink::create(0.1, count),
		CCCallFuncN::create(this,SEL_CallFuncN(&LoadLayer::goToMenuLayer)),
		NULL
		)
		);
	return true;
}
void LoadLayer::goToMenuLayer(CCObject* pSender)
{
	//���ű�������
	if (LoadAndSave::GetInt("musicFlag", 1) == 1)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/background.mp3", true);
	}
	sm->goMenuLayer();
	
}

