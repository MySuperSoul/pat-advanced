#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool is_prime(int cur_number)
{
	if (cur_number <= 1)
		return false;
	else if (cur_number == 2)
		return true;
	else
	{
		for (int i = 2; i <= sqrt(cur_number); i++)
		{
			if (cur_number % i == 0)
				return false;
		}
	}

	return true;
}

/*function to do reverse*/
int Reverse(int N, int D)
{
	int result = 0;
	while (N != 0)
	{
		result = result * D + (N % D);
		N /= D;
	}

	return result;
}

int main()
{
	int N, D;
	scanf("%d%d", &N, &D);

	/*To do while*/
	while (N >= 0)
	{
		int temp = N;
		int reverse_number = Reverse(N, D);

		/*To do judge*/
		if (is_prime(N) && is_prime(reverse_number))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		/*continue to read in*/
		scanf("%d", &N);
		if (N < 0)
			break;
		else
			scanf("%d", &D);
	}
	//system("pause");
	return 0;
}