#pragma once
#include"../GameScenario/GameScriptEngine.h"
#include "ModeBase.h"
#include<vector>
#include<memory>
#include<string>

class Game;

class ModeMainGame:public ModeBase
{
public:
	ModeMainGame( Game& game ,int layer,std::string stagename);
	virtual ~ModeMainGame();
	void Init ();

	virtual bool Update ( ); // �X�V

	virtual bool Draw ( );	// �`��
protected:
	//GameScriptEngine GameSclipt;
	ObjectServer<ActorBase3D> _objectServer;
};
