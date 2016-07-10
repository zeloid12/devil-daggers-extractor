#include "app.h"

#include "frame/frame_main.h"

App::App()
{

}

App::~App()
{

}

bool App::OnInit()
{
    m_mainFrame = new frame::Main();
    m_mainFrame->Show(true);
    return true;
}
