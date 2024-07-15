#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Image.h"

namespace Farming
{
	struct FARMING_API Coordinates
	{
		int x{ 0 };
		int y{ 0 };

		Coordinates();
		Coordinates(int xVal, int yVal);
	};

	struct FARMING_API Speed
	{
		int xSpeed{ 0 };
		int ySpeed{ 0 };

		Speed();
		Speed(int xComponent, int yComponent);
	};


	class FARMING_API Unit
	{
	public:
		Unit(const std::string& fileName, Coordinates newCoordinates);
		Unit(std::string&& fileName, Coordinates newCoordinates);

		void SetCoordinates(Coordinates newCoord);
		Coordinates GetCoordinates() const;

		void LoadSprite(const std::string& fileName);
		void LoadSprite(std::string&& fileName);

		bool OverlapsWith(const Unit& other) const;

		void UpdateXBy(int amount);
		void UpdateYBy(int amount);

		int GetWidth() const;
		int GetHeight() const;

		Speed GetSpeed() const;
		void SetSpeed(Speed newSpeed);
		void UpdateSpeed(int xChange, int yChange);

		void SetIsInteract();
		void SetNoInteract();
		bool GetIsInteract();


		void SetCounter(int num);
		void UpdateCounter(int num);
		int GetCounter() const;

		bool IsVisible() const;
		void SetVisible();
		void SetInvisible();

		friend class Renderer;

	private:
		Coordinates mCoords;
		Image mSprite;
		bool mIsVisible{ true };
		Speed mSpeed;
		int mCounter = 0;
		bool IsInteract{ true };
	};
}