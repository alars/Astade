speed *= glFloatingConstants::damping;

double speedMod = speed.Mod();

if (speedMod > glFloatingConstants::maxspeed)
{
	speed /= speedMod;
	speed *= glFloatingConstants::maxspeed;
}

absPosition += speed;
