#ifndef FRAME_MAIN_H
#define FRAME_MAIN_H

#include "wx/frame.h"

namespace frame
{

class Main final : public wxFrame
{
public:

    Main();
    virtual ~Main();

private:

    wxDECLARE_EVENT_TABLE();

    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

} // namespace frame

#endif // FRAME_MAIN_H
