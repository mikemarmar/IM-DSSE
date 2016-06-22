#include <tomcrypt.h>
#include <iaes_asm_interface.h>
#include <iaesni.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef __SIZE_TYPE__ size_t;
#define BLOCK_CIPHER_SIZE 16


int ccm_128_enc_dec(int cipher, const unsigned char *key, unsigned long keylen, symmetric_key *uskey, const unsigned char *nonce,
                    unsigned long noncelen, const unsigned char *header, unsigned long headerlen, unsigned char *pt, unsigned long ptlen,
                    unsigned char *ct, unsigned char *tag, unsigned long *taglen, int  direction);


//Intel AES NI functions
int aes128_ctr_encdec( unsigned char *pt, unsigned char *ct,  unsigned char *key,  unsigned char *ctr,  size_t numBlocks);

int omac_aes128_intel(unsigned char *omac_out, int omac_length, const unsigned char *data, int datalen, unsigned char *key);

int omac_aesni_init(omac_state *omac, int cipher, unsigned char *key);
int omac_aesni_process(omac_state *omac, unsigned char *key, const unsigned char *in, unsigned long inlen);
int omac_aesni_done(omac_state *omac, unsigned char *key, unsigned char *out, int outlen);


// PRNG using Fortuna
int rdrand_get_n_uints_retry(unsigned int n, unsigned int retry_limit, unsigned int *dest);

int invokeFortuna_prng(unsigned char *seed, unsigned char *key, int seedlen, int keylen);
int rdrand(unsigned char* output, unsigned int output_len, unsigned int retry_limit);
int _rdrand64_asm(unsigned long int *therand);
int _rdrand32_step(unsigned int *therand);
int _rdrand64_step(unsigned long long int *therand);

#ifdef __cplusplus
}
#endif
