wxFileName newFilename = GuessGoodFilename("attribute_" + GetName());

if (GetFileName() != newFilename)
	AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(),newFilename);