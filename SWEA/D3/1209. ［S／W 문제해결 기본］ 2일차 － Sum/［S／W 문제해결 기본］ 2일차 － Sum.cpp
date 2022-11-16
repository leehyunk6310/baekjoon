#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;	
	int arr[100][100];

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int t;
		vector<int> sum;

		cin >> t;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
			}
		}

		// 가로의 합 체크
		for (int i = 0; i < 100; i++)
		{
			int tmp = 0;
			for (int j = 0; j < 100; j++)
			{
				tmp += arr[i][j];
			}
			sum.push_back(tmp);
		}

		// 세로의 합 체크
		for (int i = 0; i < 100; i++)
		{
			int tmp = 0;
			for (int j = 0; j < 100; j++)
			{
				tmp += arr[j][i];
			}
			sum.push_back(tmp);
		}

		// 대각선 합 체크 
		int tmp = 0;
		for (int i = 0; i < 100; i++)
		{
			tmp += arr[i][i];
		}
		sum.push_back(tmp);

		tmp = 0;
		for (int i = 99; i >= 100; i--)
		{
			tmp += arr[i][99 - i];
		}
		sum.push_back(tmp);

		sort(sum.begin(), sum.end());

		cout << "#" << t << " " << sum.back() << '\n';
	}

	return 0;
}