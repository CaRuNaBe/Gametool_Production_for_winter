/*****************************************************************//**
 * \file   ModeBase.h
 * \brief  モードベース実装
 * 
 * \author 阿部健太郎
 * \date   October 2022
 *********************************************************************/
#pragma once

class Game;

class ModeBase
{
public:
	ModeBase ( Game& game );
	virtual ~ModeBase ();

	virtual void Update ();  // 更新
	virtual void Render ();	// 描画
	void Alpha ();
	void Ini ();
	int random ( int min , int max );

	virtual bool	IsDead ()
	{
		return _dead;
	}

	virtual void 	Dead ()
	{
		_dead = true;
	}

	int _Modealpha;
	bool _AlphaSwitch;
	int  _fremecount;
protected:
	Game& _game;
	bool	_dead;
};