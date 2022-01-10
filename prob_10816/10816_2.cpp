//10816: 숫자 카드 2
// pass
// 복잡하게 할 필요없이 제한 메모리 내에서 배열 크게 써서 쉽고 빠르게 할 수 있다!
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N; //the number of cards
    int M; //the length of check list
    int cards[500000];
    pair<int, int> question[500000]; //first:the number question ask, second:input order
    int answer[500000] = {
        0,
    };
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> question[i].first;
        question[i].second = i;
    }
    sort(cards, cards + N, less<int>());
    struct questionLess
    {
        bool operator()(pair<int, int> &card1, pair<int, int> &card2)
        {
            return card1.first < card2.first;
        }
    } questionLess;
    sort(question, question + M, questionLess);
    int idxQ, idxC;
    for (idxQ = 0, idxC = 0; idxC < N && idxQ < M;)
    {
        if (question[idxQ].first == cards[idxC])
        {
            ++answer[question[idxQ].second];
            ++idxC;
        }
        else if (question[idxQ].first < cards[idxC])
        {
            if (idxQ > 0)
                if (question[idxQ - 1].first == question[idxQ].first)
                    answer[question[idxQ].second] = answer[question[idxQ - 1].second];
            ++idxQ;
        }
        else //question[idxQ].first > cards[idxC]
        {
            ++idxC;
        }
    }
    //in case idxC<N, question is left
    for (++idxQ; idxQ < M && question[idxQ - 1].first == question[idxQ].first; ++idxQ)
        answer[question[idxQ].second] = answer[question[idxQ - 1].second];

    for (size_t i = 0; i < M; i++)
    {
        cout << answer[i] << ' ';
    }
    return 0;
}