
from collections import Counter

t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))
	f = Counter(a)
	print(sum(v-1 for k, v in f.items()))
