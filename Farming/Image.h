#pragma once

#include "pch.h"
#include "Utilities.h"
#include "ImageImplementation.h"

namespace Farming
{
	class FARMING_API Image
	{
	public:
		Image(const std::string& fileName);
		Image(std::string&& fileName);
		Image();

		void LoadImage(const std::string& fileName);
		void LoadImage(std::string&& fileName);

		void Bind();
		int GetWidth() const;
		int GetHeight() const;

	private:
		std::unique_ptr<ImageImplementation> mImplementation;
	};
}