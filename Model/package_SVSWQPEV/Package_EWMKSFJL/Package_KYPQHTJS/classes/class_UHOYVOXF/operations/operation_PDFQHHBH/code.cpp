const double maxspeed = 1;

speed *= damping;

double speedMod = speed.Mod();

if (speedMod > maxspeed)
{
	speed /= speedMod;
	speed *= maxspeed;
}

absPosition += speed;
