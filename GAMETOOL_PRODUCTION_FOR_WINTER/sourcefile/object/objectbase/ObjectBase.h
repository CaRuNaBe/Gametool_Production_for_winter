#pragma once
#include	"Math.h"
#include "Dxlib.h"
class Game;
class ModeBase;
// ObjectBaseƒNƒ‰ƒX
class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase();

	virtual void	Init();
	virtual bool	Update( Game& game,ModeBase& mode );
	virtual bool	Draw( Game& game,ModeBase& mode );

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
		return isUpdateSkip;
	}
	void SetUpdateSkip(bool UpdateSkip)
	{
		isUpdateSkip = UpdateSkip;
	}
	bool GetDrawSkip()
	{
		return isDrawSkip;
	}
protected:
	bool	_dead;
	bool isUpdateSkip;
	bool isDrawSkip;

};
