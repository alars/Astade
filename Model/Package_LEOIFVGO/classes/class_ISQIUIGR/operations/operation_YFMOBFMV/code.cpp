if ((eventNumber<0) || (eventNumber>itsEvents.size()))
	return wxEmptyString;

char formate[50];
sprintf(formate,"%%%ds   %%s   %%-%ds   %%s\n",longestObjectName,longestObjectName);

wxString ret;
char command[10] = "?";

switch (itsEvents[eventNumber].eventID)
{
	case ID_GLOBALCALL:
		ret.Printf(formate,"*","==>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_CALL:
	case ID_SELFCALL:
		ret.Printf(formate,classes[itsEvents[eventNumber].sourceObject].c_str(),"==>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_RECEIVE:
	case ID_SELFRECEIVE:
		ret.Printf(formate,classes[itsEvents[eventNumber].sourceObject].c_str(),"-->",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_SEND:
	case ID_SELFSEND:
		ret.Printf(formate,classes[itsEvents[eventNumber].sourceObject].c_str(),">--",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_COMMENT:
		ret.Printf("# %s\n",itsEvents[eventNumber].label.c_str());
	break;

	case ID_GLOBALRETURN:
		ret.Printf(formate,"*","<==",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_RETURN:
	case ID_SELFRETURN:
		ret.Printf(formate,classes[itsEvents[eventNumber].sourceObject].c_str(),"<==",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_CREATE:
		ret.Printf(formate,classes[itsEvents[eventNumber].sourceObject].c_str(),"(!)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_GLOBALCREATE:
		ret.Printf(formate,"*","(!)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_DELETE:
		ret.Printf(formate,classes[itsEvents[eventNumber].sourceObject].c_str(),"(X)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_GLOBALDELETE:
		ret.Printf(formate,"*","(X)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_CLASSBOX:
	case ID_NOP:
	break;

	default:
		ret = "<UNKNOWN>\n";
	break;
}

return ret;