if ((eventNumber < 0) ||
	(static_cast<unsigned>(eventNumber) >= itsEvents.size()))
	return wxEmptyString;

char formate[50];
sprintf(formate,"%%04d %%%ds %%%ds   %%s   %%-%ds   %%s\n",longestTimeStamp,longestObjectName,longestObjectName);

wxString ret;

switch (itsEvents[eventNumber].eventID)
{
	case ID_EXIST:
		ret.Printf("! %s\n",classes[itsEvents[eventNumber].destinationObject].c_str());
	break;

	case ID_STATECHANGE:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),">>>",itsEvents[eventNumber].label.c_str(),"");
	break;

	case ID_GLOBALCALL:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),"*","==>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_CALL:
	case ID_SELFCALL:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),"==>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_RECEIVE:
	case ID_SELFRECEIVE:
		if (itsEvents[eventNumber].sourceObject >= 0)
			ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),"-->",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
		else
			ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),"*","-->",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_SEND:
	case ID_SELFSEND:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),">--",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_COMMENT:
		ret.Printf("# %s\n",itsEvents[eventNumber].label.c_str());
	break;

	case ID_GLOBALRETURN:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),"*","<==",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_RETURN:
	case ID_SELFRETURN:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),"<==",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_TASKSWITCH:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),"<=>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_CREATE:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),"(!)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_GLOBALCREATE:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),"*","(!)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_DELETE:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),classes[itsEvents[eventNumber].sourceObject].c_str(),"(X)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_GLOBALDELETE:
		ret.Printf(formate,eventNumber,itsEvents[eventNumber].aTimeStamp.c_str(),"*","(X)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_CLASSBOX:
	case ID_NOP:
	break;

	default:
		ret = "<UNKNOWN>\n";
	break;
}

return ret;