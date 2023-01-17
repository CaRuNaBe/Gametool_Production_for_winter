#include "SupplyEria.h"
SupplyEria::SupplyEria()
	:base()
{


	Init();
}

SupplyEria::~SupplyEria()
{

}

void SupplyEria::Init()
{
	base::Init();


}

bool SupplyEria::Update( Game& game,ModeBase& mode )
{
	base::Update( game,mode );



	return true;
}

bool SupplyEria::Draw( Game& game,ModeBase& mode )
{
	base::Draw( game,mode );
	return true;
}
