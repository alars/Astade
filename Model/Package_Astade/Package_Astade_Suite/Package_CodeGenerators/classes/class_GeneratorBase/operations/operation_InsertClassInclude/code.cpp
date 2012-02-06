//~~ void InsertClassInclude(std::set<wxString, AdeStringCompare>& filenames, const wxString& theClassInclude) [GeneratorBase] ~~

wxStringTokenizer tkz(theClassInclude, wxS(",;"));
while (tkz.HasMoreTokens())
    filenames.insert(tkz.GetNextToken().Trim(true).Trim(false));
