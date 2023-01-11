/*****************************************************************//**
 * \file   ResourceServer.cpp
 * \brief  ���\�[�X�Ǘ��N���X����
 *
 * \author ����搶
 * \date   August 2022
 *********************************************************************/

#include "DxLib.h"
#include "resourceserver.h"

// �ÓI�����o����
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

// ���ׂẴf�[�^�̍폜������
void	 ResourceServer::ClearGraph ()
{
	for ( auto&& graph : _mapGraph )
	{
		DeleteGraph ( graph.second );      // unorderd_map�� graph.first �̓L�[�A graph.second �͒l
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

// �L�[����������
int     ResourceServer::FindGraph ( std::string filename )
{
	auto itr = _mapGraph.find ( filename );    // map::find() �̓L�[�Ńf�[�^�����邩�T���B�����ꍇ�Amap::end()���Ԃ�
	if ( itr != _mapGraph.end () )
	{
// �L�[���������Bsecond���l
		return itr->second;
	}
	// �L�[���Ȃ�����
	return -1;
}

int		ResourceServer::LoadGraph ( std::string filename )
{
	int cg = FindGraph ( filename );    // ���łɓǂݍ��ݍςȂ�Acg��-1�ȊO�̒l���Ԃ�B
	if ( cg == -1 )
	{
// �L�[���Ȃ������̂œǂݍ���
		cg = ::LoadGraph ( filename.c_str () );     // DXLIB��API���ĂԂ̂ŁA::��擪�ɕt���A���̃N���X�̓������O�̊֐��Ƌ�ʂ���
		// �L�[�ƃf�[�^��map�ɓo�^
		_mapGraph [ filename ] = cg;
	}
	return cg;
}

// �L�[����������
int     ResourceServer::FindSound ( std::string filename )
{
	auto itr = _mapSound.find ( filename );    // map::find() �̓L�[�Ńf�[�^�����邩�T���B�����ꍇ�Amap::end()���Ԃ�
	if ( itr != _mapSound.end () )
	{
// �L�[���������Bsecond���l
		return itr->second;
	}
	// �L�[���Ȃ�����
	return -1;
}

int		ResourceServer::LoadSoundMem ( std::string filename )
{
	int sound = FindSound ( filename );    // ���łɓǂݍ��ݍςȂ�Asound��-1�ȊO�̒l���Ԃ�B
	if ( sound == -1 )
	{
// �L�[���Ȃ������̂œǂݍ���
		sound = ::LoadSoundMem ( filename.c_str () );     // DXLIB��API���ĂԂ̂ŁA::��擪�ɕt���A���̃N���X�̓������O�̊֐��Ƌ�ʂ���
		// �L�[�ƃf�[�^��map�ɓo�^
		_mapSound [ filename ] = sound;
	}
	return sound;
}