AdeElementIterator it;

// unprepare all the childs
for (it=begin();it!=end();++it)
{
	AdeModelElement* aElement = it.CreateNewElement();
	aElement->Move_Unprepare();
	delete(aElement);
}

AdeModelElement::Move_Unprepare();