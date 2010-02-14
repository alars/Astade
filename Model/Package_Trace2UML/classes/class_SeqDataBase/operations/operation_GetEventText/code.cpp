if (eventNumber < 0 ||
	static_cast<unsigned>(eventNumber) >= itsEvents.size())
	return wxEmptyString;

wxString format;
format.Printf(wxS("%%04d %%%ds %%%ds   %%s   %%-%ds   %%s\n"), longestTimeStamp, longestObjectName, longestObjectName);

wxString ret;

switch (itsEvents[eventNumber].eventID)
{
	case ID_EXIST:
		ret.Printf(wxS("! %s\n"), classes[itsEvents[eventNumber].destinationObject].c_str());
		break;

	case ID_STATECHANGE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS(">>>"), itsEvents[eventNumber].label.c_str(), wxS(""));
		break;

	case ID_NOTE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("note:"), itsEvents[eventNumber].label.c_str(), wxS(""));
		break;

	case ID_GLOBALCALL:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), wxS("~"), wxS("==>"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_CALL:
	case ID_SELFCALL:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("==>"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_RECEIVE:
	case ID_SELFRECEIVE:
		if (itsEvents[eventNumber].sourceObject >= 0)
			ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("-->"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		else
			ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), wxS("~"), wxS("-->"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_GLOBALRECEIVE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), wxS("~"), wxS("-->"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_SEND:
	case ID_SELFSEND:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS(">--"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_COMMENT:
		ret.Printf(wxS("# %s\n"), itsEvents[eventNumber].label.c_str());
		break;

	case ID_COMMENTONLY:
		ret.Printf(wxS("%s\n"), itsEvents[eventNumber].label.c_str());
		break;

	case ID_GLOBALRETURN:
		if (itsEvents[eventNumber].eventNumber != 0)
		{
			wxString action;
			action.Printf("ret(%d)",itsEvents[eventNumber].eventNumber);
			ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), action.c_str(), "   ", "", itsEvents[eventNumber].label.c_str());
		}
		else
			ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), wxS("~"), wxS("<=="), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_RETURN:
	case ID_SELFRETURN:
		if (itsEvents[eventNumber].eventNumber != 0)
		{
			wxString action;
			action.Printf("ret(%d)",itsEvents[eventNumber].eventNumber);
			ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), action.c_str(), "   ", "", itsEvents[eventNumber].label.c_str());
		}
		else
			ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("<=="), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_TASKSWITCH:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("<=>"), classes[itsEvents[eventNumber].destinationObject].c_str(), itsEvents[eventNumber].label.c_str());
		break;

	case ID_CREATE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("(!)"), classes[itsEvents[eventNumber].destinationObject].c_str(), wxS(""));
		break;

	case ID_GLOBALCREATE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), wxS("~"), wxS("(!)"), classes[itsEvents[eventNumber].destinationObject].c_str(), wxS(""));
		break;

	case ID_DELETE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), classes[itsEvents[eventNumber].sourceObject].c_str(), wxS("(X)"), classes[itsEvents[eventNumber].destinationObject].c_str(), wxS(""));
		break;

	case ID_GLOBALDELETE:
		ret.Printf(format, eventNumber, itsEvents[eventNumber].aTimeStamp.c_str(), wxS("~"), wxS("(X)"), classes[itsEvents[eventNumber].destinationObject].c_str(), wxS(""));
		break;

	case ID_PAUSE:
		ret.Printf(wxS("...\n"));
		break;

	case ID_CLASSBOX:
	case ID_NOP:
		break;

	default:
		ret = wxS("<UNKNOWN>\n");
		break;
}

return ret;
