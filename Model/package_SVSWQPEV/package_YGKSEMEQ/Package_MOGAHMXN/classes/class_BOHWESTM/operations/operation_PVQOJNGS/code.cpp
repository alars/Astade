iconBitmapMap_t::iterator iter = myIconBitmapMap.find(index);
if(iter!=myIconBitmapMap.end())	
	return iter->second;
else
	return wxNullBitmap;
