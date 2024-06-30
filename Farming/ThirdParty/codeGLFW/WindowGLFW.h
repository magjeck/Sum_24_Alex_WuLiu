#pragma once

#include "WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace Farming
{
	class WindowGLFW : public WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, std::string&& windowName) override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		WindowGLFW();
		~WindowGLFW();
	private:
		GLFWwindow* mWindow{ nullptr };
	};
}