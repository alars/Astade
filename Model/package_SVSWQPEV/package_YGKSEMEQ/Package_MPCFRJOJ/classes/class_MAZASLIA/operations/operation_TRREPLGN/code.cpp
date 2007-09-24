file_position fp = start.get_position();
long startPosition = XYToPosition(fp.column-1,fp.line-1);

fp = end.get_position();
long endPosition = XYToPosition(fp.column-1,fp.line-1);

wxTextCtrl::SetStyle(startPosition, endPosition, style);