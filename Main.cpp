#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows > 1)
    {
        int LEN = s.length();
        string pattern;
        if (LEN > 0)
        {
            vector<string> pattern_store(numRows);
            int i = -1;
            int j = 0;
            while (j < LEN)
            {
                while (i < numRows - 1 && j < LEN)
                {
                    pattern_store[++i].push_back(s[j++]);
                }
                while (i > 0 && j < LEN)
                {
                    pattern_store[--i].push_back(s[j++]);
                }
            }

            for (auto s : pattern_store)
            {
                pattern.append(s);
            }
        }
        return pattern;
    }
    return s;
    
}

int main(int argc, char** argv)
{
    if (argc >= 3)
    {
        string  s(argv[1]);
        int numRows = atoi(argv[2]);
        string ret = convert(s, numRows);
        cout << "Zigzag String is :" << ret;
    }
    return 0;
}