A = int(input("Ingrese el primer numero\n ~>"))
B = int(input("Ingrese el segundo numero\n ~>"))
N = int(input("Ingrese el modulo\n ~>"))
n = N.bit_length()

R = 0

for i in range(0, n):
    q = int(R + (A & (1 << i) != 0) * B) % 2
    R = int((R + (A & (1 << i) != 0) * B + q * N) / 2)

print("Result:", R % N)