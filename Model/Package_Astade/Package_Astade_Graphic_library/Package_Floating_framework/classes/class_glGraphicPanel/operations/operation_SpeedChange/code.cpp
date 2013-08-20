//~~ void SpeedChange(int speed) [glGraphicPanel] ~~
stateFastest = false;
switch (speed)
{
	case 0: moveTimer.Start(100);break;
	case 1: moveTimer.Start(25);break;
	case 2: moveTimer.Start(6);break;
	case 3: moveTimer.Start(6);
			stateFastest = true;
		break;
}