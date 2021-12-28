#include <stdio.h>
enum
{
    M = 1234567891,
    a = 31, //coefficient
    MAX_L = 50
};
int main(void)
{
    int L;               //the length of string
    long long int H = 0; //hash
    char str[MAX_L];     //string from input
    //H= (r[0] +a*r[1] +a*a*r[2] +...) mod M
    //(a + b) mod M = ((a mod M) + (b mod M)) mod M
    //(a * a) mod M = (a * (a mod M)) mod M
    scanf("%d%s", &L, str);
    for (int i = L - 1; i >= 0; --i)
    {
        int r = str[i] - ('a' - 1); // alphabet to number
        H = (a * H + r) % M;
    }
    printf("%lld", H);

    return 0;
}