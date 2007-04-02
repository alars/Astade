DECLARE_EVENT_TYPE(ASTADE_ICON_EVENT, unused)

typedef void (wxEvtHandler::*astade_iconFunction)(AstadeIconEvent&);

#define EVT_ASTADE_ICON(func) wx__DECLARE_EVT0(ASTADE_ICON_EVENT, (wxObjectEventFunction)(wxEventFunction)wxStaticCastEvent(astade_iconFunction, &func))