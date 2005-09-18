//---------------------------------------------------------------------------
//
// Name:        ResourceEdit.cpp
// Author:      
// Created:     25.04.2005 19:19:46
// Copyright:
//
//---------------------------------------------------------------------------

#ifdef __GNUG__
    #pragma implementation "ResourceEdit.h"
#endif

/* for compilers that support precompilation
   includes <wx/wx.h> */

#include <wx/wxprec.h>
#undef wxUSE_RESOURCES
#define wxUSE_RESOURCES 1
#include <wx/utils.h>
#include <wx/timer.h>

#include <wx/filename.h>

#include "../treeview/AstadeDef.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "ResourceEdit.h"

#include "../Icons/edit.xpm"
#include "../Icons/parameter.xpm"
#include "../Icons/class.xpm"
#include "../Icons/component.xpm"
#include "../Icons/attribute.xpm"
#include "../Icons/operation.xpm"
#include "../Icons/const.xpm"
#include "../Icons/dest.xpm"
#include "../Icons/relation.xpm"
#include "../Icons/association.xpm"
#include "../Icons/aggregation.xpm"
#include "../Icons/composition.xpm"
#include "../Icons/generalisation.xpm"
#include "../Icons/Type.xpm"
#include "../Icons/components.xpm"
#include "../Icons/package.xpm"

////Header Include Start
////Header Include End



//----------------------------------------------------------------------------
// ResourceEdit
//----------------------------------------------------------------------------

    ////Event Table Start
    BEGIN_EVENT_TABLE(ResourceEdit,wxDialog)

    EVT_CLOSE(ResourceEdit::ResourceEditClose)
	EVT_INIT_DIALOG(ResourceEdit::InitDialog)
	EVT_BUTTON(ID_CANCEL,ResourceEdit::Cancel)
	EVT_BUTTON(ID_SAVEANDEXIT,ResourceEdit::Save)
    EVT_CHECKBOX(ID_VIRTUAL, ResourceEdit::UncheckStatic)
    EVT_CHECKBOX(ID_STATIC, ResourceEdit::UncheckVirtual)
    EVT_CHECKBOX(ID_ABSTRACT, ResourceEdit::CheckVirtual)
    EVT_TEXT(ID_AGREGATIONTYPE, ResourceEdit::ChangeIcon)	
    	
    END_EVENT_TABLE()
    ////Event Table End



ResourceEdit::ResourceEdit( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    Multiplicity = NULL;
    TextMultiplicity = NULL;
    Implementation = NULL;
    CreateGUIControls();
}

ResourceEdit::~ResourceEdit()
{
    
} 

void ResourceEdit::CreateGUIControls(void)
{
	this->SetSize(8,8,506,483);
	this->SetTitle(_("Resource Edit"));
	this->Center();
}

void ResourceEdit::Cancel(wxCommandEvent& event)
{
    Destroy();
}

void ResourceEdit::UncheckStatic(wxCommandEvent& event)
{
    if (VirtualField && StaticField && AbstractField)
        if (VirtualField->IsChecked())
        {
            StaticField->SetValue(false); 
        }
        else
        {
            AbstractField->SetValue(false); 
        }        
}

void ResourceEdit::UncheckVirtual(wxCommandEvent& event)
{
    if (VirtualField && StaticField && AbstractField)
        if (StaticField->IsChecked())
        {
            VirtualField->SetValue(false); 
            AbstractField->SetValue(false); 
        }    
}

void ResourceEdit::CheckVirtual(wxCommandEvent& event)
{
    if (VirtualField && StaticField && AbstractField)
        if (AbstractField->IsChecked())
        {
            VirtualField->SetValue(true); 
            StaticField->SetValue(false); 
        }    
}

wxArrayString ResourceEdit::getMultiplicityImplementations()
{
    wxArrayString ret;
	ret.Add(_("1"));
	ret.Add(_("*"));
	ret.Add(_("1..*"));
	return ret;
}

