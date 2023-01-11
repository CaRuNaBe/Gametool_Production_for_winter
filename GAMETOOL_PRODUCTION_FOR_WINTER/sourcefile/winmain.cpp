#include <memory>
#include <stdio.h>
#include <time.h>
#include "DxLib.h"
#include"Game.h"
#include "ResourceServer.h"

// プログラムはWinMain から始まります
int WINAPI WinMain( _In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow )
{
	ChangeWindowMode( TRUE );    // ウインドウモードに変更
	SetGraphMode( SCREEN_W,SCREEN_H,SCREEN_DEPTH );    // 画面の解像度(幅,高さ)と色数(32bit)を指定
	DxLib_Init();    // Dxライブラリ初期化
	SetDrawScreen( DX_SCREEN_BACK );    // 描画先画面を裏にする
	SetMouseDispFlag( FALSE );//カーソル非表示

	ResourceServer::Init();	//リソースサーバ初期化

	auto game = std::make_unique<Game>();

	// メインループ
	// Windows 特有の面倒な処理をライブラリにやらせる
	// -1 が返ってきたらループを抜ける
	while ( ProcessMessage() != -1 )
	{
		// ゲームの処理
		game->Input();   // 入力
		game->Update();   // 更新
		game->Render();   // 描画
		if ( ProcessMessage() == -1 ) break;                 //エラーが起きたら終了
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) )//エスケープキーでゲーム終了
		{
			break;
		}
	}
	ResourceServer::Release();	//リソースサーバ解放

	// Dxライブラリ終了
	DxLib_End();

	return 0;
}