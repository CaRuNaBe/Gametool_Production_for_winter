#pragma once
#include"../Math/math.h"
#include "objectbase/ActorBase3D.h"
#include"../game.h"
using namespace math;

// �J����
class Camera {
public:
	vector4	_vPos;					// �ʒu
	vector4	_vTarget;				// ����
	float	_clipNear, _clipFar;	// �N���b�v
};

class Player : public ActorBase3D {
	typedef ActorBase3D base;
public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual bool Update(Game& game, ModeBase& mode);
	virtual bool Draw( Game& game, ModeBase& mode);

	void CameraUpdate( Game& game);    // �J�����X�V

protected:
	// �J����
	Camera	_cam;

	float  _speed;
	float  _rotatX;
	float  _rotatY;
	int    _handle;
	int    _cg;

};
