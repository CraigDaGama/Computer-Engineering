#include <iostream>
#include <string>
using namespace std;

int longestCommonSubsequece(string str1, string str2, int len1, int len2)
{
    int i, j, LCS[len1 + 1][len2 + 1];
    int start = 0; // index of the first character in the longest common substring

    // create a matrix LCS of order (len1+1)*(len2+1) to tabulate values
    // initializing
    for (i = 0; i <= len1; i++)
        LCS[i][0] = 0; // empty str2
    for (j = 0; j <= len2; j++)
        LCS[0][j] = 0; // empty str1

    // now, start filling the matrix row wise
    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            // if current character of both strings match
            if (str1[i - 1] == str2[j - 1])
            {
                if (i == 1 || j == 1)
                    start = i - 1;
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            // mismatch
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    // construct the longest common substring
    string str = "";
    for (i = len1; i > 0 && LCS[i][len2] > 0; i--)
    {
        if (LCS[i][len2] == LCS[i - 1][len2])
            continue;
        str = str1[i - 1] + str;
    }

    // return the final value in LCS[len1][len2];
    cout << "Size of longest common subsequece is: " << LCS[len1][len2] << endl;
    cout << "Longest common subsequece is: " << str << endl;

    return LCS[len1][len2];
}

int main()
{
    int n, m, p, len1, len2;
    string string1, string2;

    cout << "Enter 1st string :";
    getline(cin, string1);
    cout << "Enter 2nd string :";
    getline(cin, string2);

    len1 = string1.length();
    len2 = string2.length();

    longestCommonSubsequece(string1, string2, len1, len2);

    return 0;
}
