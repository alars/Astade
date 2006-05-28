#include "GrafPanel.h"

BEGIN_EVENT_TABLE(GrafPanel, wxScrolledWindow)
	EVT_TIMER(wxID_ANY,GrafPanel::OnTimer)
END_EVENT_TABLE()
