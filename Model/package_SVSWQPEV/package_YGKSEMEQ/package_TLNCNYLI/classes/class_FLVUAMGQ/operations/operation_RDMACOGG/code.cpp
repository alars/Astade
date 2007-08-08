if (dynamic_cast<AdeAttribute*>(theModelElement) != 0)
	return new AstadeAttribute(static_cast<AdeAttribute*>(theModelElement));

return new AstadeTreeItemBase(theModelElement);