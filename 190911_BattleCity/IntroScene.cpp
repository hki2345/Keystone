#include "IntroScene.h"

#include <KWindowManager.h>
#include <KInputManager.h>	
#include <KSceneManager.h>

#include <KBitMap_Render.h>
#include <KText_Render.h>
#include <KOne.h>

IntroScene::IntroScene()
{
}


IntroScene::~IntroScene()
{
}


void IntroScene::create()
{
	KScene::create();
	UISize = 9;
	VectorUI.reserve(UISize);
	
	for (int i = 0; i < UISize; i++)
	{
		VectorUI.push_back(KScene::create_kone(L"IntroUI"));
	}

	KBitMap_Render* BattleSprite = VectorUI[0]->add_component<KBitMap_Render>();
	BattleSprite->set_bit(L"res\\BattleLogo.bmp", 10);

	KText_Render* Text1 = VectorUI[1]->add_component<KText_Render>();
	Text1->set_font(L"���� ���� - 00 �ִ� ���� - 20000", 20, 10, L"DungGeunMo", RGB(255, 255, 255));
	KText_Render* Text2 = VectorUI[2]->add_component<KText_Render>();
	Text2->set_font(L"1 �÷��̾�", 20, 10, L"DungGeunMo", RGB(255, 255, 255), TA_LEFT);
	KText_Render* Text3 = VectorUI[3]->add_component<KText_Render>();
	Text3->set_font(L"2 �÷��̾�", 20, 10, L"DungGeunMo", RGB(255, 255, 255), TA_LEFT);
	KText_Render* Text4 = VectorUI[4]->add_component<KText_Render>();
	Text4->set_font(L"�����ϱ�", 20, 10, L"DungGeunMo", RGB(255, 255, 255), TA_LEFT);
	KText_Render* Text5 = VectorUI[5]->add_component<KText_Render>();
	Text5->set_font(L"NAMCOT", 15, 10, L"�޸յձ�������", RGB(255, 0, 0));
	KText_Render* Text6 = VectorUI[6]->add_component<KText_Render>();
	Text6->set_font(L"�� 1980 1985 NAMCO LTD.", 15, 10, L"DungGeunMo", RGB(255, 255, 255));
	KText_Render* Text7 = VectorUI[7]->add_component<KText_Render>();
	Text7->set_font(L"ALL RIGHTS RESERVED", 15, 10, L"DungGeunMo", RGB(255, 255, 255));


	KBitMap_Render* BattleSelect = VectorUI[8]->add_component<KBitMap_Render>();
	BattleSelect->set_bit(L"res\\PlayerSelect.bmp", 10);
}


bool IntroScene::init()
{
	KScene::init();
	KWindowManager::instance()->backcolor(RGB(0, 0, 0));
	float X = KWindowManager::instance()->main_size().x / 2;
	MaxYPos = 40.0f;

	VectorUI[0]->size({ 600.0f, 300.0f });
	VectorUI[0]->pos({ 100.0f, 60.0f });


	VectorUI[1]->pos({ X, MaxYPos });
	VectorUI[2]->pos({ 350.0f, 375.0f });
	VectorUI[3]->pos({ 350.0f, 400.0f });
	VectorUI[4]->pos({ 350.0f, 425.0f });
	VectorUI[5]->pos({ X, 475.0f });
	VectorUI[6]->pos({ X, 500.0f });
	VectorUI[7]->pos({ X, 525.0f });


	VectorUI[8]->size({ 20.0f, 20.0f });
	VectorUI[8]->active(false);


	for (size_t i = 0; i < VectorUI.size(); i++)
	{
		VectorUI[i]->moving_pluspos(KPos2::Up * 800.0f);
	}
	eIntroState = INTRO_STATE::IS_WAIT;

	return true;
}
void IntroScene::update()
{
	KScene::update();

	if (VectorUI[1]->pos().y > MaxYPos && INTRO_STATE::IS_WAIT == eIntroState)
	{
		for (size_t i = 0; i < VectorUI.size(); i++)
		{
			VectorUI[i]->moving_delta(KPos2::Down * 100.0f);
		}
	}
	
	
	if(INTRO_STATE::IS_WAIT == eIntroState &&
		(VectorUI[1]->pos().y <= MaxYPos ||
		true == KInputManager::instance()->is_down(VK_SPACE)))
	{
		VectorUI[8]->active(true);
		VectorUI[8]->pos({ 300.0f, 375.0f });
		eIntroState = INTRO_STATE::IS_PLAY;
	}


	if(INTRO_STATE::IS_PLAY == eIntroState)
	{
		float X = KWindowManager::instance()->main_size().x / 2;
		VectorUI[0]->pos({ 100.0f, 60.0f });
		VectorUI[1]->pos({ X, MaxYPos });
		VectorUI[2]->pos({ 350.0f, 375.0f });
		VectorUI[3]->pos({ 350.0f, 400.0f });
		VectorUI[4]->pos({ 350.0f, 425.0f });
		VectorUI[5]->pos({ X, 475.0f });
		VectorUI[6]->pos({ X, 500.0f });
		VectorUI[7]->pos({ X, 525.0f });

		if (true == KInputManager::instance()->is_down(VK_SPACE))
		{
			KSceneManager::instance()->change_scene(L"Game");
		}
	}

}