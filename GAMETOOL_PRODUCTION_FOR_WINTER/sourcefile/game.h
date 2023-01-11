#pragma once
#include	<unordered_map>
#include	"ModeServer.h"
#include<string>
// ��ʐݒ�
constexpr auto SCREEN_W = 1920;		///< ��ʂ̉��𑜓x
constexpr auto SCREEN_H = 1080;//< ��ʂ̏c�𑜓x
constexpr auto SCREEN_DEPTH = 32; ///< �P�h�b�g������̃r�b�g��

//���_
constexpr auto BASICS_X = 0;
constexpr auto BASICS_Y = 0;



// �Q�[���N���X�̐錾
class Game
{
public:
	Game();			// �R���X�g���N�^
	~Game();		// �f�X�g���N�^
	void Input();	// ����
	void Update();  // �X�V
	void Render();	// �`��
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
	int _cgTextbox;//�������f���Ƃ��A���ɕ\�������O���t�B�b�N�n���h��
	int _cgResult;//���U���g��ʂ̃O���t�B�b�N�n���h��
	int _cgKnowlege;
	int _cgMagic;
	int _cgMagischeKrafte;
		//ui�m�F���
	int _cgUibutton;
	int _cgUicheckScreen;

	int _CrText;//�����F
	int _CrBrack;
	std::unordered_map<std::string,int>	_se;	// SE�}�b�v

protected:
	ModeServer		_modeServer;
};
