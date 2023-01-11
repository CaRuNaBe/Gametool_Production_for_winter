/*****************************************************************//**
 * \file   ResourceServer.cpp
 * \brief  リソース管理クラス実装
 *
 * \author 猪狩先生
 * \date   August 2022
 *********************************************************************/

#include "DxLib.h"
#include "resourceserver.h"

// 静的メンバ実体
std::unordered_map<std::string , int>	ResourceServer::_mapGraph;
std::unordered_map<std::string , int>	ResourceServer::_mapSound;

void    ResourceServer::Init ()
{
	_mapGraph.clear ();
	_mapSound.clear ();
}

void    ResourceServer::Release ()
{
	ClearGraph ();
	ClearSound ();
}

// すべてのデータの削除をする
void	 ResourceServer::ClearGraph ()
{
	for ( auto&& graph : _mapGraph )
	{
		DeleteGraph ( graph.second );      // unorderd_mapの graph.first はキー、 graph.second は値
	}
	_mapGraph.clear ();
}

void	 ResourceServer::ClearSound ()
{
	for ( auto&& sound : _mapSound )
	{
		DeleteSoundMem ( sound.second );
	}
	_mapSound.clear ();
}

// キーを検索する
int     ResourceServer::FindGraph ( std::string filename )
{
	auto itr = _mapGraph.find ( filename );    // map::find() はキーでデータがあるか探す。無い場合、map::end()が返る
	if ( itr != _mapGraph.end () )
	{
// キーがあった。secondが値
		return itr->second;
	}
	// キーがなかった
	return -1;
}

int		ResourceServer::LoadGraph ( std::string filename )
{
	int cg = FindGraph ( filename );    // すでに読み込み済なら、cgに-1以外の値が返る。
	if ( cg == -1 )
	{
// キーがなかったので読み込み
		cg = ::LoadGraph ( filename.c_str () );     // DXLIBのAPIを呼ぶので、::を先頭に付け、このクラスの同じ名前の関数と区別する
		// キーとデータをmapに登録
		_mapGraph [ filename ] = cg;
	}
	return cg;
}

// キーを検索する
int     ResourceServer::FindSound ( std::string filename )
{
	auto itr = _mapSound.find ( filename );    // map::find() はキーでデータがあるか探す。無い場合、map::end()が返る
	if ( itr != _mapSound.end () )
	{
// キーがあった。secondが値
		return itr->second;
	}
	// キーがなかった
	return -1;
}

int		ResourceServer::LoadSoundMem ( std::string filename )
{
	int sound = FindSound ( filename );    // すでに読み込み済なら、soundに-1以外の値が返る。
	if ( sound == -1 )
	{
// キーがなかったので読み込み
		sound = ::LoadSoundMem ( filename.c_str () );     // DXLIBのAPIを呼ぶので、::を先頭に付け、このクラスの同じ名前の関数と区別する
		// キーとデータをmapに登録
		_mapSound [ filename ] = sound;
	}
	return sound;
}