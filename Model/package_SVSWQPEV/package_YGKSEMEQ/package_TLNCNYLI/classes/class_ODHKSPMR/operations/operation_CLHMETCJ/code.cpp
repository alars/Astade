wxTreeItemId aID = myTree->GetSelection();
wxFileName aFilename = myTree->GetItem(aID)->GetFileName();
wxFileDataObject dragData;
dragData.AddFile(aFilename.GetFullPath());
wxDropSource dropSource(dragData, this);
/*wxDragResult dragResult = */ dropSource.DoDragDrop(wxDrag_AllowMove);
/*switch(dragResult)
{
	case wxDragCopy:
		wxLogMessage("DragCopy");
		break;
	case wxDragMove:
		wxLogMessage("DragMove");
		break;
	case wxDragLink:
		wxLogMessage("DragLink");
		break;
	case wxDragCancel:
		wxLogMessage("DragCancel");
		break;
	case wxDragNone:
		wxLogMessage("DragNone");
		break;
	case wxDragError:
		wxLogMessage("DragNone");
		break;
}*/