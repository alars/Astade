//~~ void CodeCommonEventFiles() [StateChartCoderBase] ~~

wxFileName aFilename = myFilename;
std::set<wxString> aSet = myAdeStatechart->GetTrigger();
aFilename.SetFullName("ACF_events.h");

boost::interprocess::named_semaphore aSem(boost::interprocess::open_or_create_t(), "ACF_events", 1);
aSem.wait();

wxTextFile aTextFile(aFilename.GetFullPath());
if (aTextFile.Exists())
{
	aTextFile.Open();

	for (wxString line = aTextFile.GetFirstLine(); !aTextFile.Eof(); line = aTextFile.GetNextLine())
	{
		char found[200];	
		if (sscanf(line.c_str(),"extern const char* %s",found) == 1)
		{
			wxString aString(found);
			aString.RemoveLast(); //semicolon
			aSet.insert(aString);
		}
	}
}

std::ofstream out;

out.open(aFilename.GetFullPath().c_str());
PrintHeader(out, aFilename.GetFullName());

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
	out << "extern const char* "
		<< (*iter).c_str()
		<< ";"
		<< std::endl;
}
out << std::endl;
out.close();

aSet.erase("ACF_timeout");
aFilename.SetExt("c");
out.open(aFilename.GetFullPath().c_str());
PrintHeader(out, aFilename.GetFullName());

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
{
	out << "const char* "
		<< (*iter).c_str()
		<< " = \""
		<< (*iter).c_str()
		<< "\";"
		<< std::endl;
}
out << std::endl;
out.close();

aSem.post();
