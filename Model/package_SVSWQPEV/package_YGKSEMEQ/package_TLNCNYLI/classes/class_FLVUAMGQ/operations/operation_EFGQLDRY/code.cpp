if(style & COPY_TARGET)
{
	aMenu.Append(ID_PASTE, "paste", wxEmptyString, wxITEM_NORMAL);
	aMenu.Enable(ID_PASTE, OfferPaste());
}

if(style & COPY_SOURCE)
{
	aMenu.Append(ID_COPY, "copy", wxEmptyString, wxITEM_NORMAL);
	if((style & COPY_NOCUT) == 0)
		aMenu.Append(ID_CUT, "cut", wxEmptyString, wxITEM_NORMAL);
}
