#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main()
{
    vector<int> vec;
    int temp;
    while (cin >> temp)
    {
        vec.push_back(temp);
    }
    int arr[vec.size()];
    for (int i = 0; i < vec.size(); i++)
    {
        arr[i] = vec[i];
    }
    int maximum, sum;
    maximum = INT_MIN;
    sum = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        sum = sum + arr[j];
        if (sum < 0)
            sum = 0;
        if (sum > maximum)
            maximum = sum;
    }

    cout << maximum << endl;
    return 0;
}