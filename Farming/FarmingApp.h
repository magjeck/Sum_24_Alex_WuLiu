#pragma once

#include "pch.h"
#include "Utilities.h"

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

	private:
		int mFrameRate{ 0 }; // measured in frames per second

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration;
	};
}