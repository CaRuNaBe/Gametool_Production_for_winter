#include "game.h"
#include"mode/ModeMainGame.h"
// �R���X�g���N�^
Game::Game()
	: _modeServer( *this )
{
	auto game = std::make_shared<ModeMainGame>( *this,1,"game" );
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
