#include <memory>
#include "DxLib.h"
#include "Game.h"
#include "ResourceServer.h"

namespace
{
	// 画面設定
	constexpr auto SCREEN_WIDTH = 1920;// 画面の横解像度
	constexpr auto SCREEN_HEIGHT = 1080;// 画面の縦解像度
	constexpr auto SCREEN_DEPTH = 32;//ドットあたりのビット数
};

// プログラムはWinMain から始まります
int WINAPI WinMain( _In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow )
{
 #if _DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
	ChangeWindowMode( TRUE );    // ウインドウモードに変更

	SetGraphMode( SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_DEPTH );    // 画面の解像度(幅,高さ)と色数(32bit)を指定

	DxLib_Init();    // Dxライブラリ初期化

	SetDrawScreen( DX_SCREEN_BACK );    // 描画先画面を裏にする
	SetMouseDispFlag( FALSE );//カーソル非表示

	ResourceServer::Init();	//リソースサーバ初期化

	auto game = std::make_unique<Game>();

	// メインループ
	// Windows 特有の面倒な処理をライブラリにやらせる
	// -1 が返ってきたらループを抜ける
	while ( (ProcessMessage() != -1) )
	{
		// ゲームの処理
		game->Input();   // 入力
		game->Update();   // 更新
		game->Draw();   // 描画

	}

	ResourceServer::Release();	//リソースサーバ解放

	// Dxライブラリ終了
	DxLib_End();

	return 0;
}