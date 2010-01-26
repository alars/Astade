// FIXME: wxWidgets/UTF-8/STL around r63252 crashes in ~wxStringTokenizer()
static wxStringTokenizer tkz;
tkz.SetString(theClassInclude, ",;");
while (tkz.HasMoreTokens())
    filenames.insert(tkz.GetNextToken().Trim(true).Trim(false));
