//2490: 윷놀이
//not submitted
#include <iostream>

using namespace std;
int main(void)
{
    constexpr int BACK = 1;
    // constexpr int FRONT = 0;
    constexpr size_t CNT_YOOT = 4;
    constexpr size_t CNT_CASE = 3;
    typedef enum _YootState
    {
        Do = 3,
        Gae = 2,
        Gur = 1,
        Yoot = 0,
        Mo = 4
    } YootState; //value = the number of BACK
    int yoot;

    for (size_t j = 0; j < CNT_CASE; j++)
    {
        int cntBack = 0;
        for (size_t i = 0; i < CNT_YOOT; i++)
        {
            cin >> yoot;
            if (yoot == BACK)
                ++cntBack;
        }
        char c;
        switch (YootState(cntBack))
        {
        case Do:
            c = 'A';
            break;
        case Gae:
            c = 'B';
            break;
        case Gur:
            c = 'C';
            break;
        case Yoot:
            c = 'D';
            break;
        case Mo:
            c = 'E';
            break;
        default:
            break;
        }
        cout << c << '\n';
    }
    return 0;
}