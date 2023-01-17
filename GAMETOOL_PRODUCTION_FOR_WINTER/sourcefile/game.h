#pragma once

#include <memory>

#include"GameScenario/input_manager.h"
#include"../sourcefile/mode/ModeServer.h"

// ゲームクラスの宣言
class Game
{
public:
	Game();			// コンストラクタ
	~Game();		// デストラクタ

	void Input();	// 入力
	void Update();  // 更新
	void Draw();	// 描画


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
