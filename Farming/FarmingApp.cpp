#include "pch.h"

#include "FarmingApp.h"
#include "FarmingWindow.h"

namespace Farming
{
	void FarmingApp::OnUpdate()
	{
	}

	void FarmingApp::Run()
	{
		FarmingWindow::Init();
		FarmingWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		while (true)
		{
			OnUpdate();

			FarmingWindow::GetWindow()->SwapBuffers();
			FarmingWindow::GetWindow()->PollEvents();
		}
	}
}