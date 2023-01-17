#pragma once
#include "ModeBase.h"
#include"string"
#include "../game.h"

class ModeSclipt:public ModeBase
{
public:
	ModeSclipt(Game& game,int layer,std::string storyname);
	virtual ~ModeSclipt();

	virtual bool Update();  // çXêV
	virtual bool Draw();	// ï`âÊ

private:
	//ScriptEngine script;
};
