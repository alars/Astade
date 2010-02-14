#if !defined(wxS)
#  define wxS(x) wxT(x)
#endif

wxMessageDialog(this, wxS("Astade UML utility,\n" COPYRIGHT "\nRelease: " AstadeVersion "\nBuilt against ") wxVERSION_STRING, "about:").ShowModal();
