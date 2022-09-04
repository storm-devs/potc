int Whr_InitDayStorm(int n)
{
// ====================================================================
// Day storm, 7 - 17 hour

	Weathers[n].id = "Day Storm";
	Weathers[n].Hour.Min = 0;
	Weathers[n].Hour.Max = 24;
	Weathers[n].Lighting = "day3";
	Weathers[n].LightingLm = "storm";
	Weathers[n].InsideBack = "n";

	Weathers[n].Storm = true;
	Weathers[n].Tornado = true;
	Weathers[n].Shark = true;
	Weathers[n].Lights = false;
	Weathers[n].Night = false;

	Weathers[n].Shadow.Density.Head = argb(255,96,96,96);
	Weathers[n].Shadow.Density.Foot = argb(255,96,96,64);

	Weathers[n].Lightning.Enable = true;
	Weathers[n].Lightning.Texture = "Weather\lightning\lightning_storm.tga";
	Weathers[n].Lightning.FlickerTime = 32;
	Weathers[n].Lightning.SubTexX = 4;
	Weathers[n].Lightning.SubTexY = 1;
	Weathers[n].Lightning.ScaleX = 0.7;
	Weathers[n].Lightning.ScaleY = 1.0;
	Weathers[n].Lightning.Flash.Texture = "Weather\lightning\flash.tga";

	Weathers[n].Sky.Dir = "weather\skies\7\";
	Weathers[n].Sky.Color = argb(0,255,255,255);
	Weathers[n].Sky.Rotate.Min = 0.004;
	Weathers[n].Sky.Rotate.Max = 0.008;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.0;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 14000.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.030;
	Weathers[n].Fog.SeaDensity = 0.019;
	Weathers[n].Fog.Color = argb(0,33,40,50);
	
	Weathers[n].Rain.NumDrops = 10000;
	Weathers[n].Rain.Color = argb(0,63,63,63);
	Weathers[n].Rain.DropLength = 2.12;
	Weathers[n].Rain.Height = 30.0;
	Weathers[n].Rain.Radius = 30.0;
	Weathers[n].Rain.Speed = 18.0;
	Weathers[n].Rain.Jitter = 0.4;
	Weathers[n].Rain.WindSpeedJitter = 0.5;
	Weathers[n].Rain.MaxBlend = 129;
	Weathers[n].Rain.TimeBlend = 2000;

	Weathers[n].Rainbow.Enable = false;
	Weathers[n].Rainbow.Texture = "weather\rainbow\rainbow.tga";

	Weathers[n].Sun.Color = argb(0,189,209,228);
	Weathers[n].Sun.Ambient = argb(0,33,33,55);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(90.0);
	Weathers[n].Sun.HeightAngle = 0.95;

	Weathers[n].Sun.Glow.Enable = false;
	
	Weathers[n].Sun.Flare.Enable = false;
	Weathers[n].Sun.Overflow.Enable = false;

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,67,65,67);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,0,0);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.07;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 9.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.1;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.Water.Color = argb(0,0,0,10);
	Weathers[n].Sea.Pena.Color = argb(0,100,100,100);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.07;
	Weathers[n].Sea.Bump.Ang = 2.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 23.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 1.0;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,0,0,0);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,0,0,0);
	Weathers[n].Sea.SunRoad.Power = 3.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,10.0,0.1202,80.87,-68.00";
	Weathers[n].Sea.Harmonics.h2 = "1.57,10.0,2.1002,82.28,88.00";
	Weathers[n].Sea.Harmonics.h3 = "0.47,7.0,2.2002,82.28,68.00";
	Weathers[n].Sea.Harmonics.h4 = "0.27,47.0,0.0502,82.28,288.00";
	Weathers[n].Sea.Harmonics.h5 = "1.27,57.0,0.0702,82.28,188.00";
	Weathers[n].Sea.Harmonics.h6 = "2.27,57.0,0.0302,82.28,88.00";
	Weathers[n].Sea.Harmonics.h7 = "2.27,37.0,0.1402,82.28,188.00";
	Weathers[n].Sea.Harmonics.h8 = "2.77,17.0,0.0502,82.28,288.00";
	Weathers[n].Sea.Harmonics.h9 = "1.77,17.0,0.1002,82.28,188.00";
	Weathers[n].Sea.Harmonics.h10 = "1.0,14.0,0.5002,82.28,28.00";
	
	Weathers[n].Wind.Angle = 3.59;
	Weathers[n].Wind.Speed.Min = 14.0;
	Weathers[n].Wind.Speed.Max = 18.0;
	
	n++;

