//~~ void OnAssociation(wxCommandEvent& event) [glRelation] ~~

type = rtAssociation;
if (myStartMult.myText.IsEmpty())
	myStartMult.myText = wxS("1");
if (myEndMult.myText.IsEmpty())
	myEndMult.myText = wxS("*");
