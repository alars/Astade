#ifdef __GNUG__
    #pragma implementation "AstadeFrame.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstopCodeEditor
#endif


#include "AstadeFrame.h"
#include "ctreeitemdata.h"
#include <wx/dir.h>


BEGIN_EVENT_TABLE(AstadeFrame,wxFrame)
	EVT_TREE_BEGIN_DRAG(ID_WXTREECTRL,AstadeFrame::OnBeginDrag)
	EVT_TREE_ITEM_RIGHT_CLICK(ID_WXTREECTRL,AstadeFrame::OnRightMouseClick)
	EVT_TREE_ITEM_EXPANDING(ID_WXTREECTRL, AstadeFrame::ExpandNode)	
	EVT_TREE_ITEM_COLLAPSING(ID_WXTREECTRL, AstadeFrame::CollapsNode)	
 	EVT_TREE_SEL_CHANGED(ID_WXTREECTRL,AstadeFrame::OnSelChanged)
 	EVT_TREE_BEGIN_LABEL_EDIT(ID_WXTREECTRL, AstadeFrame::OnBeginEdit)
    EVT_TREE_END_LABEL_EDIT(ID_WXTREECTRL, AstadeFrame::OnEndEdit)
	EVT_MENU(ID_SETMOULEPATH, AstadeFrame::SetModulePath)	
	EVT_MENU(ID_ADDPACKAGE, AstadeFrame::AddPackage)	
	EVT_MENU(ID_ADDCLASS, AstadeFrame::AddClass)	
	EVT_MENU(ID_ADDCLASSES, AstadeFrame::AddClasses)	
	EVT_MENU(ID_ADDRELATIONS, AstadeFrame::AddRelations)	
	EVT_MENU(ID_ADDCOMPONENTFOLDER, AstadeFrame::AddComponentFolder)	
	EVT_MENU(ID_ADDCOMPONENT, AstadeFrame::AddComponent)	
	EVT_MENU(ID_ADDCONFIGURATION, AstadeFrame::AddConfiguration)	
	EVT_MENU(ID_ADDATTRIBUTE, AstadeFrame::AddAttribute)	
	EVT_MENU(ID_ADDATTRIBUTES, AstadeFrame::AddAttributes)	
	EVT_MENU(ID_ADDOPERATION, AstadeFrame::AddOperation)	
	EVT_MENU(ID_ADDCONSTRUCTOR, AstadeFrame::AddConstructor)	
	EVT_MENU(ID_ADDDESTRUCTOR, AstadeFrame::AddDestructor)	
	EVT_MENU(ID_ADDOPERATIONS, AstadeFrame::AddOperations)	
	EVT_MENU(ID_ADDPARAMETERS, AstadeFrame::AddParameters)	
	EVT_MENU(ID_ADDPARAMETER, AstadeFrame::AddParameter)	
	EVT_MENU(ID_SETCLASSEDITOR, AstadeFrame::SetClassEditor)	
	EVT_MENU(ID_SETATTRIBEDITOR, AstadeFrame::SetAttributeEditor)	
	EVT_MENU(ID_SETPARAMEDITOR, AstadeFrame::SetParameterEditor)	
	EVT_MENU(ID_SETRELATIONEDITOR, AstadeFrame::SetRelationEditor)	
    EVT_MENU(ID_SETOPEDITOR, AstadeFrame::SetOpEditor)	
	EVT_MENU(ID_SETCODEEDITOR, AstadeFrame::SetCodeEditor)	
	EVT_MENU(ID_SETOMDVIEWER, AstadeFrame::SetOMDViewer)	
	EVT_MENU(ID_SETCODER, AstadeFrame::SetCoder)	
	EVT_MENU(ID_CLASSFEATURES, AstadeFrame::CallClassEditor)	
	EVT_MENU(ID_ATTRIBFEATURES, AstadeFrame::CallAttributeEditor)	
	EVT_MENU(ID_RELATIONFEATURES, AstadeFrame::CallRelationEditor)	
	EVT_MENU(ID_INRELATIONFEATURES, AstadeFrame::CallInRelationEditor)	
	EVT_MENU(ID_PARAMFEATURES, AstadeFrame::CallParameterEditor)	
	EVT_MENU(ID_OPFEATURES, AstadeFrame::CallOpEditor)	
	EVT_MENU(ID_GENCODE, AstadeFrame::CallCoder)	
	EVT_MENU(ID_DELETE, AstadeFrame::Delete)	
	EVT_MENU(ID_UP, AstadeFrame::Up)	
	EVT_MENU(ID_DOWN, AstadeFrame::Down)	
	EVT_MENU(ID_CODE, AstadeFrame::CallCodeEditor)	
	EVT_MENU(ID_EDITIMPLEMENTATION, AstadeFrame::CallImplementationEditor)	
	EVT_MENU(ID_EDITSPECIFICATION, AstadeFrame::CallSpecificationEditor)	
	EVT_MENU(ID_ADDRELATION, AstadeFrame::DoStartRelation)	
	EVT_MENU(ID_COMPLETERELATION, AstadeFrame::DoCompleteRelation)	
	EVT_MENU(ID_OBJECTMODELDIAGRAM, AstadeFrame::ShowOMD)	
	EVT_SIZE(AstadeFrame::SizeChanged)	
	EVT_CLOSE(AstadeFrame::AstadeFrameClose)
END_EVENT_TABLE()
 


