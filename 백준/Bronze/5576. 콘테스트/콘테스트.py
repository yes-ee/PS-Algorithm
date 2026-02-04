w = [int(input()) for i in range(10)]
k = [int(input()) for i in range(10)]

w.sort()
k.sort()
wsum, ksum = 0, 0

for i in range(3):
    wsum += w[9 - i]
    ksum += k[9 - i]
print(wsum, ksum)