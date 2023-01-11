/*****************************************************************//**
 * \file   ModeGame.cpp
 * \brief  ゲームモード実装
 *
 * \author 阿部健太郎
 * \date   September 2022
 *********************************************************************/

#include "ModeGame.h"
#include <DxLib.h>
#include "Game.h"
#include "ResourceServer.h"

namespace
{
}

ModeGame::ModeGame ( Game& game )
	: ModeBase ( game )
{
	ModeBase::Ini ();
	Init_modegame ();
}

ModeGame::~ModeGame ()
{}
/**
 *¥fn void ModeGame::Init_modegame.
 *¥brief
 *¥return void
 */
void ModeGame::Init_modegame ()
{
	};
/**
 *¥fn void ModeGame::Update.
 *¥brief 計算処理毎回呼ばれる
 *¥return void
 */
void ModeGame::Update ()
{
	ModeBase::Update ();

}
/**
 *¥fn void ModeGame::Render.
 *¥brief 描画処理毎回呼ばれる
 *¥return void
 */
void ModeGame::Render ()
{
	ModeBase::Render ();

}
