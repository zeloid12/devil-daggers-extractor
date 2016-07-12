#ifndef PANEL_AUDIO_H
#define PANEL_AUDIO_H

#include "wx/panel.h"

namespace panel
{

class Audio final : public wxPanel
{
public:

    Audio(wxWindow* parent);
    virtual ~Audio();
};

} // namespace panel

#endif // PANEL_AUDIO_H
