#include <stdlib.h>
#include <stdio.h>
#include <sodium.h>

#define Bytes 700
char TEXTO [Bytes];
char Direccion[50] = "file.txt";
#define MESSAGE ((unsigned char *) TEXTO)
#define MESSAGE_LEN Bytes
#define CIPHERTEXT_LEN (crypto_secretbox_MACBYTES + MESSAGE_LEN)

void dump_hex_buff(unsigned char buf[], unsigned int len)
{
    int i;
    for (i = 0; i < len; i++) printf("%02X ", buf[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{

    FILE* pf;
    pf = fopen(Direccion, "r");
    fgets(TEXTO, Bytes,pf );
    fclose(pf);

    unsigned char key[crypto_secretbox_KEYBYTES];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    unsigned char ciphertext[CIPHERTEXT_LEN];
    unsigned char decrypted[MESSAGE_LEN];


    crypto_secretbox_keygen(key);
    printf("secret key generated:\n");
    dump_hex_buff(key, crypto_secretbox_KEYBYTES);


    randombytes_buf(nonce, sizeof nonce);
    printf("nonce:\n");
    dump_hex_buff(nonce, sizeof nonce);

    int O;
    printf("1) Cifrar\n2) VDescifrar\n0) Cerrar\n ~>");
    scanf_s("%d", &O);

    while (1) {

        if (O == 1) {
            crypto_secretbox_easy(ciphertext, MESSAGE, MESSAGE_LEN, nonce, key);
            pf = fopen(Direccion, "w+");
            fprintf(pf, ciphertext);
            fclose(pf);
            printf("ciphertext:\n");
            dump_hex_buff(ciphertext, CIPHERTEXT_LEN);
        }

        else if (O == 2) {
            if (crypto_secretbox_open_easy(decrypted, ciphertext, CIPHERTEXT_LEN, nonce, key) != 0) {

            }
            else {
                printf("decrypted data (hex):\n");
                dump_hex_buff(decrypted, MESSAGE_LEN);
                pf = fopen(Direccion, "w+");
                fprintf(pf, decrypted);
                fclose(pf);
                printf("decrpyted data (ascii):%s\n", decrypted);
            }
        }
        else if (O == 0) {
            break;
        }

        printf("1) Cifrar\n2) VDescifrar\n0) Cerrar\n ~>");
        scanf_s("%d", &O);
    }
   

    return 0;
}