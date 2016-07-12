#ifndef PANEL_MODEL_H
#define PANEL_MODEL_H

#include "wx/panel.h"

namespace panel
{

class Model final : public wxPanel
{
public:

    Model(wxWindow* parent);
    virtual ~Model();
};

} // namespace panel

#endif // PANEL_MODEL_H
