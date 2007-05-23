wxFileName newFilename = GuessGoodFilename("type_" + GetName());

if (GetFileName() != newFilename)
	AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(),newFilename);