int count = 0;
for (std::list<glGraphicElement *>::iterator it = glGraphicElement::objectList.begin(); it != glGraphicElement::objectList.end(); it++)
{
	glNode* aNode = dynamic_cast<glNode*>(*it);
	if (aNode)
	{
		aNode->id = ++count;
	}
}
