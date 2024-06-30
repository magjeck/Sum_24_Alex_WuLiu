#include "Farming.h"
#include <iostream>

class BestGame : public Farming::FarmingApp
{
	virtual void OnUpdate() override
	{
		FARMING_LOG("Running" << "\n");
	}
};

GAME_FARMING_START(BestGame);