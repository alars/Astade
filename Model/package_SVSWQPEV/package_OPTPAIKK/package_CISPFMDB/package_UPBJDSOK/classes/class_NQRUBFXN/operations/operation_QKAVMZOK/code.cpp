wxString s;
char range = 'Z' - 'A' + 1;
for (int i=0;i<8;i++)
{
	char c = 'A' + char(range * rand()/(RAND_MAX + 1.0));
	s = s + c;
}
return s;
