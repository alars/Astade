#include "SeqGraphTab.h"

#include <gdk/gdk.h>
#include <gtk/gtk.h>

BEGIN_EVENT_TABLE(SeqGraphTab, wxScrolledWindow)
  EVT_PAINT(SeqGraphTab::OnPaint)
  EVT_RIGHT_DOWN(SeqGraphTab::OnRightDown)
  EVT_MOTION(SeqGraphTab::OnMouseMove)
  EVT_LEAVE_WINDOW(SeqGraphTab::LeaveWindow)
  EVT_MENU(ID_MNU_DELETE, SeqGraphTab::DeleteEvent)
END_EVENT_TABLE()
