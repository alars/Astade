wxMenu* aSubUp =  new wxMenu("");

aSubUp->Append(ID_EDITSPECPROLOG,"edit specification prolog","", wxITEM_NORMAL);
aSubUp->Append(ID_EDITIMPPROLOG,"edit implementation prolog","", wxITEM_NORMAL);
aSubUp->Append(ID_EDITSPECEPILOG,"edit specification epilog","", wxITEM_NORMAL);
aSubUp->Append(ID_EDITIMPGEPILOG,"edit implementation epilog","", wxITEM_NORMAL);

return aSubUp;