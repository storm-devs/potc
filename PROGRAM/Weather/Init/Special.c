int Whr_InitSpecial(int n)
{
// ====================================================================
// special blue sky for Alcove

	Weathers[n].id = "Alcove";
	Weathers[n].Hour.Min = 7;
	Weathers[n].Hour.Max = 17;
	Weathers[n].Lighting = "day1";
	Weathers[n].LightingLm = "day";
	Weathers[n].InsideBack = "";
	Weathers[n].Skip = true;

	Weathers[n].Storm = false;
	Weathers[n].Tornado = false;
	Weathers[n].Shark = true;
	Weathers[n].Lights = false;
	Weathers[n].Night = false;

	Weathers[n].Shadow.Density.Head = argb(255,96,96,96);
	Weathers[n].Shadow.Density.Foot = argb(255,96,96,64);

	Weathers[n].Lightning.Enable = false;
	Weathers[n].Lightning.Texture = "Weather\lightning\lightning.tga";
	Weathers[n].Lightning.FlickerTime = 32;
	Weathers[n].Lightning.SubTexX = 1;
	Weathers[n].Lightning.SubTexY = 1;

	Weathers[n].Sky.Dir = "weather\skies\8\";
	Weathers[n].Sky.Color = argb(0,255,255,255);
	Weathers[n].Sky.Rotate.Min = -0.001;
	Weathers[n].Sky.Rotate.Max = 0.001;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.0;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 100.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.001;
	Weathers[n].Fog.SeaDensity = 0.001;
	Weathers[n].Fog.Color = argb(0,200,220,255);
	
	Weathers[n].Rain.NumDrops = 0;
	Weathers[n].Rain.Color = argb(0,73,73,73);
	Weathers[n].Rain.DropLength = 2.12;
	Weathers[n].Rain.Height = 30.0;
	Weathers[n].Rain.Radius = 30.0;
	Weathers[n].Rain.Speed = 18.0;
	Weathers[n].Rain.Jitter = 0.4;
	Weathers[n].Rain.WindSpeedJitter = 0.5;
	Weathers[n].Rain.MaxBlend = 49;
	Weathers[n].Rain.TimeBlend = 2000;

	Weathers[n].Rainbow.Enable = false;
	Weathers[n].Rainbow.Texture = "weather\rainbow\rainbow.tga";

	Weathers[n].Sun.Color = argb(0,160,120,98);
	Weathers[n].Sun.Ambient = argb(0,100,90,80);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(3.0);
	Weathers[n].Sun.HeightAngle = 0.36;
	Weathers[n].Sun.Overflow.Enable = false;
	Weathers[n].Sun.Glow.Enable = true;
	Weathers[n].Sun.Glow.Dist = 3500.0;
	Weathers[n].Sun.Glow.Size = 1250.0;
	Weathers[n].Sun.Glow.RotateSpeed = 1.0;
	Weathers[n].Sun.Glow.Texture = "weather\sun\glow\sunglow.tga";
	Weathers[n].Sun.Glow.DecayTime = 8.0;
	Weathers[n].Sun.Glow.TechniqueNoZ = "sunglow_noz";
	Weathers[n].Sun.Glow.TechniqueZ = "sunglow_z";
	Weathers[n].Sun.Glow.Color = argb(0,255,255,255);
	Weathers[n].Sun.Flare.Enable = true;
	Weathers[n].Sun.Flare.Texture = "weather\sun\flare\allflares.tga";
	Weathers[n].Sun.Flare.Dist = 3500.0;
	Weathers[n].Sun.Flare.TexSizeX = 2;
	Weathers[n].Sun.Flare.TexSizeY = 2;
	Weathers[n].Sun.Flare.Technique = "sunflare";
	Weathers[n].Sun.Flare.Scale = 2.0;
	Weathers[n].Sun.Flares.f1 = "1.0,200.0,0,0x0F0F0F";
	Weathers[n].Sun.Flares.f2 = "0.9,20.0,1,0x0F0F0F";
	Weathers[n].Sun.Flares.f3 = "0.8,30.0,2,0x0F0F0F";
	Weathers[n].Sun.Flares.f4 = "0.6,150.0,0,0x0F0F0F";
	Weathers[n].Sun.Flares.f5 = "0.5,50.0,0,0x0F0F0F";
	Weathers[n].Sun.Flares.f6 = "0.4,100.0,1,0x0F0F0F";
	Weathers[n].Sun.Flares.f7 = "0.3,200.0,0,0x0F0F0F";
	Weathers[n].Sun.Flares.f8 = "0.2,200.0,0,0x0F0F0F";

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,30,55,100);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.06;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 23.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.4;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Water.Color = argb(0,30,55,100);
	Weathers[n].Sea.Pena.Color = argb(0,175,175,155);
	Weathers[n].Sea.Bump.Tile = 0.05;
	Weathers[n].Sea.Bump.Ang = 0.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 15.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 0.99	;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,128,55,0);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,255,200,150);
	Weathers[n].Sea.SunRoad.Power = 0.2;
	Weathers[n].Sea.Harmonics.h1 = "0.0,10.0,0.1802,80.87,-78.00";
	Weathers[n].Sea.Harmonics.h2 = "1.87,12.0,0.202,82.28,78.00";
	Weathers[n].Sea.Harmonics.h3 = "0.27,7.0,0.2002,82.28,78.00";

	Weathers[n].Wind.Angle = 2.0;
	Weathers[n].Wind.Speed.Min = 5.0;
	Weathers[n].Wind.Speed.Max = 8.0;

	n++;

	return n;
}