import sys
input = sys.stdin.readline

num = ['0', '0', '1', '7', '4', '2', '6', '8', '10', '18', '22', '20', '28', '68', '88', '108', '188', '200']

for i in range(18, 101):
    num.append(num[i - 7] + '8')

def make_max(n):
    ret = 1
    if n % 2:
        ret = 7
    n //= 2
    for i in range(1, n):
        ret *= 10
        ret += 1

    return ret

t = int(input())
for i in range(t):
    n = int(input())
    print(num[n], make_max(n))