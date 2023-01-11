/*****************************************************************//**
 * \file   ResourceServer.h
 * \brief ���\�[�X�̊Ǘ���`
 * ���ׂĐÓI�����o�ō\������
 *
 * \author ����搶
 * \date   July 2022
 *********************************************************************/
#pragma once
#include	<unordered_map>
#include<string>
class ResourceServer
{
public:
	static	 void	Init();//������
	static void	Release();//�J��

	static 	void	 ClearGraph();						// ���ׂẲ摜���N���A����
	static 	int FindGraph( std::string filename );	// �t�@�C��������摜��T���B�ǂݍ���ł��Ȃ����-1
	static 	int 	LoadGraph( std::string fileName );	// �t�@�C��������摜��ǂݍ��ށB
	static	void	ClearSound();						// ���ׂẴT�E���h���N���A����
	static	int FindSound( std::string filename );	// �t�@�C��������T�E���h��T���B�ǂݍ���ł��Ȃ����-1
	static	int		LoadSoundMem( std::string FileName );	// �t�@�C��������T�E���h��ǂݍ��ށB

private:
	// unorderd_map�͕�����Ȃǂ��L�[�ɂł���R���e�i�B
	// �t�@�C�������L�[�ɂ��āA���łɓǂݍ���ł��邩���m�F����
	static std::unordered_map<std::string,int>	_mapGraph;
	static std::unordered_map<std::string,int>	_mapSound;
};