wxArrayString ResourceEdit::getRelationImplementations()
{
    wxString buffer;
    wxArrayString ret;
    buffer.Printf("%s*",RelatedClass.c_str());
	ret.Add(buffer);
    buffer.Printf("std::list<%s *>",RelatedClass.c_str());
	ret.Add(buffer);
    buffer.Printf("std::vector<%s *>",RelatedClass.c_str());
	ret.Add(buffer);
    buffer.Printf("std::deque<%s *>",RelatedClass.c_str());
	ret.Add(buffer);
    buffer.Printf("std::map<%s *, ???>",RelatedClass.c_str());
	ret.Add(buffer);
	return ret;
}

void ResourceEdit::ChangeIcon(wxCommandEvent& event)
{
    if (AgregationType)
    {
        wxString CodingType = AgregationType->GetValue();
        
       	if ((Multiplicity==NULL) &&
            ((CodingType=="Association")||(CodingType=="Agregation")||(CodingType=="Composition")))
       	{
        	Multiplicity =  new wxComboBox(this, ID_AGREGATIONTYPE ,"1" ,wxPoint(330,58),wxSize(145,21), getMultiplicityImplementations());
            TextMultiplicity = new wxStaticText(this, ID_TYPE ,_("multiplicity:") ,wxPoint(260,58));
            TextMultiplicity->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
            
     	    Implementation =  new wxComboBox(this, ID_IMPLEMENTATION ,"" ,wxPoint(155,100),wxSize(300,21), getRelationImplementations());
            TextImplementation = new wxStaticText(this, ID_TYPE ,_("implement as:") ,wxPoint(25,100));
        }
        else   	
       	    if ((Multiplicity!=NULL) &&
       	        ((CodingType=="ImplementationDependency")||(CodingType=="SpecificationDependency"))||(CodingType=="Generalization"))
       	    {
       	        delete Multiplicity;
                delete TextMultiplicity;
                delete Implementation;
                delete TextImplementation;
       	        Multiplicity = NULL;
                TextMultiplicity = NULL;
                Implementation = NULL;
                TextImplementation = NULL;
       	    }    
        
    	if (CodingType=="ImplementationDependency")
    	     myBitmap->SetBitmap(wxIcon(relation));
    	
    	if (CodingType=="SpecificationDependency")
    	     myBitmap->SetBitmap(wxIcon(relation));
    	
    	if (CodingType=="Association")
    	     myBitmap->SetBitmap(wxIcon(association));
    	
    	if (CodingType=="Agregation")
    	     myBitmap->SetBitmap(wxIcon(aggregation));
    	
    	if (CodingType=="Composition")
    	     myBitmap->SetBitmap(wxIcon(composition));
    	
    	if (CodingType=="Generalization")
    	     myBitmap->SetBitmap(wxIcon(generalisation));
    }    
}

