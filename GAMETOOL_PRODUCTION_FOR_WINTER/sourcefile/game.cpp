#include "game.h"
#include <memory>
#include <DxLib.h>
#include "resourceserver.h"
#include<picojson.h>
// コンストラクタ
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

// デストラクタ
Game::~Game ()
{}

// 入力
void Game::Input ()
{
	auto keyold = _key;
	_key = GetJoypadInputState ( DX_INPUT_KEY_PAD1 );
	_trg = ( _key ^ keyold ) & _key;	// キーのトリガ情報生成（押した瞬間しか反応しないキー情報）
	_rel = ( _key ^ keyold ) & ~_key;	// キーのリリース情報生成（離した瞬間しか反応しないキー情報）
}

// 更新
void Game::Update ()
{
	_modeServer.Update ();
}

// 描画
void Game::Render ()
{
	ClearDrawScreen ();		// 画面を初期化する
	_modeServer.Render ();
	ScreenFlip ();			// 裏画面の内容を表画面に反映させる
}

void Game::Road ()
{
}