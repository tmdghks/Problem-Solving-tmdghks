equation = input()
e1 = equation.split('-')
sum = 0
j = 0
for e in e1:
    e2 = e.split('+')
    tmp = 0
    for i in e2:
        tmp += int(i)
    if j == 0:
        sum += tmp
    else:
        sum -= tmp
    j += 1

print(sum)