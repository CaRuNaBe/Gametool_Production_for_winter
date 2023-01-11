/*****************************************************************//**
 * \file   ModeBase.h
 * \brief  ���[�h�x�[�X����
 * 
 * \author ���������Y
 * \date   October 2022
 *********************************************************************/
#pragma once

class Game;

class ModeBase
{
public:
	ModeBase ( Game& game );
	virtual ~ModeBase ();

	virtual void Update ();  // �X�V
	virtual void Render ();	// �`��
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