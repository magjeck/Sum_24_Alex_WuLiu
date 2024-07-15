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

		
		/*map.LoadBackgroundImage("../Farming/Assets/Images/Background.png");
		std::vector<std::vector<bool>> util;
		for (int i = 0; i < 118; i++)
			util.push_back(std::vector<bool>(1000, false));
		for (int i = 0; i < 628; i++)
			util.push_back(std::vector<bool>(1000, true));
		map.LoadPixelPassability(util);
		*/

		
	}



	virtual void OnUpdate() override
	{
		map.LoadBackgroundImage("../Farming/Assets/Images/Grass.png");

		
		Farming::Renderer::Get()->Draw(map);

		Farming::Renderer::Get()->Draw(house);

		Farming::Renderer::Get()->Draw(Plot1);
		Farming::Renderer::Get()->Draw(Plot2);
		Farming::Renderer::Get()->Draw(Plot3);
		Farming::Renderer::Get()->Draw(Plot4);

		Farming::Renderer::Get()->Draw(Box1);
		Farming::Renderer::Get()->Draw(Box2);
		Farming::Renderer::Get()->Draw(Box3);
		Farming::Renderer::Get()->Draw(Box4);


		if (Box1.GetIsInteract())
		{
			Farming::Renderer::Get()->Draw(Text1);
		}

		if (Box2.GetIsInteract())
		{
			Farming::Renderer::Get()->Draw(Text2);
		}
	
		if (Box3.GetIsInteract())
		{
			Farming::Renderer::Get()->Draw(Text3);
		}

		if (Box4.GetIsInteract())
		{
			Farming::Renderer::Get()->Draw(Text4);
		}


		if (farmer.OverlapsWith(Box1) && Box1.GetIsInteract())
		{
			Box1.SetNoInteract();
			farmer.UpdateCounter(1);
		}
		else if (farmer.OverlapsWith(Box2) && Box2.GetIsInteract())
		{
			Box2.SetNoInteract();
			farmer.UpdateCounter(1);
		}
		else if (farmer.OverlapsWith(Box3) && Box3.GetIsInteract())
		{
			Box3.SetNoInteract();
			farmer.UpdateCounter(1);
		}
		else if (farmer.OverlapsWith(Box4) && Box4.GetIsInteract())
		{
			Box4.SetNoInteract();
			farmer.UpdateCounter(1);
		}


		if (farmer.GetCounter() == 4)
		{
			Farming::Renderer::Get()->Draw(Sleep);
		}

		if (farmer.GetCounter() == 4 && farmer.OverlapsWith(house))
		{
			farmer.SetCounter(0);
			Box1.SetIsInteract();
			Box2.SetIsInteract();
			Box3.SetIsInteract();
			Box4.SetIsInteract();
		}

		Farming::Renderer::Get()->Draw(farmer);
		
		
	}

private:
	// x -> 0 to 950 (Left to Right)
	// y -> 0 to 750 (Down to Up)
	Farming::Map map;

	Farming::Unit farmer{ "../Farming/Assets/Images/Farmer.png", {475, 650} };

	Farming::Unit house{ "../Farming/Assets/Images/House.png", {425, 650} };

	Farming::Unit Box1{ "../Farming/Assets/Images/Box.png", {625, 250} };
	Farming::Unit Box2{ "../Farming/Assets/Images/Box.png", {300, 250} };
	Farming::Unit Box3{ "../Farming/Assets/Images/Box.png", {625, 500} };
	Farming::Unit Box4{ "../Farming/Assets/Images/Box.png", {300, 500} };

	Farming::Unit Plot1{ "../Farming/Assets/Images/Garden_Plot.png", {700, 225} };
	Farming::Unit Plot2{ "../Farming/Assets/Images/Garden_Plot.png", {150, 225} };
	Farming::Unit Plot3{ "../Farming/Assets/Images/Garden_Plot.png", {700, 475} };
	Farming::Unit Plot4{ "../Farming/Assets/Images/Garden_Plot.png", {150, 475} };

	Farming::Unit Text1{ "../Farming/Assets/Images/Box1.png", {625, 325} };
	Farming::Unit Text2{ "../Farming/Assets/Images/Box2.png", {300, 325} };
	Farming::Unit Text3{ "../Farming/Assets/Images/Box3.png", {625, 575} };
	Farming::Unit Text4{ "../Farming/Assets/Images/Box4.png", {300, 575} };

	Farming::Unit Sleep{ "../Farming/Assets/Images/HouseSleep.png", {475, 750} };




	void MyKeyPressedCallback(const Farming::KeyPressedEvent& key) {
		if (key.GetKey() == FARMING_KEY_RIGHT)
		{
			farmer.UpdateXBy(25);
			if (farmer.GetCoordinates().x > 950)
			{
				farmer.SetCoordinates({ 950, farmer.GetCoordinates().y });
			}
		}	
		else if (key.GetKey() == FARMING_KEY_LEFT)
		{
			farmer.UpdateXBy(-25);
			if (farmer.GetCoordinates().x < 0)
			{
				farmer.SetCoordinates({ 0, farmer.GetCoordinates().y });
			}
		}
		else if (key.GetKey() == FARMING_KEY_UP)
		{
			farmer.UpdateYBy(25);
			if (farmer.GetCoordinates().y > 750)
			{
				farmer.SetCoordinates({ farmer.GetCoordinates().x, 750 });
			}
		}
		else if (key.GetKey() == FARMING_KEY_DOWN)
		{
			farmer.UpdateYBy(-25);
			if (farmer.GetCoordinates().y < 0)
			{
				farmer.SetCoordinates({ farmer.GetCoordinates().x, 0 });
			}
		}
	}

	void MyKeyReleasedCallback(const Farming::KeyReleasedEvent& key)
	{

	}
};

GAME_FARMING_START(BestGame);