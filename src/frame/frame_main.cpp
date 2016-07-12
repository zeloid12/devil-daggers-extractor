#include "frame_main.h"

#include "wx/menu.h"
#include "wx/msgdlg.h"
#include "wx/dataview.h"
#include "wx/sizer.h"
#include "wx/srchctrl.h"
#include "wx/dirdlg.h"

#include "panel/panel_texture.h"

namespace frame
{

wxBEGIN_EVENT_TABLE(Main, wxFrame)
    EVT_MENU(wxID_OPEN, Main::OnOpen)
    EVT_MENU(wxID_EXIT, Main::OnExit)
    EVT_MENU(wxID_ABOUT, Main::OnAbout)
wxEND_EVENT_TABLE()

Main::Main()
: wxFrame(nullptr, wxID_ANY, "Devil Daggers Extractor", wxDefaultPosition, wxSize(800, 600))
{
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(wxID_OPEN);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu();
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);

    wxSearchCtrl* searchCtrl = new wxSearchCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1));
    wxDataViewTreeCtrl* treeView = new wxDataViewTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(200, -1));
    leftSizer->Add(searchCtrl, 0, wxALL, 5);
    leftSizer->Add(treeView, 1, wxALL, 5);

    // tmp
    panel::Texture* texture = new panel::Texture(this);
    rightSizer->Add(texture, 1, wxALL | wxEXPAND, 5);

    mainSizer->Add(leftSizer, 0, wxEXPAND);
    mainSizer->Add(rightSizer, 1, wxEXPAND);

    SetSizer(mainSizer);
    Layout();
}

Main::~Main()
{

}

void Main::OnOpen(wxCommandEvent& event)
{
    wxDirDialog* dlg = new wxDirDialog(this, "Select Devil Daggers directory", wxEmptyString, wxDD_DIR_MUST_EXIST);
    if (dlg->ShowModal() == wxOK)
    {

    }

    delete dlg;
}

void Main::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Main::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(
        "Devil Daggers Extractor\n"
        "Version 1.0\n"
        , "About"
        , wxOK | wxICON_INFORMATION
    );
}

} // namespace frame
