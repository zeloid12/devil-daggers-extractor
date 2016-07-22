#ifndef CONTROLLER_MAIN_H
#define CONTROLLER_MAIN_H

#include "wx/string.h"
#include "wx/treelist.h"

class wxTreeListCtrl;

namespace frame
{
    class Main;
}

namespace resource
{
    class Manager;
}

namespace controller
{

class Main
{
public:

    Main(frame::Main* frame, resource::Manager* resourceManager);

    void onOpen(const wxString& path, wxTreeListCtrl& treeListCtrl);
    void onItemChecked(wxTreeListCtrl& treeListCtrl, const wxTreeListItem& listItem);
    void onItemActivated(wxTreeListCtrl& treeListCtrl, const wxTreeListItem& listItem);

private:

    resource::Manager* m_resourceManager;
};

} // namespace controller

#endif // CONTROLLER_MAIN_H