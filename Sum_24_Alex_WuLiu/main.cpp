#include "Farming.h"
#include <iostream>

class BestGame : public Farming::FarmingApp
{
public:
	BestGame()
	{
		SetKeyPressedCallback([this](const Farming::KeyPressedEvent& key) {
			MyKeyPressedCallback(key);
			});
	}



	virtual void OnUpdate() override
	{
		Farming::Renderer::Get()->Draw(pic, x, y);
	}

private:
	Farming::Image pic{ "../Farming/Assets/Images/Sun.png" };

	int x{ 100 };
	int y{ 200 };

	void MyKeyPressedCallback(const Farming::KeyPressedEvent& key) {
		if (key.GetKey() == FARMING_KEY_RIGHT)
		{
			x += 40;
			if (x > 800)
			{
				x = 800;
			}
		}
			
		if (key.GetKey() == FARMING_KEY_LEFT)
		{
			x -= 40;
			if (x < 0)
			{
				x = 0;
			}
		}

		if (key.GetKey() == FARMING_KEY_UP)
		{
			y += 40;
			
			if (y > 1000)
			{
				y = 1000;
			}
		}

		if (key.GetKey() == FARMING_KEY_DOWN)
		{
			y -= 40;

			if (y < 0)
			{
				y = 0;
			}
		}
	}
};

GAME_FARMING_START(BestGame);