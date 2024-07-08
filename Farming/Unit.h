#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Image.h"
#include "Renderer.h"

namespace Farming
{
	struct FARMING_API Coordinates
	{
		int x{ 0 };
		int y{ 0 };

		Coordinates();
		Coordinates(int xVal, int yVal);
	};


	class FARMING_API Unit
	{
	public:
		void SetCoordinates(Coordinates newCoord);
		Coordinates GetCoordinates() const;

		void LoadSprite(const std::string& fileName);
		void LoadSprite(std::string&& fileName);

		bool OverlapsWith(const Unit& other) const;

		void UpdateXBy(int amount);
		void UpdateYBy(int amount);

		int GetWidth() const;
		int GetHeight() const;

		bool IsVisible() const;
		void SetVisible();
		void SetInvisible();

		friend class Renderer;

	private:
		Coordinates mCoords;
		Image mSprite;
		bool mIsVisible{ true };
	};
}