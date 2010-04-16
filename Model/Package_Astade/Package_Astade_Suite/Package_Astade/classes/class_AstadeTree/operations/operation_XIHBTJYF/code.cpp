wxCommandEvent dummy;
AstadeFrame* myFrame = dynamic_cast<AstadeFrame*>(GetParent());
if ((myFrame != 0) && (event.m_controlDown))
	myFrame->Features(dummy);
