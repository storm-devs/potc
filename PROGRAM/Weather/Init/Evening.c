int Whr_InitEvening(int n)
{
// ====================================================================
// evening, after rain, 17 - 21 hour
	Weathers[n].id = "Evening After Rain";

	Weathers[n].Hour.Min = 17;
	Weathers[n].Hour.Max = 21;
	Weathers[n].Lighting = "evening1";
	Weathers[n].LightingLm = "evening";
	Weathers[n].InsideBack = "e";

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

	Weathers[n].Sky.Dir = "weather\skies\3\";
	Weathers[n].Sky.Color = argb(0,255,255,255);
	Weathers[n].Sky.Rotate = 0.0;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 3.20;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 300.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.003;
	Weathers[n].Fog.SeaDensity = 0.003;
	Weathers[n].Fog.Color = argb(0,95,75,76);
	
	Weathers[n].Rain.NumDrops = 2000;
	Weathers[n].Rain.Color = argb(0,73,73,73);
	Weathers[n].Rain.DropLength = 2.12;
	Weathers[n].Rain.Height = 30.0;
	Weathers[n].Rain.Radius = 20.0;
	Weathers[n].Rain.Speed = 16.0;
	Weathers[n].Rain.Jitter = 0.4;
	Weathers[n].Rain.WindSpeedJitter = 0.5;
	Weathers[n].Rain.MaxBlend = 49;
	Weathers[n].Rain.TimeBlend = 2000;

	Weathers[n].Rainbow.Enable = true;
	Weathers[n].Rainbow.Texture = "weather\rainbow\rainbow.tga";

	Weathers[n].Sun.Color = argb(0,255,188,144);
	Weathers[n].Sun.Ambient = argb(0,66,38,33);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(172.0);
	Weathers[n].Sun.HeightAngle = 0.25;
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
	Weathers[n].Sun.Flares.f7 = "0.3,200.0,0,0x1F1F1F";
	Weathers[n].Sun.Flares.f8 = "0.2,200.0,0,0x0F0F0F";
	Weathers[n].Sun.Overflow.Enable = false;
	Weathers[n].Sun.Overflow.Texture = "Weather\lightning\flash.tga";
	//Weathers[n].Sun.Overflow.Texture = "weather\sun\overflow\overflow.tga";
	Weathers[n].Sun.Overflow.Color = argb(0, 155, 255, 155);
	Weathers[n].Sun.Overflow.Size = 5500.0;
	Weathers[n].Sun.Overflow.Technique = "sunoverflow";
	Weathers[n].Sun.Overflow.Start = 0.8;

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,100,70,65);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,0,0);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.04;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 7.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.4;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.Water.Color = argb(0,30,42,55);
	Weathers[n].Sea.Pena.Color = argb(0,255,150,100);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.04;
	Weathers[n].Sea.Bump.Ang = 1.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 15.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 0.99;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,255,77,55);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,255,180,22);
	Weathers[n].Sea.SunRoad.Power = 4.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,20.0,0.2202,80.87,-128.00";
	Weathers[n].Sea.Harmonics.h2 = "1.57,8.0,0.40002,82.28,68.00";
	Weathers[n].Sea.Harmonics.h3 = "0.77,20.0,0.2002,82.28,128.00";
	Weathers[n].Sea.Harmonics.h4 = "1.27,22.0,0.1402,82.28,128.00";
	//Weathers[n].Sea.Harmonics.h5 = "2.10,42.0,0.1002,82.28,28.00";

	Weathers[n].Wind.Angle = 2.0;
	Weathers[n].Wind.Speed.Min = 10.0;
	Weathers[n].Wind.Speed.Max = 14.0;
	
	n++;

// ====================================================================
// evening, red sky, 19 - 22 hour
	Weathers[n].id = "Red Sky";

	Weathers[n].Hour.Min = 18;
	Weathers[n].Hour.Max = 22;
	Weathers[n].Lighting = "evening2";
	Weathers[n].LightingLm = "evening";
	Weathers[n].InsideBack = "e";

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

	Weathers[n].Sky.Dir = "weather\skies\4\";
	Weathers[n].Sky.Color = argb(0,255,255,255);
	Weathers[n].Sky.Rotate = 0.0;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.0;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 400.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.002;
	Weathers[n].Fog.SeaDensity = 0.002;
	Weathers[n].Fog.Color = argb(0,60,40,40);
	
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

	Weathers[n].Sun.Color = argb(0,255,141,55);
	Weathers[n].Sun.Ambient = argb(0,66,33,33);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(180.0);
	Weathers[n].Sun.HeightAngle = 0.20;
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
	Weathers[n].Sun.Overflow.Enable = false;
	Weathers[n].Sun.Overflow.Texture = "Weather\lightning\flash.tga";
	//Weathers[n].Sun.Overflow.Texture = "weather\sun\overflow\overflow.tga";
	Weathers[n].Sun.Overflow.Color = argb(0, 255, 255, 255);
	Weathers[n].Sun.Overflow.Size = 5500.0;
	Weathers[n].Sun.Overflow.Technique = "sunoverflow";
	Weathers[n].Sun.Overflow.Start = 0.84;

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,70,40,30);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,0,0);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.04;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 7.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.4;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
	Weathers[n].Sea.Water.Color = argb(0,30,42,55);
	Weathers[n].Sea.Pena.Color = argb(0,255,100,70);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.04;
	Weathers[n].Sea.Bump.Ang = 1.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 20.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 0.993;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,200,44,44);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,255,128,55);
	Weathers[n].Sea.SunRoad.Power = 2.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,20.0,0.3202,80.87,-128.00";
	Weathers[n].Sea.Harmonics.h2 = "1.57,8.0,0.30002,82.28,68.00";
	Weathers[n].Sea.Harmonics.h3 = "0.77,20.0,0.2002,82.28,128.00";
	Weathers[n].Sea.Harmonics.h4 = "1.27,22.0,0.3402,82.28,128.00";

	Weathers[n].Wind.Angle = 2.0;
	Weathers[n].Wind.Speed.Min = 7.0;
	Weathers[n].Wind.Speed.Max = 9.0;
	
	n++;

