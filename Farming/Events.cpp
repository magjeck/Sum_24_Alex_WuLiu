#include "pch.h"

#include "Events.h"

namespace Farming
{
	KeyPressedEvent::KeyPressedEvent(int keyCode) : mKeyCode(keyCode)
	{
	}

	int KeyPressedEvent::GetKey() const
	{
		return mKeyCode;
	}

	KeyReleasedEvent::KeyReleasedEvent(int keyCode) : mKeyCode(keyCode)
	{
	}

	int KeyReleasedEvent::GetKey() const
	{
		return mKeyCode;
	}
}