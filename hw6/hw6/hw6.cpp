#include <iostream>
using namespace std;
//q1
int reverseNum(int num, int* countOdd);
int tu(int t);

//q2
int maxSequence(int num);
int sum(int num);
int dif(int num);

//q3
bool smallestDigit(int num);
int op(int num);
int zop(int num);

int main()
{

}



//q1
int reverseNum(int num, int* countOdd)
{
	int temp = num % 10;
	if (num <= 0)
	{
		return 0;
	}
	else
	{
		int x = tu(num);
		for (int i = 1; i < x; i++)
		{
			temp *= 10;
		}
		return temp + reverseNum(num / 10, countOdd);

	}

}
int tu(int t)
{
	if (t <= 0)
	{
		return 0;
	}
	else
	{
		return 1 + tu(t / 10);
	}

}


//q3
int op(int num)
{
	if (num / 10 == 0)
	{
		return num;
	}
	else
	{
		return op(num / 10);
	}
}
int zop(int num)
{
	if (num <= 10)
	{
		return 1;
	}
	else
	{
		return 10 * zop(num / 10);

	}

}
bool smallestDigit(int num)
{
	if (num <= 0)
	{
		return true;
	}

	if (num % 10 > op(num))
	{
		return false;
	}
	else
	{
		return smallestDigit(num % zop(num));
	}


}

//q2
int maxSequence(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	if (sum(num) > sum(dif(num)))
	{

		return num;
	}
}
int sum(int num)
{
	if (num % 10 == num / 10 % 10)
	{
		return 1 + sum(num / 10);
	}
	else
	{
		return 1;
	}
}
int dif(int num)
{
	if (num % 10 == num / 10 % 10)
	{
		return dif(num / 10);
	}
	else
	{
		return num;
	}

}
