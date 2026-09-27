#include <bits/stdc++.h>
using namespace std;

string abc;

string transform(string s)
{
    bool upper = false;
    string res = "";
    for (auto c : s)
    {
        upper = false;
        if ((char)c < 91)
        {
            c += 32;
            upper = true;
        }

        if (upper)
            res += (char)(abc.find(c) + 97);
        else
            res += (char)(abc.find(c) + 65);
    }
    return res;
}

int main(int argc, char **argv)
{
    string a;
    int n;
    cin >> abc >> n;

    vector<string> words;
    words.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        words.push_back(a);
    }

    sort(words.begin(), words.end(), [](string &l, string &r)
         { 
             return transform(l)<transform(r); }); 
             
    for (auto i = words.begin(); i != words.end(); i++)
        cout << *i << endl;

    return 0;
}
