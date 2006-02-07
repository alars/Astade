int rc = lhs.CmpNoCase(rhs);
if (rc == 0)
	rc = lhs.Cmp(rhs);
return rc < 0;
