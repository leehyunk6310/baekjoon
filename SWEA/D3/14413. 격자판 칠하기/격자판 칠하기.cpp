#include <iostream>
using namespace std;
// # => 검은색 . -> 흰색 ? => 둘다 가능
// 매 칸마다 상하좌우를 체크해서 현재 칸의 색과 다른칸인지 파악해야한다.
// .으로 시작하는 녀석과 #으로 시작하는 녀석만 존재한다.
// 해당 칸에있는 녀석이 ?이면 그냥 통과할 수 있으나, 아니면 그렇지 않음.
int main()
{
	int test_case;
	int T;
	cin >> T;
	char arr[51][51];

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		bool flag = true;

		cin >> N >> M;
		// 그래프 초기화
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		if (arr[1][1] == '#')
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					// 더해서 짝이면 #이 나 ?가 나와야 됨. 홀이면 . 나 ?가 나와야된다.
					if ((i + j) % 2 == 0)
					{
						if (arr[i][j] == '.')
						{
							flag = false;
						}
					}
					else
					{
						if (arr[i][j] == '#')
						{
							flag = false;
						}
					}
				}
			}
		}
		else if (arr[1][1] == '.')
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					// 더해서 짝이면 #이 나 ?가 나와야 됨. 홀이면 . 나 ?가 나와야된다.
					if ((i + j) % 2 == 0)
					{
						if (arr[i][j] == '#')
						{
							flag = false;
						}
					}
					else
					{
						if (arr[i][j] == '.')
						{
							flag = false;
						}
					}
				}
			}
		}
		// 이 경우는 처음에 ?을 넣거나 .을 넣는 두 경우를 고려하여야 한다.
		else if (arr[1][1] == '?')
		{
			bool flag1 = true;
			bool flag2 = true;

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					// 더해서 짝이면 #이 나 ?가 나와야 됨. 홀이면 . 나 ?가 나와야된다.
					if ((i + j) % 2 == 0)
					{
						if (arr[i][j] == '.')
						{
							flag1 = false;
						}
					}
					else
					{
						if (arr[i][j] == '#')
						{
							flag1 = false;
						}
					}
				}
			}	

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					// 더해서 짝이면 #이 나 ?가 나와야 됨. 홀이면 . 나 ?가 나와야된다.
					if ((i + j) % 2 == 0)
					{
						if (arr[i][j] == '#')
						{
							flag2 = false;
						}
					}
					else
					{
						if (arr[i][j] == '.')
						{
							flag2 = false;
						}
					}
				}
			}

			if (flag1 || flag2)
				flag = true;
			else
				flag = false;
		}
		cout << "#" << test_case << " ";
		if (flag)
			cout << "possible" << '\n';
		else
			cout << "impossible" << '\n';
	}

	return 0;
}