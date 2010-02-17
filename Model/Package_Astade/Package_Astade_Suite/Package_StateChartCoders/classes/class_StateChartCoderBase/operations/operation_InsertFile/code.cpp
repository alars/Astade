wxFileName PrefixName;
if (name.GetDirCount() == 0)
{
	PrefixName = myAdeStatechart->GetFileName();
	PrefixName.SetFullName(name.GetFullName());
}
else
	PrefixName = name;
wxTextFile Gprefixtext(PrefixName.GetFullPath());
if (Gprefixtext.Exists())
	Gprefixtext.Open();
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		stream << str.c_str() << std::endl;
	if (!str.empty())
		stream << str.c_str() << std::endl;
	stream << std::endl;
}
