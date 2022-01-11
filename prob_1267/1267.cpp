//1267: 핸드폰 요금
//pass
#include <iostream>

using namespace std;

int main(void)
{
    size_t countCall;
    int callLen;
    int yeongsik = 0;
    int minsik = 0;
    cin >> countCall;
    for (size_t i = 0; i < countCall; i++)
    {
        cin >> callLen;
        // yeongsik
        //30sec 10won
        yeongsik += (1 + callLen / 30) * 10;
        // minsik
        //60sec 15won
        minsik += (1 + callLen / 60) * 15;
    }
    if (yeongsik < minsik)
        cout << "Y " << yeongsik;
    else if (minsik < yeongsik)
        cout << "M " << minsik;
    else
        cout << "Y M " << yeongsik;
    return 0;
}