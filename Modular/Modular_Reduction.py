import math

p = int(input("Ingrese el numero primo\n ~>"))
m = int(input("Ingrese el modulo\n ~>")) 
b = 2 ** 64
k = 4 #En base a la clase
u = (b**(2*k)) / p

q = ((m / b**(k-1)) * u / b**(k+1))
r = (m % (b ** (k+1)) - q - (p % (b ** (k+1))))


if r < 0:
    r = r + b ** (k+1)


while r >= p:
    r = r - p
print(r)