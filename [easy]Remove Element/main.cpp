#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int vResult = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= nums.size() - vResult)
            {
                break;
            }
            if (nums[i] == val)
            {
                if (i == nums.size() - vResult - 1)
                {
                    vResult++;
                    continue;
                }
                for (int k = nums.size() - vResult - 1; k > i; k--)
                {
                    if (k == i + 1 && nums[k] == val)
                    {
                        vResult++;
                        i--;
                        break;
                    }
                    if (nums[i] != nums[k])
                    {
                        swap(nums[i], nums[k]);
                        vResult++;
                        break;
                    }
                }
            }
        }
        return nums.size() - vResult;
    }
};

int main()
{
    vector<int> data = {3, 3};
    int y = 0;
    vector<int> t = {5, 4};
    Solution tool = Solution();
    int result = tool.removeElement(data, 3);
    cout << "[ ";
    for (int &j : data)
    {
        cout << j << ", ";
    }
    cout << " ]" << endl;
    cout << result << endl;
    cout << 3 / 2 << endl;
}