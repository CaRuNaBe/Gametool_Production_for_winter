#pragma once
#include "objectbase/ActorBase3D.h"
class SupplyEria:
    public ActorBase3D
{
	using base = ActorBase3D;
public:
	SupplyEria();
	virtual ~SupplyEria();

	virtual void Init();
	virtual bool Update( Game& game,ModeBase& mode );
	virtual bool Draw( Game& game,ModeBase& mode );

protected:
	int    _handle;
};

