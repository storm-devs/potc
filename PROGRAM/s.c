object test;
void main()
{
	test.l = "Hello";
	DumpAttributes(&test);
	trace("------------------------------------");

	SaveEngineState("test");
	DumpAttributes(&test);

	trace("------------------------------------");

	LoadEngineState("test");
	DumpAttributes(&test);

	ExitProgram();
}