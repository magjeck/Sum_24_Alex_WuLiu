#include "Farming.h"
#include <iostream>
#include <vector>

class BestGame : public Farming::FarmingApp
{
public:
	BestGame()
	{
		SetKeyPressedCallback([this](const Farming::KeyPressedEvent& key) {
			MyKeyPressedCallback(key);
			});

		SetKeyReleasedCallback([this](const Farming::KeyReleasedEvent& key) {
			MyKeyReleasedCallback(key);
			});

		
		/*map.LoadBackgroundImage("../Farming/Assets/Images/Background.png");
		std::vector<std::vector<bool>> util;
		for (int i = 0; i < 118; i++)
			util.push_back(std::vector<bool>(1000, false));
		for (int i = 0; i < 628; i++)
			util.push_back(std::vector<bool>(1000, true));
		map.LoadPixelPassability(util);
		*/

		unit.SetSpeed({ 10, -10 });
	}



	virtual void OnUpdate() override
	{
		
		Farming::Renderer::Get()->Draw(unit);
		// Farming::Renderer::Get()->Draw(map);
	}

private:
	Farming::Unit unit{ "../Farming/Assets/Images/Sun.png", {300, 400 } }; // How to move Unit class
	// (If map class works) With map class not moving at all



	// If unit and map classes doesn't work on move,  HOW do I get Image background to not move while Image farmer can move?

	//Farming::Image background{ "../Farming/Assets/Background.png" };
	//Farming::Image farmer{ " ../Farming/Assets/Farmer.png" };

	int x = unit.GetCoordinates().x;
	int y = unit.GetCoordinates().y;



	//Farming::Map map;
	//Farming::Physics physics;

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

		unit.SetCoordinates({ x, y });
	}

	void MyKeyReleasedCallback(const Farming::KeyReleasedEvent& key)
	{

	}
};

GAME_FARMING_START(BestGame);