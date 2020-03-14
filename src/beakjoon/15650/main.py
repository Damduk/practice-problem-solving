n, m = list(map(lambda x: int(x), input().split()))

def out(out):
	for e in out:
		print(e, '', end='')
	
	print()

output = []
def f(x):
	output.append(x)
	
	size = len(output)
	if size == m:
		out(output)
	elif size < m:
		for next in range(x + 1, n + 1):
			f(next)

	del output[size - 1]


for i in range(1, n + 1):
	f(i)