#pragma once
#include	<unordered_map>
#include	"ModeServer.h"
#include<string>
// 画面設定
constexpr auto SCREEN_W = 1920;		///< 画面の横解像度
constexpr auto SCREEN_H = 1080;//< 画面の縦解像度
constexpr auto SCREEN_DEPTH = 32; ///< １ドットあたりのビット数

//原点
constexpr auto BASICS_X = 0;
constexpr auto BASICS_Y = 0;



// ゲームクラスの宣言
class Game
{
public:
	Game();			// コンストラクタ
	~Game();		// デストラクタ
	void Input();	// 入力
	void Update();  // 更新
	void Render();	// 描画
	void Road();

	virtual ModeServer& GetModeServer()
	{
		return _modeServer;
	}
	virtual ModeServer::TypeModes& GetModes()
	{
		return _modeServer.GetModes();
	}



	bool isEndsclipt;
	bool isUpdatestart;
	bool  isBgmstart;
	bool isLoadend;
	bool isBlackbackground;
	int			_key,_trg,_rel;

	int _cgLoadanime;//
	int		_cgTitle;
	int _cgStart;
	int _cgGuide;
	int _cgExplan;
	int _cgAlbum;
	int _cgBgbook;
	int _cgBook[35];
	int _cgpopeffect[19];
	int _cgicon;
	int _cgResultGage;
	int _cgCharselect_Nocolor;
	int _cgBreaktime;
	int _cgConfirm_Nocolor;
	int _cgConfirmGage;
	int _cgConfirmYes;
	int _cgConfirmNo;
	int _cgLiotcolor;
	int _cgAniecolor;
	int _cgLunascolor;
	int _cgBreaktimeColor;
	int _cgCharselectgage;
	int _cgTextbox;//文字を映すとき、後ろに表示されるグラフィックハンドル
	int _cgResult;//リザルト画面のグラフィックハンドル
	int _cgKnowlege;
	int _cgMagic;
	int _cgMagischeKrafte;
		//ui確認画面
	int _cgUibutton;
	int _cgUicheckScreen;

	int _CrText;//文字色
	int _CrBrack;
	std::unordered_map<std::string,int>	_se;	// SEマップ

protected:
	ModeServer		_modeServer;
};
