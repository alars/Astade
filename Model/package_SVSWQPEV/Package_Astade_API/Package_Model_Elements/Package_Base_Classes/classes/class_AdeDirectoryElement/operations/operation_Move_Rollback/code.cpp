// rollback all the childs
for (AdeElementIterator it = begin(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	anElement->Move_Rollback();
	delete anElement;
}

AdeModelElement::Move_Rollback();
