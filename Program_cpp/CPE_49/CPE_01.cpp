//Vito's_family
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int answer_num;
    cin >> answer_num;
    for (int i = 0; i < answer_num; i++)
    {
        int answer = 0;
        int question_arr_size;
        cin >> question_arr_size;

        int question_arr[question_arr_size];
        for (int j = 0; j < question_arr_size; j++)
            cin >> question_arr[j];
        sort(question_arr, question_arr + question_arr_size);
        int key = question_arr_size / 2;
        for (int k = 0; k < question_arr_size; k++)
        {
            answer += abs(question_arr[k] - question_arr[key]);
        }
        cout << answer << endl;
    }
    return 0;
}