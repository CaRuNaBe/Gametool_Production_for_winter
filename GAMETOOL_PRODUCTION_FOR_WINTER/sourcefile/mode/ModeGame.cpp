/*****************************************************************//**
 * \file   ModeGame.cpp
 * \brief  ゲームモード実装
 *
 * \author 阿部健太郎
 * \date   September 2022
 *********************************************************************/

#include "ModeGame.h"
#include <DxLib.h>
#include "../Game.h"
#include "../ResourceServer.h"


namespace
{
	//const std::string filepass = 
}

ModeGame::ModeGame ( Game& game, int layer,std::string stagename)
	: ModeBase ( game ,layer )

{
	ModeBase::Initialize ();
	Init_modegame ();
	//GameSclipt.Initialize(filename,stagename);
}

ModeGame::~ModeGame ()
{}
/**
 *¥fn void ModeGame::Init_modegame.
 *¥brief
 *¥return void
 */
void ModeGame::Init_modegame ()
{};
/**
 *¥fn void ModeGame::Update.
 *¥brief 計算処理毎回呼ばれる
 *¥return void
 */
bool ModeGame::Update (  )
{
	ModeBase::Update (  );
	//GameSclipt.Update( _game );
	return true;
}
/**
 *¥fn void ModeGame::Render.
 *¥brief 描画処理毎回呼ばれる
 *¥return void
 */
bool ModeGame::Draw (  )
{
	ModeBase::Draw (  );
	//GameSclipt.Draw( _game );
	return true;
}
