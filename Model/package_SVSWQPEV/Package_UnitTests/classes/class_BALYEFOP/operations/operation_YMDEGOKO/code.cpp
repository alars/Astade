switch (event.GetInt())
{
	case 0:
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);
		break;
	case 1:
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
		break;
	case 2:
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
		break;
}

addButton->Enable(AdeRevisionControlBase::GetRevisionControlObject()->IsAddSupported());
