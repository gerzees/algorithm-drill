#include <bits/stdc++.h>

using namespace std;

char subject[51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    double total_credit = 0.0;
    double total_grade_point = 0.0;
    for (int i = 0; i < 20; ++i)
    {
        double credit, point = 0.0;
        char grade[3];

        cin >> subject >> credit >> grade;


        if (grade[0] == 'P')
        {
            continue;
        }

        if (grade[0] == 'A' && grade[1] == '+') point = 4.5;
        else if (grade[0] == 'A' && grade[1] == '0') point = 4.0;
        else if (grade[0] == 'B' && grade[1] == '+') point = 3.5;
        else if (grade[0] == 'B' && grade[1] == '0') point = 3.0;
        else if (grade[0] == 'C' && grade[1] == '+') point = 2.5;
        else if (grade[0] == 'C' && grade[1] == '0') point = 2.0;
        else if (grade[0] == 'D' && grade[1] == '+') point = 1.5;
        else if (grade[0] == 'D' && grade[1] == '0') point = 1.0;

        total_grade_point += credit * point;
        total_credit += credit;
    }

    cout << total_grade_point / total_credit;
}
