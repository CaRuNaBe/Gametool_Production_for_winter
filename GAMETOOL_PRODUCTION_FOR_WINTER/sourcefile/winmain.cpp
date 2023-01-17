#include <memory>
#include "DxLib.h"
#include "Game.h"
#include "ResourceServer.h"

namespace
{
	// ��ʐݒ�
	constexpr auto SCREEN_WIDTH = 1920;// ��ʂ̉��𑜓x
	constexpr auto SCREEN_HEIGHT = 1080;// ��ʂ̏c�𑜓x
	constexpr auto SCREEN_DEPTH = 32;//�h�b�g������̃r�b�g��
};

// �v���O������WinMain ����n�܂�܂�
int WINAPI WinMain( _In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow )
{
 #if _DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
	ChangeWindowMode( TRUE );    // �E�C���h�E���[�h�ɕύX

	SetGraphMode( SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_DEPTH );    // ��ʂ̉𑜓x(��,����)�ƐF��(32bit)���w��

	DxLib_Init();    // Dx���C�u����������

	SetDrawScreen( DX_SCREEN_BACK );    // �`����ʂ𗠂ɂ���
	SetMouseDispFlag( FALSE );//�J�[�\����\��

	ResourceServer::Init();	//���\�[�X�T�[�o������

	auto game = std::make_unique<Game>();

	// ���C�����[�v
	// Windows ���L�̖ʓ|�ȏ��������C�u�����ɂ�点��
	// -1 ���Ԃ��Ă����烋�[�v�𔲂���
	while ( (ProcessMessage() != -1) )
	{
		// �Q�[���̏���
		game->Input();   // ����
		game->Update();   // �X�V
		game->Draw();   // �`��

	}

	ResourceServer::Release();	//���\�[�X�T�[�o���

	// Dx���C�u�����I��
	DxLib_End();

	return 0;
}