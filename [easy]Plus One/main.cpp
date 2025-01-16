#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        std::vector<int> result = {};
        int startValue = digits[digits.size() - 1] + 1;
        for (int i = 0; digits.size() - i > 0; i++)
        {
            result.insert(result.begin(), startValue % (10));
            if (digits.size() - i == 1)
            {
                startValue = startValue / 10;
                break;
            }
            startValue = digits[digits.size() - 2 - i] + (startValue / 10);
        }
        if (startValue > 0)
        {
            result.insert(result.begin(), startValue);
        }
        return result;
    }
};

int main()
{
    Solution f = Solution();
    std::vector<int> data = {9, 9, 9};
    std::vector<int> dataResult = f.plusOne(data);
    for (int t : dataResult)
    {
        std::cout << t << " ";
    }
    return 0;
}