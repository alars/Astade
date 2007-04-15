for (unsigned i = 0; i < itsEvents.size(); ++i)
{
	switch (itsEvents[i].eventID)
	{
		case ID_EXIST:
		case ID_CLASSBOX:
		case ID_GLOBALCALL:
		case ID_GLOBALRECEIVE:
		case ID_GLOBALRETURN:
		case ID_GLOBALCREATE:
		case ID_GLOBALDELETE:
			if (itsEvents[i].destinationObject == classIndex)
				DeleteEvent(i--);
		break;

		case ID_SELFCALL:
		case ID_SELFRECEIVE:
		case ID_STATECHANGE:
		case ID_SELFSEND:
		case ID_SELFRETURN:
			if (itsEvents[i].sourceObject == classIndex)
				DeleteEvent(i--);
		break;

		case ID_SEND:
			if ((itsEvents[i].destinationObject == classIndex) || (itsEvents[i].sourceObject == classIndex))
				DeleteEvent(i--);
		break;

		case ID_RECEIVE:
			if (itsEvents[i].destinationObject == classIndex)
				DeleteEvent(i--);
			else if (itsEvents[i].sourceObject == classIndex)
			{
				itsEvents[i].sourceObject = wxNOT_FOUND;
				itsEvents[i].eventID = ID_GLOBALRECEIVE;
			}
		break;

		case ID_RETURN:
			if (itsEvents[i].destinationObject == classIndex)
				DeleteEvent(i--);
			else if (itsEvents[i].sourceObject == classIndex)
			{
				itsEvents[i].sourceObject = wxNOT_FOUND;
				itsEvents[i].eventID = ID_GLOBALRETURN;
			}
		break;

		case ID_CALL:
			if (itsEvents[i].destinationObject == classIndex)
				DeleteEvent(i--);
			else if (itsEvents[i].sourceObject == classIndex)
			{
				itsEvents[i].sourceObject = wxNOT_FOUND;
				itsEvents[i].eventID = ID_GLOBALCALL;
			}
		break;

		case ID_CREATE:
			if (itsEvents[i].destinationObject == classIndex)
				DeleteEvent(i--);
			else if (itsEvents[i].sourceObject == classIndex)
			{
				itsEvents[i].sourceObject = wxNOT_FOUND;
				itsEvents[i].eventID = ID_GLOBALCREATE;
			}
		break;

		case ID_DELETE:
			if (itsEvents[i].destinationObject == classIndex)
				DeleteEvent(i--);
			else if (itsEvents[i].sourceObject == classIndex)
			{
				itsEvents[i].sourceObject = wxNOT_FOUND;
				itsEvents[i].eventID = ID_GLOBALDELETE;
			}
		break;
	}
}