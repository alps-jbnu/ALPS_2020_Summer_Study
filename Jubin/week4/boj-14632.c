#ifndef ONLINE_JUDGE
#pragma warning(disable:4996)
#endif

#include <stdio.h>
#include <stdlib.h>

enum
{
	MAX_STAMP_SIZE = 501,
	PAPER_HEIGHT = 1001,
	PAPER_WIDTH = 1002
};

void print_stamp(const short sy, const short sx, char dest[PAPER_HEIGHT][PAPER_WIDTH], char** src, const short* dest_rect, const short* src_rect)
{
	for (short y = 0; y < src_rect[0]; ++y)
	{
		if (sy + y >= dest_rect[0])
		{
			continue;
		}

		for (short x = 0; x < src_rect[1]; ++x)
		{
			if (sx + x >= dest_rect[1])
			{
				break;
			}

			dest[sy + y][sx + x] = src[y][x];
		}
	}
}

int main()
{
	short stamp_rect[MAX_STAMP_SIZE][2];
	char paper[1001][1002] = { 0 };
	char*** stamp = (char***)malloc(sizeof(char**) * MAX_STAMP_SIZE);

	short paper_rect[2];
	short stamp_size;
	scanf("%hd%hd%hd", paper_rect, paper_rect + 1, &stamp_size);

	for (short i = 1; i <= stamp_size; ++i)
	{
		scanf("%hd%hd", stamp_rect[i], stamp_rect[i] + 1);

		short stampHeight = stamp_rect[i][0];
		short stampWidth = stamp_rect[i][1];

		stamp[i] = (char**)malloc(sizeof(char*) * stampHeight);

		for (short y = 0; y < stampHeight; ++y)
		{
			stamp[i][y] = (char*)malloc(sizeof(char) * (1 + stampWidth));

			scanf("%s", stamp[i][y]);
		}
	}

	short Q;
	scanf("%hd", &Q);

	while (Q--)
	{
		short T;
		short y;
		short x;
		scanf("%hd%hd%hd", &T, &y, &x);

		print_stamp(y, x, paper, stamp[T], paper_rect, stamp_rect[T]);
	}

	for (short y = 0; y < paper_rect[0]; ++y)
	{
		for (short x = 0; x < paper_rect[1]; ++x)
		{
			putchar(paper[y][x] != 0 ? paper[y][x] : '.');
		}
		putchar('\n');
	}

	for (int i = 1; i <= stamp_size; ++i)
	{
		for (short y = 0; y < stamp_rect[i][0]; ++y)
		{
			free(stamp[i][y]);
		}
		free(stamp[i]);
	}
	free(stamp);

	return 0;
}