// ====================================================================
// Day storm, 7 - 17 hour

	Weathers[n].id = "Black Pearl Fight";
	Weathers[n].Hour.Min = 0;
	Weathers[n].Hour.Max = 24;
	Weathers[n].Lighting = "day3";
	Weathers[n].LightingLm = "storm";
	Weathers[n].InsideBack = "n";
	Weathers[n].Skip = true;

	Weathers[n].Storm = true;
	Weathers[n].Tornado = true;
	Weathers[n].Shark = false;
	Weathers[n].Lights = false;
	Weathers[n].Night = true;

	Weathers[n].Shadow.Density.Head = argb(255,96,96,96);
	Weathers[n].Shadow.Density.Foot = argb(255,96,96,64);

	Weathers[n].Lightning.Enable = true;
	Weathers[n].Lightning.Texture = "Weather\lightning\lightning_storm.tga";
	Weathers[n].Lightning.FlickerTime = 32;
	Weathers[n].Lightning.SubTexX = 4;
	Weathers[n].Lightning.SubTexY = 1;
	Weathers[n].Lightning.ScaleX = 0.7;
	Weathers[n].Lightning.ScaleY = 1.0;
	Weathers[n].Lightning.Flash.Texture = "Weather\lightning\flash.tga";

	Weathers[n].Sky.Dir = "weather\skies\7\";
	Weathers[n].Sky.Color = argb(0,255,255,255);
	Weathers[n].Sky.Rotate.Min = 0.004;
	Weathers[n].Sky.Rotate.Max = 0.008;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.0;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 500.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.0010;
	Weathers[n].Fog.SeaDensity = 0.019;
	Weathers[n].Fog.Color = argb(0,33,40,50);
	
	Weathers[n].Rain.NumDrops = 1500;
	Weathers[n].Rain.Color = argb(0,63,63,63);
	Weathers[n].Rain.DropLength = 4.12;
	Weathers[n].Rain.Height = 30.0;
	Weathers[n].Rain.Radius = 30.0;
	Weathers[n].Rain.Speed = 20.0;
	Weathers[n].Rain.Jitter = 0.4;
	Weathers[n].Rain.WindSpeedJitter = 0.5;
	Weathers[n].Rain.MaxBlend = 129;
	Weathers[n].Rain.TimeBlend = 2000;

	Weathers[n].Rainbow.Enable = false;
	Weathers[n].Rainbow.Texture = "weather\rainbow\rainbow.tga";

	Weathers[n].Sun.Color = argb(0,189,209,228);
	Weathers[n].Sun.Ambient = argb(0,33,33,55);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(90.0);
	Weathers[n].Sun.HeightAngle = 0.95;

	Weathers[n].Sun.Glow.Enable = false;
	
	Weathers[n].Sun.Flare.Enable = false;
	Weathers[n].Sun.Overflow.Enable = false;

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,0,10);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.07;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 9.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.1;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.Water.Color = argb(0,0,0,10);
	Weathers[n].Sea.Pena.Color = argb(0,100,100,100);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.07;
	Weathers[n].Sea.Bump.Ang = 2.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 23.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 1.0;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,0,0,0);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,0,0,0);
	Weathers[n].Sea.SunRoad.Power = 3.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,10.0,0.1202,80.87,-68.00";
	Weathers[n].Sea.Harmonics.h2 = "1.57,10.0,2.1002,82.28,88.00";
	Weathers[n].Sea.Harmonics.h3 = "0.47,7.0,2.2002,82.28,68.00";
	Weathers[n].Sea.Harmonics.h4 = "0.27,47.0,0.0502,82.28,288.00";
	Weathers[n].Sea.Harmonics.h5 = "1.27,57.0,0.0702,82.28,188.00";
	Weathers[n].Sea.Harmonics.h6 = "2.27,57.0,0.0302,82.28,88.00";
	Weathers[n].Sea.Harmonics.h7 = "2.27,37.0,0.1402,82.28,188.00";
	Weathers[n].Sea.Harmonics.h8 = "2.77,17.0,0.0502,82.28,288.00";
	Weathers[n].Sea.Harmonics.h9 = "1.77,17.0,0.1002,82.28,188.00";
	Weathers[n].Sea.Harmonics.h10 = "1.0,14.0,0.5002,82.28,28.00";
	
	Weathers[n].Wind.Angle = 3.59;
	Weathers[n].Wind.Speed.Min = 14.0;
	Weathers[n].Wind.Speed.Max = 18.0;
	
	n++;

	return n;
}