#ifndef CONTROLLER_MAIN_H
#define CONTROLLER_MAIN_H

#include "wx/string.h"

class wxTreeListCtrl;

namespace frame
{
    class Main;
}

namespace controller
{

class Main
{
public:

    Main(frame::Main* frame);

    void onOpen(const wxString& path, wxTreeListCtrl& treeListCtrl);
    void onItemDoubleClick(uint32_t id);

private:

    //resource::Manager* m_resourceManager;
};

} // namespace controller

#endif // CONTROLLER_MAIN_H