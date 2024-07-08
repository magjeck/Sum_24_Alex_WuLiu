#include "pch.h"
#include "Unit.h"

namespace Farming
{
	Farming::Coordinates::Coordinates() : x(0), y(0)
	{
	}

	Coordinates::Coordinates(int xVal, int yVal) : x(xVal), y(yVal)
	{
	}


	void Unit::SetCoordinates(Coordinates newCoord)
	{
		mCoords = newCoord;
	}

	Coordinates Unit::GetCoordinates() const
	{
		return mCoords;
	}

	void Unit::LoadSprite(const std::string& fileName)
	{
		mSprite.LoadImage(fileName);
	}

	void Unit::LoadSprite(std::string&& fileName)
	{
		mSprite.LoadImage(std::move(fileName));
	}

	bool Unit::OverlapsWith(const Unit& other) const
	{
		bool overlapsOnX{
			(mCoords.x >= other.mCoords.x && mCoords.x <= other.mCoords.x + other.GetWidth()) or
			(mCoords.x <= other.mCoords.x && other.mCoords.x <= mCoords.x + GetWidth())
		};

		bool overlapsOnY{ 
			(mCoords.y >= other.mCoords.y && mCoords.y <= other.mCoords.y + other.GetHeight()) or
			(mCoords.y <= other.mCoords.y && other.mCoords.y <= mCoords.y + GetHeight()) 
		};

		return overlapsOnX && overlapsOnY;
	}

	void Unit::UpdateXBy(int amount)
	{
		mCoords.x += amount;
	}

	void Unit::UpdateYBy(int amount)
	{
		mCoords.y += amount;
	}

	int Unit::GetWidth() const
	{
		return mSprite.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mSprite.GetHeight();
	}

	bool Unit::IsVisible() const
	{
		return mIsVisible;
	}

	void Unit::SetVisible()
	{
		mIsVisible = true;
	}

	void Unit::SetInvisible()
	{
		mIsVisible = false;
	}

}