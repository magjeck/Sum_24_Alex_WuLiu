#include "pch.h"
#include "Map.h"

namespace Farming
{
	void Map::LoadBackgroundImage(const std::string& fileName)
	{
		mBackground.LoadImage(fileName);

		mPassable.resize(mBackground.GetHeight());
		for (auto& row : mPassable)
		{
			row.resize(mBackground.GetWidth(), true);
		}
	}

	void Map::LoadBackgroundImage(std::string&& fileName)
	{
		mBackground.LoadImage(std::move(fileName));

		mPassable.resize(mBackground.GetHeight());
		for (auto& row : mPassable)
		{
			row.resize(mBackground.GetWidth(), true);
		}
	}

	void Map::LoadMapPassability(std::vector<std::vector<bool>> pixelPassability)
	{
		if(pixelPassability.size() != mBackground.GetHeight() || pixelPassability[0].size() != mBackground.GetWidth() || pixelPassability.size() == 0)
		{
			FARMING_ERROR("ERROR: ");
		}

		mPassable = std::move(pixelPassability);
	}

	void Map::LoadPixelPassability(Coordinates coords, bool isPassable)
	{
		if (coords.x >= mBackground.GetWidth() || coords.y >= mBackground.GetHeight())
		{
			FARMING_ERROR("ERROR: LoadPixelPassability got out of range coordinates!!!")
			return;
		}

		mPassable[coords.y][coords.x] = isPassable;
	}

	bool Map::GetPixelPassability(Coordinates coords) const
	{
		if (coords.y >= mPassable.size() || coords.x >= mPassable[0].size())
			return false;
		return mPassable[coords.y][coords.x];
	}

	int Map::GetWidth() const
	{
		return mBackground.GetWidth();
	}

	int Map::GetHeight() const
	{
		return mBackground.GetHeight();
	}

}