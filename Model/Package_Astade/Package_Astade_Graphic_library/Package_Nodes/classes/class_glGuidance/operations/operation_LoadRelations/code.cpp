//~~ void LoadRelations(wxConfigBase& configObject) [glGuidance] ~~


int count = 1;

wxString attachName;
attachName.Printf(wxS("Attach%03d"), count);

while (configObject.Exists(attachName))
{
	int AttachID;
	configObject.Read(attachName, &AttachID);
	
	glNode* partnerNode = glNode::getNodeById(AttachID);
	
	if (partnerNode)
		new glAttach(myParent, *this, *partnerNode);
	
	count++;
	attachName.Printf(wxS("Attach%03d"), count);
}
