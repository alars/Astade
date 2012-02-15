//~~ void AddBaseClassesSizer(wxSizer* topSizer) [ResourceEdit] ~~

bool is = false;
wxConfigBase::Get()->Read(wxS("Astade/ManualClass"), &is);

if (is)
	return;

wxConfigBase::Get()->Read(wxS("Astade/LibClass"), &is);

if (is)
{
	wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(this, -1, wxS("Class include:")), wxHORIZONTAL);

	ClassIncludeEditField = new wxTextCtrl(this, -1);
	box->Add(ClassIncludeEditField, 1);

	topSizer->Add(box, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

	ClassIncludeEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/ClassInclude"), wxEmptyString));
}
else
{
	wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(this, -1, wxS("Additional base classes:")), wxHORIZONTAL);

	AdditionalClassesEditField = new wxTextCtrl(this, ID_ADDITIONALCLASSESEDITFIELD);
	box->Add(AdditionalClassesEditField, 1);

	topSizer->Add(box, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

	AdditionalClassesEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/AdditionalClasses"), wxEmptyString));
}
