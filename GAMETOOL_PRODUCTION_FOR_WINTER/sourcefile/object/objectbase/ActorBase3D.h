#pragma once

#include "../Math/math.h"
#include "ObjectBase.h"
using namespace math;
class ActorBase3D : public ObjectBase {
	typedef ObjectBase base;
public:
	ActorBase3D();
	virtual ~ActorBase3D();


	virtual void Init();
	virtual bool Update( Game& game, ModeBase& mode);

	virtual bool Draw( Game& game, ModeBase& mode);




	virtual void Damage(ModeBase& mode) {}


	// ���W�̐ݒ�
	void SetPosition(const vector4& pos) { _vPos = pos; }
	void SetPosition(float x, float y, float z) { _vPos.x = x; _vPos.y = y; _vPos.z = z; }
	// �����x�N�g���̐ݒ�
	void SetDir(const vector4& dir) { _vDir = dir; }
	void SetDir(float x, float y, float z) { _vDir.x = x; _vDir.y = y; _vDir.z = z; }

public:
	vector4 _vPos;   // �ʒu
	vector4 _vEvent;   // �C�x���g�ʒu
	vector4 _vDir;   // ����



	float _speed;   // ���x
	bool  _overlap;   // ���肪�d�Ȃ�����
	bool  _event;   // �C�x���g����Əd�Ȃ�����

	int _cnt;  // ����J�E���g
	int _CT;   // �N�[���^�C��
	int _ST;   // ��������
};