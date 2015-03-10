//~~ void CodeCommonEventFiles() [StateChartCoderBase] ~~

wxFileName aFilename = myFilename;
std::set<wxString> aSet = myAdeStatechart->GetTrigger();
aFilename.SetFullName(getPrefix()+wxS("_events.h"));

boost::interprocess::named_semaphore aSem(boost::interprocess::open_or_create_t(), (::wxGetUserId() + wxS("_ACF_events")).utf8_str(), 1);
aSem.wait();

wxTextFile aTextFile(aFilename.GetFullPath());
if (aTextFile.Exists())
{
	aTextFile.Open();

	for (wxString line = aTextFile.GetFirstLine(); !aTextFile.Eof(); line = aTextFile.GetNextLine())
	{
		char found[200];
		if (sscanf(line.utf8_str(), "extern const char* %s", found) == 1)
		{
			wxString aString(found, wxConvUTF8);
			aString.RemoveLast(); //semicolon
			aSet.insert(aString);
		}
	}
}

std::ofstream out;
out.open(aFilename.GetFullPath().utf8_str());
PrintHeader(out, aFilename.GetFullName());

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
	out << "extern const char* "
		<< iter->utf8_str()
		<< ";"
		<< std::endl;
}
out << std::endl;
out.close();

aSet.erase(getPrefix()+wxS("_timeout"));
aFilename.SetExt(wxS("c"));
out.open(aFilename.GetFullPath().utf8_str());
PrintHeader(out, aFilename.GetFullName());

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
	out << "const char* "
		<< iter->utf8_str()
		<< " = \""
		<< iter->utf8_str()
		<< "\";"
		<< std::endl;
}
out << std::endl;
out.close();

aSem.post();
