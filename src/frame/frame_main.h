#ifndef FRAME_MAIN_H
#define FRAME_MAIN_H

#include "wx/frame.h"

#include "signal.h"
#include "wx/treelist.h"

namespace controller
{
    class Main;
}

namespace frame
{

class Main final : public wxFrame
{
public:

    typedef Signal<void, const wxString&, wxTreeListCtrl&> SignalOpen;
    typedef Signal<void, wxTreeListCtrl&, const wxTreeListItem&> SignalItemChecked;
    typedef Signal<void, wxTreeListCtrl&, const wxTreeListItem&> SignalItemActivated;

public:

    Main();
    virtual ~Main();

    SignalOpen& getSignalOnOpen()
    {
        return m_signalOpen;
    }

    SignalItemChecked& getSignalItemChecked()
    {
        return m_signalItemChecked;
    }

    SignalItemChecked& getSignalItemActivated()
    {
        return m_signalItemActivated;
    }

private:

    wxDECLARE_EVENT_TABLE();

    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnItemChecked(wxTreeListEvent& event);
    void OnItemActivated(wxTreeListEvent& event);

private:

    SignalOpen m_signalOpen;
    SignalItemChecked m_signalItemChecked;
    SignalItemActivated m_signalItemActivated;

    wxTreeListCtrl* m_treeListCtrl;
};

} // namespace frame

#endif // FRAME_MAIN_H
