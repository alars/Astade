//~~ void DrawPause(cairo_t* cr, int classIndex, int timeIndex) [SeqGraphTab] ~~
int startY = dataBase->GetTime2Y(timeIndex);
int length = startY - dataBase->GetTime2Y(timeIndex - 1);

if (length <= 0)
	return;

int middle = dataBase->GetClassMiddle(classIndex);

setColor(cr, white);
cairo_rectangle(cr, middle - 35, startY - length, 70, length);
cairo_fill(cr);

cairo_set_line_width (cr, 1.0);
setColor(cr, green);

double dashlen[2] = {1.0, 8};
cairo_set_dash(cr,dashlen,2,0);

cairo_move_to(cr, middle, startY);
cairo_line_to (cr, middle, startY-length);
cairo_stroke (cr);