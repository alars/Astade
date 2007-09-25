if (colorisePosition == GetInsertionPoint())
	return;

contentChanged = false;
colorisePosition = GetInsertionPoint();

Colorise();