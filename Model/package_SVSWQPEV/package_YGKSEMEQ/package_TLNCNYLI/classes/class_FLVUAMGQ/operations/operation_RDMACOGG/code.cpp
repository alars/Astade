if (dynamic_cast<AdeAttribute*>(theModelElement) != 0)
	return new AstadeAttribute(static_cast<AdeAttribute*>(theModelElement));

if (dynamic_cast<AdeAttributes*>(theModelElement) != 0)
	return new AstadeAttributes(static_cast<AdeAttributes*>(theModelElement));

if (dynamic_cast<AdeStatechart*>(theModelElement) != 0)
	return new AstadeStatechart(static_cast<AdeStatechart*>(theModelElement));

if (dynamic_cast<AdeClass*>(theModelElement) != 0)
	return new AstadeClass(static_cast<AdeClass*>(theModelElement));

if (dynamic_cast<AdeClasses*>(theModelElement) != 0)
	return new AstadeClasses(static_cast<AdeClasses*>(theModelElement));

if (dynamic_cast<AdeComponents*>(theModelElement) != 0)
	return new AstadeComponents(static_cast<AdeComponents*>(theModelElement));

if (dynamic_cast<AdeParameter*>(theModelElement) != 0)
	return new AstadeParameter(static_cast<AdeParameter*>(theModelElement));

if (dynamic_cast<AdeParameters*>(theModelElement) != 0)
	return new AstadeParameters(static_cast<AdeParameters*>(theModelElement));

if (dynamic_cast<AdeSourceFile*>(theModelElement) != 0)
	return new AstadeSourceFile(static_cast<AdeSourceFile*>(theModelElement));

if (dynamic_cast<AdeType*>(theModelElement) != 0)
	return new AstadeType(static_cast<AdeType*>(theModelElement));

if (dynamic_cast<AdeTransition*>(theModelElement) != 0)
	return new AstadeTransition(static_cast<AdeTransition*>(theModelElement));

if (dynamic_cast<AdeState*>(theModelElement) != 0)
	return new AstadeState(static_cast<AdeState*>(theModelElement));

return new AstadeTreeItemBase(theModelElement);