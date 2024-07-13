#include "pch.h"
#include "Renderer.h"
#include "ThirdParty/codeOpenGL/RendererOpenGL.h"
#include "FarmingWindow.h"

namespace Farming
{
	void Renderer::Init()
	{
		mInstance = std::shared_ptr<Renderer>{ new Renderer };
	}

	std::shared_ptr<Renderer> Renderer::Get()
	{
		return mInstance;
	}

	void Renderer::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
	{
		mImplementation->Draw(pic, xCoord, yCoord, shaders);
	}

	void Renderer::Draw(Image& pic, int xCoord, int yCoord)
	{
		//mDefaultShaders.SetUniform2Ints(
		//	"ScreenSize", 
		//	FarmingWindow::GetWindow()->GetWidth(), 
		//	FarmingWindow::GetWindow()->GetHeight());
		mImplementation->Draw(pic, xCoord, yCoord);
	}

	void Renderer::Draw(Unit& unit, Shaders& shaders)
	{
		if(unit.IsVisible())
			mImplementation->Draw(unit.mSprite, unit.mCoords.x, unit.mCoords.y, shaders);
	}

	void Renderer::Draw(Unit& unit)
	{
		if(unit.IsVisible())
			mImplementation->Draw(unit.mSprite, unit.mCoords.x, unit.mCoords.y);
	}

	void Renderer::Draw(Map& map, Shaders& shaders)
	{
		mImplementation->Draw(map.mBackground, 0, 0, shaders);
	}

	void Renderer::Draw(Map& map)
	{
		mImplementation->Draw(map.mBackground, 0, 0);
	}

	void Renderer::ClearScreen()
	{
		mImplementation->ClearScreen();
	}

	Renderer::Renderer()
	{
#ifdef FARMING_OPENGL
		mImplementation = std::make_unique<RendererOpenGL>();
#else
		#ERROR_FARMING_OPENGL_ISNT_DEFINED
#endif
	}

}