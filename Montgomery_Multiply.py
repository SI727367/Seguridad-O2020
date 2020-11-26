A = 15
B = 17
N = 5
n = N.bit_length()

R = 0

for i in range(0, n):
    q = int(R + (A & (1 << i) != 0) * B) % 2
    R = int((R + (A & (1 << i) != 0) * B + q * N) / 2)

print("Result:", R % N)