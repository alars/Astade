/* vi: set tabstop=4: */

wxMenu* aPopUp = new wxMenu(wxEmptyString);

int flags = 0;
wxTreeItemId aID = myTree->HitTest(myTree->ScreenToClient(wxGetMousePosition()),flags);

if (!aID.IsOk() || (flags & (wxTREE_HITTEST_ONITEMLABEL | wxTREE_HITTEST_ONITEMICON)) == 0)
{
	wxConfigBase* theConfig = wxConfigBase::Get();
	wxString activeGUID = theConfig->Read("TreeView/ActiveGUID");
	AdeModelElement* aElement = AdeModelElement::CreateNewElement(AdeGUIDCache::Instance()->GetCachedEntry(activeGUID));
	AdeComponent* aComponent = dynamic_cast<AdeComponent*>(aElement);
	if (aComponent)
	{
		aPopUp->Append(-1,"Active component classes:",CreateJumpMenu(*aComponent));
	}
	delete aElement;
}
else
{
	myTree->SelectItem(aID);

	AdeModelElement* element = myTree->GetItem(aID);
	AstadeTreeItemBase* aTreeItem = myTree->GetItemObject(aID);

	int type = element->GetType();

	switch (type & ITEM_TYPE_MASK)
	{
		case ITEM_IS_COMPONENT:
			aPopUp->Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_ACTIVECONFIGURATION,"set as active component",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_ADDCONFIGURATION,"add configuration",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_ADDUSECASEDS,"add usecase diagrams",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_REGENERATE,"regenerate all",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_EDITPROLOGEPILOG,"edit prolog/epilog",CreatePrologEpilogMenu());
			aPopUp->AppendSeparator();

			if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
				aPopUp->Append(ID_RENAMEELEMENT,"Rename component folder",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(-1,"jump to class",CreateJumpMenu(*(dynamic_cast<AdeComponent*>(element))));

			if (dynamic_cast<AdeComponent*>(element)->IsActiveComponent())
				aPopUp->Enable(ID_ACTIVECONFIGURATION,false);
			else
				aPopUp->Enable(ID_REGENERATE,false);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_CONFIGURATION:
			aPopUp->Append(ID_FEATURES, "features", wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE, "paste", wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_CUT, "cut", wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_MAKECLEAN, "clean", wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_MAKE, "build", wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_MAKEALL, "rebuild", wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_INSTALL, "install", wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_RUN, "run", wxEmptyString, wxITEM_NORMAL);

			if (theMakeProcess)
			{
				aPopUp->Enable(ID_MAKECLEAN, false);
				aPopUp->Enable(ID_MAKE, false);
				aPopUp->Enable(ID_MAKEALL, false);
				aPopUp->Enable(ID_INSTALL, false);
				aPopUp->Enable(ID_RUN, false);
			}

			aPopUp->AppendSeparator();
			aPopUp->Append(ID_COPYMAKEFILE, "copy Makefile", wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();

			if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
				aPopUp->Append(ID_RENAMEELEMENT,"Rename configuration folder",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_FILE:
			aPopUp->Append(ID_EDIT,"edit",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete",wxEmptyString, wxITEM_NORMAL);
		break;

		case ITEM_IS_FILES:
			if (element->GetLabel()=="manual")
			{
				aPopUp->Append(ID_COPYFILE,"copy file",wxEmptyString, wxITEM_NORMAL);
				aPopUp->Append(ID_MAKEMAINCPP,"Make Empty main.cpp", wxEmptyString, wxITEM_NORMAL);
			}

		break;

		case ITEM_IS_MAKE:
			aPopUp->Append(ID_EDIT,"edit",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete",wxEmptyString, wxITEM_NORMAL);
		break;

		case ITEM_IS_OPERATIONS:
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_ADDOPERATION,"add operation",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_ADDCONSTRUCTOR,"add constructor",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_ADDDESTRUCTOR,"add destructor",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			if (dynamic_cast<AdeDirectoryElement*>(element)->GetHasDestructor())
				aPopUp->Enable(ID_ADDDESTRUCTOR,false);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
	 	break;

		case ITEM_IS_OPERATION:
			aPopUp->Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_COPY,"copy",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_ADDPARAMETERS,"add parameters",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();

			if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
				aPopUp->Append(ID_RENAMEELEMENT,"Rename element file",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			if ((dynamic_cast<AdeDirectoryElement*>(element)->GetHasParameters()) ||
				((type&ITEM_IS_DEST)==ITEM_IS_DEST))
				aPopUp->Enable(ID_ADDPARAMETERS,false);

	 	break;

		case ITEM_IS_PACKAGE:
			aPopUp->Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_COPY,"copy",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_ADDPACKAGE,"add package",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_ADDCLASSES,"add classes",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_ADDSEQUENCES,"add sequence diagrams",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_OBJECTMODELDIALOG,"Object model diagram",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();

			if (AdeRevisionControlBase::GetRevisionControlObject()->IsRenameSupported())
				aPopUp->Append(ID_RENAMEELEMENT,"Rename package folder",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			if (dynamic_cast<AdeDirectoryElement*>(element)->GetHasClasses())
				aPopUp->Enable(ID_ADDCLASSES,false);

			if (dynamic_cast<AdeDirectoryElement*>(element)->GetHasSequences())
				aPopUp->Enable(ID_ADDSEQUENCES,false);

			if (dynamic_cast<AdeDirectoryElement*>(element)->GetHasUsecaseDiagrams())
				aPopUp->Enable(ID_ADDUSECASEDS,false);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_RELATIONS:
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_ADDRELATION,"start relation to ...",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_RELATION:
			aPopUp->Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_JUMPDEST,"jump to destination",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_COPY,"copy",wxEmptyString, wxITEM_NORMAL);
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);
		break;

		case ITEM_IS_INRELATION:
			aPopUp->Append(ID_JUMPORIG,"jump to origin",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
		break;

		case ITEM_IS_MODEL:
	   		aPopUp->Append(ID_ADDCOMPONENTFOLDER,"add component folder",wxEmptyString, wxITEM_NORMAL);
	   		aPopUp->Append(ID_ADDPACKAGE,"add package",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(-1,"select repository",CreateRepositoryMenu());

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_SEQUENCE:
			aPopUp->Append(ID_EDIT,"edit",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete",wxEmptyString, wxITEM_NORMAL);
		break;

		case ITEM_IS_SEQUENCES:
			aPopUp->Append(ID_ADDSEQUENCEDIAGRAM,"add sequence diagram",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_TYPES:
			aPopUp->Append(ID_ADDTYPE,"add type",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
	 	break;

		case ITEM_IS_USECASE:
			aPopUp->Append(ID_EDIT,"edit",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete",wxEmptyString, wxITEM_NORMAL);
		break;

		case ITEM_IS_USECASEDIAGRAMS:
			aPopUp->Append(ID_ADDUSECASEDIAGRAM,"add use case diagram",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

			aPopUp->Enable(ID_PASTE,(copySource.IsOk() && IsPasteAble()));
		break;

		case ITEM_IS_WEBSITE:
			aPopUp->Append(ID_SHOW,"show",wxEmptyString, wxITEM_NORMAL);
		break;

		default:
		{
			if (copySource.IsOk())
				myTree->GetItemObject(copySource)->SetToGlobalCopySource();
			aTreeItem->AppendMenuItems(*aPopUp);
		}
		break;
	}
}

PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
