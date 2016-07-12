#ifndef PANEL_TEXTURE_H
#define PANEL_TEXTURE_H

#include "wx/panel.h"

namespace panel
{

class Texture final : public wxPanel
{
public:

    Texture(wxWindow* parent);
    virtual ~Texture();
};

} // namespace panel

#endif // PANEL_TEXTURE_H
