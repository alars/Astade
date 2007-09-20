wxFileName ret;

if ((myOperationParser == 0) || (!myOperationParser->ParseSuccessful()))
	return ret;

if (!myOperationParser->returnType.empty()
	&& !myOperationParser->functionName.empty()
	&& myOperationParser->functionName[0] != '~')
{
	// normal operation
	ret = AdeOperation::CreateNewElement(myModelElement->GetFileName(),
			myOperationParser->functionName,
			myOperationParser->returnType,
			myOperationParser->isVirtual,
			false,
			myOperationParser->isStatic,
			myOperationParser->isConst);
}

if (myOperationParser->returnType.empty()
	&& !myOperationParser->functionName.empty()
	&& myOperationParser->functionName[0] == '~')
{
	// destructor
}

if (myOperationParser->returnType.empty()
	&& !myOperationParser->functionName.empty()
	&& myOperationParser->functionName[0] != '~')
{
	// possible Constructor
	int result = wxMessageDialog(ourTree, "The function in clipboard has no return type.\nIs it a constructor?", "Constructor?", wxYES_NO).ShowModal();
}


return ret;