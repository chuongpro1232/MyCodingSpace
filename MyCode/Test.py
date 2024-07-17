def add(a, b):
    return x + y

def subtract(x, y):
    return x - y

def product(x, y):
    return x * y

def divide(x, y):
    return x / y

def power(x, y):
    return x ** y

a = float(input('Please enter the value of a: '))
b = float(input('Please enter the value of b: '))
c = float(input('Please enter the value of c: '))
d = float(input('Please enter the value of d: '))

total = subtract(divide(d,4),product(divide(power(a,b),2.1),power(divide(c,add(power(a,4),d)),(divide(2,c)))))
print(total)