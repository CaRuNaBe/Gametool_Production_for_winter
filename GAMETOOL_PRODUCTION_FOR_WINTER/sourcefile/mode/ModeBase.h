#pragma once
#include	"../Object/ObjectServer.h"
#include"../object/ActorBase3D.h"
class Game;
class ModeBase
{
public:
	ModeBase( Game& game,int layer);
	virtual ~ModeBase();
	virtual	bool Initialize();
	virtual bool Update( );  // �X�V
	virtual bool Draw(  );	// �`��

	virtual bool	IsDead()
	{
		return _dead;
	}

	virtual void	Dead()
	{
		_dead = true;
	}

	bool GetUpdateSkip()
	{
		return _isModeSkip;
	}
	bool GetDrawSkip()
	{
		return _isDrawSkip;
	}

	int GetLayer()
	{
		return _layer;
	}
	
protected:
	Game& _game;

	bool	_dead;
	bool _isModeSkip;
	bool _isDrawSkip;
	int _layer;
};
