#include <iostream>
#include <algorithm>

using namespace std;

int N;

void Swap(char* const a, char* const b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int GetRowMaxCount(char board[50][51], int row)
{
	char last = '\0';

	int maxCount = 0;
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		char c = board[row][i];
		if (last != c)
		{
			maxCount = max(maxCount, count);
			count = 0;
			last = c;
		}
		++count;
	}
	maxCount = max(maxCount, count);

	return maxCount;
}

int GetColumnMaxCount(char board[50][51], int column)
{
	char last = '\0';

	int maxCount = 0;
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		char c = board[i][column];
		if (last != c)
		{
			maxCount = max(maxCount, count);
			count = 0;
			last = c;
		}
		++count;
	}
	maxCount = max(maxCount, count);

	return maxCount;
}

int main()
{
	int maxCount = 0;
	char board[50][51];

	cin >> N;

	for (int n = 0; n < N; ++n)
	{
		cin >> board[n];
	}

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N - 1; ++x)
		{
			Swap(board[y] + x, board[y] + x + 1);
			maxCount = max(maxCount, GetRowMaxCount(board, y));
			maxCount = max(maxCount, GetColumnMaxCount(board, x));
			maxCount = max(maxCount, GetColumnMaxCount(board, x + 1));
			Swap(board[y] + x, board[y] + x + 1);
		}
		maxCount = max(maxCount, GetRowMaxCount(board, y));
	}

	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < N - 1; ++y)
		{
			Swap(board[y] + x, board[y + 1] + x);
			maxCount = max(maxCount, GetColumnMaxCount(board, x));
			maxCount = max(maxCount, GetRowMaxCount(board, y));
			maxCount = max(maxCount, GetRowMaxCount(board, y + 1));
			Swap(board[y] + x, board[y + 1] + x);
		}
		maxCount = max(maxCount, GetColumnMaxCount(board, x));
	}

	cout << maxCount;

	return 0;
}
