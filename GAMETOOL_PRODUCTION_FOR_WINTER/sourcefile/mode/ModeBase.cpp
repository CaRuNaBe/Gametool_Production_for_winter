/*
** ModeBase
*/

#include "ModeBase.h"

ModeBase::ModeBase(Game& game, int layer)
	: _game(game)
	,_dead(false)
	,_isModeSkip(false)
	,_isDrawSkip(false)
	,_layer(layer)
{}

ModeBase::~ModeBase()
{}

bool ModeBase::Initialize()
{
	return true;
};
// XV
bool ModeBase::Update(  )
{
	return true;
}

// •`‰æ
bool ModeBase::Draw( )
{
	return true;
}
