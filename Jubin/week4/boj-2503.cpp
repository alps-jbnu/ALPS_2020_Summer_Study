#include <vector>
#include <iostream>

using namespace std;

bool answer[1000];
std::vector<int> list;

void init(int a, int b, int c)
{    
    if (c >= 10)
    {
        init(a, b + 1, 1);
    }
    else if (b >= 10)
    {
        init(a + 1, 1, 1);
    }
    else if (a >= 10)
    {
        return;
    }
    else
    {
        if (a != b && b != c && c != a)
        {
            int num = a * 100 + b * 10 + c;
            answer[num] = true;
            list.push_back(num);
        }
        init(a, b, c + 1);
    }    
}

void result(int answer, int num, int* strike, int* ball)
{
    if (answer == num)
    {
        *strike = 3;
        *ball = 0;
        return;
    }
    
    int a1 = answer / 100;
    int b1 = (answer / 10) % 10;
    int c1 = answer % 10;
    int p1 = (1 << a1) | (1 << b1) | (1 << c1);
    
    int a2 = num / 100;
    int b2 = (num / 10) % 10;
    int c2 = num % 10;
    int p2 = (1 << a2) | (1 << b2) | (1 << c2);
    
    int intersection = p1 & p2;
    for (int i = 1; i < 10; ++i)
    {
        if (intersection & (1 << i))
        {
            ++(*ball);
        }
    }
    
    if (a1 == a2)
    {
        ++(*strike);
        --(*ball);
    }
    
    if (b1 == b2)
    {
        ++(*strike);
        --(*ball);
    }
    
    if (c1 == c2)
    {
        ++(*strike);
        --(*ball);
    }
}

int main()
{
	int N;
	cin >> N;
	
	list.reserve(504);
	init(1, 2, 3);
	
	while (N--)
	{
		int x;
		int strike;
		int ball;
		
		cin >> x >> strike >> ball;

        for (int num : list)
        {
            int s = 0;
            int b = 0;
            result(x, num, &s, &b);
            
            if (strike != s || ball != b)
            {
                answer[num] = false;
            }
	    }
	}
	
	int count = 0;
	for (int num : list)
    {
        if (answer[num])
        {
            ++count;
        }
    }
    
    cout << count;
    
	return 0;
}
