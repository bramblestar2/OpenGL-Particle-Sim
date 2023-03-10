#include "Window3D.h"

Window3D::Window3D(const unsigned int _Width,
				   const unsigned int _Height,
				   const std::string _Title,
				   const bool _IsTransparent)
				   : Window2D(_Width, _Height, _Title, _IsTransparent)
{
	Window2D::setContext(24, 8, 2, 0);
	camera = nullptr;
}

Window3D::Window3D() : Window2D()
{
	camera = nullptr;
}

Window3D::~Window3D()
{
}

void Window3D::setCamera(Camera* _Camera)
{
	camera = _Camera;
}

void Window3D::display()
{
	//if (camera != nullptr)
	//	camera->update();

	glfwSwapBuffers(window);
}
