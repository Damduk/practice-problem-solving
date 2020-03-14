xpos = []
ypos = []
for _ in range(3):
	x, y = input().split()
	xpos.append(int(x))
	ypos.append(int(y))

x = list(filter(lambda x: xpos.count(x) == 1, xpos))[0]
y = list(filter(lambda y: ypos.count(y) == 1, ypos))[0]

print(x, y)
