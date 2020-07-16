import sys
import heapq

N = int(input())
first_h = []  # 내림차순
second_h = []  # 오름차순


for _ in range(N):
    value = int(sys.stdin.readline()[:-1])
    if len(first_h) == 0:
        heapq.heappush(first_h, -value)
    else:
        if -first_h[0] < value:
            heapq.heappush(second_h, value)
        else:
            heapq.heappush(first_h, -value)
        if len(first_h) < len(second_h):
            heapq.heappush(first_h, -heapq.heappop(second_h))
        elif len(first_h) > len(second_h)+1:
            heapq.heappush(second_h, - heapq.heappop(first_h))
    print(-first_h[0])
