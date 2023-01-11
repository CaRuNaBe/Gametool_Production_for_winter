#pragma once
#include "ModeBase.h"
#include<vector>
#include<memory>
class Game;
class ModeGame :public ModeBase
{
public:
	ModeGame ( Game& game );
	virtual ~ModeGame ();
	void Init_modegame ();

	virtual void Update (); // çXêV

	virtual void Render ();	// ï`âÊ
protected:
	};
