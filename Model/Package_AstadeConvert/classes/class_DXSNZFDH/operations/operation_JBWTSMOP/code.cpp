//~~ void printForwardDeclaration(unsigned int indent) [ACSourceFile] ~~
if (m_keyword ==0 )
    return;
    
bool init = false;

wxFileName PrefixName(m_Element->GetFileName());
wxTextFile prefixtext(PrefixName.GetFullPath());
if (prefixtext.Exists())
    prefixtext.Open();
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
    wxString str;
    for (str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine())
    {
        if (str.find(wxS("//~~")) != 0)
        {
            if (!init)
            {
                printf("\n");
                pIndent(indent);
                printf("%s:",m_keyword);
                init = true;
            }
            printf("\n");
            pIndent(indent+1);
            str.Replace(wxS("\t"),wxS("\\t"));
            str.Replace(wxS("\""),wxS("\\\""));
            printf("\"%s\"",str.mb_str().data());
        }
    }
    if (init)
        printf(";\n");
    else
        printf("\n");
}
