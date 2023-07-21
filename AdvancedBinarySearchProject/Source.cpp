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

int GetIndex(std::vector<int>& nums, int target, bool GetFirst)
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
			if (GetFirst == true)
			{
				e = mid - 1;
			}
			else
			{
				s = mid + 1;
			}
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

int BinarySearchForRotatedSortedArray(std::vector<int>& a, int key)
{
	int s = 0;
	int e = a.size() - 1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (a[mid] == key)
		{
			return mid;
		}

		if (a[s] <= a[mid])
		{
			if (key >= a[s] && key <= mid)
			{
				e = mid - 1;
			}
			else
			{
				s = mid + 1;
			}
		}
		else
		{
			if (key >= a[mid] && key <= a[e])
			{
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
		}
		return -1;


	}
}

int MajorityElementMooreAlgo(std::vector<int>& A)
{
	int cand = A[0];
	int count = 1;

	int n = A.size();
	for (int i = 1; i < n; i++)
	{
		if (A[i] == cand)
		{
			count++;
		}
		else
		{
			count--;
			if (count == 0)
			{
				cand = A[i];
				count = 1;
			}
		}
		// we cannot always assume majority element is there
		int count2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == cand)
			{
				count2++;
			}
		}
		if (count2 > n / 2)
		{
			return cand;
		}
		else
		{
			return -1;
		}
	}
}

int main()
{

	std::vector<int> nums{ 5, 7, 7, 8, 8, 10 };

	int TargetNum = 8;

	int First = GetIndex(nums, TargetNum, true);
	int Last = GetIndex(nums, TargetNum, false);

	std::cout << First << " " << Last << "\n";

	int Testing = First * (First > Last) + Last * (First < Last);

	std::cout << Testing << "\n";

	return 0;
}