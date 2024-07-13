#pragma once

#include "pch.h"
#include "Utilities.h"
#include "RendererImplementation.h"
#include "Image.h"
#include "Shaders.h"
#include "Unit.h"
#include "Map.h"

namespace Farming
{
	class FARMING_API Renderer
	{
	public:
		static void Init();
		static std::shared_ptr<Renderer> Get();

		void Draw(Image &pic, int xCoord, int yCoord, Shaders& shaders);
		void Draw(Image& pic, int xCoord, int yCoord);
		void Draw(Unit& unit, Shaders& shaders);
		void Draw(Unit& unit);
		void Draw(Map& map, Shaders& shaders);
		void Draw(Map& map);
		void ClearScreen();


	private:
		std::unique_ptr<RendererImplementation> mImplementation;

		inline static std::shared_ptr<Renderer> mInstance;
		Renderer();
	};
}