#include <iostream>
#include <vector>
using namespace::std;

int maxArea(vector<int>& height)
{
	int left = 0;
	int right = height.size()-1;
	if(right < 1)
		return 0;
	int res = 0;
	while(left < right)
	{
		int h = height[left]<height[right]?height[left]:height[right];
        int w = right - left;
        int area = h*w;
		if(area>res)
			res = area;
		if(height[left]>height[right])
			--right;
		else
			++left;
	}
	return res;
}
