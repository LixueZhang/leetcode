#include <string>
#include <iostream>
#include <vector>
using namespace::std;

int lengthOfLongestSubstring(string s)
{
	int max = 0;
	vector<int> repeatRef(256, -1);
	int length = 0;
	int startPoint = -1;
	for(int i=0;i<s.size();++i)
	{
		int loc = (int)s[i];
		if(repeatRef[loc] > startPoint)
			startPoint = repeatRef[loc];
		if(i-startPoint > max)
			max = i - startPoint;
		repeatRef[loc] = i;
	}
	return max;
}

int main(int argc, char *argv[])
{
	string s("abcabcdebb");
	cout<<"length is "<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}


