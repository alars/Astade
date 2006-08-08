wxFileName aFileName = CreateNewElement(parentPath);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());     //copyed .ini file
wxFileConfig copyConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());   //source .ini file myFileName is in the AdeModelElement

wxString suffix("_Copied");
theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name") + suffix);
theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
theConfig.Write("Astade/AdditionalClasses", copyConfig.Read("Astade/AdditionalClasses"));
theConfig.Write("Astade/Description",  copyConfig.Read("Astade/Description"));

/*                                                          */
/* copying epilog.h/cpp, prolog.h/cpp only they are existed */
/*                                                          */

{
	wxFileName codeSource = myFileName;
	wxDir sourceDir(codeSource.GetPath());

	wxString codeFileName;
	bool cont = sourceDir.GetFirst(&codeFileName, wxEmptyString, wxDIR_FILES); //Getting file name in the class directory

	while(cont)
	{
		wxFileName codeSource2 = myFileName;
	    wxFileName codeDest2 = aFileName;

		if(codeFileName == "epilog.h" || codeFileName == "epilog.cpp" || codeFileName == "prolog.h" || codeFileName == "prolog.cpp")
		{
			codeSource2.SetFullName(codeFileName);
			codeDest2.SetFullName(codeFileName);

			wxCopyFile(codeSource2.GetFullPath(),codeDest2.GetFullPath());


			AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
			if (theRevisionControl->IsAddSupported())
			{
				int ret = theRevisionControl->Add(codeDest2);
				wxArrayString output = theRevisionControl->GetOutput();

				if (ret!=0)
				{
					wxString message;
					for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
					wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
				}
			}
		}
		cont = sourceDir.GetNext(&codeFileName);
	}
}
/*                                                                            */
/* Copying subdirectories such as attribute, operations, relations, and types */
/*                                                                            */

if (GetHasOperations())  //Copying operations
{

	wxFileName operationsFileName = AdeOperations::CreateNewElement(aFileName.GetFullPath()); //in the copyed operations directory.

	wxFileName sourceOperations = myFileName;  //copy source class path
	sourceOperations.AppendDir("operations"); //append "operations" directory to the path.

	wxDir dir(sourceOperations.GetPath());    //open directory for copying files from.

    if (dir.IsOpened()) //copying .ini file
    {
		wxFileConfig theConfigTarget(wxEmptyString,wxEmptyString,operationsFileName.GetFullPath());     //copyed .ini file
		wxFileConfig theConfigSource(wxEmptyString,wxEmptyString,sourceOperations.GetFullPath());   //source .ini file

		theConfigTarget.Write("Astade/Type", theConfigSource.Read("Astade/Type"));
		theConfigTarget.Write("Astade/Name", theConfigSource.Read("Astade/Name"));

        wxString operationName;
	    bool cont = dir.GetFirst(&operationName,wxEmptyString,wxDIR_DIRS); //Getting Operation directory name.
	    while ( cont )   //copy all operations in this loop.
	    {
	        wxFileName operationFileName = AdeOperation::CreateNewElement(operationsFileName.GetFullPath()); //in the copyed operation directory.

	    	wxFileName sourceFileName =  sourceOperations;
	    	sourceFileName.AppendDir(operationName);
	    	wxDir sourceDir(sourceFileName.GetPath());   //opening source directory.


	    	if(sourceDir.IsOpened())
	    	{

				wxFileConfig theConfig(wxEmptyString,wxEmptyString,operationFileName.GetFullPath());
				wxFileConfig copyConfig(wxEmptyString,wxEmptyString,sourceFileName.GetFullPath());

				theConfig.Write("Astade/Name",copyConfig.Read("Astade/Name"));					//start .ini file copying
				theConfig.Write("Astade/Type", copyConfig.Read("Astade/Type"));
				theConfig.Write("Astade/CodingType", copyConfig.Read("Astade/CodingType"));
				theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
				theConfig.Write("Astade/ReturnDescription", copyConfig.Read("Astade/ReturnDescription"));
				theConfig.Write("Astade/Virtual", copyConfig.Read("Astade/Virtual"));
				theConfig.Write("Astade/Abstract",  copyConfig.Read("Astade/Abstract"));
				theConfig.Write("Astade/Static",  copyConfig.Read("Astade/Static"));
				theConfig.Write("Astade/Const",  copyConfig.Read("Astade/Const"));  			//end of copying


				if (sourceDir.HasSubDirs())  //checking subdirectory from copy source.
				{
					wxFileName parametersFileName = AdeParameters::CreateNewElement(operationFileName.GetFullPath()); //in the copyed operation directory.

					wxFileName sourceParameter = sourceFileName;  //copy source path
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
										wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
									}
								}

		  			  	 	 }
		   					 cont = dir.GetNext(&filename);
	   					 }  //end second while
					}
				}

				wxFileName codeSource = sourceFileName;
				wxFileName codeDest = operationFileName;

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
						wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
					}
				}


          	}
	    	cont = dir.GetNext(&operationName);
	    } //end first while
	}
}

