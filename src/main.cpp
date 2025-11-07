#include "Application.h"

int main()
{
    Resonance::Application* app = new Resonance::Application();
    app->Run();
    delete app;
}