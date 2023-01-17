#include "game.h"
#include"mode/ModeGame.h"
// �R���X�g���N�^
Game::Game()
	: _modeServer( *this )
{
	auto game = std::make_shared<ModeGame>( *this,1,"game" );
	_modeServer.Add( game );
}

// �f�X�g���N�^
Game::~Game()
{}

// ����
void Game::Input()
{
	_input.Update();
}

// �X�V
void Game::Update()
{
	_modeServer.UpdateInit();
	_modeServer.Update();
	_modeServer.UpdateFinish();
}

// �`��
void Game::Draw()
{
	_modeServer.DrawInit();
	_modeServer.Draw();
	_modeServer.DrawFinish();
}
