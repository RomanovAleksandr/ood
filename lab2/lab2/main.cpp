#include <SFML/Graphics.hpp>
#include <iostream>
#include "Application.h"

using namespace std;

int main()
{
    Application* application = Application::GetInstance();
    application->Run();

    return 0;
}