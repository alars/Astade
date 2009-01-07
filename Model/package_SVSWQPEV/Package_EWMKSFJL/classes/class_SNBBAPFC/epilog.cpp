BEGIN_EVENT_TABLE(glGraphicPanel,wxScrolledWindow)
	EVT_TIMER(ID_RefreshTimer,glGraphicPanel::OnRefreshTimer)
	EVT_TIMER(ID_MoveTimer,glGraphicPanel::OnMoveTimer)
END_EVENT_TABLE()