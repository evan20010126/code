#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	int times = 1;
	while (cin >> input)
	{
		int aAmount[1001] = {}, bAmount[1001] = {};
		for (int i = 0; i != input.size(); i++)
		{
			aAmount[i + 1] = aAmount[i], bAmount[i + 1] = bAmount[i];
			if (input[i] == 'a')
				aAmount[i + 1]++;
			else
				bAmount[i + 1]++;
		}

		for (auto x : aAmount)
			cout << x << " ";
		cout << endl;
		for (auto x : bAmount)
			cout << x << " ";
		cout << endl;

		cout << "AB Circle #" << times++ << ":\n";
		for (int i = 0; i != input.size(); i++)
			for (int j = i + 1; j != input.size(); j++)
				if (aAmount[j] - aAmount[i] == bAmount[input.size()] + bAmount[i] - bAmount[j] ||
					bAmount[j] - bAmount[i] == aAmount[input.size()] + aAmount[i] - aAmount[j])
					cout << i << ',' << j << endl;
		putchar('\n');
	}
}

// https://zerojudge.tw/ShowProblem?problemid=d017