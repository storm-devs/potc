object Particles;

void InitParticles()
{
	Particles.windpower = 1.0;
	Particles.winddirection.x = frnd();
	Particles.winddirection.z = frnd();
	if (!CreateParticleEntity())
	{
		Trace("Can't create 'particles' class");
	}
}

void PauseParticles(bool bPause)
{
	if (!CreateParticleEntity()) return;
	SendMessage(&Particles, "ll", PS_PAUSEALL, bPause);
}

void DeleteParticles()
{
	SendMessage(&Particles,"l", PS_CLEARALL);
	Particles.winddirection.x = frnd();
	Particles.winddirection.z = frnd();
}

void DeleteParticleSystem(int id)
{
	SendMessage(&Particles,"ll",PS_DELETE,id);
}


int CreateParticleSystem(string name,float x,float y,float z,
		float ax,float ay,float az,int lifetime)
{
	int pid;
	if (!CreateParticleEntity()) return 0;
	pid = SendMessage(&Particles,"lsffffffl",PS_CREATE,name,x,y,z,ax,ay,az,lifetime);
	return pid;
}

bool CreateParticleEntity()
{
	if(IsEntity(Particles) == false)
	{
		if (CreateEntity(&Particles,"particles") == false) return false;
		Trace("bool CreateParticleEntity()");
		LayerAddObject("realize",Particles,65536);
		LayerAddObject("execute",Particles,0);
		LayerAddObject(SEA_REALIZE,Particles,65536);
		LayerAddObject(SEA_EXECUTE,Particles,0);
	}
	return true;
}

int CreateParticleSystemX(string name,float x,float y,float z,
		float ax,float ay,float az,int lifetime)
{
	int pid;
	if (!CreateParticleEntity()) return false;
	pid = SendMessage(&Particles,"lsffffffl",PS_CREATEX,name,x,y,z,ax,ay,az,lifetime);
	return pid;
}

int CreateBlast(float x,float y,float z)
{
	int iRes;
	object blast;
	iRes = CreateEntity(&blast,"blast");
	SendMessage(&blast,"lfff",LM_SETPOINT,x,y,z);
	LayerAddObject("realize",blast,3);
	LayerAddObject(SEA_REALIZE,blast,3);
	return iRes;
}

int CreateBlastX(float x,float y,float z,float ax,float ay,float az)
{
	int iRes;
	object blast;
	iRes = CreateEntity(&blast,"blast");
	SendMessage(&blast,"lffffff",LM_SETPOINTANDANGLES,x,y,z,ax,ay,az);
	LayerAddObject("realize",blast,3);
	LayerAddObject(SEA_REALIZE,blast,3);
	return iRes;
}
