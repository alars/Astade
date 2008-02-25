wxStringTokenizer tkz(theClassInclude, ",;");
while (tkz.HasMoreTokens())
    filenames.insert(tkz.GetNextToken().Trim(true).Trim(false));
