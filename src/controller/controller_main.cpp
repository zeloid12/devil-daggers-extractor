#include "controller_main.h"

#include "frame/frame_main.h"
#include "resource/resource_manager.h"
#include "wx/treelist.h"
#include "resource/resource_toc.h"

namespace controller
{

Main::Main(frame::Main* frame, resource::Manager* resourceManager)
: m_resourceManager(resourceManager)
{
    frame->getSignalOnOpen().connect(std::bind(&Main::onOpen, this, std::placeholders::_1, std::placeholders::_2));
    frame->getSignalItemChecked().connect(std::bind(&Main::onItemChecked, this, std::placeholders::_1, std::placeholders::_2));
    frame->getSignalItemActivated().connect(std::bind(&Main::onItemActivated, this, std::placeholders::_1, std::placeholders::_2));
}

void Main::onOpen(const wxString& path, wxTreeListCtrl& treeListCtrl)
{
    treeListCtrl.ClearColumns();
    treeListCtrl.AppendColumn("Files");

    if (m_resourceManager->init(path.ToStdString()))
    {
        const resource::Toc* toc = m_resourceManager->getToc();
        while (toc)
        {
            if (toc->m_file)
            {

                wxTreeListItem& root = treeListCtrl.AppendItem(treeListCtrl.GetRootItem(), toc->m_name);

                wxTreeListItem* audioRoot = nullptr;
                wxTreeListItem* textureRoot = nullptr;
                wxTreeListItem* shaderRoot = nullptr;
                wxTreeListItem* modelRoot = nullptr;

                resource::File* file = toc->m_file;

                wxTreeListItem* rootCur = nullptr;
                while (file)
                {
                    switch (file->m_type)
                    {
                        case 0x20: // audio
                        {
                            if (!audioRoot)
                            {
                                audioRoot = &treeListCtrl.AppendItem(root, "audio");
                            }

                            rootCur = audioRoot;
                        }
                        break;

                        case 0x02: // texture
                        {
                            if (!textureRoot)
                            {
                                textureRoot = &treeListCtrl.AppendItem(root, "texture");
                            }

                            rootCur = textureRoot;
                        }
                        break;

                        case 0x01: // model
                        {
                            if (!modelRoot)
                            {
                                modelRoot = &treeListCtrl.AppendItem(root, "model");
                            }

                            rootCur = modelRoot;
                        }
                        break;

                        case 0x10: // shaders
                        {
                            if (!shaderRoot)
                            {
                                shaderRoot = &treeListCtrl.AppendItem(root, "shader");
                            }

                            rootCur = shaderRoot;
                        }
                        break;
                    }

                    if (rootCur)
                    {
                        treeListCtrl.AppendItem(*rootCur, file->m_name);
                    }

                    file = file->m_next;
                }
            }
            
            toc = toc->m_next;
        }
    }
}

void Main::onItemChecked(wxTreeListCtrl& treeListCtrl, const wxTreeListItem& listItem)
{

}

void Main::onItemActivated(wxTreeListCtrl& treeListCtrl, const wxTreeListItem& listItem)
{

}

} // namespace controller
