import sys
def part1(a,b):
	ans = 0
	for c in a:
		for w in b:
			if c in w:
				ans +=1
	return ans

def part2(a,b):
	ans = 0
	w = set()
	for r in a:
		w.add(r)
		w.add(r[::-1])
	for r in b:
		for c in w:
			for z in r.split(' '):
				print(z)
				if c in z:
					ans += len(c)
		print(ans)

	return ans


def main():
	input = sys.stdin.read()
	a = input.splitlines()
	#print(part1(a[0].split(','),a[1].split(' ')))
	print(part2(a[0].split(','), a[1:]))
if __name__ == "__main__":
	main()
