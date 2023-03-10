#include<algorithm>
#include "DxLib.h"
#include "ModeServer.h"
#include"../game.h"
ModeServer::ModeServer( Game& game )
	: _game( game )
	,_updating( false )
{}

ModeServer::~ModeServer()
{
	Clear();
}

void ModeServer::Clear()
{
	if ( _updating )
	{
		for ( auto&& mode : _vModes )
		{
			mode->Dead();
		}
	}
	else
	{
		_vModes.clear();
	}
}

void	ModeServer::Add( ModeBasePtr mode )
{
	if ( _updating )
	{
		_vPendingModes.push_back( mode );
	}
	else
	{
		_vModes.push_back( mode );
	}
}

void	ModeServer::AddPendingModes()
{
	// _vPendingModes -> _vModes に追加
	_vModes.insert(
		_vModes.end(),
		make_move_iterator( _vPendingModes.begin() ),
		make_move_iterator( _vPendingModes.end() )
	);
	// _vPendingModes をクリア
	_vPendingModes.clear();
}

void	ModeServer::Del( ModeBase& mode )
{
	mode.Dead();
}

void	ModeServer::DeleteModes()
{
	// コンテナをイテレータで回す( eraseがイテレータを要求しているため )
	for ( auto ite = _vModes.begin(); ite != _vModes.end(); )
	{
		if ( (*ite)->IsDead() )
		{
			ite = _vModes.erase( ite );		// これでobjectそのものも削除される
		}
		else
		{
			++ite;
		}
	}

}
// 更新初期化
bool ModeServer::UpdateInit()
{
	return true;
}
// 更新
bool ModeServer::Update()
{

	_updating = true;
	for ( auto&& mode : _vModes )
	{
		if ( mode->GetUpdateSkip() )
		{
			continue;
		}
		mode->Update();
	}

	// レイヤーによるソート
	std::sort( _vModes.begin(),_vModes.end(),[]( const ModeBasePtr ch1,const ModeBasePtr ch2 )
	{
		return ch1->GetLayer() < ch2->GetLayer();
	} );

	_updating = false;
	AddPendingModes();
	DeleteModes();	// 削除予約されたオブジェクトを削除する
	return true;
}
// 後処理
bool ModeServer::UpdateFinish()
{
	return true;
}
// 描画初期化
bool ModeServer::DrawInit()
{
	ClearDrawScreen();		// 画面を初期化する
	return true;
}
// 描画
bool ModeServer::Draw()
{
	for ( auto&& mode : _vModes )
	{
		if ( mode->GetDrawSkip() )
		{
			continue;
		}
		mode->Draw();
	}
	return true;
}
// 描画後処理
bool ModeServer::DrawFinish()
{
	ScreenFlip();			// 裏画面の内容を表画面に反映させる
	return true;
}