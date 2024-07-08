#pragma once

#include "Utilities.h"

namespace Farming
{
	class FARMING_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKey() const;
	private:
		int mKeyCode{ -1 };
	};

	class FARMING_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
		int GetKey() const;
	private:
		int mKeyCode{ -1 };
	};

	class FARMING_API WindowCloseEvent
	{

	};
}