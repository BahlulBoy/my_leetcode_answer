#include <string>
#include <iostream>

using namespace std;

int translateRomanChar(char s)
{
    switch (s)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}

int romanToInt(string s)
{
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i != s.size() - 1)
        {
            {
                int a, b; // a for current index, b for next current index
                a = translateRomanChar(s.at(i));
                b = translateRomanChar(s.at(i + 1));
                if (b > a)
                {
                    result -= a;
                }
                else
                {
                    result += a;
                }
            }
        }
        else
        {
            result = result + translateRomanChar(s.at(i));
        }
        cout << result << endl;
    }
    return result;
}

int main()
{
    string haha = "XII";
    int result = romanToInt(haha);
    cout << result;
}
