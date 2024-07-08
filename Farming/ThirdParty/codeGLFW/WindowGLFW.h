#pragma once

#include "WindowImplementation.h"

#define GLFW_INCLUDE_NONE
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

		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback) override;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback) override;
		virtual void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback) override;

		WindowGLFW();
		~WindowGLFW();

	private:
		struct Callbacks
		{
			std::function<void(const KeyPressedEvent&)> KeyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> KeyReleasedCallback{ [](const KeyReleasedEvent&) {} };
			std::function<void(const WindowCloseEvent&)> WindowCloseCallback{ [](const WindowCloseEvent&) {} };
		} mCallbacks;

		GLFWwindow* mWindow{ nullptr };

		void SetDefaultCallbacks();
	};
}