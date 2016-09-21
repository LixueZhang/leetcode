#include <string>
#include <iostream>
using namespace::std;

string longestPalindrome(string s)
{
	//step 1 : adjustment of string s.
	string temp = "#";
	int i = 0;
	while(i<s.size())
	{
		temp += s[i++];
		temp += '#';
	}
	cout<<"string s is "<<temp<<endl;
	//step 2&3 : generate arrary P.
	int *p = new int[temp.size()];
	int leftPtr = 0;
	int rightPtr = 0;
	int loc = 0;
	int max = 0;
	for(i=0;i<temp.size();++i)
	{
		int pval = 0;
		if(i%2==0)
		{
			leftPtr = i-1;
			rightPtr = i+1;
		}
		else
		{
			leftPtr = i-2;
			rightPtr = i+2;
			pval = 1;
		}
		while(leftPtr>=0 && rightPtr<temp.size())
		{
			if(temp[leftPtr]==temp[rightPtr])
				pval += 2;
			else
				break;
			leftPtr -= 2;
			rightPtr += 2;
		}
		p[i] = pval;
		if(p[i]>max)
		{
			max = p[i];
			loc = i;		
		}
	}
	//step 3 : find the largest value.
	//step 4 : return the result.
	int first = loc - max + 1;
	string res;
	for(i=0;i<max;++i)
	{
		res += temp[first];
		first += 2;
	}
	delete []p;
	p = NULL;
	return res;
}

int main(int argc, char *argv[])
{
	cout<<"the result is "<<longestPalindrome("")<<endl;
	return 0;
}

