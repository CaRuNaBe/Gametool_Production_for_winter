/*
** ObjectBase
*/

#include "DxLib.h"
#include "ObjectBase.h"
#include "../../mode/ModeBase.h"
ObjectBase::ObjectBase()
	:isUpdateSkip(false)
	,isDrawSkip(false)
{
	Init();
}

ObjectBase::~ObjectBase()
{}

void ObjectBase::Init()
{
	// 情報の初期化
	_dead = false;
}

bool ObjectBase::Update( Game& game,ModeBase& mode )
{
	return true;
}

bool ObjectBase::Draw( Game& game,ModeBase& mode )
{
	return true;
}

