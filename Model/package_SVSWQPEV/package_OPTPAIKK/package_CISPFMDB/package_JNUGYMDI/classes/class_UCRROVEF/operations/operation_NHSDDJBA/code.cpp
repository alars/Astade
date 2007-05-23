wxFileName newFilename = GuessGoodFilename("parameter_" + GetName());

if (GetFileName() != newFilename)
	AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(),newFilename);