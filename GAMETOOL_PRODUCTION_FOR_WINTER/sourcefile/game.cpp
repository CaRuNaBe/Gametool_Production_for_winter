#include "game.h"
#include"mode/ModeMainGame.h"
// コンストラクタ
Game::Game()
	: _modeServer( *this )
{
	auto game = std::make_shared<ModeMainGame>( *this,1,"game" );
	_modeServer.Add( game );
}

// デストラクタ
Game::~Game()
{}

// 入力
void Game::Input()
{
	_input.Update();
}

// 更新
void Game::Update()
{
	_modeServer.UpdateInit();
	_modeServer.Update();
	_modeServer.UpdateFinish();
}

// 描画
void Game::Draw()
{
	_modeServer.DrawInit();
	_modeServer.Draw();
	_modeServer.DrawFinish();
}
