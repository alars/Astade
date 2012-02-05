//~~ void OnAggregation(wxCommandEvent& event) [glRelation] ~~

type = rtAggregation;
if (myStartMult.myText.IsEmpty())
	myStartMult.myText = wxS("1");
if (myEndMult.myText.IsEmpty())
	myEndMult.myText = wxS("*");
