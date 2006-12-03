bool retVal = false;

if((buf) && copySource.IsOk())
{
	memcpy(buf, &copySource, GetDataSize());
	retVal = true;
}

return retVal;