if(GetHasRelations())  //Copying Relations
{
    wxFileName relationsFileName = AdeRelations::CreateNewElement(aFileName.GetFullPath());

    wxFileName sourceRelations = myFileName;
    sourceRelations.AppendDir("relations");

    wxDir dir(sourceRelations.GetPath());

    if(dir.IsOpened())
    {
    	wxFileConfig theConfigTarget(wxEmptyString, wxEmptyString, relationsFileName.GetFullPath());
    	wxFileConfig theConfigSource(wxEmptyString, wxEmptyString, sourceRelations.GetFullPath());

    	theConfigTarget.Write("Astade/Type", theConfigSource.Read("Astade/Type"));
    	theConfigTarget.Write("Astade/Name", theConfigSource.Read("Astade/Name"));

    	//Copying all attributes
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES); //First contents in the directory "relations".
	    while ( cont )
	    {
	        if (filename!="ModelNode.ini")
	        {
		        relationsFileName.SetFullName(filename);
		        sourceRelations.SetFullName(filename);
		        wxCopyFile(sourceRelations.GetFullPath(), relationsFileName.GetFullPath());

				AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
				if (theRevisionControl->IsAddSupported())
				{
					int ret = theRevisionControl->Add(relationsFileName);
					wxArrayString output = theRevisionControl->GetOutput();

					if (ret!=0)
					{
						wxString message;
						for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
						wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
					}
				}

		    }
		    cont = dir.GetNext(&filename);
	    }
    }
}

if(GetHasTypes()) //Copying Types
{
   	wxFileName typesFileName = AdeTypes::CreateNewElement(aFileName.GetFullPath());

   	wxFileName sourceTypes = myFileName;
   	sourceTypes.AppendDir("types");

   	wxDir dir(sourceTypes.GetPath());

   	if(dir.IsOpened())
   	{
   		wxFileConfig theConfigTarget(wxEmptyString, wxEmptyString, typesFileName.GetFullPath());
   		wxFileConfig theConfigSource(wxEmptyString, wxEmptyString, sourceTypes.GetFullPath());

   		theConfigTarget.Write("Astade/Type", theConfigSource.Read("Astade/Type"));
   		theConfigTarget.Write("Astade/Name", theConfigSource.Read("Astade/Name"));

   		 //Copying all types
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES); //First contents in the directory "types".
	    while ( cont )
	    {
	        if (filename!="ModelNode.ini")
	        {
		        typesFileName.SetFullName(filename);
		        sourceTypes.SetFullName(filename);
		        wxCopyFile(sourceTypes.GetFullPath(), typesFileName.GetFullPath());

				AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
				if (theRevisionControl->IsAddSupported())
				{
					int ret = theRevisionControl->Add(typesFileName);
					wxArrayString output = theRevisionControl->GetOutput();

					if (ret!=0)
					{
						wxString message;
						for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
						wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
					}
				}

		    }
		    cont = dir.GetNext(&filename);
	    }
	}
}

if(GetHasAttributes())   //Copying Attributes
{
	wxFileName attributesFileName = AdeAttributes::CreateNewElement(aFileName.GetFullPath());

	wxFileName sourceAttributes = myFileName;
	sourceAttributes.AppendDir("attributes");

	wxDir dir(sourceAttributes.GetPath());

	if(dir.IsOpened())
	{
		wxFileConfig theConfigTarget(wxEmptyString, wxEmptyString, attributesFileName.GetFullPath());
		wxFileConfig theConfigSource(wxEmptyString, wxEmptyString, sourceAttributes.GetFullPath());

		theConfigTarget.Write("Astade/Type", theConfigSource.Read("Astade/Type"));
		theConfigTarget.Write("Astade/Name", theConfigSource.Read("Astade/Name"));

	    //Copying all attributes
		wxString filename;
	    bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES); //First contents in the directory "attributes".
	    while ( cont )
	    {
	        if (filename!="ModelNode.ini")
	        {
		        attributesFileName.SetFullName(filename);
		        sourceAttributes.SetFullName(filename);
		        wxCopyFile(sourceAttributes.GetFullPath(), attributesFileName.GetFullPath());

				AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
				if (theRevisionControl->IsAddSupported())
				{
					int ret = theRevisionControl->Add(attributesFileName);
					wxArrayString output = theRevisionControl->GetOutput();

					if (ret!=0)
					{
						wxString message;
						for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
						wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
					}
				}

		    }
		    cont = dir.GetNext(&filename);
	    }
	}
}

return aFileName;