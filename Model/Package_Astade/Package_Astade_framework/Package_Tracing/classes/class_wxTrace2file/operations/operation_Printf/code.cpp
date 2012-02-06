//~~ int Printf(const char* fmt, ...) [wxTrace2file] ~~

// Argumenteliste für eine variable Anzahl von
// Funktionsargumenten erzeugen
va_list ap;
va_start(ap, fmt);

// Ausgeben mit wx-Funktion
wxString f(fmt, wxConvAuto());
wxString s;
int nRet = s.PrintfV(f, ap);
// Argumenteliste aufräumen
va_end( ap);

if (ms_ofile.is_open())
{
	wxMutexLocker lock(myMutex);
	ms_ofile << "#" << (const char*)s.utf8_str() << std::endl;
}
return nRet;
