#include "main.xpm"
#include "SeqFrame.h"
#include <wx/clipbrd.h>
#include <wx/icon.h>
#include <Trace2UMLVersion.h>
#include <cairo-svg.h> 
#include <cairo-pdf.h> 

BEGIN_EVENT_TABLE(SeqFrame,wxFrame)
	EVT_CLOSE(SeqFrame::Exit)
	EVT_MENU(ID_OPEN, SeqFrame::Open)
	EVT_MENU(ID_SAVE, SeqFrame::Save)
	EVT_MENU(ID_PAGESETUP, SeqFrame::OnPageSetup)
	EVT_MENU(ID_PRINT, SeqFrame::OnPrint)
	EVT_MENU(ID_SAVESVG, SeqFrame::SaveGraphicSVG)
	EVT_MENU(ID_SAVEPDF, SeqFrame::SaveGraphicPDF)
	EVT_MENU(ID_SAVEPNG, SeqFrame::SaveGraphicPNG)
	EVT_MENU(ID_COPYGRAPH, SeqFrame::CopyBitmap)
	EVT_MENU(ID_SAVEAS, SeqFrame::SaveFileAs)
	EVT_MENU(ID_ABOUT, SeqFrame::OnAbout)
	EVT_MENU(ID_HELP, SeqFrame::OnHelp)
	EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, SeqFrame::GenText)
	EVT_MENU_RANGE(ID_EDITBEGIN, ID_EDITEND, SeqFrame::DeleteObject)
END_EVENT_TABLE()
