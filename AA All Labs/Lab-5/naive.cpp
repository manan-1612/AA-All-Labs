#include <bits/stdc++.h>
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
    int s = 0;
    for (; s <= n - m; s++)
    {
        int i = 0, j = 0;
        while (j < m && text[s + i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern matched at index " << s << endl;
        }
    }
    if(s == 0){
        cout << "Pattern not matched" << endl;
    }
    return 0;
}