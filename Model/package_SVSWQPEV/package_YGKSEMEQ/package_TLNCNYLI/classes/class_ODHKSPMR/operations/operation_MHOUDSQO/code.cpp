wxMenu* aPopUp =  new wxMenu("");

wxTreeItemId aID = event.GetItem();
AdeModelElement* element = myTree->GetItem(aID);
int type = element->GetType();

switch (type & 0x7F00000)
{

	case ITEM_IS_ATTRIBUTES:
		aPopUp->Append(ID_PASTE,"paste","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDATTRIBUTE,"add attribute","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		aPopUp->Enable(ID_PASTE,false);

		if (copySource.IsOk())
		{
			AdeModelElement* copyElement = myTree->GetItem(copySource);
			int copyType = copyElement->GetType();
			if ((copyType & 0x7FF00000) == ITEM_IS_ATTRIBUTE)
			aPopUp->Enable(ID_PASTE,true);
		}
	break;

	case ITEM_IS_ATTRIBUTE:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_COPY,"copy","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_CLASSES:
		aPopUp->Append(ID_ADDCLASS,"add class","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDLIBCLASS,"add lib class","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDSTATECHART,"add statechart","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_OBJECTMODELDIALOG,"Object model diagram","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_CLASS:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();

		if (!static_cast<AdeClass*>(element)->GetIsLibClass())
		{

			if (static_cast<AdeClass*>(element)->GetIsInActiveComponent())
				aPopUp->Append(ID_REMOVEFROMCOMPONENET,"remove from active componenet","", wxITEM_NORMAL);
			else
			{
				if (wxConfigBase::Get()->Read("TreeView/ActiveComponent")!="none")
					aPopUp->Append(ID_ADDTOCOMPONENET,"add to active componenet","", wxITEM_NORMAL);
			}

			aPopUp->Append(ID_GENCODE,"generate code","", wxITEM_NORMAL);
			aPopUp->AppendSeparator();

			aPopUp->Append(ID_ADDRELATION,"start relation to ...","", wxITEM_NORMAL);
			if (RelationStart.IsOk())
			{
				wxString mName = "complete relation from ";
				mName = mName + myTree->GetItem(RelationStart)->GetLabel();
				aPopUp->Append(ID_COMPLETERELATION,mName,"", wxITEM_NORMAL);
			}
			aPopUp->AppendSeparator();

			aPopUp->Append(ID_ADDATTRIBUTES,"add attributes","", wxITEM_NORMAL);
			aPopUp->Append(ID_ADDOPERATIONS,"add operations","", wxITEM_NORMAL);
			aPopUp->Append(ID_ADDTYPES,"add types","", wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_OBJECTMODELDIALOG,"Object model diagram","", wxITEM_NORMAL);
			aPopUp->AppendSeparator();
			aPopUp->Append(ID_EDITIMPLEMENTATION,"edit implementation","", wxITEM_NORMAL);
			aPopUp->Append(ID_EDITSPECIFICATION,"edit specification","", wxITEM_NORMAL);

			aPopUp->Append(ID_EDITPROLOGEPILOG,"edit prolog/epilog",CreatePrologEpilogMenu());

	        aPopUp->AppendSeparator();
			aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

			if (!static_cast<AdeClass*>(element)->GetIsInActiveComponent())
			{
				aPopUp->Enable(ID_GENCODE,false);
				aPopUp->Enable(ID_EDITIMPLEMENTATION,false);
				aPopUp->Enable(ID_EDITSPECIFICATION,false);
			}

			if (static_cast<AdeDirectoryElement*>(element)->GetHasAttributes())
				aPopUp->Enable(ID_ADDATTRIBUTES,false);

			if (static_cast<AdeDirectoryElement*>(element)->GetHasOperations())
				aPopUp->Enable(ID_ADDOPERATIONS,false);

			if (static_cast<AdeDirectoryElement*>(element)->GetHasTypes())
				aPopUp->Enable(ID_ADDTYPES,false);
		}
		else
		{
			if (RelationStart.IsOk())
			{
				wxString mName = "complete relation from ";
				mName = mName + myTree->GetItem(RelationStart)->GetLabel();
				aPopUp->Append(ID_COMPLETERELATION,mName,"", wxITEM_NORMAL);
				aPopUp->AppendSeparator();
			}
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
		aPopUp->Append(ID_ACTIVECONFIGURATION,"set as active component","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDCONFIGURATION,"add configuration","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_REGENERATE,"regenerate all","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		if (static_cast<AdeComponent*>(element)->IsActiveComponent())
			aPopUp->Enable(ID_ACTIVECONFIGURATION,false);
		else
			aPopUp->Enable(ID_REGENERATE,false);
	break;

	case ITEM_IS_CONFIGURATION:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_MAKE,"build","", wxITEM_NORMAL);
		aPopUp->Append(ID_MAKEALL,"rebuild","", wxITEM_NORMAL);
		aPopUp->Append(ID_INSTALL,"install","", wxITEM_NORMAL);

		if (theMakeProcess)
		{
			aPopUp->Enable(ID_MAKE,false);
			aPopUp->Enable(ID_MAKEALL,false);
			aPopUp->Enable(ID_INSTALL,false);
		}

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

	case ITEM_IS_FILES:
		if (element->GetLabel()=="manual")
			aPopUp->Append(ID_COPYFILE,"copy file","", wxITEM_NORMAL);
	break;

	case ITEM_IS_HFILE:
		aPopUp->Append(ID_EDIT,"edit","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_MAKE:
		aPopUp->Append(ID_EDIT,"edit","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_OPERATIONS:
		aPopUp->Append(ID_PASTE,"paste","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDOPERATION,"add operation","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDCONSTRUCTOR,"add constructor","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDDESTRUCTOR,"add destructor","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		if (static_cast<AdeDirectoryElement*>(element)->GetHasDestructor())
			aPopUp->Enable(ID_ADDDESTRUCTOR,false);

		aPopUp->Enable(ID_PASTE,false);

		if (copySource.IsOk())
		{
			AdeModelElement* copyElement = myTree->GetItem(copySource);
			int copyType = copyElement->GetType();
			if ((copyType & 0x7FF00000) == ITEM_IS_OPERATION)
			aPopUp->Enable(ID_PASTE,true);
		}
 	break;

	case ITEM_IS_OPERATION:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_COPY,"copy","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDPARAMETERS,"add parameters","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		if ((static_cast<AdeDirectoryElement*>(element)->GetHasParameters()) ||
			((type&ITEM_IS_DEST)==ITEM_IS_DEST))
			aPopUp->Enable(ID_ADDPARAMETERS,false);

 	break;

	case ITEM_IS_PACKAGE:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDPACKAGE,"add package","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDCLASSES,"add classes","", wxITEM_NORMAL);
		aPopUp->Append(ID_ADDSEQUENCES,"add sequences","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_OBJECTMODELDIALOG,"Object model diagram","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_PARAMETERS:
		aPopUp->Append(ID_PASTE,"paste","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDPARAMETER,"add parameter","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		aPopUp->Enable(ID_PASTE,false);

		if (copySource.IsOk())
		{
			AdeModelElement* copyElement = myTree->GetItem(copySource);
			int copyType = copyElement->GetType();
			if ((copyType & 0x7FF00000) == ITEM_IS_PARAMETER)
			aPopUp->Enable(ID_PASTE,true);
		}

	break;

	case ITEM_IS_PARAMETER:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_COPY,"copy","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_UP,"up","", wxITEM_NORMAL);
		aPopUp->Append(ID_DOWN,"down","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		if (myTree->GetItemData(myTree->GetPrevSibling(aID))==0)
			aPopUp->Enable(ID_UP,false);

		if (myTree->GetItemData(myTree->GetNextSibling(aID))==0)
			aPopUp->Enable(ID_DOWN,false);

	break;

	case ITEM_IS_RELATIONS:
		aPopUp->Append(ID_ADDRELATION,"start relation to ...","", wxITEM_NORMAL);
	break;

	case ITEM_IS_RELATION:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_MODEL:
   		aPopUp->Append(ID_ADDCOMPONENTFOLDER,"add component folder","", wxITEM_NORMAL);
   		aPopUp->Append(ID_ADDPACKAGE,"add package","", wxITEM_NORMAL);
        aPopUp->AppendSeparator();
		aPopUp->Append(-1,"select repository",CreateRepositoryMenu());
	break;

	case ITEM_IS_SEQUENCE:
		aPopUp->Append(ID_EDIT,"edit","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete","", wxITEM_NORMAL);
	break;

	case ITEM_IS_SEQUENCES:
		aPopUp->Append(ID_ADDSEQUENCEDIAGRAM,"add sequence diagram","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_STATE:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_ADDTRANSITION,"add transition","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
	break;

	case ITEM_IS_STATECHART:
	{
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();

		if (static_cast<AdeClass*>(element)->GetIsInActiveComponent())
			aPopUp->Append(ID_REMOVEFROMCOMPONENET,"remove from active componenet","", wxITEM_NORMAL);
		else
		{
			if (wxConfigBase::Get()->Read("TreeView/ActiveComponent")!="none")
				aPopUp->Append(ID_ADDTOCOMPONENET,"add to active componenet","", wxITEM_NORMAL);
		}

		aPopUp->Append(ID_GENSTATECHART,"generate code","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();

		if (RelationStart.IsOk())
		{
			wxString mName = "complete relation from ";
			mName = mName + myTree->GetItem(RelationStart)->GetLabel();
			aPopUp->Append(ID_COMPLETERELATION,mName,"", wxITEM_NORMAL);
			aPopUp->AppendSeparator();
		}

		aPopUp->Append(ID_ADDSTATE,"add state","", wxITEM_NORMAL);

		aPopUp->AppendSeparator();
		aPopUp->Append(ID_STATECHART,"Statechart","", wxITEM_NORMAL);

		aPopUp->AppendSeparator();
		aPopUp->Append(ID_EDITIMPLEMENTATION,"edit implementation","", wxITEM_NORMAL);
		aPopUp->Append(ID_EDITSPECIFICATION,"edit specification","", wxITEM_NORMAL);

        aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);

		if (!static_cast<AdeStatechart*>(element)->GetIsInActiveComponent())
		{
			aPopUp->Enable(ID_GENSTATECHART,false);
			aPopUp->Enable(ID_EDITIMPLEMENTATION,false);
			aPopUp->Enable(ID_EDITSPECIFICATION,false);
		}
	}
	break;

	case ITEM_IS_TYPES:
		aPopUp->Append(ID_ADDTYPE,"add type","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
 	break;

	case ITEM_IS_TYPE:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
 	break;

	case ITEM_IS_TRANSITION:
		aPopUp->Append(ID_FEATURES,"features","", wxITEM_NORMAL);
		aPopUp->AppendSeparator();
		aPopUp->Append(ID_DELETE,"delete from Model","", wxITEM_NORMAL);
 	break;
}

wxWindow aWindow(this,-1,wxPoint(0,0),wxSize(0,0));
aWindow.PopupMenu(aPopUp);
delete aPopUp;
