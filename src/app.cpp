#include "app.h"

#include "frame/frame_main.h"
#include "controller/controller_main.h"
#include "resource/resource_manager.h"
#include "connector.h"

App::App()
: m_resourceManager(nullptr)
{

}

App::~App()
{
    delete m_mainController;
    delete m_resourceManager;
}

bool App::OnInit()
{
    m_resourceManager = new resource::Manager();
    m_mainFrame = new frame::Main();
    m_mainController = new controller::Main(m_mainFrame);

    m_mainFrame->Show(true);

    return true;
}
