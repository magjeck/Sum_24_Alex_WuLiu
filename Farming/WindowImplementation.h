#pragma once

#include "pch.h"
#include "Events.h"

namespace Farming
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void CreateWindow(int width, int height, std::string&& windowName) = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback) = 0;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback) = 0;
		virtual void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback) = 0;

		virtual ~WindowImplementation() {};
	private:

	};
}