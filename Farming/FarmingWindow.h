#pragma once

#include "pch.h"
#include "Utilities.h"
#include "WindowImplementation.h"
#include "Events.h"

namespace Farming
{
	class FARMING_API FarmingWindow
	{
	public:
		static void Init();
		static std::shared_ptr<FarmingWindow> GetWindow();

		void CreateWindow(int width, int height, const std::string& windowName);
		void CreateWindow(int width, int height, std::string&& windowName);
		int GetWidth() const;
		int GetHeight() const;
		void SwapBuffers();
		void PollEvents();

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback);
		void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback);

	private:
		FarmingWindow();
		inline static std::shared_ptr<FarmingWindow> mInstance{ nullptr };

		std::unique_ptr<WindowImplementation> mImplementation{nullptr};
	};
}