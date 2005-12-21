wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/CodingType", copyConfig.Read("Astade/CodingType"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Virtual", copyConfig.Read("Astade/Virtual"));
theConfig.Write("Astade/Abstract",  copyConfig.Read("Astade/Abstract"));
theConfig.Write("Astade/Static",  copyConfig.Read("Astade/Static"));
theConfig.Write("Astade/Const",  copyConfig.Read("Astade/Const"));

if (GetHasParameters())
{
	wxFileName parametersFileName = AdeParameters::CreateNewElement(aFileName.GetFullPath());

	wxFileName sourceParameter = myFileName;
	sourceParameter.AppendDir("parameters");

	wxDir dir(sourceParameter.GetPath());

    if ( dir.IsOpened() )
    {
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES);
	    while ( cont )
	    {
	        if (filename!="ModelNode.ini")
	        {
		        parametersFileName.SetFullName(filename);
		        sourceParameter.SetFullName(filename);
		        wxCopyFile(sourceParameter.GetFullPath(),parametersFileName.GetFullPath());
		    }
		    cont = dir.GetNext(&filename);
	    }
	}
}

wxFileName codeSource = myFileName;
wxFileName codeDest = aFileName;

codeSource.SetFullName("code.cpp");
codeDest.SetFullName("code.cpp");

wxCopyFile(codeSource.GetFullPath(),codeDest.GetFullPath());

return aFileName;