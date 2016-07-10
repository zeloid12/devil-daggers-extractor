#ifndef APP_H
#define APP_H

#include "wx/app.h"

namespace frame
{
    class Main;
}

class App final : public wxApp
{
public:

    App();
    virtual ~App();

    virtual bool OnInit() override;

private:

    frame::Main* m_mainFrame;
};

#endif // APP_H