void ResourceEdit::Save(wxCommandEvent& event)
{
    wxWriteResource("Astade","ID","$Id$",file);
    wxWriteResource("Astade","LastChanged",wxGetUTCTime(),file);
    
    if (NameEditField)
    {
        wxString theName = NameEditField->GetValue();
        theName.Replace(" ","_");
        
        if (theName.size()==0)
            theName = "JohnDoe";
        wxWriteResource("Astade","Name",theName,file);
    }
        
    if (DefaultEditField)
    {
        wxString theName = DefaultEditField->GetValue();
        
        if (theName.size()!=0)
            wxWriteResource("Astade","Default",Encode(theName),file);
    }
        
    if (TypeEditField)
    {
        wxString theName = TypeEditField->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","CodingType",Encode(theName),file);
    }
        
    if (DescriptionEditField)
    {
        wxString theName = DescriptionEditField->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","Description",Encode(theName),file);
    }
        
    if (DeclarationEditField)
    {
        wxString theName = DeclarationEditField->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","Declaration",Encode(theName),file);
    }
        
    if (AdditionalClassesEditField)
    {
        wxString theName = AdditionalClassesEditField->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","AdditionalClasses",Encode(theName),file);
    }
        
    if (InitializerEditField)
    {
        wxString theName = InitializerEditField->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","Initializer",Encode(theName),file);
    }
        
    if (Multiplicity)
    {
        wxString theName = Multiplicity->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","Multiplicity",theName,file);
    }
        
    if (ConstField)
    {
        if (ConstField->IsChecked())
            wxWriteResource("Astade","Const","yes",file);
        else
            wxWriteResource("Astade","Const","no",file);
    }
        
    if (VirtualField)
    {
        if (VirtualField->IsChecked())
            wxWriteResource("Astade","Virtual","yes",file);
        else
            wxWriteResource("Astade","Virtual","no",file);
    }
        
    if (AgregationType)
    {
        wxString theName = AgregationType->GetValue();
        if (theName.size()!=0)
            wxWriteResource("Astade","RelationType",theName,file);
    }
        
    if (Implementation)
    {
        wxString theName = Implementation->GetValue();
        wxWriteResource("Astade","Implementation",Encode(theName),file);
    }
        
    if (StaticField)
    {
        if (StaticField->IsChecked())
            wxWriteResource("Astade","Static","yes",file);
        else
            wxWriteResource("Astade","Static","no",file);
    }
        
    if (AbstractField)
    {
        if (AbstractField->IsChecked())
            wxWriteResource("Astade","Abstract","yes",file);
        else
            wxWriteResource("Astade","Abstract","no",file);
    }
        
    if (m_private)
    {
        if (m_private->GetValue())    
        {
            m_iType |= ITEM_IS_PRIVATE;
            m_iType &= ~ITEM_IS_PROTECTED; 
            m_iType &= ~ITEM_IS_PUBLIC; 
        }
        else
        if (m_public->GetValue())    
        {
            m_iType &= ~ITEM_IS_PRIVATE;
            m_iType &= ~ITEM_IS_PROTECTED; 
            m_iType |= ITEM_IS_PUBLIC; 
        }
        else
        if (m_protected->GetValue())    
        {
            m_iType &= ~ITEM_IS_PRIVATE;
            m_iType |= ITEM_IS_PROTECTED; 
            m_iType &= ~ITEM_IS_PUBLIC; 
        }    
    }    

    wxWriteResource("Astade","Type",m_iType,file);
    Destroy();
}

void ResourceEdit::ResourceEditClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}

