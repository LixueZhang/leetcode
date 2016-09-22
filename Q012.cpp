#include <iostream>
#include <string>
using namespace::std;

string translate(int num, string one, string five, string ten)
{
	string res;
	switch(num)
	{
		case 1 : res += one;break;
		case 2 : res += (one + one);break;
		case 3 : res += (one + one + one);break;
		case 4 : res += (one + five);break;
		case 5 : res += five;break;
		case 6 : res += (five + one);break;
		case 7 : res += (five + one + one);break;
		case 8 : res += (five + one + one + one);break;
		case 9 : res += (one + ten);break;
		default : break;
	}
	return res;
}

string intToRoman(int num)
{
	string res;
	int count = 0;
	int i=0;
	if(num/1000 > 0)
	{
		count = num/1000;
		num = num%1000;
		for(i=0;i<count;++i)
		{
			res += "M";
		}
	}

	if(num/100 > 0)
	{
		count = num/100;
		res += translate(count, "C", "D", "M");
		num = num%100;
	}

	if(num/10 > 0)
	{
		count = num/10;
		res += translate(count, "X", "L", "C");
		num = num%10;
	}

	if(num > 0)
	{
		res += translate(num, "I", "V", "X");
	}
	return res;
}


int main()
{
	cout<<intToRoman(1)<<endl;
	return 0;
}




