
#include "ActorBase3D.h"

ActorBase3D::ActorBase3D()
	:base()
{
	Init();
}

ActorBase3D::~ActorBase3D()
{}

void ActorBase3D::Init()
{
	base::Init();
	_vPos = {0.f, 0.f ,0.f};
	_vEvent = {0.f, 0.f ,0.f};
	_vDir = {0.f, 0.f ,0.f};

	_speed = 0.f;
	_overlap = false;
	_event = false;
	_cnt = 0;
	_ST = 0;

}

bool ActorBase3D::Update( Game& game,ModeBase& mode )
{
	base::Update( game,mode );

	_overlap = false;
	_event = false;

	_cnt++;
	if ( _CT > 0 )
	{
		_CT--;
	}
	if ( _ST > 0 )
	{
		_ST--;
	}
	return true;
}



bool ActorBase3D::Draw( Game& game,ModeBase& mode )
{
	base::Draw( game,mode );

	return true;
}

