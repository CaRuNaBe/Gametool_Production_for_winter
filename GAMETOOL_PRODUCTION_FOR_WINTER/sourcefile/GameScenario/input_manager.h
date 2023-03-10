/*****************************************************************//**
 * \file   input_manager.h
 * \brief  入力管理クラス
 * 
 * \author 阿部健太郎
 * \date   January 2023
 *********************************************************************/
#pragma once
#include<DxLib.h>
class InputManager
{
public:
	InputManager();
	~InputManager();
	//
	bool Update();

	//入力関数
	const bool& EveryOtherKey( int button,const int FrequencyFrame );
	const int GetKey( int button );
	const int GetTrg( int button );
	const int GetRel( int button );
	const bool& XinputEveryOtherKey( int button,const int FrequencyFrame );
	const bool& XinputEveryOtherLeftTrigger( const int FrequencyFrame );
	const bool& XinputEveryOtherRightTrigger( const int FrequencyFrame );

	const unsigned char& GetLeftTrigger();
	const unsigned char& GetRightTrigger();
	short& GetLstickX();
	short& GetLstickY();
	const short& GetRstickX();
	const short& GetRstickY();
	const bool GetKeyXinput( const int button );
	const bool GetTrgXinput( const int button );
	const bool GetRelXinput( const int button );
private:
	XINPUT_STATE _gxKey;
	XINPUT_STATE _gxTrg;
	XINPUT_STATE _gxRel;
	int		_gKey,_gTrg,_gRel;
	int Key_skip_count;
	int LeftTrigger_skip_count;
	int RightTrigger_skip_count;
	bool is_Click_on_Key;
	bool is_Click_on_R_Trigger;
	bool is_Click_on_L_Trigger;
};
