#include "pch.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "FarmingApp.h"
#include "FarmingWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "stb_image.h"
#include "Renderer.h"

namespace Farming
{
	FarmingApp::FarmingApp()
	{
		FarmingWindow::Init();
		FarmingWindow::GetWindow()->CreateWindow(1000, 800, "Farm");

		Renderer::Init();

		SetFrameRate(DEFAULT_FRAME_RATE);

		SetWindowCloseCallback([this](const WindowCloseEvent& event) {DefaultWindowCloseCallback(event); });
	}

	void FarmingApp::OnUpdate()
	{
	}

	void FarmingApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue)
		{
			Renderer::Get()->ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			FarmingWindow::GetWindow()->SwapBuffers();
			FarmingWindow::GetWindow()->PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void FarmingApp::SetFrameRate(int newFrameRate)
	{
		mFrameRate = newFrameRate;
		mFrameDuration = std::chrono::milliseconds{ 1000 } / mFrameRate;
	}

	void FarmingApp::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback)
	{
		FarmingWindow::GetWindow()->SetKeyPressedCallback(newCallback);
	}

	void FarmingApp::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback)
	{
		FarmingWindow::GetWindow()->SetKeyReleasedCallback(newCallback);
	}

	void FarmingApp::SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback)
	{
		FarmingWindow::GetWindow()->SetWindowCloseCallback(newCallback);
	}


	void FarmingApp::DefaultWindowCloseCallback(const WindowCloseEvent& event)
	{
		mShouldContinue = false;
	}
}