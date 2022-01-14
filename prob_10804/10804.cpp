//10804: 카드 역배치
#include <iostream>
#include <utility>

using namespace std;
class Card
{
    constexpr static size_t CNT = 20;         //the number of cards
    static constexpr size_t CNT_REVERSE = 10; //the count of reverse arrangement
    inline static int card[1 + CNT];          //order:index,number on card:value
    static inline void reverseArrange(const size_t begin, const size_t end)
    {
        for (size_t idx1 = begin, idx2 = end; idx1 < idx2; ++idx1, --idx2)
            swap(card[idx1], card[idx2]);
    }

public:
    static void init(void)
    {
        for (size_t i = 1; i <= CNT; i++)
            card[i] = i;
    }
    static void reverseArrange(void)
    {
        for (size_t i = 0; i < CNT_REVERSE; i++)
        {
            size_t begin, end;
            cin >> begin >> end;
            reverseArrange(begin, end);
        }
    }
    static void print(void)
    {
        for (size_t i = 1; i <= CNT; i++)
            cout << card[i] << ' ';
    }
};
int main(void)
{
    Card::init();
    Card::reverseArrange();
    Card::print();
    return 0;
}