AstadeFrame::AstadeFrame() : wxFrame(NULL,1,"")
{
    srand(static_cast<unsigned>(time(0)));
	myStatusBar =  new wxStatusBar(this, ID_WXSTATUSBAR );
	myTree =  new CAstadeTree(this, ID_WXTREECTRL, wxPoint(0,0),GetClientSize(), wxTR_HAS_BUTTONS|wxTR_EDIT_LABELS);
	myToolBar =  new wxToolBar(this, ID_WXTOOLBAR , wxPoint(0,0),wxSize(369,32) );
	myToolBar->Realize();

	this->SetToolBar(myToolBar);
	this->SetStatusBar(myStatusBar);
	this->SetTitle(_("Astade"));
    this->SetIcon(wxIcon("ICO00",wxBITMAP_TYPE_ICO_RESOURCE	));
	
    int xPos,yPos,xSize,ySize;
	
    if ( wxGetResource("TreeView","XPos", &xPos,"Astade.ini") &&
         wxGetResource("TreeView","YPos", &yPos,"Astade.ini") &&
         wxGetResource("TreeView","XSize", &xSize,"Astade.ini") &&
         wxGetResource("TreeView","YSize", &ySize,"Astade.ini"))
    {
	    this->SetSize(xPos,yPos,xSize,ySize);
    }
    else
    {
	    this->SetSize(8,8,380,350);
	    this->Center();
    }    
        
    myImageList.Create(16,16);
    for (int i=0;i<=36;i++)
    {
        char* Buffer = new char[10];
        sprintf(Buffer,"ICO%02d",i);
        myImageList.Add(wxIcon(Buffer,wxBITMAP_TYPE_ICO_RESOURCE	));
    }    

    wxTreeItemId root;
    myTree->SetImageList(&myImageList);
    root = myTree->AddRoot("model",1);
    wxChar* path;
    wxGetResource("TreeView","ModelPath", &path,"Astade.ini");
    RootName = wxString(path);
    wxFileName::SetCwd(RootName);
    
    wxGetResource("Editor","Class", &path,"Astade.ini");
    ClassEditor = wxFileName(path);
    
    wxGetResource("Editor","Attribute", &path,"Astade.ini");
    AttributeEditor = wxFileName(path);
    
    wxGetResource("Editor","Relation", &path,"Astade.ini");
    RelationEditor = wxFileName(path);
    
    wxGetResource("Editor","Parameter", &path,"Astade.ini");
    ParameterEditor = wxFileName(path);
    
    wxGetResource("Editor","Operation", &path,"Astade.ini");
    OperationEditor = wxFileName(path);
    
    wxGetResource("Editor","Code", &path,"Astade.ini");
    CodeEditor = wxFileName(path);
    
    wxGetResource("Editor","OMD", &path,"Astade.ini");
    OMDViewer = wxFileName(path);
    
    wxGetResource("Editor","Coder", &path,"Astade.ini");
    Coder = wxFileName(path);
    
    CTreeItemData* t = new CTreeItemData;
    t->path = wxFileName(RootName,"");
    t->type = ITEM_IS_MODEL|ITEM_IS_FOLDER;
    myTree->SetItemData(root,t);
    myTree->SetItemHasChildren(root);
}

AstadeFrame::~AstadeFrame()
{
} 

void AstadeFrame::AstadeFrameClose(wxCloseEvent& event)
{
    // --> Don't use Close with a Frame,
    // use Destroy instead.
    int x,y;
    GetPosition(&x,&y);
    wxWriteResource("TreeView","XPos", x,"Astade.ini");
    wxWriteResource("TreeView","YPos", y,"Astade.ini");
    GetSize(&x,&y);
    wxWriteResource("TreeView","XSize", x,"Astade.ini");
    wxWriteResource("TreeView","YSize", y,"Astade.ini");
    Destroy();
}
 
void AstadeFrame::OnBeginDrag(wxTreeEvent& event)
{
    wxLogMessage(_T("OnBeginDrag"));
}

