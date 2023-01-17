#include "SkySphere.h"
SkySphere::SkySphere()
	:base()
{
	_handle = MV1LoadModel( "res/stage/skysphere/cg_stageSkymap_1.mv1" );

	Init();
}

SkySphere::~SkySphere()
{

}

void SkySphere::Init()
{
	base::Init();


}

bool SkySphere::Update( Game& game,ModeBase& mode )
{
	base::Update( game,mode );



	return true;
}

bool SkySphere::Draw( Game& game,ModeBase& mode )
{
	base::Draw( game,mode );
	MV1SetScale( _handle,VGet( 40.0f,40.0f,40.0f ) );
	MV1DrawModel( _handle );
	return true;
}
