SetIcon();
/*
if (AgregationType)
{
	wxString CodingType = AgregationType->GetValue();

	if ((Multiplicity==NULL) &&
		((CodingType=="Association")||(CodingType=="Agregation")||(CodingType=="Composition")))
	{
		Multiplicity =  new wxComboBox(this, ID_AGREGATIONTYPE ,"1" ,wxPoint(330,58),wxSize(145,21), getMultiplicityImplementations());
		TextMultiplicity = new wxStaticText(this, ID_TYPE ,"multiplicity:", wxPoint(260,58));
		TextMultiplicity->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));

		Implementation =  new wxComboBox(this, ID_IMPLEMENTATION ,"" ,wxPoint(155,100),wxSize(300,21), getRelationImplementations());
		TextImplementation = new wxStaticText(this, ID_TYPE ,"implement as:", wxPoint(25,100));
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
	myBitmap->SetBitmap(wxIcon(imprelation_xpm));

	if (CodingType=="SpecificationDependency")
	myBitmap->SetBitmap(wxIcon(specrelation_xpm));

	if (CodingType=="Association")
	myBitmap->SetBitmap(wxIcon(association));

	if (CodingType=="Agregation")
	myBitmap->SetBitmap(wxIcon(aggregation));

	if (CodingType=="Composition")
	myBitmap->SetBitmap(wxIcon(composition));

	if (CodingType=="Generalization")
	myBitmap->SetBitmap(wxIcon(generalisation));
}
*/