void ResourceEdit::InitDialog(wxInitDialogEvent& event)
{
    m_iType = 0;
	new wxButton(this, ID_CANCEL, _("cancel") , wxPoint(25,422),wxSize(100,32) );
	
	myBitmap =  new wxStaticBitmap(this, ID_THEBITMAP, wxNullBitmap, wxPoint(9,0),wxSize(48,48) );
	
    if ((file.size()>0) && (wxGetResource("Astade","Type",&m_iType,file)))
	{
        new wxButton(this, ID_SAVEANDEXIT, _("Save and Exit") , wxPoint(388,422),wxSize(100,32) );

    	DefaultEditField = 0;
        switch (m_iType&0xfff00000)
    	{
             case ITEM_IS_CLASS:         myBitmap->SetBitmap(wxIcon(Class));break;
             case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(wxIcon(component));break;
             case ITEM_IS_COMPONENTS:    myBitmap->SetBitmap(wxIcon(components_xpm));break;
             case ITEM_IS_PACKAGE:       myBitmap->SetBitmap(wxIcon(package));break;
             case ITEM_IS_TYPE:          myBitmap->SetBitmap(wxIcon(Type_xpm));break;
             case ITEM_IS_ATTRIBUTE:     myBitmap->SetBitmap(wxIcon(attribute));
                    DefaultEditField =  new wxTextCtrl(this, ID_DEFAULTEDITFIELD, "" , wxPoint(100,84),wxSize(375,21) );
            	    DefaultEditField->SetMaxLength(128);
            	    (new wxStaticText(this, ID_NAME ,_("default:") ,wxPoint(25,85)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
                 break;
             case ITEM_IS_PARAMETER:     myBitmap->SetBitmap(wxIcon(parameter));break;
             case ITEM_IS_OPERATION:     
                 if (m_iType & ITEM_IS_NORMALOP)
                     //Normal Operation
                     myBitmap->SetBitmap(wxIcon(operation));
                 else
                 if (m_iType & ITEM_IS_DEST)
                     //Destructor
                     myBitmap->SetBitmap(wxIcon(dest));
                 else
                     //Constructor
                     myBitmap->SetBitmap(wxIcon(Const));
                 break;
             default: myBitmap->SetBitmap(wxIcon(edit));
        }    
    }
    else
    {
    	myBitmap->SetBitmap(wxIcon(edit));
    }  

    char* hp;

    if ((file.size()>0) && (wxGetResource("Astade","PartnerPath",&hp,file)))
	{
        wxFileName partnerName = wxString(hp);

        int i = partnerName.GetDirCount();
        partnerName.RemoveDir(i-1);
        partnerName.SetName("ModelNode"); 
        partnerName.SetExt("ini");
        wxString sName = "*deleted*";
        if (wxGetResource("Astade","Name", &hp, partnerName.GetFullPath()))
            RelatedClass = hp;
    }
        
    if ((file.size()>0) && (wxGetResource("Astade","Const",&hp,file)))
	{
    	m_oName = hp;
	    ConstField =  new wxCheckBox(this, ID_CONST, _("const") , wxPoint(25,58),wxSize(60,21) );
	    ConstField->SetValue(m_oName=="yes");
    } 
	else 
	    ConstField = NULL;
     
    if (DefaultEditField)
    {
        if ((file.size()>0) && (wxGetResource("Astade","Default",&hp,file)))
    	{
        	m_oName = hp;
    	    DefaultEditField->SetValue(Decode(m_oName));
        }    
    }

    if ((file.size()>0) && (wxGetResource("Astade","Virtual",&hp,file)))
	{
    	m_oName = hp;
	    VirtualField =  new wxCheckBox(this, ID_VIRTUAL, _("virtual") , wxPoint(85,58),wxSize(60,21) );
	    VirtualField->SetValue(m_oName=="yes");
    } 
	else 
	    VirtualField = NULL;
     
    if ((file.size()>0) && (wxGetResource("Astade","Static",&hp,file)))
	{
    	m_oName = hp;
	    StaticField =  new wxCheckBox(this, ID_STATIC, _("static") , wxPoint(145,58),wxSize(60,21) );
	    StaticField->SetValue(m_oName=="yes");
    } 
	else 
	    StaticField = NULL;
     
    if ((file.size()>0) && (wxGetResource("Astade","Abstract",&hp,file)))
	{
    	m_oName = hp;
	    AbstractField =  new wxCheckBox(this, ID_ABSTRACT, _("abstract") , wxPoint(205,58),wxSize(60,21) );
	    AbstractField->SetValue(m_oName=="yes");
    } 
	else 
	    AbstractField = NULL;
     
    if ((file.size()>0) && (wxGetResource("Astade","Name",&hp,file)))
	{
    	m_oName = hp;
        NameEditField =  new wxTextCtrl(this, ID_NAMEEDITFIELD, m_oName , wxPoint(100,12),wxSize(375,21) );
	    NameEditField->SetMaxLength(128);
        if (((m_iType&0xfff00000)==ITEM_IS_OPERATION) && ((m_iType & ITEM_IS_NORMALOP)==0)) 
            NameEditField->SetEditable(false);
	    (new wxStaticText(this, ID_NAME ,_("name:") ,wxPoint(60,12)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}
	else 
	    NameEditField = NULL;
               
    if ((file.size()>0) && (wxGetResource("Astade","CodingType",&hp,file)))
	{
    	wxString CodingType = hp;
        TypeEditField =  new wxTextCtrl(this, ID_NAMEEDITFIELD, Decode(CodingType) , wxPoint(100,33),wxSize(375,21) );
	    TypeEditField->SetMaxLength(128);
	    (new wxStaticText(this, ID_TYPE ,_("type:") ,wxPoint(60,33)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}
	else 
	    TypeEditField = NULL;

    if ((file.size()>0) && (wxGetResource("Astade","RelationType",&hp,file)))
	{
        wxString CodingType = hp;

        wxString Multi;
        if (wxGetResource("Astade","Multiplicity",&hp,file))
             Multi = hp;
        else
             Multi = "1";
        
    	wxArrayString arrayStringFor_WxComboBox1;
    	arrayStringFor_WxComboBox1.Add(_("ImplementationDependency"));
    	arrayStringFor_WxComboBox1.Add(_("SpecificationDependency"));
    	arrayStringFor_WxComboBox1.Add(_("Association"));
    	arrayStringFor_WxComboBox1.Add(_("Agregation"));
    	arrayStringFor_WxComboBox1.Add(_("Composition"));
    	arrayStringFor_WxComboBox1.Add(_("Generalization"));
    	AgregationType =  new wxComboBox(this, ID_AGREGATIONTYPE ,CodingType ,wxPoint(25,58),wxSize(180,21), arrayStringFor_WxComboBox1, wxCB_READONLY   );
    	
       	if ((Multiplicity==NULL) &&
            ((CodingType=="Association")||(CodingType=="Agregation")||(CodingType=="Composition")))
       	{
        	Multiplicity =  new wxComboBox(this, ID_AGREGATIONTYPE ,Multi ,wxPoint(330,58),wxSize(145,21),  getMultiplicityImplementations());
            TextMultiplicity = new wxStaticText(this, ID_TYPE ,_("multiplicity:") ,wxPoint(260,58));
            TextMultiplicity->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));

            hp[0]=0;
            wxGetResource("Astade","Implementation",&hp,file);
     	    Implementation =  new wxComboBox(this, ID_IMPLEMENTATION ,Decode(hp),wxPoint(105,100),wxSize(300,21), getRelationImplementations());
            TextImplementation = new wxStaticText(this, ID_TYPE ,_("implement as:") ,wxPoint(25,100));
        }
        
    	if (CodingType=="ImplementationDependency")
    	     myBitmap->SetBitmap(wxIcon(relation));
    	
    	if (CodingType=="SpecificationDependency")
    	     myBitmap->SetBitmap(wxIcon(relation));
    	
    	if (CodingType=="Association")
    	     myBitmap->SetBitmap(wxIcon(association));
    	
    	if (CodingType=="Agregation")
    	     myBitmap->SetBitmap(wxIcon(aggregation));
    	
    	if (CodingType=="Composition")
    	     myBitmap->SetBitmap(wxIcon(composition));
    	
    	if (CodingType=="Generalization")
    	     myBitmap->SetBitmap(wxIcon(generalisation));
	}
	else 
	    AgregationType = NULL;



    if ((file.size()>0) && (wxGetResource("Astade","Declaration",&hp,file)))
	{
     	wxString Declaration = hp;
        DeclarationEditField =  new wxTextCtrl(this, ID_DECLARATIONEDITFIELD, Decode(Declaration) , wxPoint(25,78),wxSize(450,100), wxTE_MULTILINE );
	    DeclarationEditField->SetMaxLength(0x4000);
	    (new wxStaticText(this, ID_DESCRIPTION ,_("declaration:") ,wxPoint(25,58)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}

    if ((m_iType&0xfff00000)==ITEM_IS_CLASS)
	{
        wxString Declaration;
        if ((file.size()>0) && (wxGetResource("Astade","AdditionalClasses",&hp,file)))
        {
         	Declaration = hp;
       	}   	
        AdditionalClassesEditField =  new wxTextCtrl(this, ID_ADDITIONALCLASSESEDITFIELD, Decode(Declaration) , wxPoint(25,78),wxSize(450,100), wxTE_MULTILINE );
	    AdditionalClassesEditField->SetMaxLength(0x4000);
	    (new wxStaticText(this, ID_DESCRIPTION ,_("Additional base classes:") ,wxPoint(25,58)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}

    if ((m_iType&0xfffff000)==ITEM_IS_OPERATION)
	{
        wxString Declaration;
        if ((file.size()>0) && (wxGetResource("Astade","Initializer",&hp,file)))
        {
         	Declaration = hp;
       	}   	
        InitializerEditField =  new wxTextCtrl(this, ID_ADDITIONALCLASSESEDITFIELD, Decode(Declaration) , wxPoint(25,88),wxSize(450,90), wxTE_MULTILINE );
	    InitializerEditField->SetMaxLength(0x4000);
	    (new wxStaticText(this, ID_DESCRIPTION ,_("Initializer:") ,wxPoint(25,68)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}

    if ((file.size()>0) && (wxGetResource("Astade","Description",&hp,file)))
	{
     	wxString Description = hp;
        DescriptionEditField =  new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, Decode(Description) , wxPoint(25,200),wxSize(450,200), wxTE_MULTILINE );
	    DescriptionEditField->SetMaxLength(0x4000);
	    (new wxStaticText(this, ID_DESCRIPTION ,_("description:") ,wxPoint(25,180)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}
	else
     {
        DescriptionEditField =  new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, "" , wxPoint(25,200),wxSize(450,200), wxTE_MULTILINE );
	    DescriptionEditField->SetMaxLength(0x4000);
	    (new wxStaticText(this, ID_DESCRIPTION ,_("description:") ,wxPoint(25,180)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
     } 

    if ((m_iType&ITEM_IS_PRIVATE)||
        (m_iType&ITEM_IS_PROTECTED)||
        (m_iType&ITEM_IS_PUBLIC))
    {
    	m_private =  new wxRadioButton(this, ID_M_PRIVATE ,_("private") ,wxPoint(286,58),wxSize(70,21) );
    	m_protected =  new wxRadioButton(this, ID_M_PROTECTED ,_("protected") ,wxPoint(356,58),wxSize(70,21) );
    	m_public =  new wxRadioButton(this, ID_M_PUBLIC ,_("public") ,wxPoint(426,58),wxSize(70,21) );
    
        if (m_iType&ITEM_IS_PRIVATE)
        {
            m_private->SetValue(true);
            m_protected->SetValue(false);
            m_public->SetValue(false);
        }
        else    
        if (m_iType&ITEM_IS_PROTECTED)
        {
            m_private->SetValue(false);
            m_protected->SetValue(true);
            m_public->SetValue(false);
        }
        else    
        if (m_iType&ITEM_IS_PUBLIC)
        {
            m_private->SetValue(false);
            m_protected->SetValue(false);
            m_public->SetValue(true);
        }
    } 
    else
    {
        m_private = NULL;
        m_protected = NULL;
        m_public = NULL;
    }       
               
  	myBitmap->Enable(true);
}

wxString ResourceEdit::Encode(wxString input)
{
    input.Replace("\n","\\n");
    input.Replace("\r","\\r");
    input.Replace("\"","\\\"");
    input.Replace("\'","\\\'");
    return input;
}
    
wxString ResourceEdit::Decode(wxString input)
{
    input.Replace("\\n","\n");
    input.Replace("\\r","\r");
    input.Replace("\\\"","\"");
    input.Replace("\\\'","\'");
    return input;
} 
 
