/*****************************************************************//**
 * \file   ResourceServer.h
 * \brief リソースの管理定義
 * すべて静的メンバで構成する
 *
 * \author 猪狩先生
 * \date   July 2022
 *********************************************************************/
#pragma once
#include	<unordered_map>
#include<string>
class ResourceServer
{
public:
	static	 void	Init();//初期化
	static void	Release();//開放

	static 	void	 ClearGraph();						// すべての画像をクリアする
	static 	int FindGraph( std::string filename );	// ファイル名から画像を探す。読み込んでいなければ-1
	static 	int 	LoadGraph( std::string fileName );	// ファイル名から画像を読み込む。
	static	void	ClearSound();						// すべてのサウンドをクリアする
	static	int FindSound( std::string filename );	// ファイル名からサウンドを探す。読み込んでいなければ-1
	static	int		LoadSoundMem( std::string FileName );	// ファイル名からサウンドを読み込む。

private:
	// unorderd_mapは文字列などをキーにできるコンテナ。
	// ファイル名をキーにして、すでに読み込んでいるかを確認する
	static std::unordered_map<std::string,int>	_mapGraph;
	static std::unordered_map<std::string,int>	_mapSound;
};
