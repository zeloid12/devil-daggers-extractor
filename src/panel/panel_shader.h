#ifndef PANEL_SHADER_H
#define PANEL_SHADER_H

#include "wx/panel.h"

namespace panel
{

class Shader final : public wxPanel
{
public:

    Shader(wxWindow* parent);
    virtual ~Shader();
};

} // namespace panel

#endif // PANEL_SHADER_H
