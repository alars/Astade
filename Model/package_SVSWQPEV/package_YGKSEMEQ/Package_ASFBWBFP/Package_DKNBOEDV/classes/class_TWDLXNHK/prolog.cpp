#include "GrafPanel.h"

BEGIN_EVENT_TABLE(GrafPanel, wxScrolledWindow)
	EVT_RIGHT_UP(GrafPanel::OnRightUp)
	EVT_MOTION(GrafPanel::MouseMotion)
	EVT_LEFT_DOWN(GrafPanel::OnClick)
	EVT_TIMER(wxID_ANY,GrafPanel::OnTimer)
	EVT_LEAVE_WINDOW(GrafPanel::OnLeave)
	EVT_ENTER_WINDOW(GrafPanel::OnEnter)
END_EVENT_TABLE()
