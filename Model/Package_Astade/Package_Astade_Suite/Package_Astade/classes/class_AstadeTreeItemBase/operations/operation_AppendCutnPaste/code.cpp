//~~ void AppendCutnPaste(wxMenu& aMenu, int style) [AstadeTreeItemBase] ~~

if (style & COPY_TARGET)
{
	aMenu.Append(ID_PASTE, wxS("paste"), wxEmptyString, wxITEM_NORMAL);
	aMenu.Enable(ID_PASTE, OfferPaste());
}

if (style & COPY_SOURCE)
{
	aMenu.Append(ID_COPY, wxS("copy"), wxEmptyString, wxITEM_NORMAL);
	if ((style & COPY_NOCUT) == 0)
		aMenu.Append(ID_CUT, wxS("cut"), wxEmptyString, wxITEM_NORMAL);
}
