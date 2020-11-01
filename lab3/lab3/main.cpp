#include "Application.h"

int main()
{
    Application* application = Application::GetInstance();
    application->Run();

    return 0;
}