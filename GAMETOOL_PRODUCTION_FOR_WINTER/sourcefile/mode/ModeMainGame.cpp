/*****************************************************************//**
 * \file   ModeGame.cpp
 * \brief  ゲームモード実装
 *
 * \author 阿部健太郎
 * \date   September 2022
 *********************************************************************/

#include "ModeMainGame.h"
#include <DxLib.h>
#include "../Game.h"
#include "../ResourceServer.h"
#include"../object/Player.h"
#include"../object/GameStage.h"
namespace
{
	//const std::string filepass = 
}

ModeMainGame::ModeMainGame( Game& game,int layer,std::string stagename )
	: ModeBase( game,layer )

{
	Init();
	auto player = std::make_shared<Player>();
	_objectServer.Add( player );
	auto stage = std::make_shared<GameStage>();
	_objectServer.Add( stage );

	//GameSclipt.Initialize(filename,stagename);
}

ModeMainGame::~ModeMainGame()
{}
/**
 *¥fn void ModeGame::Init_modegame.
 *¥brief
 *¥return void
 */
void ModeMainGame::Init()
{
	ModeBase::Initialize();
};
/**
 *¥fn void ModeGame::Update.
 *¥brief 計算処理毎回呼ばれる
 *¥return void
 */
bool ModeMainGame::Update()
{
	ModeBase::Update();
	_objectServer.Update( _game,*this );
	//GameSclipt.Update( _game );
	return true;
}
/**
 *¥fn void ModeGame::Render.
 *¥brief 描画処理毎回呼ばれる
 *¥return void
 */
bool ModeMainGame::Draw()
{
	ModeBase::Draw();
	_objectServer.Draw( _game,*this );
	//GameSclipt.Draw( _game );
	return true;
}
