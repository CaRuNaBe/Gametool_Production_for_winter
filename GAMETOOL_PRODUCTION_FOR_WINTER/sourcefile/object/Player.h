#pragma once
#include"../Math/math.h"
#include "objectbase/ActorBase3D.h"
#include"../game.h"
using namespace math;

// カメラ
class Camera {
public:
	vector4	_vPos;					// 位置
	vector4	_vTarget;				// 距離
	float	_clipNear, _clipFar;	// クリップ
};

class Player : public ActorBase3D {
	typedef ActorBase3D base;
public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual bool Update(Game& game, ModeBase& mode);
	virtual bool Draw( Game& game, ModeBase& mode);

	void CameraUpdate( Game& game);    // カメラ更新

protected:
	// カメラ
	Camera	_cam;

	float  _speed;
	float  _rotatX;
	float  _rotatY;
	int    _handle;
	int    _cg;

};
