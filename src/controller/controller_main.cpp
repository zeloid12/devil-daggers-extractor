#include "controller_main.h"

#include "frame/frame_main.h"
#include "wx/treelist.h"

namespace controller
{

Main::Main(frame::Main* frame)
{
    frame->getSignalOnOpen().connect(std::bind(&Main::onOpen, this, std::placeholders::_1, std::placeholders::_2));
    frame->getSignalItemDoubleClick().connect(std::bind(&Main::onItemDoubleClick, this, std::placeholders::_1));
}

void Main::onOpen(const wxString& path, wxTreeListCtrl& treeListCtrl)
{
    treeListCtrl.ClearColumns();
    treeListCtrl.AppendColumn("test");
    wxTreeListItem& roota = treeListCtrl.AppendItem(treeListCtrl.GetRootItem(), "core");
    treeListCtrl.AppendItem(roota, "a");
    treeListCtrl.AppendItem(treeListCtrl.GetRootItem(), "res");
}

void Main::onItemDoubleClick(uint32_t id)
{

}

} // namespace controller
