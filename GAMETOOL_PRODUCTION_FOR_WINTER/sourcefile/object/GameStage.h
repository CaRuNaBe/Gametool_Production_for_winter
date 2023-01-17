#pragma once
#include "objectbase/ActorBase3D.h"
class GameStage:public ActorBase3D
{
	using base = ActorBase3D;
public:
	GameStage();
	virtual ~GameStage();

	virtual void Init();
	virtual bool Update( Game& game,ModeBase& mode );
	virtual bool Draw( Game& game,ModeBase& mode );

protected:
	int    _handle;
};

