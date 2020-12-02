A = int(input("Ingrese el primer numero\n ~>"))
B = int(input("Ingrese el segundo numero\n ~>"))
N = int(input("Ingrese el modulo\n ~>"))

R = 1
A = A % N 

while (B > 0) :    
    if ((B & 1) == 1) : 
        R = (R * A) % N

    B = B >> 1 
    A = (A * A) % N

print(R)
