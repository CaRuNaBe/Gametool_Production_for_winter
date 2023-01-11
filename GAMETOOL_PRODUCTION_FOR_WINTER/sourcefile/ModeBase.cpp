/*****************************************************************//**
 * \file   ModeBase.cpp
 * \brief  モードベース実装
 * 
 * \author 阿部健太郎
 * \date   October 2022
 *********************************************************************/

#include <DxLib.h>
#include <random>
#include "ModeBase.h"
#include "Game.h"

ModeBase::ModeBase ( Game& game )
	: _game ( game )
	, _dead ( false )
	, _Modealpha ( 255 )
	, _AlphaSwitch ( true )
	, _fremecount ( 0 )
{}

ModeBase::~ModeBase ()
{}

// 更新
void ModeBase::Update ()
{
	Alpha ();
}

// 描画
void ModeBase::Render ()
{}

void ModeBase::Ini ()
{
	_Modealpha = 255;
	_AlphaSwitch = true;
	_fremecount = 0;
}

void ModeBase::Alpha ()
{
	if ( _Modealpha > 255 )
	{
		_Modealpha = 255;
		_AlphaSwitch = true;
	}

	if ( _Modealpha < 0 )
	{
		_Modealpha = 0;
		_AlphaSwitch = false;
	}

	if ( _AlphaSwitch )
	{
		_Modealpha -= 5;
	}
	else
	{
		_Modealpha += 5;
	}
};

/**
 *¥fn int ModeGame::random.
 *¥brief ランダム生成関数
 *¥param min　
 *¥param max
 *¥return int
 */
int ModeBase::random ( int min , int max )
{
	std::random_device seed_gen;
	std::mt19937 engine ( seed_gen () );
	std::uniform_int_distribution<>dist1 ( min , max );
	auto r1 = dist1 ( engine );
	return r1;
};

