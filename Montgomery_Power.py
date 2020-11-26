
def power(x, y, p) : 
    resultado = 1
    x = x % p  
      
    if (x == 0) : 
        return 0
  
    while (y > 0) : 
          
        if ((y & 1) == 1) : 
            resultado = (resultado * x) % p 

        y = y >> 1 
        x = (x * x) % p 
          
    return resultado 
      
  
  
x = 15; y = 17; p = 5
print("Power is ", power(x, y, p)) 