#include <iostream>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, a=0, b=0, c=0, d=0, e=0;
		cin >> N;
		
		while (N % 2 == 0 && N != 0)
		{
			a++;
			N /= 2;
		}
		while (N % 3 == 0 && N != 0)
		{
			b++;
			N /= 3;
		}
		while (N % 5 == 0 && N != 0)
		{
			c++;
			N /= 5;

		}
		while (N % 7 == 0 && N != 0)
		{
			d++;
			N /= 7;

		}
		while (N % 11 == 0 && N != 0)
		{
			e++;
			N /= 11;
		}


		cout << "#" << test_case << " " << a << " " << b << " " << c << " " << d << " " << e << "\n";
	}

	return 0;
}