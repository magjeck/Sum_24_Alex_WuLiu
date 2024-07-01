#pragma once

#include "../../RendererImplementation.h"
#include "Thirdparty/codeOpenGL/ShadersOpenGL.h"

namespace Farming
{
	class RendererOpenGL : public RendererImplementation
	{
	public:
		RendererOpenGL();
		~RendererOpenGL();

		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders) override;
		virtual void Draw(Image& pic, int xCoord, int yCoord) override;
		virtual void ClearScreen() override;

	private:
		ShadersOpenGL mDefaultShaders;
	};
}