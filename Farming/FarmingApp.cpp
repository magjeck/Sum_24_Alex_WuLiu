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
	void FarmingApp::OnUpdate()
	{
	}

	void FarmingApp::Run()
	{
		FarmingWindow::Init();
		FarmingWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		Renderer::Init();

		Farming::Image pic{ "../Farming/Assets/Image/Sun.png" };

		while (true)
		{
			Renderer::Get()->ClearScreen();

			OnUpdate();

			Renderer::Get()->Draw(pic, 100, 200);

			FarmingWindow::GetWindow()->SwapBuffers();
			FarmingWindow::GetWindow()->PollEvents();
		}
	}
}