//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeConstructor] ~~

wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write(wxS("Astade/Type"), myConfig->Read(wxS("Astade/Type")));
theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Initializer"), myConfig->Read(wxS("Astade/Initializer")));

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
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
	    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES); //First contents in the directory "parameter".
	    while (cont)
	    {
	        if (filename != wxS("ModelNode.ini"))
	        {
		        parametersFileName.SetFullName(filename);
		        sourceParameter.SetFullName(filename);
		        wxCopyFile(sourceParameter.GetFullPath(), parametersFileName.GetFullPath());

				AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
				if (theRevisionControl->IsAddSupported())
					theRevisionControl->Add(parametersFileName);
		    }
		    cont = dir.GetNext(&filename);
	    }
	}
}

wxFileName codeSource = myFileName;
codeSource.SetFullName(wxS("code.cpp"));
if (!wxFile::Exists(codeSource.GetFullPath()))
{
	// "code.cpp" doesn't exist, look for "code.<language_ext>"
	codeSource.SetExt(GetImpExtension());
}
wxFileName codeDest = aFileName;
codeDest.SetName(wxS("code"));
codeDest.SetExt(GetImpExtension());

wxCopyFile(codeSource.GetFullPath(),codeDest.GetFullPath());

if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(codeDest);

return aFileName;