void AstadeFrame::OnRightMouseClick(wxTreeEvent& event)
{
    wxMenu* aPopUp =  new wxMenu(_("")  );

    
    wxTreeItemId aID = event.GetItem();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        int iEntryType = static_cast<CTreeItemData*>(data)->type;
    
        IS_ITEM(iEntryType,ITEM_IS_MODEL)
        {
    	    aPopUp->Append(ID_ADDCOMPONENTFOLDER,_("add component folder"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDPACKAGE,_("add package"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_SETMOULEPATH,_("set modelpath"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETCLASSEDITOR,_("set class feature editor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETATTRIBEDITOR,_("set attribute feature editor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETPARAMEDITOR,_("set parameter feature editor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETOPEDITOR,_("set operation feature editor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETCODEEDITOR,_("set operation code editor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETRELATIONEDITOR,_("set relation feature editor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETOMDVIEWER,_("set object model diagram viewer"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_SETCODER,_("set code builder"),_(""), wxITEM_NORMAL);
   	    }    
    
        IS_ITEM(iEntryType,ITEM_IS_PACKAGE)
        {
    	    aPopUp->Append(ID_ADDPACKAGE,_("add package"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDCLASSES,_("add classes"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_OBJECTMODELDIAGRAM,_("Object model diagram"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);

    	    wxFileName newPath = path;
    	    newPath.AppendDir("classes");
    	    if (wxDirExists(newPath.GetPath()))
    	    {
    	        aPopUp->Enable(ID_ADDCLASSES,false);
    	    }    
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_CLASSES)
        {
    	    aPopUp->Append(ID_ADDCLASS,_("add class"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_OBJECTMODELDIAGRAM,_("Object model diagram"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_COMPONENTS)
        {
    	    aPopUp->Append(ID_ADDCOMPONENT,_("add component"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_PARAMETERS)
        {
    	    aPopUp->Append(ID_ADDPARAMETER,_("add parameter"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_PARAMETER)
        {
    	    aPopUp->Append(ID_PARAMFEATURES,_("features"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_UP,_("up"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_DOWN,_("down"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
    	    
    	    if (myTree->GetItemData(myTree->GetPrevSibling(aID))==0)
    	    {
    	        aPopUp->Enable(ID_UP,false);
    	    }    
    	    
    	    if (myTree->GetItemData(myTree->GetNextSibling(aID))==0)
    	    {
    	        aPopUp->Enable(ID_DOWN,false);
    	    }    
    	    
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_COMPONENT)
        {
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_CONFIGURATION)
        {
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_COMPONENT)
        {
    	    aPopUp->Append(ID_ADDCONFIGURATION,_("add configuration"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_RELATIONS)
        {
    	    aPopUp->Append(ID_ADDRELATION,_("start relation to ..."),_(""), wxITEM_NORMAL);
    	    if (RelationStart.IsOk())
            {
                wxTreeItemData* data = myTree->GetItemData(RelationStart);
                if (data)
                {
                    wxString mName = "complete relation from ";
                    mName = mName + myTree->GetItemText(myTree->GetItemParent(RelationStart));
                    aPopUp->Append(ID_COMPLETERELATION,mName,_(""), wxITEM_NORMAL);
                }    
            }    
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_CLASS)
        {
    	    aPopUp->Append(ID_CLASSFEATURES,_("features"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDATTRIBUTES,_("add attributes"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDOPERATIONS,_("add operations"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDCLASSES,_("add classes"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDRELATIONS,_("add relations"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_OBJECTMODELDIAGRAM,_("Object model diagram"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_GENCODE,_("generate code"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_EDITIMPLEMENTATION,_("edit implementation"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_EDITSPECIFICATION,_("edit specification"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
    	    
    	    wxFileName newPath = path;
    	    newPath.AppendDir("attributes");
    	    if (wxDirExists(newPath.GetPath()))
    	    {
    	        aPopUp->Enable(ID_ADDATTRIBUTES,false);
    	    }    

    	    newPath = path;
    	    newPath.AppendDir("operations");
    	    if (wxDirExists(newPath.GetPath()))
    	    {
    	        aPopUp->Enable(ID_ADDOPERATIONS,false);
    	    }    

    	    newPath = path;
    	    newPath.AppendDir("classes");
    	    if (wxDirExists(newPath.GetPath()))
    	    {
    	        aPopUp->Enable(ID_ADDCLASSES,false);
    	    }    

    	    newPath = path;
    	    newPath.AppendDir("relations");
    	    if (wxDirExists(newPath.GetPath()))
    	    {
    	        aPopUp->Enable(ID_ADDRELATIONS,false);
    	    }    
   	    }    
    
        IS_ITEM(iEntryType,ITEM_IS_ATTRIBUTE)
        {
    	    aPopUp->Append(ID_ATTRIBFEATURES,_("features"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_RELATION)
        {
    	    aPopUp->Append(ID_RELATIONFEATURES,_("features"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_INRELATION)
        {
    	    aPopUp->Append(ID_INRELATIONFEATURES,_("features"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_ATTRIBUTES)
        {
    	    aPopUp->Append(ID_ADDATTRIBUTE,_("add attribute"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_OPERATIONS)
        {
    	    aPopUp->Append(ID_ADDOPERATION,_("add operation"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDCONSTRUCTOR,_("add constructor"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDDESTRUCTOR,_("add destructor"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);

    	    wxFileName newPath = path;
    	    newPath.AppendDir("destructor");
    	    if (wxDirExists(newPath.GetPath()))
    	    {
    	        aPopUp->Enable(ID_ADDDESTRUCTOR,false);
    	    }    
   	    }    

        IS_ITEM(iEntryType,ITEM_IS_OPERATION)
        {
    	    aPopUp->Append(ID_OPFEATURES,_("features"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_CODE,_("code"),_(""), wxITEM_NORMAL);
    	    aPopUp->Append(ID_ADDPARAMETERS,_("add parameters"),_(""), wxITEM_NORMAL);
    	    aPopUp->AppendSeparator();
    	    aPopUp->Append(ID_DELETE,_("delete from Model"),_(""), wxITEM_NORMAL);

    	    wxFileName newPath = path;
    	    newPath.AppendDir("parameters");
    	    if (wxDirExists(newPath.GetPath())||((iEntryType&ITEM_IS_DEST)==ITEM_IS_DEST))
    	    {
    	        aPopUp->Enable(ID_ADDPARAMETERS,false);
    	    }    

   	    }    

        wxWindow* aWindow = new wxWindow(this,-1);
        aWindow->PopupMenu(aPopUp);
        delete aPopUp;
    }    
}

void AstadeFrame::UpdateText(wxTreeItemId aID)
{
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        int theType = static_cast<CTreeItemData*>(data)->type;

        IS_ITEM(theType,ITEM_IS_INRELATION)
        {
            wxChar* name = new wxChar[200];
            wxString theName = path.GetFullPath();
            wxGetResource("Relation","PartnerPath", &name, theName);
            wxFileName partnerName = wxString(name);
            partnerName.MakeAbsolute(RootName);

            wxGetResource("Astade","RelationType", &name, partnerName.GetFullPath());            
            wxString CodingType = name;

            int i = partnerName.GetDirCount();
            partnerName.RemoveDir(i-1);
            partnerName.SetName("Desktop"); 
            partnerName.SetExt("ini");
            wxString sName = "*deleted*";
            if (wxGetResource("Astade","Name", &name, partnerName.GetFullPath()))
                sName = name;
            wxString sText = "from: "+sName;
            myTree->SetItemText(aID,sText);    

        	if (CodingType=="ImplementationDependency")
        	     myTree->SetItemImage(aID,28);
        	
        	if (CodingType=="SpecificationDependency")
        	     myTree->SetItemImage(aID,28);
        	
        	if (CodingType=="Association")
        	     myTree->SetItemImage(aID,30);
        	
        	if (CodingType=="Agregation")
        	     myTree->SetItemImage(aID,32);
        	
        	if (CodingType=="Composition")
        	     myTree->SetItemImage(aID,34);
        	
        	if (CodingType=="Generalization")
        	     myTree->SetItemImage(aID,36);
            
            delete [] name;
       }    
       
        IS_ITEM(theType,ITEM_IS_RELATION)
        {
            wxChar* name = new wxChar[200];
            wxString theName = path.GetFullPath();
            wxGetResource("Relation","PartnerPath", &name, theName);
            wxFileName partnerName = wxString(name);
            partnerName.MakeAbsolute(RootName);

            wxGetResource("Astade","RelationType", &name, theName);            
            wxString CodingType = name;

            int i = partnerName.GetDirCount();
            partnerName.RemoveDir(i-1);
            partnerName.SetName("Desktop"); 
            partnerName.SetExt("ini");
            wxString sName = "*deleted*";
            if (wxGetResource("Astade","Name", &name, partnerName.GetFullPath()))
                sName = name;
            wxString sText = "to: "+sName;
            myTree->SetItemText(aID,sText);    

        	if (CodingType=="ImplementationDependency")
        	     myTree->SetItemImage(aID,26);
        	
        	if (CodingType=="SpecificationDependency")
        	     myTree->SetItemImage(aID,26);
        	
        	if (CodingType=="Association")
        	     myTree->SetItemImage(aID,29);
        	
        	if (CodingType=="Agregation")
        	     myTree->SetItemImage(aID,31);
        	
        	if (CodingType=="Composition")
        	     myTree->SetItemImage(aID,33);
        	
        	if (CodingType=="Generalization")
        	     myTree->SetItemImage(aID,35);
            
            delete [] name;
        }    
       
         IS_ITEM(theType,ITEM_IS_PARAMETER)
        {
            wxChar* name = new wxChar[200];
            wxString theName = path.GetFullPath();
            wxGetResource("Astade","Name", &name, theName);
            wxString sName = name;
            wxGetResource("Astade","CodingType", &name, theName);
            wxString sType = Decode(name);
            name = "";
            wxGetResource("Parameter","InitialValue", &name, theName);
            wxString sValue = name;

            wxString sText;
            if (sValue.length()==0)
                sText = sType+" "+sName;
            else
                sText = sType+" "+sName+" = "+sValue;
            myTree->SetItemText(aID,sText);    
                        
            delete [] name;
        }    
        
        IS_ITEM(theType,ITEM_IS_ATTRIBUTE)
        {
            wxChar* name = new wxChar[200];
            wxString theName = path.GetFullPath();
            wxGetResource("Astade","Name", &name, theName);
            wxString sName = name;
            wxGetResource("Astade","CodingType", &name, theName);
            wxString sType = Decode(name);
            wxGetResource("Astade","Type", &theType, theName);
            if (static_cast<CTreeItemData*>(data)->type != theType)
            {
                static_cast<CTreeItemData*>(data)->type = theType;
                myTree->SetItemImage(aID,selectIcon(theType));
                wxTreeItemId parent = myTree->GetItemParent(aID);
                myTree->SortChildren(parent);
            }    
            
            name = "";
            wxGetResource("Astade","Default", &name, theName);
            wxString sValue = Decode(name);

            wxString sText;
            if (sValue.length()==0)
                sText = sType+" "+sName;
            else
                sText = sType+" "+sName+" = "+sValue;
            
            if (wxGetResource("Astade","Static", &name, theName))
            {
                if (wxString(name)=="yes")
                    sText = "static " + sText; 
            } 
               
            if (wxGetResource("Astade","Const", &name, theName))
            {
                if (wxString(name)=="yes")
                    sText = "const " + sText; 
            } 
               
            myTree->SetItemText(aID,sText);    
                        
            delete [] name;
        }    
        
        IS_ITEM(theType,ITEM_IS_OPERATION)
        {
            path.SetName("Desktop"); 
            path.SetExt("ini");
             
            wxChar* name = new wxChar[200];
            wxString theName = path.GetFullPath();
            wxGetResource("Astade","Name", &name, theName);
            wxString sName = name;
            wxGetResource("Astade","Type", &theType, theName);
            if (static_cast<CTreeItemData*>(data)->type != theType)
            {
                static_cast<CTreeItemData*>(data)->type = theType;
                myTree->SetItemImage(aID,selectIcon(theType));
                wxTreeItemId parent = myTree->GetItemParent(aID);
                myTree->SortChildren(parent);
            }    
            
            wxFileName parameterPath = path;
            parameterPath.AppendDir("parameters");
            wxString paramlist;
                
            if (wxFileName(parameterPath.GetPath()).DirExists())
            {
                wxString filename;
                
                wxDir dir(parameterPath.GetPath());
                bool cont = dir.GetFirst(&filename,"*.ini");
                
                wxString params[256];
                wxString types[256];
                
                while ( cont )
                {
                    wxFileName newPath(parameterPath);
                    newPath.SetFullName(filename);
                    
                    int type;
                    wxGetResource("Astade","Type", &type, newPath.GetFullPath());
                    
                    IS_ITEM(type,ITEM_IS_PARAMETER)
                    {
                        int number = type & 0xff;
    
                        wxChar* name = new wxChar[200];
                        wxGetResource("Astade","Name", &name, newPath.GetFullPath());
                        params[number] = name;
                        wxGetResource("Astade","CodingType", &name, newPath.GetFullPath());
                        types[number] = Decode(name);
                        delete [] name;
                    }
    
                    cont = dir.GetNext(&filename);
                }
    
                for (int i=0;i<256;++i)
                {
                    if (params[i].length()!=0)
                    {
                        if (paramlist.length()!=0)
                            paramlist = paramlist + ",";
                        paramlist = paramlist + types[i] + " " + params[i];
                    }    
                }    
            }
            
            name = "";  
            wxString typestr;
            
            if ((theType&ITEM_IS_NORMALOP)==ITEM_IS_NORMALOP)      
            {
                wxGetResource("Astade","CodingType", &name, theName);
                typestr = name;
                typestr = typestr + " ";
            } 
               
            wxString sText = typestr+sName+"("+paramlist+")";
            
            if (wxGetResource("Astade","Virtual", &name, theName))
            {
                if (wxString(name)=="yes")
                    sText = "virtual " + sText; 
            } 
               
            if (wxGetResource("Astade","Abstract", &name, theName))
            {
                if (wxString(name)=="yes")
                    sText = "pure " + sText; 
            } 
               
            if (wxGetResource("Astade","Static", &name, theName))
            {
                if (wxString(name)=="yes")
                    sText = "static " + sText; 
            } 
               
            if (wxGetResource("Astade","Const", &name, theName))
            {
                if (wxString(name)=="yes")
                    sText = "const " + sText; 
            } 
               
            myTree->SetItemText(aID,sText);    
                        
            delete [] name;
        }    

        IS_ITEM(theType,ITEM_IS_CLASS)
        {
            path.SetName("Desktop"); 
            path.SetExt("ini");
             
            wxChar* name = new wxChar[200];
            wxString theName = path.GetFullPath();
            wxGetResource("Astade","Name", &name, theName);
            wxString sName = name;

            myTree->SetItemText(aID,sName);    
                        
            delete [] name;
        }    

    }    
}    

void AstadeFrame::OnSelChanged(wxTreeEvent& event)
{
    wxTreeItemData* data = myTree->GetItemData(myTree->GetSelection());
    if (data)
    {
        wxTreeItemId oldID = event.GetOldItem();
        wxTreeItemId newID = event.GetItem();
        
        UpdateText(oldID);
        UpdateText(newID);
       
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        if (myTree->GetSelection()!=myTree->GetRootItem())
             path.MakeRelativeTo(RootName);
        myStatusBar->PushStatusText(path.GetFullPath());

        IS_ITEM(static_cast<CTreeItemData*>(data)->type,ITEM_IS_PARAMETER)
        {
            UpdateText(myTree->GetItemParent(myTree->GetItemParent(newID)));
        }              
    }    
    else
        myStatusBar->PushStatusText("No Data");
}
void AstadeFrame::SizeChanged(wxSizeEvent& event)
{
    myTree->SetSize(GetClientSize());
}

void AstadeFrame::ExpandNode(wxTreeEvent& event)
{
    wxTreeItemId aID = event.GetItem();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxDir dir(path.GetFullPath());
    
        if ( !dir.IsOpened() )
             return;
    
        wxString filename;
        // Verzeichnisse
        bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_DIRS);
        while ( cont )
        {
            wxFileName newPath(path);
            newPath.AppendDir(filename);
            wxFileName iniPath(newPath);
            
            iniPath.SetName("Desktop"); 
            iniPath.SetExt("ini"); 
            
            wxChar* name = new wxChar[200];
            int type=0;
            
            wxString theName = iniPath.GetFullPath();
            
            wxGetResource("Astade","Type", &type, theName);
            wxGetResource("Astade","Name", &name, theName);
                

            wxTreeItemId newItem = myTree->AppendItem(aID,name, selectIcon(type));
            delete [] name;
            
            CTreeItemData* t = new CTreeItemData;
            t->path = newPath;
            t->type = type;
            myTree->SetItemData(newItem,t);
            UpdateText(newItem);
            
            wxDir newDir(newPath.GetFullPath());
            wxString tmp;
            if (newDir.GetFirst(&tmp,wxEmptyString,wxDIR_DIRS ) )
                myTree->SetItemHasChildren(newItem);
            else
            {
               //Testen obs Files gibt
               wxString newfilename;
               bool cont = newDir.GetFirst(&newfilename,"*.ini",wxDIR_FILES);
                while ( cont )
                {
                    if (newfilename!="Desktop.ini")
                    {
                        myTree->SetItemHasChildren(newItem);
                        break;
                    }    
                    cont = newDir.GetNext(&newfilename);
                }
            }    
            
            cont = dir.GetNext(&filename);
        }
        
        // Dateien
        cont = dir.GetFirst(&filename,"*.ini",wxDIR_FILES);
        while ( cont )
        {
            if (filename!="Desktop.ini")
            {
                wxFileName newPath(path);
                newPath.SetName(filename);
                
                wxChar* name = new wxChar[200];
                int type=0;
                
                wxString theName = newPath.GetFullPath();
                
                wxGetResource("Astade","Type", &type, theName);
                wxGetResource("Astade","Name", &name, theName);
                    
    
                wxTreeItemId newItem = myTree->AppendItem(aID,name, selectIcon(type));
                delete [] name;


                CTreeItemData* t = new CTreeItemData;
                t->path = newPath;
                t->type = type;
                myTree->SetItemData(newItem,t);
                UpdateText(newItem);
            }    
            cont = dir.GetNext(&filename);
        }
        myTree->SortChildren(aID);
    }    
}

int AstadeFrame::selectIcon(int iType)
{
   int IconIndex = 0;
   
   iType &= ~(ITEM_IS_FOLDER);
   iType &= 0x7FFFFF00; //count maskieren
   
   switch (iType)
   {
       case ITEM_IS_COMPONENTS:
           IconIndex = 4;
       break;

       case ITEM_IS_ATTRIBUTE|ITEM_IS_PUBLIC:
           IconIndex = 7;
       break;

       case ITEM_IS_ATTRIBUTE|ITEM_IS_PRIVATE:
           IconIndex = 11;
       break;

       case ITEM_IS_ATTRIBUTE|ITEM_IS_PROTECTED:
           IconIndex = 12;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PUBLIC|ITEM_IS_NORMALOP:
           IconIndex = 8;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PRIVATE|ITEM_IS_NORMALOP:
           IconIndex = 18;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PROTECTED|ITEM_IS_NORMALOP:
           IconIndex = 19;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PUBLIC|ITEM_IS_DEST:
           IconIndex = 23;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PRIVATE|ITEM_IS_DEST:
           IconIndex = 24;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PROTECTED|ITEM_IS_DEST:
           IconIndex = 25;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PUBLIC:
           IconIndex = 20;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PRIVATE:
           IconIndex = 21;
       break;

       case ITEM_IS_OPERATION|ITEM_IS_PROTECTED:
           IconIndex = 22;
       break;

       case ITEM_IS_PARAMETER:
           IconIndex = 17;
       break;

       case ITEM_IS_MODEL:
           IconIndex = 1;
       break;

       case ITEM_IS_COMPONENT:
           IconIndex = 6;
       break;

       case ITEM_IS_CONFIGURATION:
           IconIndex = 9;
       break;

       case ITEM_IS_TARGET:
           IconIndex = 10;
       break;

       case ITEM_IS_CLASS:
           IconIndex = 5;
       break;

       case ITEM_IS_PACKAGE:
           IconIndex = 2;
       break;

       case ITEM_IS_ATTRIBUTES:
           IconIndex = 13;
       break;

       case ITEM_IS_OPERATIONS:
           IconIndex = 14;
       break;

       case ITEM_IS_PARAMETERS:
           IconIndex = 15;
       break;

       case ITEM_IS_CLASSES:
           IconIndex = 16;
       break;

       case ITEM_IS_RELATION:
           IconIndex = 26;
       break;

       case ITEM_IS_INRELATION:
           IconIndex = 28;
       break;

       case ITEM_IS_RELATIONS:
           IconIndex = 27;
       break;

   }    
   return IconIndex;
}    

void AstadeFrame::CollapsNode(wxTreeEvent& event)
{
    wxTreeItemId aID = event.GetItem();
    myTree->CollapseAndReset(aID);
}

void AstadeFrame::OnBeginEdit(wxTreeEvent& event)
{
    wxTreeItemId aID = event.GetItem();
    wxTreeItemData* data = myTree->GetItemData(aID);
    wxFileName path = static_cast<CTreeItemData*>(data)->path;
    if (data)
    {
        int theType = static_cast<CTreeItemData*>(data)->type;
        IS_ITEM(theType,ITEM_IS_MODEL)
        {
            event.Veto();
            return;
        }    
        IS_ITEM(theType,ITEM_IS_TARGET)
        {
            event.Veto();
            return;
        }    
        IS_ITEM(theType,ITEM_IS_ATTRIBUTES)
        {
            event.Veto();
            return;
        }    
        IS_ITEM(theType,ITEM_IS_OPERATIONS)
        {
            event.Veto();
            return;
        }    
        IS_ITEM(theType,ITEM_IS_PARAMETERS)
        {
            event.Veto();
            return;
        }    
        IS_ITEM(theType,ITEM_IS_CLASSES)
        {
            event.Veto();
            return;
        }    
        IS_ITEM(theType,ITEM_IS_RELATIONS)
        {
            event.Veto();
            return;
        }    
        
        IS_ITEM(theType,ITEM_IS_OPERATION)
        {
            if((theType&ITEM_IS_NORMALOP) != ITEM_IS_NORMALOP)
            {
                event.Veto();
                return;
            }
        }        

        const wxString theLabel = event.GetLabel();
        wxChar* name = new wxChar[200];

        if (theType&ITEM_IS_FOLDER)
        {
            path.SetName("Desktop"); 
            path.SetExt("ini"); 
        }    
        wxString theName = path.GetFullPath();
        wxGetResource("Astade","Name", &name, theName);
        
        if (theLabel != name)
        {
           myTree->SetItemText(aID,name);
           myTree->EditLabel(aID);
           event.Veto();
        }
        delete [] name;
        return;
    }    
}

void AstadeFrame::OnEndEdit(wxTreeEvent& event)
{
    if (event.IsEditCancelled())
        return;
    wxTreeItemId aID = event.GetItem();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        int type = static_cast<CTreeItemData*>(data)->type;
        wxString name = event.GetLabel();
        wxFileName path = static_cast<CTreeItemData*>(data)->path;

        if(type&ITEM_IS_FOLDER)
        {
            path.SetName("Desktop");
            path.SetExt("ini");
            wxString theName = path.GetFullPath();
            wxWriteResource("Astade","Name", name, theName);
        }
        else    
        {
            wxString theName = path.GetFullPath();
            wxWriteResource("Astade","Name", name, theName);
        }  
        
        IS_ITEM(type,ITEM_IS_PARAMETER)
        {
            UpdateText(myTree->GetItemParent(myTree->GetItemParent(aID)));
        }              
          
    }
}

void AstadeFrame::AddComponentFolder(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"components",ITEM_IS_FOLDER|ITEM_IS_COMPONENTS);
    CreateNewFolder(newID);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddComponent(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"component",ITEM_IS_FOLDER|ITEM_IS_COMPONENT);
    CreateNewFolder(newID);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddConfiguration(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"config",ITEM_IS_FOLDER|ITEM_IS_CONFIGURATION);
    CreateNewFolder(newID);
    wxTreeItemId tID = AddNamedItem(newID,"target",ITEM_IS_FOLDER|ITEM_IS_TARGET);
    CreateNewFolder(tID,false);
    myTree->SortChildren(aID);
}

void AstadeFrame::CreateNewFolder(wxTreeItemId aID, bool useGUID)
{
    wxTreeItemId parent = myTree->GetItemParent(aID);
    wxTreeItemData* data = myTree->GetItemData(parent);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxString theName;
        
        if (useGUID)
            theName = myTree->GetItemText(aID)+"_"+GUID();
        else
            theName = myTree->GetItemText(aID);
            
        wxFileName newPath(path);
        newPath.AppendDir(theName);
        
        if (!newPath.Mkdir(newPath.GetFullPath()))
            return;
       
        data = myTree->GetItemData(aID);
        if (data)
        {
            WriteDesktopIni(newPath,static_cast<CTreeItemData*>(data)->type,myTree->GetItemText(aID));
            static_cast<CTreeItemData*>(data)->path = newPath;
        }    
    } 
}    

void AstadeFrame::CreateNewFile(wxTreeItemId aID)
{
    wxTreeItemId parent = myTree->GetItemParent(aID);
    wxTreeItemData* data = myTree->GetItemData(parent);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxString theName = myTree->GetItemText(aID)+"_"+GUID();
        wxFileName newPath(path);
        newPath.SetName(theName);
        newPath.SetExt("ini");
        wxTreeItemData* data = myTree->GetItemData(aID);
        int iType;
        if (data)
        {
            static_cast<CTreeItemData*>(data)->path = newPath;
            iType = static_cast<CTreeItemData*>(data)->type;
        }    
        wxWriteResource("Astade","Type", iType, newPath.GetFullPath());
        wxWriteResource("Astade","Name", myTree->GetItemText(aID), newPath.GetFullPath());
    } 
}    

void AstadeFrame::AddPackage(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"package",ITEM_IS_PACKAGE|ITEM_IS_FOLDER);
    CreateNewFolder(newID);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddClass(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"class",ITEM_IS_CLASS|ITEM_IS_FOLDER);
    CreateNewFolder(newID);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddClasses(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"classes",ITEM_IS_CLASSES|ITEM_IS_FOLDER);
    CreateNewFolder(newID,false);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddRelations(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"relations",ITEM_IS_RELATIONS|ITEM_IS_FOLDER);
    CreateNewFolder(newID,false);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddAttribute(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"attribute",ITEM_IS_ATTRIBUTE|ITEM_IS_PRIVATE);
    CreateNewFile(newID);
    
    wxTreeItemData* data = myTree->GetItemData(newID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxWriteResource("Astade","CodingType", "int", path.GetFullPath());
        wxWriteResource("Astade","Static", "no", path.GetFullPath());
        wxWriteResource("Astade","Const", "no", path.GetFullPath());
    } 
    myTree->SortChildren(aID);
    UpdateText(newID);
}

void AstadeFrame::AddAttributes(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"attributes",ITEM_IS_ATTRIBUTES|ITEM_IS_FOLDER);
    CreateNewFolder(newID,false);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddOperations(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"operations",ITEM_IS_OPERATIONS|ITEM_IS_FOLDER);
    CreateNewFolder(newID,false);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddParameters(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"parameters",ITEM_IS_PARAMETERS|ITEM_IS_FOLDER);
    CreateNewFolder(newID,false);
    myTree->SortChildren(aID);
}

void AstadeFrame::AddParameter(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"parameter",ITEM_IS_PARAMETER);
    CreateNewFile(newID);

    wxTreeItemIdValue cookie;
    wxTreeItemId item1 = myTree->GetFirstChild(aID,cookie);

    int count = 0;
    wxTreeItemData* data;
    
    do
    {
        data = myTree->GetItemData(item1);
        if (data)
        {
            count++;
            int type = static_cast<CTreeItemData*>(data)->type;
            
            int oldType = type;
            type &= 0x7FFFFF00;
            type |= count;
            
            if (oldType!=type)
            {
                static_cast<CTreeItemData*>(data)->type = type;
                wxFileName path = static_cast<CTreeItemData*>(data)->path;
                wxWriteResource("Astade","Type", type, path.GetFullPath());
            }    
        }    
        item1 = myTree->GetNextChild(aID,cookie);
    } while (data);

    data = myTree->GetItemData(newID);
    int type = static_cast<CTreeItemData*>(data)->type;
    
    type &= 0x7FFFFF00;
    type |= count;
    
    static_cast<CTreeItemData*>(data)->type = type;
    wxFileName path = static_cast<CTreeItemData*>(data)->path;
    wxWriteResource("Astade","CodingType", "int", path.GetFullPath());
    wxWriteResource("Astade","Type", type , path.GetFullPath());
     
    myTree->SortChildren(aID);
    wxTreeItemId operation = myTree->GetItemParent(aID);
    UpdateText(operation);
}

void AstadeFrame::AddOperation(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"operation",ITEM_IS_OPERATION|ITEM_IS_FOLDER|ITEM_IS_NORMALOP|ITEM_IS_PRIVATE);
    CreateNewFolder(newID);
    wxTreeItemData* data = myTree->GetItemData(newID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
        wxWriteResource("Astade","CodingType", "void", path.GetFullPath());
        wxWriteResource("Astade","Virtual", "no", path.GetFullPath());
        wxWriteResource("Astade","Abstract", "no", path.GetFullPath());
        wxWriteResource("Astade","Static", "no", path.GetFullPath());
        wxWriteResource("Astade","Const", "no", path.GetFullPath());
    } 
    myTree->SortChildren(aID);
    UpdateText(newID);
}

void AstadeFrame::AddConstructor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"constructor",ITEM_IS_OPERATION|ITEM_IS_FOLDER|ITEM_IS_PUBLIC);
    CreateNewFolder(newID);
    wxTreeItemData* data = myTree->GetItemData(newID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
    } 
    myTree->SortChildren(aID);
    UpdateText(newID);
}

void AstadeFrame::AddDestructor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemId newID = AddNamedItem(aID,"destructor",ITEM_IS_OPERATION|ITEM_IS_FOLDER|ITEM_IS_DEST|ITEM_IS_PUBLIC);
    CreateNewFolder(newID,false);
    wxTreeItemData* data = myTree->GetItemData(newID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
        wxWriteResource("Astade","Virtual", "yes", path.GetFullPath());
    } 
    myTree->SortChildren(aID);
    UpdateText(newID);
}

void AstadeFrame::WriteDesktopIni(wxFileName dir,int iType,wxString name)
{
       wxString me = wxGetApp().argv[0];
       dir.SetName("Desktop");
       dir.SetExt("ini");
       wxString theName = dir.GetFullPath();
 
       wxWriteResource("Astade","Type", iType, theName);
       wxWriteResource("Astade","Name", name, theName);
}

void AstadeFrame::SetModulePath(wxCommandEvent& event)
{
    const wxString& dir = wxDirSelector("Set Modelpath");
    if ( !dir.empty() )
    {
       myTree->CollapseAndReset(myTree->GetRootItem());
       wxWriteResource("TreeView","ModelPath", dir,"Astade.ini");
       RootName = dir;
       wxFileName::SetCwd(RootName);
       myStatusBar->PushStatusText(dir);
       wxTreeItemData* data = myTree->GetItemData(myTree->GetRootItem());
       if (data)
       {
           static_cast<CTreeItemData*>(data)->path=wxFileName(dir,"");
           static_cast<CTreeItemData*>(data)->type=ITEM_IS_MODEL;
           WriteDesktopIni(wxFileName(dir,""),ITEM_IS_MODEL,"Model");
       }
    }
}

void AstadeFrame::DoStartRelation(wxCommandEvent& event)
{
    RelationStart = myTree->GetSelection();
}

void AstadeFrame::DoCompleteRelation(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    
    wxTreeItemId newID1 = AddNamedItem(RelationStart,"relation",ITEM_IS_RELATION);
    wxTreeItemId newID2 = AddNamedItem(aID,"inrelation",ITEM_IS_INRELATION);

    CreateNewFile(newID1);
    CreateNewFile(newID2);

    wxTreeItemData* data1 = myTree->GetItemData(newID1);
    wxTreeItemData* data2 = myTree->GetItemData(newID2);
    
    if (data1 && data2)
    {
        wxFileName path1 = static_cast<CTreeItemData*>(data1)->path;
        wxFileName rpath1(path1);
        rpath1.MakeRelativeTo(RootName);
        
        wxFileName path2 = static_cast<CTreeItemData*>(data2)->path;
        wxFileName rpath2(path2);
        rpath2.MakeRelativeTo(RootName);
        
        wxWriteResource("Relation","PartnerPath", rpath1.GetFullPath(), path2.GetFullPath());
        wxWriteResource("Relation","PartnerPath", rpath2.GetFullPath(), path1.GetFullPath());
        
        wxWriteResource("Astade","Type", static_cast<CTreeItemData*>(data1)->type , path1.GetFullPath());
        wxWriteResource("Astade","Type", static_cast<CTreeItemData*>(data2)->type , path2.GetFullPath());

        wxWriteResource("Astade","RelationType", "ImplementationDependency", path1.GetFullPath());
    } 
    myTree->SortChildren(RelationStart);
    myTree->SortChildren(aID);
    
    RelationStart = wxTreeItemId();
    
    UpdateText(newID1);
    UpdateText(newID2);

}

void AstadeFrame::SetClassEditor(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set class editor");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Class", file,"Astade.ini");
       ClassEditor = file;
    }
}

void AstadeFrame::SetAttributeEditor(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set attribute editor");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Attribute", file,"Astade.ini");
       AttributeEditor = file;
    }
}

void AstadeFrame::SetRelationEditor(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set relation editor");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Relation", file,"Astade.ini");
       RelationEditor = file;
    }
}

void AstadeFrame::SetParameterEditor(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set parameter editor");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Parameter", file,"Astade.ini");
       ParameterEditor = file;
    }
}

void AstadeFrame::SetOpEditor(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set operation editor");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Operation", file,"Astade.ini");
       OperationEditor = file;
    }
}

void AstadeFrame::SetCodeEditor(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set code editor");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Code", file,"Astade.ini");
       CodeEditor = file;
    }
}

void AstadeFrame::SetOMDViewer(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set object model diagram viewer");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","OMD", file,"Astade.ini");
       OMDViewer = file;
    }
}

void AstadeFrame::SetCoder(wxCommandEvent& event)
{
    wxString file = wxFileSelector("Set code builder");
    if ( !file.empty() )
    {
       wxWriteResource("Editor","Coder", file,"Astade.ini");
       Coder = file;
    }
}

void AstadeFrame::CallClassEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
        wxString callName = ClassEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallAttributeEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxString callName = AttributeEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallRelationEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxString callName = RelationEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallInRelationEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxChar* path;
        wxString infilename = static_cast<CTreeItemData*>(data)->path.GetFullPath();
        wxGetResource("Relation","PartnerPath", &path, infilename);
        wxFileName partnerName(path);
        partnerName.MakeAbsolute(RootName);
        wxString outpath = partnerName.GetFullPath();
        
        wxString callName = RelationEditor.GetFullPath()+" \""+outpath+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallParameterEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxString callName = ParameterEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallOpEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
        wxString callName = OperationEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallCodeEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("code.cpp");
        wxString callName = CodeEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallSpecificationEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetName(myTree->GetItemText(aID));
        path.SetExt("h");
        wxString callName = CodeEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallImplementationEditor(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetName(myTree->GetItemText(aID));
        path.SetExt("cpp");
        wxString callName = CodeEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::ShowOMD(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
        wxString callName = "\""+OMDViewer.GetFullPath()+"\" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::CallCoder(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        path.SetFullName("Desktop.ini");
        wxString callName = "\""+Coder.GetFullPath()+"\" \""+path.GetFullPath()+"\"";
        wxExecute(callName);
    }    
}

void AstadeFrame::DeleteDir(wxString& path)
{
    {
        wxDir dir(path);
        
        if ( !dir.IsOpened() )
        return;
        
        wxString filename;
        // Verzeichnisse
        bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_DIRS);
        while ( cont )
        {
            wxFileName newPath(path);
            newPath.AppendDir(filename);
            wxString callPath = newPath.GetFullPath(); 
            DeleteDir(callPath);
            cont = dir.GetNext(&filename);
        }
            
        // Dateien
        cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES);
        while ( cont )
        {
             wxFileName newPath(path);
             newPath.SetName(filename);
             wxString callPath = newPath.GetFullPath(); 
             DeleteOther(callPath);
             wxRemoveFile(callPath);
             cont = dir.GetNext(&filename);
        }
    }    
    wxFileName newPath(path);
    wxString callPath = newPath.GetPath(); 
    wxRmdir(callPath);
}

void AstadeFrame::Delete(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        int type = static_cast<CTreeItemData*>(data)->type;
        if (type&ITEM_IS_FOLDER)
        {
            wxString callpath = path.GetFullPath();
            DeleteDir(callpath);
            myTree->Delete(aID);
        }    
        else
        {
            wxString callPath = path.GetFullPath(); 
            DeleteOther(callPath);
            if (wxRemoveFile(callPath))
            {
                myTree->Delete(aID);
            }    
        }    
    }    
}

void AstadeFrame::DeleteOther(wxString& myName)
{
    wxChar* path;
    if (wxGetResource("Relation","PartnerPath", &path, myName))
        {
            wxFileName partnerName = wxString(path);
            partnerName.MakeAbsolute(RootName);
            wxRemoveFile(partnerName.GetFullPath());
        }
}

void AstadeFrame::Up(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxTreeItemData* data2 = myTree->GetItemData(myTree->GetPrevSibling(aID));
        int type = static_cast<CTreeItemData*>(data)->type;
        static_cast<CTreeItemData*>(data)->type = static_cast<CTreeItemData*>(data2)->type;
        static_cast<CTreeItemData*>(data2)->type = type;
        myTree->SortChildren(myTree->GetItemParent(aID));
        
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxWriteResource("Astade","Type", static_cast<CTreeItemData*>(data)->type , path.GetFullPath());

        path = static_cast<CTreeItemData*>(data2)->path;
        wxWriteResource("Astade","Type", static_cast<CTreeItemData*>(data2)->type , path.GetFullPath());
        UpdateText(myTree->GetItemParent(myTree->GetItemParent(aID)));
   }    
}

void AstadeFrame::Down(wxCommandEvent& event)
{
    wxTreeItemId aID = myTree->GetSelection();
    wxTreeItemData* data = myTree->GetItemData(aID);
    if (data)
    {
        wxTreeItemData* data2 = myTree->GetItemData(myTree->GetNextSibling(aID));
        int type = static_cast<CTreeItemData*>(data)->type;
        static_cast<CTreeItemData*>(data)->type = static_cast<CTreeItemData*>(data2)->type;
        static_cast<CTreeItemData*>(data2)->type = type;
        myTree->SortChildren(myTree->GetItemParent(aID));
 
        wxFileName path = static_cast<CTreeItemData*>(data)->path;
        wxWriteResource("Astade","Type", static_cast<CTreeItemData*>(data)->type , path.GetFullPath());

        path = static_cast<CTreeItemData*>(data2)->path;
        wxWriteResource("Astade","Type", static_cast<CTreeItemData*>(data2)->type , path.GetFullPath());
        UpdateText(myTree->GetItemParent(myTree->GetItemParent(aID)));
   }    
}

wxTreeItemId AstadeFrame::AddNamedItem(wxTreeItemId aID,wxString guessedName,int iType)
{
    wxTreeItemId newItem = myTree->AppendItem(aID,guessedName,selectIcon(iType));
    myTree->SetItemHasChildren(aID);
    if (!myTree->IsExpanded(aID))
        myTree->Expand(aID);
    CTreeItemData* t = new CTreeItemData();
    t->type = iType;
    myTree->SetItemData(newItem,t);
    return newItem;
}    

wxString AstadeFrame::GUID()
{
    wxString s;
    char range = 'Z' - 'A' + 1;
    for (int i=0;i<8;i++)
    {
        char c = 'A' + char(range * rand()/(RAND_MAX + 1.0));
        s = s + c;
    }        
    return s;
}    

wxString AstadeFrame::Encode(wxString input)
{
    input.Replace("\n","\\n");
    input.Replace("\r","\\r");
    input.Replace("\"","\\\"");
    input.Replace("\'","\\\'");
    return input;
}
    
wxString AstadeFrame::Decode(wxString input)
{
    input.Replace("\\n","\n");
    input.Replace("\\r","\r");
    input.Replace("\\\"","\"");
    input.Replace("\\\'","\'");
    return input;
}    


