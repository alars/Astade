#include "GrafPanel.h"

BEGIN_EVENT_TABLE(GrafPanel, wxScrolledWindow)
	EVT_MOTION(GrafPanel::MouseMotion)
	EVT_LEFT_DOWN(GrafPanel::OnClick)
	EVT_TIMER(wxID_ANY,GrafPanel::OnTimer)
END_EVENT_TABLE()
