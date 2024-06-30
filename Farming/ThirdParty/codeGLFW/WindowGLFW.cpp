#include "pch.h"

#include "WindowGLFW.h"
#include "Utilities.h"

namespace Farming
{
	void WindowGLFW::CreateWindow(int width, int height, const std::string& windowName)
	{
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (mWindow == NULL)
		{
			FARMING_ERROR("ERROR: Window failed to create!!!")
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);
	}

	void WindowGLFW::CreateWindow(int width, int height, std::string&& windowName)
	{
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (mWindow == NULL)
		{
			FARMING_ERROR("ERROR: Window failed to create!!!")
				glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);
	}

	int WindowGLFW::GetWidth() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int WindowGLFW::GetHeight() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}


	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwTerminate();
	}
}