import nacl.secret
import nacl.utils


Llave = nacl.utils.random(nacl.secret.SecretBox.KEY_SIZE)
Caja = nacl.secret.SecretBox(Llave)
Option = int(input(' 1 Cifrar\n 2 Comprobar\n 0 Parar \n~>:'))

while Option != 0:    
    if Option == 1:
        Texto = open("F:\\Mensaje secreto secretioso.txt", "r")
        Linea = Texto.readline()

        while Linea:
            Linea = Texto.readline()
        mensaje = Linea.encode("utf-8")
        mcifrado = Caja.encrypt(mensaje)

        #MASCII = mcifrado.encode("ascii")
        print('Firma:',mcifrado)
    elif Option == 2:
        assert len(mcifrado) == len(mensaje) + Caja.NONCE_SIZE + Caja.MACBYTES
        mdescifrado = Caja.decrypt(mcifrado)

        if(mdescifrado == mensaje):
            print('Firma correspondiente')
        else:
            print('Firma erronea')
    elif Option == 0:
        print("Excelente")
        break
    else:
        print('ERROR')
    Option = int(input(' 1 Cifrar\n 2 Comprobar\n 0 Parar \n~>:'))


