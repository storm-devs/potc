string s[5] = 
{
	"1",
	"2",
	"3",
	"4",
	"5",
};
ref r;
void main()
{
	r = &s;
	trace(r[1]);
}

