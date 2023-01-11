#include "game.h"
#include <memory>
#include <DxLib.h>
#include "resourceserver.h"
#include<picojson.h>
// �R���X�g���N�^
Game::Game ()
	: _modeServer ( *this )
	, _CrBrack ( GetColor ( 0 , 0 , 0 ) )
	, _CrText ( GetColor ( 94 , 52 , 21 ) )
	, _key ( 0 )
	, _trg ( 0 )
	, _rel ( 0 )
	, isEndsclipt ( false )
	, isUpdatestart ( false )
	, isBgmstart ( false )
	, isLoadend ( false )
	, isBlackbackground ( false )
{
	Road ();

	isLoadend = true;
	isBlackbackground = true;

}

// �f�X�g���N�^
Game::~Game ()
{}

// ����
void Game::Input ()
{
	auto keyold = _key;
	_key = GetJoypadInputState ( DX_INPUT_KEY_PAD1 );
	_trg = ( _key ^ keyold ) & _key;	// �L�[�̃g���K��񐶐��i�������u�Ԃ����������Ȃ��L�[���j
	_rel = ( _key ^ keyold ) & ~_key;	// �L�[�̃����[�X��񐶐��i�������u�Ԃ����������Ȃ��L�[���j
}

// �X�V
void Game::Update ()
{
	_modeServer.Update ();
}

// �`��
void Game::Render ()
{
	ClearDrawScreen ();		// ��ʂ�����������
	_modeServer.Render ();
	ScreenFlip ();			// ����ʂ̓��e��\��ʂɔ��f������
}

void Game::Road ()
{
}