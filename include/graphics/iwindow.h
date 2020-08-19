#pragma once

#include <string>

struct WindowDimensions
{
	unsigned int width;
	unsigned int height;
};

class IWindow
{
	public:
		IWindow(std::string title, unsigned int width, unsigned int height) :
			m_windimens{width, height}, m_title(title) {}
		virtual ~IWindow() {};

		virtual void clear() const = 0;
		virtual void swapBuffers() const = 0;
		unsigned int getWidth()  const { return m_windimens.width;  };
		unsigned int getHeight() const { return m_windimens.height; };

	protected:
		virtual void createWindow() = 0;

	protected:
		WindowDimensions m_windimens;
		std::string m_title;
};
