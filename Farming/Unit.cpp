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




	Unit::Unit(const std::string& fileName, Coordinates newCoordinates) : mCoords(newCoordinates)
	{
		LoadSprite(fileName);
	}

	Unit::Unit(std::string&& fileName, Coordinates newCoordinates) : mCoords(newCoordinates)
	{
		LoadSprite(std::move(fileName));
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
			(mCoords.x >= other.mCoords.x && mCoords.x <= other.mCoords.x + other.GetWidth()) ||
			(mCoords.x <= other.mCoords.x && other.mCoords.x <= mCoords.x + GetWidth())
		};

		bool overlapsOnY{ 
			(mCoords.y >= other.mCoords.y && mCoords.y <= other.mCoords.y + other.GetHeight()) ||
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

	Speed Unit::GetSpeed() const
	{
		return mSpeed;
	}

	void Unit::SetSpeed(Speed newSpeed)
	{
		mSpeed = newSpeed;
	}

	void Unit::UpdateSpeed(int xChange, int yChange)
	{
		mSpeed.xSpeed += xChange;
		mSpeed.ySpeed += yChange;
	}

	void Unit::SetIsInteract()
	{
		IsInteract = 1;
	}

	void Unit::SetNoInteract()
	{
		IsInteract = 0;
	}

	bool Unit::GetIsInteract()
	{
		return IsInteract;
	}

	void Unit::SetCounter(int num)
	{
		mCounter = num;
	}

	void Unit::UpdateCounter(int num)
	{
		mCounter = mCounter + num;
	}

	int Unit::GetCounter() const
	{
		return mCounter;
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

	Speed::Speed()
	{
	}

	Speed::Speed(int xComponent, int yComponent) : xSpeed(xComponent), ySpeed(yComponent)
	{
	}

}