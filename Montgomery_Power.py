
def power(x, y, p) : 
    resultado = 1
    x = x % p  
    if (x == 0): 
        return 0
    while (y > 0) : 
        if ((y & 1) == 1) : 
            resultado = (resultado * x) % p 
        y = y >> 1 
        x = (x ** 2) % p 
          
    return resultado 
      
  
  
x = int(input("Ingrese el primer numero\n ~>"))
y = int(input("Ingrese el segundo numero\n ~>"))
p = int(input("Ingrese el modulo\n ~>"))
print("PExponente es ", power(x, y, p)) 
