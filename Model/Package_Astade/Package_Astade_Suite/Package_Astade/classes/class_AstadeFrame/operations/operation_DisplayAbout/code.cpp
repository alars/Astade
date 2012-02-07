//~~ void DisplayAbout(wxCommandEvent& event) [AstadeFrame] ~~

wxMessageDialog(this, wxS("Astade UML utility,\n" COPYRIGHT "\nRelease " AstadeVersion "\nBuilt against ") wxVERSION_STRING wxS("\nBuild date " __DATE__), wxS("about:")).ShowModal();
