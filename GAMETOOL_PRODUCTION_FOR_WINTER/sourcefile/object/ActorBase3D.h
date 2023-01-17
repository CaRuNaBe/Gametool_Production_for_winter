#pragma once

#include "../Math/math.h"
#include "ObjectBase.h"
using namespace math;
class ActorBase3D : public ObjectBase {
	typedef ObjectBase base;
public:
	ActorBase3D();
	virtual ~ActorBase3D();

	enum class Type {  // ��ʂ̗񋓌^
		kBase,     // 0 �A�N�^�[
		kPlayer,   // 1 �v���C���[
		kBullet,   // 2 �e��
		kEnemyAAA, // 3 �΋�C
	};
	virtual Type GetType() = 0;

	virtual void Init();
	virtual bool Update(ApplicationBase& game, ModeBase& mode);
	virtual bool Draw(ApplicationBase& game, ModeBase& mode);

	virtual void Damage(ModeBase& mode) {}


public:


	float _speed;

	int _cnt;  // ����J�E���g
	int _ST;   // ��������
};