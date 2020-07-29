#ifndef ONLINE_JUDGE
#pragma warning(disable:4996)
#endif

#include <cstdio>
#include <algorithm>

enum
{
	MAX = 500
};

int height;
int width;

bool IsValid(const int y, const int x)
{
	return y >= 0 && y < height && x >= 0 && x < width;
}

int main()
{
	short paper[MAX][MAX] = { 0 };

	const int blocks[][4][2] =
	{
		// ****
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},

		// *
		// *
		// *
		// *
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},

		// **
		// **
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},

		// *
		// *
		// **
		{{0, 0}, {1, 0}, {2, 0}, {2, 1}},

		//  *
		//  *
		// **
		{{0, 1}, {1, 1}, {2, 1}, {2, 0}},

		// **
		// *
		// *
		{{0, 0}, {0, 1}, {1, 0}, {2, 0}},

		// **
		//  *
		//  *
		{{0, 0}, {0, 1}, {1, 1}, {2, 1}},

		// *
		// ***
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}},

		//   *
		// ***
		{{0, 2}, {1, 0}, {1, 1}, {1, 2}},

		// ***
		// *
		{{0, 0}, {0, 1}, {0, 2}, {1, 0}},

		// ***
		//   *
		{{0, 0}, {0, 1}, {0, 2}, {1, 2}},

		// *
		// **
		//  *
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},

		//  *
		// **
		// *
		{{0, 1}, {1, 0}, {1, 1}, {2, 0}},

		// **
		//  **
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}},

		//  **
		// **
		{{0, 1}, {0, 2}, {1, 0}, {1, 1}},

		// ***
		//  *
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}},

		//  *
		// ***
		{{0, 1}, {1, 0}, {1, 1}, {1, 2}},

		//  *
		// **
		//  *
		{{0, 1}, {1, 0}, {1, 1}, {2, 1}},

		// *
		// **
		// *
		{{0, 0}, {1, 0}, {1, 1}, {2, 0}}
	};


	scanf("%d%d", &height, &width);

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			scanf("%hd", paper[y] + x);
		}
	}

	int blockSize = sizeof(blocks) / sizeof(int[4][2]);

	int maxSum = 0;

	for (int i = 0; i < blockSize; ++i)
	{
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				int sum = 0;
				for (int n = 0; n < 4; ++n)
				{
					int oy = blocks[i][n][0];
					int ox = blocks[i][n][1];

					if (!IsValid(y + oy, x + ox))
					{
						goto next;
					}

					sum += paper[y + oy][x + ox];
				}
				maxSum = std::max(maxSum, sum);
			}
			
		next:
			continue;

		}
	}

	printf("%d", maxSum);

	return 0;
}
