myToolBar = CreateToolBar();

myToolBar->AddTool(ID_REGENERATE,"Regenerate all",
					wxBitmap(wxImage(wxBitmap(target_xpm).ConvertToImage()).Rescale(16,16)),
					"Regenerate: generates all .cpp and .h files of the active component");

myToolBar->AddTool(ID_MAKE,"Make all",
					wxBitmap(wxImage(wxBitmap(make_xpm).ConvertToImage()).Rescale(16,16)),
					"Make: calls \"make\"");

myToolBar->Realize();