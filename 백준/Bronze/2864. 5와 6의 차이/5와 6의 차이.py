a, b = map(str, input().split())
mina, maxa = [], []
minb, maxb = [], []

for i in range(len(a)):
    if a[i] == '6' or a[i] == '5':
        mina.append('5')
        maxa.append('6')
    else:
        mina.append(a[i])
        maxa.append(a[i])
for i in range(len(b)):
    if b[i] == '6' or b[i] == '5':
        minb.append('5')
        maxb.append('6')
    else:
        minb.append(b[i])
        maxb.append(b[i])


print(int(''.join(mina)) + int(''.join(minb)), int(''.join(maxa)) + int(''.join(maxb)))