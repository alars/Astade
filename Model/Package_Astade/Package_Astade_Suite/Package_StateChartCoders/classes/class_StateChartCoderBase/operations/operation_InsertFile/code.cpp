wxFileName PrefixName(myAdeStatechart->GetFileName());
PrefixName.SetFullName(name);
wxTextFile Gprefixtext(PrefixName.GetFullPath());
if (Gprefixtext.Exists())
	Gprefixtext.Open();
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		fprintf(fd,"%s\n",(const char*)str.c_str());
	if (!str.empty())
		fprintf(fd,"%s\n",(const char*)str.c_str());
	fprintf(fd,"\n");
}
