#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int main()
{
    string text;
    string pattern;
    cout << "Enter the Text : " << endl;
    cin >> text;
    cout << "Enter the Pattern : " << endl;
    cin >> pattern;
    int n = text.length();
    int m = pattern.length();
    // shift table
    map<char, int> shift = {};
    for (char c = 'a'; c <= 'z'; c++)
    {
        shift[c] = m;
    }
    shift[' '] = m;
    for (int i = 0; i <= (m - 2); i++)
    {
        shift[pattern[i]] = m - i - 1;
    }
    int j = 0;
    while (j + m <= n)
    {
        if (pattern[m - 1] == text[j + m - 1])
        {
            int i = m - 2;
            while (i >= 0 && pattern[i] == text[j + i])
            {
                i = i - 1;
            }
            if (i == -1)
            {
                cout << "String matched at index " << j << endl;
            }
        }
        j = j + shift[text[j + m - 1]];
    }
    return 0;
}
