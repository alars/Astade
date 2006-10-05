#include "AstadeFrame.h"

BEGIN_EVENT_TABLE(AstadeFrame,wxFrame)
	EVT_TREE_ITEM_EXPANDING(ID_ASTADETREE, AstadeFrame::ExpandNode)
	EVT_TREE_ITEM_COLLAPSED(ID_ASTADETREE, AstadeFrame::CollapseNode)
	EVT_TREE_ITEM_RIGHT_CLICK(ID_ASTADETREE, AstadeFrame::OnRightMouseClick)
	//EVT_TREE_ITEM_ACTIVATED(ID_ASTADETREE, AstadeFrame::OnDoubleMouseClick) //Choi
 	EVT_TREE_SEL_CHANGED(ID_ASTADETREE,AstadeFrame::OnSelChanged)
 	EVT_UPDATE_UI(ID_ASTADETREE, AstadeFrame::DoUpdate)
    EVT_TIMER(TIMER_ID, AstadeFrame::OnTimer)
	EVT_MENU(ID_ACTIVECONFIGURATION, AstadeFrame::SetAsActive)
	EVT_MENU(ID_ADDATTRIBUTES, AstadeFrame::AddAttributes)
	EVT_MENU(ID_ADDATTRIBUTE, AstadeFrame::AddAttribute)
	EVT_MENU(ID_ADDCLASSES, AstadeFrame::AddClassesFolder)
	EVT_MENU(ID_ADDCLASS, AstadeFrame::AddClass)
	EVT_MENU(ID_ADDLIBCLASS, AstadeFrame::AddClass)
	EVT_MENU(ID_ADDCOMPONENTFOLDER, AstadeFrame::AddComponentFolder)
	EVT_MENU(ID_ADDCOMPONENT, AstadeFrame::AddComponent)
	EVT_MENU(ID_ADDCONFIGURATION, AstadeFrame::AddConfiguration)
	EVT_MENU(ID_ADDCONSTRUCTOR, AstadeFrame::AddConstructor)
	EVT_MENU(ID_ADDDESTRUCTOR, AstadeFrame::AddDestructor)
	EVT_MENU(ID_ADDOPERATIONS, AstadeFrame::AddOperations)
	EVT_MENU(ID_ADDOPERATION, AstadeFrame::AddOperation)
	EVT_MENU(ID_ADDRELATION, AstadeFrame::AddRelation)
	EVT_MENU(ID_ADDTOCOMPONENT, AstadeFrame::AddToComponent)
	EVT_MENU(ID_ADDPACKAGE, AstadeFrame::AddPackage)
	EVT_MENU(ID_ADDPARAMETERS, AstadeFrame::AddParameters)
	EVT_MENU(ID_ADDPARAMETER, AstadeFrame::AddParameter)
	EVT_MENU(ID_ADDRELATIONS, AstadeFrame::AddRelations)
	EVT_MENU(ID_ADDSTATECHART, AstadeFrame::AddStatechart)
	EVT_MENU(ID_ADDSTATE, AstadeFrame::AddState)
	EVT_MENU(ID_ADDTRANSITION, AstadeFrame::AddTransition)
	EVT_MENU(ID_ADDTYPES, AstadeFrame::AddTypes)
	EVT_MENU(ID_ADDTYPE, AstadeFrame::AddType)
	EVT_MENU(ID_COMPLETERELATION, AstadeFrame::CompleteRelation)
	EVT_MENU(ID_COPYMAKEFILE, AstadeFrame::CopyMakefile)
	EVT_MENU(ID_COPYFILE, AstadeFrame::Copyfile)
	EVT_MENU(ID_COPY, AstadeFrame::Copy)
	EVT_MENU(ID_CUT, AstadeFrame::Cut)
	EVT_MENU(ID_PASTE, AstadeFrame::Paste)
	EVT_MENU(ID_DELETE, AstadeFrame::Delete)
	EVT_MENU(ID_DOWN, AstadeFrame::ParameterDown)
	EVT_MENU(ID_EDIT, AstadeFrame::Edit)
	EVT_MENU(ID_EDITIMPLEMENTATION, AstadeFrame::EditImplementation)
	EVT_MENU(ID_EDITSPECIFICATION, AstadeFrame::EditSpecification)
	EVT_MENU(ID_EDITSPECPROLOG, AstadeFrame::EditPrologEpilog)
	EVT_MENU(ID_EDITIMPPROLOG, AstadeFrame::EditPrologEpilog)
	EVT_MENU(ID_EDITSPECEPILOG, AstadeFrame::EditPrologEpilog)
	EVT_MENU(ID_EDITIMPGEPILOG, AstadeFrame::EditPrologEpilog)
	EVT_MENU(ID_FEATURES, AstadeFrame::Features)
	EVT_MENU(ID_GENCODE, AstadeFrame::CallCoder)
	EVT_MENU(ID_GENSTATECHART, AstadeFrame::CallStatechartCoder)
	EVT_MENU(ID_MAKE, AstadeFrame::CallMake)
	EVT_MENU(ID_MAKEALL, AstadeFrame::CallMake)
	EVT_MENU(ID_SHOW, AstadeFrame::ShowHtml)
	EVT_MENU(ID_INSTALL, AstadeFrame::CallMake)
	EVT_MENU(ID_JUMPORIG, AstadeFrame::JumpToPartner)
	EVT_MENU(ID_JUMPDEST, AstadeFrame::JumpToPartner)
	EVT_MENU(ID_RUN, AstadeFrame::CallShell)
	EVT_MENU(ID_MNU_HELP, AstadeFrame::DisplayHelp)
	EVT_MENU(ID_MNU_INFO, AstadeFrame::DisplayInfo)
	EVT_MENU(ID_MNU_ABOUT, AstadeFrame::DisplayAbout)
	EVT_MENU(ID_OBJECTMODELDIALOG, AstadeFrame::OmdDialog)
	EVT_MENU(ID_REGENERATE, AstadeFrame::Regenerate)
	EVT_MENU(ID_REMOVEFROMCOMPONENT, AstadeFrame::RemoveFromComponent)
	EVT_MENU(ID_ADDSEQUENCES, AstadeFrame::AddSequencesFolder)
	EVT_MENU(ID_SETEDITORS, AstadeFrame::DirDialog)
	EVT_MENU(ID_SETREGEX, AstadeFrame::RegExDialog)
	EVT_MENU(ID_STATECHART, AstadeFrame::DisplayStatechart)
	EVT_MENU(ID_UP, AstadeFrame::ParameterUp)
	EVT_MENU(ID_SELECTMODEL, AstadeFrame::SelectModel)
	EVT_MENU(ID_ADDSEQUENCEDIAGRAM, AstadeFrame::AddSequenceDiagram)
	EVT_MENU(ID_ADDUSECASEDS, AstadeFrame::AddUsecaseDiagrams)
	EVT_MENU(ID_SELECTNONE, AstadeFrame::SelectRepository)
	EVT_MENU(ID_SELECTSVN, AstadeFrame::SelectRepository)
	EVT_MENU(ID_SELECTGIT, AstadeFrame::SelectRepository)
	EVT_MENU(ID_SELECTCVS, AstadeFrame::SelectRepository)
	EVT_MENU(ID_ADDUSECASEDIAGRAM, AstadeFrame::AddUseCaseDiagram)
	//EVT_MENU(ID_EXIT, AstadeFrame::OnExit)	//Choi
	EVT_MENU(ID_MAKEMAINCPP, AstadeFrame::MakeMainCpp)
	EVT_END_PROCESS(wxID_ANY, AstadeFrame::EndProcess)
END_EVENT_TABLE()
