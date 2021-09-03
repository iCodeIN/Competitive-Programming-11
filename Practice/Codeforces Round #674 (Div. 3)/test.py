a = 9
b = 1
i = 2
x = pow(2, 64)-1
y = pow(9, 22)
while(True):
    a *= 9
    b *= i
    print(i, a, b)
    print(i, x >= a)
    print(i, x >= b) 
    i += 1
    if(a < b):
        break
    # if(a > x):
    #     print(i)

print(x >= y)
# print(x >= a/9)
# print(i)


# 99999999999999999
#

# 22 digits


# pos : [0,21]
