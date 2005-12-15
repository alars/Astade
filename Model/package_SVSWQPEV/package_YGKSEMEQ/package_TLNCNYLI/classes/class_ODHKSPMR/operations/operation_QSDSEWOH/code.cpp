wxMenu* aSubUp =  new wxMenu("");

aSubUp->AppendRadioItem(-1,"no attributes");
aSubUp->AppendRadioItem(-1,"public attributes");
aSubUp->AppendRadioItem(-1,"public + private attributes");
aSubUp->AppendRadioItem(-1,"all attributes");

aSubUp->AppendSeparator();

aSubUp->AppendRadioItem(-1,"no operations");
aSubUp->AppendRadioItem(-1,"public operations");
aSubUp->AppendRadioItem(-1,"public + private operations");
aSubUp->AppendRadioItem(-1,"all operations");

aSubUp->AppendSeparator();

aSubUp->AppendCheckItem(-1,"show external");

aSubUp->AppendSeparator();

aSubUp->Append(ID_OBJECTMODELDIAGRAM,"show","", wxITEM_NORMAL);

return aSubUp;