bool retVal = false;

iconNameMap_t::iterator iter = myIconNameMap.find(name);
if(iter!=myIconNameMap.end())
{
	retVal = Remove(iter->second); // remove the icon from the image list
	
	// find all derived icons
	iconAssocMap_t::iterator iter2 = myIconAssocMap.find(name);	
	if(iter2!=myIconAssocMap.end())
	{
		wxArrayString assoc = iter2->second;
		for(size_t i=0; i<assoc.GetCount(); i++)
		{
			Remove(assoc[i]); // remove the derived icon
		}		
	}	
	myIconAssocMap.erase(iter2); // cleanup references
}
myIconNameMap.erase(iter); // cleanup icon name mapping

return retVal;