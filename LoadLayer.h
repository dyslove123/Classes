#pragma once
#ifndef  _LoadLayer_H_
#define  _LoadLayer_H_
#endif
#include "cocos2d.h"
#include "SceneManager.h"
using namespace cocos2d;
class LoadLayer :
	public CCLayer
{
public:
	//��ʼ���ķ���
	virtual bool init();
	//����������
	SceneManager *sm;
	//��ת���˵�����ķ���
	void goToMenuLayer(CCObject* pSender);
	CREATE_FUNC(LoadLayer);
};
