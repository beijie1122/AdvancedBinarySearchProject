#include <iostream>
#include <vector>

int GetFirstPosition(std::vector<int>& nums, int target)
{
	int s = 0;
	int e = nums.size() - 1;
	int ans = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;

		if (nums[mid] == target)
		{
			ans = mid;
			e = mid - 1;
			//return mid; // Original Binary Search 
		}
		else if (nums[mid] < target)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	return ans;
}

int GetLastPosition(std::vector<int>& nums, int target)
{
	int s = 0;
	int e = nums.size() - 1;
	int ans = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;

		if (nums[mid] == target)
		{
			ans = mid;
			s = mid + 1;
			//return mid; // Original Binary Search 
		}
		else if (nums[mid] < target)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	return ans;
}


int main()
{

	std::vector<int> nums{ 5, 7, 7, 8, 8, 10 };

	int TargetNum = 8;

	int First = GetFirstPosition(nums, TargetNum);
	int Last = GetLastPosition(nums, TargetNum);

	std::cout << First << " " << Last << "\n";

	return 0;
}