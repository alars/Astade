const int maxspeed = 5;

speed *= damping;

double speedMod = speed.Mod();

if (speedMod > maxspeed)
{
	speed /= speedMod;
	speed *= maxspeed;
}

absPosition += speed;