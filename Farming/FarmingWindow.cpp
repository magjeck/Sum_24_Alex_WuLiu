#include "pch.h"

#include "FarmingWindow.h"
#include "ThirdParty/codeGLFW/WindowGLFW.h"

namespace Farming
{
	FarmingWindow::FarmingWindow()
	{
#ifdef FARMING_GLFW
		mImplementation = std::unique_ptr<WindowGLFW>{ new WindowGLFW };
#else
	#ERROR_FARMING_GLFW_ISNT_DEFINED
#endif
	}

	void FarmingWindow::Init()
	{
		if (!mInstance)
		{
			mInstance = std::shared_ptr<FarmingWindow>(new FarmingWindow);
		}
	}

	std::shared_ptr<FarmingWindow> FarmingWindow::GetWindow()
	{
		return mInstance;
	}

	void FarmingWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mImplementation->CreateWindow(width, height, windowName);
	}

	void FarmingWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mImplementation->CreateWindow(width, height, std::move(windowName));
	}

	int FarmingWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int FarmingWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void FarmingWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void FarmingWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}


	void FarmingWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback)
	{
		mImplementation->SetKeyPressedCallback(newCallback);
	}

	void FarmingWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback)
	{
		mImplementation->SetKeyReleasedCallback(newCallback);
	}

	void FarmingWindow::SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback)
	{
		mImplementation->SetWindowCloseCallback(newCallback);
	}

}