#pragma once
#include <SFML/Graphics.hpp>

class Application
{
protected:
	Application()
	{
	}

	static Application* application_;

public:
	Application(Application& other) = delete;
	void operator=(const Application&) = delete;
	static Application* GetInstance();
	void Run();

private:

};