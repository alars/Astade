/*
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
*/

wxConfigBase::Get()->Write("Astade/ID","$I""d$");
wxConfigBase::Get()->Write("Astade/LastChanged",wxGetUTCTime());

int elementType;
wxConfigBase::Get()->Read("Astade/Type",&elementType);

if (NameEditField)
	wxConfigBase::Get()->Write("Astade/Name",NameEditField->GetValue());

if (TypeEditField)
	wxConfigBase::Get()->Write("Astade/CodingType",TypeEditField->GetValue());

if (AdditionalClassesEditField)
	wxConfigBase::Get()->Write("Astade/AdditionalClasses",AdditionalClassesEditField->GetValue());

if (DefaultEditField)
	wxConfigBase::Get()->Write("Astade/Default",DefaultEditField->GetValue());

if (DescriptionEditField)
	wxConfigBase::Get()->Write("Astade/Description",DescriptionEditField->GetValue());

if (ConstField)
{
	if (ConstField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Const","yes");
	else
		wxConfigBase::Get()->Write("Astade/Const","no");
}

if (VirtualField)
{
	if (VirtualField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Virtual","yes");
	else
		wxConfigBase::Get()->Write("Astade/Virtual","no");
}

if (StaticField)
{
	if (StaticField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Static","yes");
	else
		wxConfigBase::Get()->Write("Astade/Static","no");
}

if (AbstractField)
{
	if (AbstractField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Abstract","yes");
	else
		wxConfigBase::Get()->Write("Astade/Abstract","no");
}

if (m_private)
{
	if (m_private->GetValue())
	{
		elementType |= ITEM_IS_PRIVATE;
		elementType &= ~ITEM_IS_PROTECTED;
		elementType &= ~ITEM_IS_PUBLIC;
	}
	else
	if (m_public->GetValue())
	{
		elementType &= ~ITEM_IS_PRIVATE;
		elementType &= ~ITEM_IS_PROTECTED;
		elementType |= ITEM_IS_PUBLIC;
	}
	else
	if (m_protected->GetValue())
	{
		elementType &= ~ITEM_IS_PRIVATE;
		elementType |= ITEM_IS_PROTECTED;
		elementType &= ~ITEM_IS_PUBLIC;
	}

	wxConfigBase::Get()->Write("Astade/Type",elementType);
}

wxConfigBase::Get()->Flush();
Destroy();
