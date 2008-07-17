if (me == NULL)
{
	::wxInitAllImageHandlers();
	me = new AstadeIcons();
}
return me;