
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sodium.h>

#define MAX_MSG_LEN 64


int sign(uint8_t sm[], const uint8_t m[], const int mlen, const uint8_t secret_key[]) {
	unsigned long long smlen;

	if (crypto_sign(sm, &smlen, m, mlen, secret_key) == 0) {
		return smlen;
	}
	else
		return 0;

	
}

int verify(uint8_t m[], const uint8_t sm[], const int smlen, const uint8_t public_key[]) {
	unsigned long long mlen;

	if (crypto_sign_open(m, &mlen, sm, smlen, public_key) == 0) {
		return mlen;
	}
	else
		return 0;

	
}

int main() {
	uint8_t secret_key[crypto_sign_SECRETKEYBYTES];
	uint8_t public_key[crypto_sign_PUBLICKEYBYTES];
	uint8_t sm[MAX_MSG_LEN + crypto_sign_BYTES];
	uint8_t m[MAX_MSG_LEN + crypto_sign_BYTES];
	int mlen, smlen,rc;

	char linea[2048];
	FILE* fich;

	fich = fopen_s(&fich,"file.txt", "r");

	memset(m, '\0', MAX_MSG_LEN);
	mlen = snprintf(m, MAX_MSG_LEN, "%c", fich);

	rc = crypto_sign_keypair(public_key, secret_key);
	if (rc < 0) {
		return 1;
	}

	int O;
	printf("1) Firmar\n2) Verificar\n0) Cerrar\n ~>");
	scanf_s("%d", &O);

	while (1){

		if (O == 1){
			smlen = sign(sm, m, mlen, secret_key);
			if (smlen > 0) {
				printf("Secret Key: ");
				for (size_t i = 0; i < 64; i++)
				{
					printf("%xu", secret_key[i]);
				}
				printf("\nFirmado\n\n");
			}
		}
		
		else if (O == 2) {
			mlen = verify(m, sm, smlen, public_key);
			if (mlen > 0) {
				printf("Public Key:");
				for (size_t i = 0; i < 32; i++)
				{
					printf("%xu", public_key[i]);
				}
				printf("\nVerificado\n");
			}
		}

		else if (O == 0) {
			break;
		}

		printf("1) Firmar\n2)Verificar\n0)Cerrar\n ~>");
		scanf_s("%d", &O);
	}

	return 0;
}
