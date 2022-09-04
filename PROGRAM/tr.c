string sTest[2];

void Main()
{
	ref rTest = &sTest;

	rTest[0] = "AAAA";
	rTest[1] = "BBBB";

	string s1 = rTest[0];
	Trace(s1);
	setarraysize(rTest,10);
	//Trace(rTest[1]);
}