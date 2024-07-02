#include "Farming.h"
#include <iostream>

class BestGame : public Farming::FarmingApp
{
public:
	virtual void OnUpdate() override
	{
		Farming::Renderer::Get()->Draw(pic, x, 200);
		x += 1;
	}

private:
	Farming::Image pic{ "../Farming/Assets/Images/Sun.png" };

	int x{ 100 };
};

GAME_FARMING_START(BestGame);