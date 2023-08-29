//1919: 애너그램 만들기
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    uint cntWord1[26] = {
        0,
    };
    uint cntWord2[26] = {
        0,
    };
    char word[1001];
    cin >> word; //only lowercase
    for (char *pChar = word; *pChar != '\0'; ++pChar)
        ++cntWord1[*pChar - 'a'];
    cin >> word; //only lowercase
    for (char *pChar = word; *pChar != '\0'; ++pChar)
        ++cntWord2[*pChar - 'a'];
    uint cntRemovedLetter = 0;
    for (size_t i = 0; i < 26; i++)
        cntRemovedLetter += (cntWord1[i] > cntWord2[i] ? cntWord1[i] - cntWord2[i] : cntWord2[i] - cntWord1[i]);
    cout << cntRemovedLetter;
    return 0;
}