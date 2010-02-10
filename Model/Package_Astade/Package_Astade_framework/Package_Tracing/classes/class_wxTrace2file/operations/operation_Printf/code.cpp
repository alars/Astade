// Argumenteliste für eine variable Anzahl von
// Funktionsargumenten erzeugen
va_list ap;
va_start(ap, fmt);

// Ausgeben mit wx-Funktion
wxString s;
int nRet = s.PrintfV(fmt, ap);
// Argumenteliste aufräumen
va_end( ap);

if (ms_ofile.is_open())
{
	wxMutexLocker lock(myMutex);
	ms_ofile << "#" << (const char*)s.c_str() << std::endl;
}
return nRet;
