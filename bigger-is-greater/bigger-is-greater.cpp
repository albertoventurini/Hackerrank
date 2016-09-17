#include <iostream>

using namespace std;

void sort(string& s, int i)
{
    // Insertion sort
    for(int j = i + 1; j < s.length(); j++)
    {
        char c = s[j];
        int k = j - 1;
        while(k >= i && s[k] > c)
        {
            s[k+1] = s[k];
            k--;
        }
        s[k+1] = c;
    }
}

string next_perm(string s)
{
    if(s.empty() || s.length() == 1) return "no answer";
    int i = s.length() - 2;
    while(i >= 0 && s[i] >= s[i+1]) i--;
    if(i < 0) return "no answer";
    int j = s.length() - 1;
    while(j != i)
    {
        if(s[j] > s[i]) break;
        j--;
    }
    //if(i == j) return "no answer";
    char c = s[i]; s[i] = s[j]; s[j] = c;
    sort(s, i + 1);
    return s;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << next_perm(s) << endl;
    }
    //cout << next_perm("zyyxwwtrrnmlggfeb") << endl;
}