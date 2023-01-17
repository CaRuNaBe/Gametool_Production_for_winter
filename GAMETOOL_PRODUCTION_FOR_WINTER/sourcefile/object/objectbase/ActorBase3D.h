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


	// 座標の設定
	void SetPosition(const vector4& pos) { _vPos = pos; }
	void SetPosition(float x, float y, float z) { _vPos.x = x; _vPos.y = y; _vPos.z = z; }
	// 向きベクトルの設定
	void SetDir(const vector4& dir) { _vDir = dir; }
	void SetDir(float x, float y, float z) { _vDir.x = x; _vDir.y = y; _vDir.z = z; }

public:
	vector4 _vPos;   // 位置
	vector4 _vEvent;   // イベント位置
	vector4 _vDir;   // 向き



	float _speed;   // 速度
	bool  _overlap;   // 判定が重なったか
	bool  _event;   // イベント判定と重なったか

	int _cnt;  // 動作カウント
	int _CT;   // クールタイム
	int _ST;   // 生存時間
};