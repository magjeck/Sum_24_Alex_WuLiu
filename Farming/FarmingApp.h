#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Events.h"

namespace Farming
{
	constexpr int DEFAULT_FRAME_RATE{ 60 };

	class FARMING_API FarmingApp
	{
	public:
		FarmingApp();

		virtual void OnUpdate();
		void Run();
		void SetFrameRate(int newFrameRate);

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback);
		void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback);

	private:
		int mFrameRate{ 0 }; // measured in frames per second

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration;

		bool mShouldContinue{ true };

		void DefaultWindowCloseCallback(const WindowCloseEvent& event);
	};
}