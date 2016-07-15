#include"Configer.h"

/*两个数组中元素的交集*/
vector<int> Intersection(vector<int>& Vector1, vector<int>& Vector2)
{
	sort(Vector1.begin(), Vector1.end());
	sort(Vector2.begin(), Vector2.end());
	int index1 = 0, index2 = 0;
	vector<int> Vector;
	while (index1 < Vector1.size() && index2 < Vector2.size())
	{
		if (Vector1[index1] == Vector2[index2])
		{
			if (Vector.size() ==0 || Vector[Vector.size() - 1] == Vector1[index1])
			Vector.push_back(Vector1[index1]);
			++index1;
			++index2;
		}
		else
			Vector1[index1] < Vector2[index2] ? ++index1 : ++index2;
	}
	return Vector;
}

/*两个数组中元素的交集（元素大小，个数均一致）*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int index1 = 0, index2 = 0;
		vector<int> Vector;
		while (index1 < nums1.size() && index2 < nums2.size())
		{
			if (nums1[index1] == nums2[index2])
			{
				int key = nums1[index1];
				while (index1 < nums1.size() && index2 < nums2.size() && nums1[++index1] == nums2[++index2])
				{}
				if (index1 == nums1.size())
				{
					if (index2 == nums2.size() || nums2[index2] != key)
						Vector.push_back(key);
				}
				else if (index2 == nums2.size())
				{
					if (nums1[index1] != key)
						Vector.push_back(key);
				}
				else if (key != nums1[index1] && key != nums2[index2])
				{
					Vector.push_back(key);
				}
			}
			else
				nums1[index1] > nums2[index2] ? ++index2 : ++index1;
		}
	}
};

