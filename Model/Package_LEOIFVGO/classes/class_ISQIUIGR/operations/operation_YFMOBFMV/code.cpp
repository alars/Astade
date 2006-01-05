if ((eventNumber<0) || (eventNumber>itsEvents.size()))
	return wxEmptyString;

char formate[50];
sprintf(formate,"%%04d %%%ds   %%s   %%-%ds   %%s\n",longestObjectName,longestObjectName);

wxString ret;
char command[10] = "?";

switch (itsEvents[eventNumber].eventID)
{
	case ID_EXIST:
		ret.Printf("! %s\n",classes[itsEvents[eventNumber].destinationObject].c_str());
	break;

	case ID_STATECHANGE:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),">>>",itsEvents[eventNumber].label.c_str(),"");
	break;

	case ID_GLOBALCALL:
		ret.Printf(formate,eventNumber,"*","==>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_CALL:
	case ID_SELFCALL:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),"==>",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_RECEIVE:
	case ID_SELFRECEIVE:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),"-->",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_SEND:
	case ID_SELFSEND:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),">--",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_COMMENT:
		ret.Printf("# %s\n",itsEvents[eventNumber].label.c_str());
	break;

	case ID_GLOBALRETURN:
		ret.Printf(formate,eventNumber,"*","<==",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_RETURN:
	case ID_SELFRETURN:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),"<==",classes[itsEvents[eventNumber].destinationObject].c_str(),itsEvents[eventNumber].label.c_str());
	break;

	case ID_CREATE:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),"(!)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_GLOBALCREATE:
		ret.Printf(formate,eventNumber,"*","(!)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_DELETE:
		ret.Printf(formate,eventNumber,classes[itsEvents[eventNumber].sourceObject].c_str(),"(X)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_GLOBALDELETE:
		ret.Printf(formate,eventNumber,"*","(X)",classes[itsEvents[eventNumber].destinationObject].c_str(),"");
	break;

	case ID_CLASSBOX:
	case ID_NOP:
	break;

	default:
		ret = "<UNKNOWN>\n";
	break;
}

return ret;