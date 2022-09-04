int Whr_InitNight(int n)
{

// ====================================================================
// night, 23 - 7 hour

	Weathers[n].id = "Moon Night";
	Weathers[n].Hour.Min = 23;
	Weathers[n].Hour.Max = 7;
	Weathers[n].Lighting = "night1";
	Weathers[n].LightingLm = "storm";
	Weathers[n].InsideBack = "n";

	Weathers[n].Storm = false;
	Weathers[n].Tornado = false;
	Weathers[n].Shark = true;
	Weathers[n].Lights = true;
	Weathers[n].Night = true;

	Weathers[n].Shadow.Density.Head = argb(255,96,96,96);
	Weathers[n].Shadow.Density.Foot = argb(255,96,96,64);

	Weathers[n].Lightning.Enable = false;
	Weathers[n].Lightning.Texture = "Weather\lightning\lightning.tga";
	Weathers[n].Lightning.FlickerTime = 32;
	Weathers[n].Lightning.SubTexX = 1;
	Weathers[n].Lightning.SubTexY = 1;

	Weathers[n].Sky.Dir = "weather\skies\6\";
	Weathers[n].Sky.Color = argb(0,200,200,255);
	Weathers[n].Sky.Rotate = 0.0;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.06;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 100.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.003;
	Weathers[n].Fog.SeaDensity = 0.003;
	Weathers[n].Fog.Color = argb(0,11,11,22);
	
	Weathers[n].Rain.NumDrops = 0;

	Weathers[n].Rainbow.Enable = false;

	Weathers[n].Sun.Color = argb(0,170,195,255);
	Weathers[n].Sun.Ambient = argb(0,12,23,33);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(0.0);
	Weathers[n].Sun.HeightAngle = 0.15;

	Weathers[n].Sun.Glow.Enable = false;
	Weathers[n].Sun.Flare.Enable = false;
	Weathers[n].Sun.Overflow.Enable = false;

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,29,30,47);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,0,0);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.05;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 7.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.4;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,200,200,255);
	Weathers[n].Sea.Water.Color = argb(0,20,28,36);
	Weathers[n].Sea.Pena.Color = argb(0,50,50,80);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.05;
	Weathers[n].Sea.Bump.Ang = 0.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 15.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 0.995;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,55,55,100);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,255,255,255);
	Weathers[n].Sea.SunRoad.Power = 3.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,10.0,0.4202,80.87,-48.00";
	Weathers[n].Sea.Harmonics.h2 = "1.57,12.0,0.2002,82.28,48.00";
	Weathers[n].Sea.Harmonics.h3 = "0.27,7.0,0.2002,82.28,48.00";

	Weathers[n].Wind.Angle = 1.0;
	Weathers[n].Wind.Speed.Min = 5.0;
	Weathers[n].Wind.Speed.Max = 7.0;
	
	n++;
	return n;
}
