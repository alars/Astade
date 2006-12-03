bool retVal = false;

if(GetDataSize() == len)
{
	memcpy(&copySource, buf, len);
	retVal = true;
}

return retVal;