// ====================================================================
// evening, crimson sky, 17 - 21 hour
	Weathers[n].id = "Crimson Sky";

	Weathers[n].Hour.Min = 17;
	Weathers[n].Hour.Max = 21;
	Weathers[n].Lighting = "evening3";
	Weathers[n].LightingLm = "evening";
	Weathers[n].InsideBack = "e";

	Weathers[n].Lights = false;
	Weathers[n].Night = false;

	Weathers[n].Storm = false;
	Weathers[n].Tornado = false;
	Weathers[n].Shark = true;

	Weathers[n].Shadow.Density.Head = argb(255,96,96,96);
	Weathers[n].Shadow.Density.Foot = argb(255,96,96,64);

	Weathers[n].Lightning.Enable = false;
	Weathers[n].Lightning.Texture = "Weather\lightning\lightning.tga";
	Weathers[n].Lightning.FlickerTime = 32;
	Weathers[n].Lightning.SubTexX = 1;
	Weathers[n].Lightning.SubTexY = 1;

	Weathers[n].Sky.Dir = "weather\skies\2\";
	Weathers[n].Sky.Color = argb(0,255,200,210);
	Weathers[n].Sky.Rotate = 0.0;
	Weathers[n].Sky.Size = 1000.0;
	Weathers[n].Sky.Angle = 0.0;
	
	Weathers[n].Fog.Enable = true;
	Weathers[n].Fog.Height = 200.0;
	Weathers[n].Fog.Start = 0.0;
	Weathers[n].Fog.Density = 0.002;
	Weathers[n].Fog.SeaDensity = 0.002;
	Weathers[n].Fog.Color = argb(0,60,30,40);
	
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

	Weathers[n].Sun.Color = argb(0,255,141,55);
	Weathers[n].Sun.Ambient = argb(0,70,50,65);
	Weathers[n].Sun.AzimuthAngle = Degree2Radian(172.0);
	Weathers[n].Sun.HeightAngle = 0.24;
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

	Weathers[n].Sea.GF2MX.Sky.Color = argb(0,110,80,90);
	Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,0,0);
	Weathers[n].Sea.GF2MX.Bump.Tile = 0.04;
	Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 7.0;
	Weathers[n].Sea.GF2MX.Bump.Dir = "weather\sea\bump_g2mx\";

	Weathers[n].Sea.Transparency = 0.4;
	Weathers[n].Sea.FrenelCoefficient = 0.7;
	Weathers[n].Sea.WaterReflection = 0.7;
	Weathers[n].Sea.WaterAttenuation = 0.8;
	Weathers[n].Sea.Sky.Color = argb(0,255,200,210);
	Weathers[n].Sea.Water.Color = argb(0,30,42,55);
	Weathers[n].Sea.Pena.Color = argb(0,255,150,100);
	Weathers[n].Sea.Bump.Dir = "resource\textures\weather\sea\bump_g3\";
	Weathers[n].Sea.Bump.Tile = 0.04;
	Weathers[n].Sea.Bump.Ang = 1.0;
	Weathers[n].Sea.Bump.Speed = 0.01;
	Weathers[n].Sea.Bump.AnimSpeed = 20.0;
	Weathers[n].Sea.Bump.Scale = 2.0;
	Weathers[n].Sea.SunRoad.Start = 0.99;
	Weathers[n].Sea.SunRoad.Color1 = argb(0,255,88,44);
	Weathers[n].Sea.SunRoad.Color2 = argb(0,255,200,55);
	Weathers[n].Sea.SunRoad.Power = 3.0;
	Weathers[n].Sea.Harmonics.h1 = "0.0,10.0,0.4202,80.87,-48.00";
	Weathers[n].Sea.Harmonics.h2 = "1.57,12.0,0.4002,82.28,48.00";
	Weathers[n].Sea.Harmonics.h3 = "0.27,7.0,0.4002,82.28,48.00";

	Weathers[n].Wind.Angle = 2.0;
	Weathers[n].Wind.Speed.Min = 7.0;
	Weathers[n].Wind.Speed.Max = 9.0;
	
	n++;

	return n;
}