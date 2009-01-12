stateFastest = false;
switch (speed)
{
	case 0: moveTimer.Start(100);break;
	case 1: moveTimer.Start(20);break;
	case 2: moveTimer.Start(4);break;
	case 3: moveTimer.Start(100);
			stateFastest = true;
		break;
}