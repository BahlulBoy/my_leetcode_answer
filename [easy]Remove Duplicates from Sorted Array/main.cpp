#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int anchor, itemErased;
        anchor = 0;
        itemErased = 0;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[anchor] == nums[i]) {
                ++itemErased;
                if (i == nums.size() - 1) {
                    if (itemErased > 0) {
                        nums.erase(nums.begin() + anchor, nums.begin() + i);
                        itemErased = 0;
                    }
                }
            }
            if (nums[anchor] != nums[i]) {
                if (itemErased > 0) {
                    nums.erase(nums.begin() + anchor + 1, nums.begin() + i);
                    itemErased = 0;
                    i = 0;
                }
                anchor = i;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> tramp = {0};
    Solution solution = Solution();
    int result = solution.removeDuplicates(tramp);
    cout << "[ " << result << " ]" << endl;
    cout << "[ " ;
    for (int num : tramp)
    {
        cout << num << " ";
    } 
    cout << "]" ;
    cout << endl;
    return 0;
}

