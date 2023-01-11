#include <memory>
#include <stdio.h>
#include <time.h>
#include "DxLib.h"
#include"Game.h"
#include "ResourceServer.h"

// �v���O������WinMain ����n�܂�܂�
int WINAPI WinMain( _In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nCmdShow )
{
	ChangeWindowMode( TRUE );    // �E�C���h�E���[�h�ɕύX
	SetGraphMode( SCREEN_W,SCREEN_H,SCREEN_DEPTH );    // ��ʂ̉𑜓x(��,����)�ƐF��(32bit)���w��
	DxLib_Init();    // Dx���C�u����������
	SetDrawScreen( DX_SCREEN_BACK );    // �`����ʂ𗠂ɂ���
	SetMouseDispFlag( FALSE );//�J�[�\����\��

	ResourceServer::Init();	//���\�[�X�T�[�o������

	auto game = std::make_unique<Game>();

	// ���C�����[�v
	// Windows ���L�̖ʓ|�ȏ��������C�u�����ɂ�点��
	// -1 ���Ԃ��Ă����烋�[�v�𔲂���
	while ( ProcessMessage() != -1 )
	{
		// �Q�[���̏���
		game->Input();   // ����
		game->Update();   // �X�V
		game->Render();   // �`��
		if ( ProcessMessage() == -1 ) break;                 //�G���[���N������I��
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) )//�G�X�P�[�v�L�[�ŃQ�[���I��
		{
			break;
		}
	}
	ResourceServer::Release();	//���\�[�X�T�[�o���

	// Dx���C�u�����I��
	DxLib_End();

	return 0;
}