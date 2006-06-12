GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);

if (aUseCase &&
	(relationType==generalisationID) &&
	(myExtent.find(aUseCase)==myExtent.end()) &&
	(myInclude.find(aUseCase)==myInclude.end()))
	mySuperclass.insert(mySuperclass.begin(),aUseCase);

if (aUseCase &&
	(relationType==extendID) &&
	(mySuperclass.find(aUseCase)==mySuperclass.end()) &&
	(myInclude.find(aUseCase)==myInclude.end()))
	myExtent.insert(myExtent.begin(),aUseCase);

if (aUseCase &&
	(relationType==includeID) &&
	(mySuperclass.find(aUseCase)==mySuperclass.end()) &&
	(myExtent.find(aUseCase)==myExtent.end()))
	myInclude.insert(myInclude.begin(),aUseCase);

