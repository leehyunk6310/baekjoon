#include <iostream>
using namespace std;

// 보드는 100 x 100 보드
// 위가 N극, 아래가 S극, 1은 N극성질, 2는 S극성질
// 매 열을 기준으로 아래로 순회하면서 현재가 1이고 다음으로 보는것이 2 이렇게 짝이 지어지면 갯수를 증가시킨다.
int main()
{
	int test_case;
	int T=10;	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, cnt=0;
		char arr[100][100];

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int col = 0; col < N; col++)
		{			
			string s = "";
			// 모든 행에 대하여 상태 체크
			for (int row = 0; row < N; row++)
			{
				if (arr[row][col] != '0')
					s += arr[row][col];
			}
			for (int i = 0; i < s.size() - 1; i++)
			{
				string tmp = ""; 
				tmp += s[i];
				tmp += s[i + 1];

				if (tmp == "12")
					cnt++;
			}
		}

		cout << "#" << test_case << " " << cnt << '\n';
	}

	return 0;
}