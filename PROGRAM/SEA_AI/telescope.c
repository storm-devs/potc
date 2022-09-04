void Telescope_Request()
{
	if (SeaCameras.Camera == "SeaDeckCamera")
		SendMessage(&Telescope, "l", MSG_TELESCOPE_REQUEST);
}