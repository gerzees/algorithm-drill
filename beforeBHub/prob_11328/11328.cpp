//11328: strfry
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int cntCase;
    cin >> cntCase;
    for (size_t i = 0; i < cntCase; i++)
    {
        char str[1001];
        int cnt[26] = {
            0,
        };
        cin >> str; //only lowercase
        for (char *pChar = str; *pChar != '\0'; ++pChar)
            ++cnt[*pChar - 'a'];
        cin >> str;
        for (char *pChar = str; *pChar != '\0'; ++pChar)
            --cnt[*pChar - 'a'];
        size_t letter;
        for (letter = 0; letter < 26 && cnt[letter] == 0; letter++)
            ;
        if (letter == 26)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}