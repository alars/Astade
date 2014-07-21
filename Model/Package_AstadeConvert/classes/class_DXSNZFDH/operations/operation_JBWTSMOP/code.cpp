//~~ void printForwardDeclaration(unsigned int indent) [ACSourceFile] ~~
if (m_keyword ==0 )
    return;
    
pIndent(indent);
printf("%s:",m_keyword);

wxFileName PrefixName(m_Element->GetFileName());
wxTextFile prefixtext(PrefixName.GetFullPath());
if (prefixtext.Exists())
    prefixtext.Open();
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
    wxString str;
    for (str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine())
    {
        printf("\n");
        pIndent(indent+1);
        str.Replace(wxS("\t"),wxS("\\t"));
        str.Replace(wxS("\""),wxS("\\\""));
        printf("\"%s\"",str.mb_str().data());
    }
    printf(";\n");
}
