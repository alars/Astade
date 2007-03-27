wxFileName aFileName = CreateNewElement(parentPath);    //creates new "operation directory and .ini file" for copying.
{
	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		int ret = theRevisionControl->Add(aFileName);
		wxArrayString output = theRevisionControl->GetOutput();

		if (ret!=0)
		{
			wxString message;
			for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
		}
	}
} //Add new directory

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString suffix;
wxFileName testFileName(myFileName);
testFileName.RemoveLastDir();
if(testFileName.GetPath() == parentPath.GetPath())
	suffix = "_copied";

theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name") + suffix);					//start .ini file copying
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/CodingType", copyConfig.Read("Astade/CodingType"));
theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/ReturnDescription", copyConfig.Read("Astade/ReturnDescription"));
theConfig.Write("Astade/Virtual", copyConfig.Read("Astade/Virtual"));
theConfig.Write("Astade/Abstract",  copyConfig.Read("Astade/Abstract"));
theConfig.Write("Astade/Static",  copyConfig.Read("Astade/Static"));
theConfig.Write("Astade/Const",  copyConfig.Read("Astade/Const"));  			//end of copying

{
	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		int ret = theRevisionControl->Add(aFileName);
		wxArrayString output = theRevisionControl->GetOutput();

		if (ret!=0)
		{
			wxString message;
			for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
		}
	}
} //Add new .ini file

if (GetHasParameters())  //checking subdirectory from copy source.
{
	wxFileName parametersFileName = AdeParameters::CreateNewElement(aFileName.GetFullPath()); //in the copyed operation directory.

	{
	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		int ret = theRevisionControl->Add(parametersFileName);
		wxArrayString output = theRevisionControl->GetOutput();

		if (ret!=0)
		{
			wxString message;
			for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
		}
	}
} //Add new Parameters directory

	wxFileName sourceParameter = myFileName;  //copy source path
	sourceParameter.AppendDir("parameters"); //append "parameters" directory to the path.

	wxDir dir(sourceParameter.GetPath());

    if ( dir.IsOpened() )
    {
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES); //First contents in the directory "parameter".
	    while ( cont )
	    {
	        if (filename!="ModelNode.ini")
	        {
		        parametersFileName.SetFullName(filename);
		        sourceParameter.SetFullName(filename);
		        wxCopyFile(sourceParameter.GetFullPath(),parametersFileName.GetFullPath());

				AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
				if (theRevisionControl->IsAddSupported())
				{
					int ret = theRevisionControl->Add(parametersFileName);
					wxArrayString output = theRevisionControl->GetOutput();

					if (ret!=0)
					{
						wxString message;
						for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
					}
				}

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

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
{
	int ret = theRevisionControl->Add(codeDest);
	wxArrayString output = theRevisionControl->GetOutput();

	if (ret!=0)
	{
		wxString message;
		for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
	}
}

return aFileName;