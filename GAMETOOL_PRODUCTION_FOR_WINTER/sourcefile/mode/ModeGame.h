#pragma once
#include"../GameScenario/GameScriptEngine.h"
#include "ModeBase.h"
#include<vector>
#include<memory>
#include<string>

class Game;

class ModeGame :public ModeBase
{
public:
	ModeGame ( Game& game ,int layer,std::string stagename);
	virtual ~ModeGame ();
	void Init_modegame ();

	virtual bool Update ( ); // �X�V

	virtual bool Draw ( );	// �`��
protected:
	//GameScriptEngine GameSclipt;
};
