if (dynamic_cast<AdeAttribute*>(theModelElement) != 0)
	return new AstadeAttribute(static_cast<AdeAttribute*>(theModelElement));

if (dynamic_cast<AdeAttributes*>(theModelElement) != 0)
	return new AstadeAttributes(static_cast<AdeAttributes*>(theModelElement));

if (dynamic_cast<AdeClass*>(theModelElement) != 0)
	return new AstadeClass(static_cast<AdeClass*>(theModelElement));

return new AstadeTreeItemBase(theModelElement);