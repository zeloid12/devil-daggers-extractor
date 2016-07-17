#ifndef APP_H
#define APP_H

#include "wx/app.h"

namespace controller
{
    class Main;
}

namespace frame
{
    class Main;
}

namespace resource
{
    class Manager;
}

class App final : public wxApp
{
public:

    App();
    virtual ~App();

    virtual bool OnInit() override;

private:

    frame::Main* m_mainFrame;
    controller::Main* m_mainController;
    resource::Manager* m_resourceManager;
};

#endif // APP_H
