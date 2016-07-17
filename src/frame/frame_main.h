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
    typedef Signal<void, uint32_t> SignalItemDoubleClick;

public:

    Main();
    virtual ~Main();

    SignalOpen& getSignalOnOpen()
    {
        return m_signalOpen;
    }

    SignalItemDoubleClick& getSignalItemDoubleClick()
    {
        return m_signalItemDoubleClick;
    }

private:

    wxDECLARE_EVENT_TABLE();

    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:

    SignalOpen m_signalOpen;
    SignalItemDoubleClick m_signalItemDoubleClick;

    wxTreeListCtrl* m_treeListCtrl;
};

} // namespace frame

#endif // FRAME_MAIN_H
