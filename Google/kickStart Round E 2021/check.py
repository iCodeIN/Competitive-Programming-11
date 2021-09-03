
t = float(input())

fact = [1]


for i in range(1, 11):
    fact.append(fact[i-1] * i)
j = 1

while t > 0:

    n = int(input())

    ans = float(0)

    for i in range(1, n+1):
        ans += i/fact[i-1]

    ans /= n

    t -= 1
    print("Case #", j, ": ", ans, sep='')
    j += 1
