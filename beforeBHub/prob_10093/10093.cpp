//10093:숫자
// for subtask
// score:30, maybe time limit
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    constexpr int diffMaxLen = 10;
    string numStr[2], numBitween;
    int num[2];
    // int numStrLen[2];
    for (size_t i = 0; i < 2; i++)
    {
        // cin >> ws;
        cin >> numStr[i];
        if (numStr[i].length() > diffMaxLen)
        {
            num[i] = stoi(numStr[i].substr(numStr[i].length() - diffMaxLen));
        }
        else
        {
            num[i] = stoi(numStr[i]);
        }
    }
    size_t count;
    if (num[0] > num[1])
    {
        count = num[0] - num[1] - 1;
        numBitween = numStr[1];
    }
    else if (num[1] > num[0])
    {
        count = num[1] - num[0] - 1;
        numBitween = numStr[0];
    }
    else
        count = 0;
    cout << count << '\n';
    for (size_t i = 0; i < count; i++)
    {
        string::reverse_iterator numStrRIter = numBitween.rbegin();
        for (; numStrRIter != numBitween.rend() && *numStrRIter == '9'; *numStrRIter = '0', ++numStrRIter)
            ;
        if (numStrRIter == numBitween.rend())
            numBitween.insert(numBitween.cbegin(), '1');
        else
            ++*numStrRIter;
        cout << numBitween << ' ';
    }

    return 0;
}