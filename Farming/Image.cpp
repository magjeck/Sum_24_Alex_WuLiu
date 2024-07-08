#include "pch.h"

#include "Image.h"
#include "ThirdParty/codeOpenGL/ImageOpenGL.h"

namespace Farming
{
	Image::Image(const std::string& fileName)
	{
#ifdef FARMING_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>( fileName );
#else
		#ERROR_FARMING_OPENGL_ISNT_DEFINED
#endif
	}

	Image::Image(std::string&& fileName)
	{
#ifdef FARMING_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>( std::move(fileName) );
#else
		#ERROR_FARMING_OPENGL_ISNT_DEFINED
#endif
	}

	Image::Image()
	{
#ifdef FARMING_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>();
#else
		#ERROR_FARMING_OPENGL_ISNT_DEFINED
#endif
	}

	void Image::LoadImage(const std::string& fileName)
	{
		mImplementation->LoadImage(fileName);
	}

	void Image::LoadImage(std::string&& fileName)
	{
		mImplementation->LoadImage(std::move(fileName));
	}

	void Image::Bind()
	{
		mImplementation->Bind();
	}

	int Image::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Image::GetHeight() const
	{
		return mImplementation->GetHeight();
	}


}