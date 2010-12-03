//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeOperation] ~~

wxFileName aFileName = CreateNewElement(parentPath);    //creates new "operation directory and .ini file" for copying.
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

wxString suffix;
wxFileName testFileName(myFileName);
testFileName.RemoveLastDir();
if (testFileName.GetPath() == parentPath.GetPath())
	suffix = wxS("_copied");

theConfig.Write(wxS("Astade/Name"), myConfig->Read(wxS("Astade/Name")) + suffix);					//start .ini file copying
theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/CodingType"), myConfig->Read(wxS("Astade/CodingType")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/ReturnDescription"), myConfig->Read(wxS("Astade/ReturnDescription")));
theConfig.Write(wxS("Astade/Virtual"), myConfig->Read(wxS("Astade/Virtual")));
theConfig.Write(wxS("Astade/Abstract"), myConfig->Read(wxS("Astade/Abstract")));
theConfig.Write(wxS("Astade/Static"), myConfig->Read(wxS("Astade/Static")));
theConfig.Write(wxS("Astade/Inline"), myConfig->Read(wxS("Astade/Inline")));
theConfig.Write(wxS("Astade/Const"), myConfig->Read(wxS("Astade/Const")));  			//end of copying

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

if (HasParameters())  //checking subdirectory from copy source.
{
	wxFileName parametersFileName = AdeParameters::CreateNewElement(aFileName.GetFullPath()); //in the copyed operation directory.

	if (theRevisionControl->IsAddSupported())
		theRevisionControl->Add(parametersFileName);

	wxFileName sourceParameter = myFileName;  //copy source path
	sourceParameter.AppendDir(wxS("parameters")); //append "parameters" directory to the path.

	wxDir dir(sourceParameter.GetPath());
    if (dir.IsOpened())
    {
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES); //First contents in the directory "parameter".
	    while (cont)
	    {
	        if (filename != wxS("ModelNode.ini"))
	        {
		        parametersFileName.SetFullName(filename);
		        sourceParameter.SetFullName(filename);
		        wxCopyFile(sourceParameter.GetFullPath(),parametersFileName.GetFullPath());

				if (theRevisionControl->IsAddSupported())
					theRevisionControl->Add(parametersFileName);
		    }
		    cont = dir.GetNext(&filename);
	    }
	}
}

wxFileName codeDest = aFileName;
codeDest.SetName(wxS("code"));
codeDest.SetExt(GetImpExtension());

wxCopyFile(GetActionCodeFile().GetFullPath(), codeDest.GetFullPath());

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(codeDest);

return aFileName;
