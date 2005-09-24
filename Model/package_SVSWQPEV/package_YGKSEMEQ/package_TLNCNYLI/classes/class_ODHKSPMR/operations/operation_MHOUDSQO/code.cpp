wxMenu* aPopUp =  new wxMenu("");

wxTreeItemId aID = event.GetItem();
AdeModelElement* element = myTree->GetItem(aID);
int type = element->GetType();

switch (type & 0x7F00000)
{

	case ITEM_IS_CLASSES:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDCLASS,"add class","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_CLASS:
	{
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		if (static_cast<AdeClass*>(element)->GetIsInActiveComponent())
			aPopUp->Append(ID_REMOVEFROMCOMPONENET,"remove from active componenet","", wxITEM_NORMAL);
		else
			aPopUp->Append(ID_ADDTOCOMPONENET,"add to active componenet","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();

		aPopUp->Append(ID_ADDATTRIBUTES,"add attributes","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDOPERATIONS,"add operations","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDCLASSES,"add classes","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDRELATIONS,"add relations","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDTYPES,"add types","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_OBJECTMODELDIAGRAM,"Object model diagram","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_GENCODE,"generate code","", wxITEM_NORMAL);
		aPopUp->Append(ID_EDITIMPLEMENTATION,"edit implementation","", wxITEM_NORMAL);
		aPopUp->Append(ID_EDITSPECIFICATION,"edit specification","", wxITEM_NORMAL);

		wxMenu* aSubUp =  new wxMenu("");
		aSubUp->Append(ID_EDITSPECPROLOG,"edit specification prolog","", wxITEM_NORMAL);
		aSubUp->Append(ID_EDITIMPPROLOG,"edit implementation prolog","", wxITEM_NORMAL);
		aSubUp->Append(ID_EDITSPECEPILOG,"edit specification epilog","", wxITEM_NORMAL);
		aSubUp->Append(ID_EDITIMPGEPILOG,"edit implementation epilog","", wxITEM_NORMAL);

		aPopUp->Append(ID_EDITPROLOGEPILOG,"edit prolog/epilog",aSubUp);

        aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	}
	break;

	case ITEM_IS_COMPONENTS:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDCOMPONENT,"add component","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_COMPONENT:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_GENERATE,"generate code","", wxITEM_NORMAL);
		aPopUp->Append(ID_REGENERATE,"regenerate code","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ACTIVECONFIGURATION,"set as active component","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDCONFIGURATION,"add configuration","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_CONFIGURATION:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_MAKE,"make","", wxITEM_NORMAL);
		aPopUp->Append(ID_MAKEALL,"make all","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_COPYMAKEFILE,"copy Makefile","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_CPPFILE:
		aPopUp->Append(ID_EDIT,"edit","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_FILE:
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_HFILE:
		aPopUp->Append(ID_EDIT,"edit","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_MAKE:
		aPopUp->Append(ID_EDIT,"edit","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_MAKE,"make","", wxITEM_NORMAL);
		aPopUp->Append(ID_MAKEALL,"make all","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_PACKAGE:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDPACKAGE,"add package","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDCLASSES,"add classes","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_OBJECTMODELDIAGRAM,"Object model diagram","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		if (element->GetHasClasses())
			aPopUp->Enable(ID_ADDCLASSES,false);
	break;

	case ITEM_IS_MODEL:
   		aPopUp->Append(ID_ADDCOMPONENTFOLDER,"add component folder","", wxITEM_NORMAL);
   		aPopUp->Append(ID_ADDPACKAGE,"add package","", wxITEM_NORMAL);
	break;

}

wxWindow aWindow(this,-1,wxPoint(0,0),wxSize(0,0));
aWindow.PopupMenu(aPopUp);
delete aPopUp;
