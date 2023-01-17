#pragma once

#include <memory>

#include"GameScenario/input_manager.h"
#include"../sourcefile/mode/ModeServer.h"

// �Q�[���N���X�̐錾
class Game
{
public:
	Game();			// �R���X�g���N�^
	~Game();		// �f�X�g���N�^

	void Input();	// ����
	void Update();  // �X�V
	void Draw();	// �`��


	InputManager& Getinput()
	{
		return _input;
	}
	
	virtual ModeServer& GetModeServer()
	{
		return _modeServer;
	}
	
private:
	InputManager _input;
	ModeServer _modeServer;
};
