if(thePrototypes.empty())
	Initialize();

wxASSERT_MSG(thePrototypes[myTypeId] == NULL, "There is no prototype for the type of value created!");

return thePrototypes[myTypeId]->Clone();