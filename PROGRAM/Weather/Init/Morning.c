int Whr_InitMorning(int n)
{
// ====================================================================
// morning 5 - 10 hour

	Weathers[n].id = "Morning";
	Weathers[n].Hour.Min = 5;
	Weathers[n].Hour.Max = 10;
	Weathers[n].Lighting = "morning1";
	Weathers[n].LightingLm = "mn";
	Weathers[n].InsideBack = "m";

	Weathers[n].Storm = false;
	Weathers[n].Tornado = false;
	Weathers[n].Shark = true;
	Weathers[n].Lights = false;
	Weathers[n].Night = false;

	Weathers[n].Shadow.Density.Head = argb(255,96,96,96);
	Weathers[n].Shadow.Density.Foot = argb(255,96,96,64);

	Weathers[n].Lightning.Enable = false;

	Weathers[n].Sky.Dir = "weather\skies\5\";
	Weathers[n].Sky.Color = argb(0,255,255,255);
	Weathers[n].Sky.Rotate = 0.00;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.0;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 2000.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.02;
	Weathers[n].Fog.SeaDensity = 0.014;
	Weathers[n].Fog.Color = argb(0,225,222,222);
	
	Weathers[n].SpecialSeaFog.Enable = true;
	Weathers[n].SpecialSeaFog.Height = 1000.0;
	Weathers[n].SpecialSeaFog.Start = 0.0;
	Weathers[n].SpecialSeaFog.Density = 0.0025;
	Weathers[n].SpecialSeaFog.SeaDensity = 0.004;
	Weathers[n].SpecialSeaFog.Color = argb(0,225,222,222);

	Weathers[n].Rain.NumDrops = 0;

	Weathers[n].Rainbow.Enable = false;

	Weathers[n].Sun.Color = argb(0,255,208,200);
	Weathers[n].Sun.Ambient = argb(0,55,44,44);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(350);
	Weathers[n].Sun.HeightAngle = 0.21;
	Weathers[n].Sun.Glow.Enable = true;
	Weathers[n].Sun.Glow.Dist = 3500.0;
	Weathers[n].Sun.Glow.Size = 1250.0;
	Weathers[n].Sun.Glow.RotateSpeed = 1.0;
	Weathers[n].Sun.Glow.Texture = "weather\sun\glow\sunglow.tga";
	Weathers[n].Sun.Glow.DecayTime = 8.0;
	Weathers[n].Sun.Glow.TechniqueNoZ = "sunglow_noz";
	Weathers[n].Sun.Glow.TechniqueZ = "sunglow_z";
	Weathers[n].Sun.Glow.Color = argb(0,255,255,255);
	Weathers[n].Sun.Overflow.Enable = false;
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

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,255,230,220);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,15,12,10);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.06;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 7.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.2;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.Water.Color = argb(0,30,42,55);
	Weathers[n].Sea.Pena.Color = argb(0,55,55,55);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.06;
	Weathers[n].Sea.Bump.Ang = 0.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 23.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 0.97;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,255,55,44);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,255,100,0);
	Weathers[n].Sea.SunRoad.Power = 3.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,40.0,0.0802,80.87,-48.00";
	Weathers[n].Sea.Harmonics.h2 = "0.57,22.0,0.0402,82.28,48.00";
	Weathers[n].Sea.Harmonics.h3 = "1.57,27.0,0.0902,82.28,48.00";
	Weathers[n].Sea.Harmonics.h4 = "1.0,17.0,0.0402,82.28,48.00";
	Weathers[n].Sea.Harmonics.h5 = "3.27,7.0,0.0402,82.28,48.00";

	Weathers[n].Wind.Angle = 2.0;
	Weathers[n].Wind.Speed.Min = 5.0;
	Weathers[n].Wind.Speed.Max = 8.0;
	
	n++;

	return n;
}