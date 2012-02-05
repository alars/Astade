//~~ void OnComposition(wxCommandEvent& event) [glSelfRelation] ~~

type = rtComposition;
if (myStartMult.myText.IsEmpty())
	myStartMult.myText = wxS("1");
if (myEndMult.myText.IsEmpty())
	myEndMult.myText = wxS("*");
