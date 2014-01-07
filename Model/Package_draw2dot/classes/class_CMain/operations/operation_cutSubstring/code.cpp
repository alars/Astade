//~~ wxString cutSubstring(wxString& string, int charCount) [CMain] ~~
if (string.Len() < 2)
{
	wxString ret(string);
	string.clear();
	return ret;
}

int first = charCount;

wxString firstPart = string.Mid(0,charCount);

if (firstPart.Find(' ',true) > (int)(firstPart.size()/3))
    first = firstPart.Find(' ',true);
else if (firstPart.Find('-',true) > (int)(firstPart.size()/3))
    first = firstPart.Find('-',true)+1;

firstPart = string.Mid(0,first);
firstPart.Trim(true);
firstPart.Trim(false);

string = string.Mid(first);

string.Trim(true);
string.Trim(false);

return firstPart;
