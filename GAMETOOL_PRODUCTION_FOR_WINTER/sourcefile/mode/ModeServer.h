#pragma once
#include <memory>
#include <vector>
#include "ModeBase.h"

class Game;

class ModeServer
{
	using ModeBasePtr = std::shared_ptr<ModeBase>;
	using TypeModes = std::vector<ModeBasePtr>;	// モードリストを定義
public:
	ModeServer(Game& game);
	~ModeServer();

	TypeModes& GetModes()
	{
		return _vModes;
	}

	void	Clear();
	void	Add(ModeBasePtr mode);
	void	Del(ModeBase& mode);

	bool UpdateInit();
	bool Update();  // 更新
	bool UpdateFinish();
	bool DrawInit();
	bool Draw();	// 描画
	bool DrawFinish();

protected:
	Game& _game;
	TypeModes _vModes;
	TypeModes _vPendingModes;
	bool	_updating;
	void	DeleteModes();
	void	AddPendingModes();
};
