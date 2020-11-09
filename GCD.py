def gcd(a, b):  
    if a == 0 : 
        return b  
      
    return gcd(b%a, a) 
  

print("Ingrese el primer numero") 
a = int(input())

print("Ingrese el segundo numero") 
b = int(input())

print("GCD(", a , "," , b, ") = ", gcd(a, b)) 

