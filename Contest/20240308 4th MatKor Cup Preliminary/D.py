import math

def cubic_equation_solver(coefficients):
    a, b, c, d = coefficients
    discriminant = 18 * a * b * c * d - 4 * b**3 * d + b**2 * c**2 - 4 * a * c**3 - 27 * a**2 * d**2
    if discriminant > 0:
        # One real root and two complex conjugate roots
        root = (c - (b**3) / (27 * a**2) + math.sqrt(discriminant)**(1/3) + math.sqrt(discriminant)**(2/3)) / (3 * a)
        return [root]
    elif discriminant == 0:
        # Three real roots, at least two of them are equal
        root = (c - (b**3) / (27 * a**2)) / (3 * a)
        return [root, root, root]
    else:
        # Three distinct real roots
        root1 = (c - (b**3) / (27 * a**2) + math.sqrt(discriminant)**(1/3) + math.sqrt(discriminant)**(2/3)) / (3 * a)
        root2 = (c - (b**3) / (27 * a**2) - (1 + 1j * math.sqrt(3)) * math.sqrt(discriminant)**(1/3) - (1 - 1j * math.sqrt(3)) * math.sqrt(discriminant)**(2/3)) / (3 * a)
        root3 = (c - (b**3) / (27 * a**2) - (1 - 1j * math.sqrt(3)) * math.sqrt(discriminant)**(1/3) - (1 + 1j * math.sqrt(3)) * math.sqrt(discriminant)**(2/3)) / (3 * a)
        return [root1, root2, root3]

c3, c2, c1, c0 = 0, 0, 0, 0
n, b = map(int, input().split())
for i in range(n):
    x, y = map(int, input().split())
    c3 += -x * x * x
    c2 += 3 * x * x * (y - b)
    c1 += -3 * x * (y - b) * (y - b)
    c0 += (y - b) * (y - b) * (y - b)

coefficients = [c3, c2, c1, c0]
solutions = cubic_equation_solver(coefficients)
print("{:.10f}".format(solutions[1]))
