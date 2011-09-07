//~~ void setColor(cairo_t* cr, color_t color) [SeqGraphTab] ~~
double dashlen[2] = {5, 4};
switch (color)
{
    case blue:
        cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
        cairo_set_dash(cr,0,0,0);
    break;
    case dashedblue:
        cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
        cairo_set_dash(cr,dashlen,2,0);
    break;
    case purple:
        cairo_set_source_rgb(cr, 0.6, 0.0, 0.6);
        cairo_set_dash(cr,dashlen,2,0);
    break;
    case black:
        cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
        cairo_set_dash(cr,0,0,0);
    break;
    case green:
        cairo_set_source_rgb(cr, 0.0, 0.5, 0.0);
        cairo_set_dash(cr,0,0,0);
    break;
    case dashedgreen:
        cairo_set_source_rgb(cr, 0.0, 0.5, 0.0);
        cairo_set_dash(cr,dashlen,2,0);
    break;
    case red:
        cairo_set_source_rgb(cr, 0.9, 0.0, 0.0);
        cairo_set_dash(cr,0,0,0);
    break;
    case white:
        cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
        cairo_set_dash(cr,0,0,0);
    break;
}

