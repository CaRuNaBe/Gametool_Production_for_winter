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
	// _vPendingModes -> _vModes �ɒǉ�
	_vModes.insert(
		_vModes.end(),
		make_move_iterator( _vPendingModes.begin() ),
		make_move_iterator( _vPendingModes.end() )
	);
	// _vPendingModes ���N���A
	_vPendingModes.clear();
}

void	ModeServer::Del( ModeBase& mode )
{
	mode.Dead();
}

void	ModeServer::DeleteModes()
{
	// �R���e�i���C�e���[�^�ŉ�( erase���C�e���[�^��v�����Ă��邽�� )
	for ( auto ite = _vModes.begin(); ite != _vModes.end(); )
	{
		if ( (*ite)->IsDead() )
		{
			ite = _vModes.erase( ite );		// �����object���̂��̂��폜�����
		}
		else
		{
			++ite;
		}
	}

}
// �X�V������
bool ModeServer::UpdateInit()
{
	return true;
}
// �X�V
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

	// ���C���[�ɂ��\�[�g
	std::sort( _vModes.begin(),_vModes.end(),[]( const ModeBasePtr ch1,const ModeBasePtr ch2 )
	{
		return ch1->GetLayer() < ch2->GetLayer();
	} );

	_updating = false;
	AddPendingModes();
	DeleteModes();	// �폜�\�񂳂ꂽ�I�u�W�F�N�g���폜����
	return true;
}
// �㏈��
bool ModeServer::UpdateFinish()
{
	return true;
}
// �`�揉����
bool ModeServer::DrawInit()
{
	ClearDrawScreen();		// ��ʂ�����������
	return true;
}
// �`��
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
// �`��㏈��
bool ModeServer::DrawFinish()
{
	ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f������
	return true;
}