#pragma once

#include "../Math/math.h"
#include "ObjectBase.h"
using namespace math;
class ActorBase3D : public ObjectBase {
	typedef ObjectBase base;
public:
	ActorBase3D();
	virtual ~ActorBase3D();

	enum class Type {  // 種別の列挙型
		kBase,     // 0 アクター
		kPlayer,   // 1 プレイヤー
		kBullet,   // 2 弾丸
		kEnemyAAA, // 3 対空砲
	};
	virtual Type GetType() = 0;

	virtual void Init();
	virtual bool Update(ApplicationBase& game, ModeBase& mode);
	virtual bool Draw(ApplicationBase& game, ModeBase& mode);

	virtual void Damage(ModeBase& mode) {}


public:


	float _speed;

	int _cnt;  // 動作カウント
	int _ST;   // 生存時間
};