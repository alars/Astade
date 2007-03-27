AdeElementIterator it;

for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	aElement->Delete();
	delete aElement;
}

myFileName.SetFullName("");
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();

theRevisionControl->Delete(myFileName);
wxArrayString output = theRevisionControl->GetOutput();
wxString message;

for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";