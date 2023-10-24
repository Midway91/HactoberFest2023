#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NUM_ROUNDS 16
#define BLOCK_SIZE 8

void des_encrypt_block(const uint8_t *input, const uint8_t *key, uint8_t *output);
void generate_round_keys(const uint8_t *key, uint8_t round_keys[16][6] ,int n);
void sbox_substitution(const uint8_t *input, uint8_t *output) ;
void swap_halves(uint32_t *left_half, uint32_t *right_half);
void xor_with_left_half(uint32_t *left_half, const uint32_t *right_half) ;
void permutation(const uint8_t *input, uint8_t *output);
void initial_permutation(uint8_t *block);
void final_permutation(uint8_t *block);
void apply_permutation(const uint8_t *input, uint8_t *output, const int *permutation, int num_bits);
void des_decrypt_block(const uint8_t *input, const uint8_t *key, uint8_t *output);

static const uint8_t sbox_table[8][4][16] = {
    // S-box S1
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },

    // S-box S2
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },

    // S-box S3
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },

    // S-box S4
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },

    // S-box S5
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },

    // S-box S6
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },

    // S-box S7
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },

    // S-box S8
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

// Initial permutation
static const int initial_permutation_table[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

// Inverse permutation
static const int final_permutation_table[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

// PC-1
static const int key_permutation_table[56] = {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
};

// Key shifts for each round
static const int key_shifts[16] = {
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1
};

// PC-2-box
static const int key_compression_table[48] = {
    14, 17, 11, 24, 1, 5, 3, 28,
    15, 6, 21, 10, 23, 19, 12, 4,
    26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
};

// E box
static const int expansion_table[48] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};

// Permutation table
static const int permutation_table[32] = {
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25
};

int main() {
    uint8_t input[BLOCK_SIZE] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};
    uint8_t key[BLOCK_SIZE] = {0x13, 0x34, 0x57, 0x79, 0x9b, 0xbd, 0xdf, 0xf1};

    printf("Input Text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", input[i]);
    }
    printf("\n");

    printf("Key: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", key[i]);
    }
    printf("\n\n");

    uint8_t cipher[BLOCK_SIZE];
    printf("Keys for Encryption are : \n");
    des_encrypt_block(input, key, cipher);

    printf("\nCipher Text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", cipher[i]);
    }
    printf("\n\n");
    uint8_t decrypted[BLOCK_SIZE];
    printf("Keys for Encryption are : \n");
    des_decrypt_block(cipher, key, decrypted);
    printf("\nDecrypted Text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", decrypted[i]);
    }
    printf("\n");

    return 0;
}

void apply_permutation(const uint8_t *input, uint8_t *output, const int *permutation, int num_bits) {
    int num_bytes = (num_bits + 7) / 8;
    memset(output, 0, num_bytes);

    for (int i = 0; i < num_bits; i++) {
        int bit = permutation[i] - 1;
        int byte_index = bit / 8;
        int bit_index = 7 - (bit % 8);

        output[i / 8] |= ((input[byte_index] >> bit_index) & 0x01) << (7 - (i % 8));
    }
    printf("Output after permutation/expansion: ");
    for (int i = 0; i < num_bytes; i++) {
        printf("%02X ", output[i]);
    }
    printf("\n");
}

void des_encrypt_block(const uint8_t *input, const uint8_t *key, uint8_t *output) {
    uint8_t round_keys[16][6];
    uint8_t perm_input[8];
    uint32_t left_half, right_half, temp;

    generate_round_keys(key, round_keys,0);
    apply_permutation(input, perm_input, initial_permutation_table, 64);

    left_half = *((uint32_t *)perm_input);
    right_half = *((uint32_t *)(perm_input + 4));

    for (int round = 0; round < 16; round++) {
        uint8_t expanded_right[6];
        apply_permutation((uint8_t *)&right_half, expanded_right, expansion_table, 48);

        for (int i = 0; i < 6; i++) {
            expanded_right[i] ^= round_keys[round][i];
        }
           uint8_t sbox_output[6];
        sbox_substitution(expanded_right, sbox_output);
        uint8_t permuted_sbox_output[4];
        permutation(sbox_output, permuted_sbox_output);
        xor_with_left_half(&left_half, (uint32_t *)permuted_sbox_output);
        if (round != 15) {
            swap_halves(&left_half, &right_half);
        }
    }
    apply_permutation((uint8_t *)&left_half, output, final_permutation_table, 64);
}

void generate_round_keys(const uint8_t *key, uint8_t round_keys[16][6],int n){
    uint8_t perm_key[7];
    apply_permutation(key, perm_key, key_permutation_table, 56);
    uint32_t left_half = *((uint32_t *)perm_key);
    uint32_t right_half = *((uint32_t *)(perm_key + 4));

    for (int i = 0; i < 16; i++) {
        int shift = key_shifts[i];
        left_half = (left_half << shift) | (left_half >> (28 - shift));
        right_half = (right_half << shift) | (right_half >> (28 - shift));
        uint32_t compressed_key = ((left_half & 0x0FFFFFFF) << 3) | (right_half & 0x0FFFFFFF);
        apply_permutation((uint8_t *)&compressed_key, round_keys[i], key_compression_table, 48);
    }
    
    for (int i = 0; i < 16; i++) {
        if(n)
        printf("Round key %d: ",16-i);
        else
        printf("Round key %d: ", i+1);
        for (int j = 0; j < 6; j++) {
            printf("%02X ", round_keys[i][j]);
        }
        printf("\n");
    }
}

void sbox_substitution(const uint8_t *input, uint8_t *output) {
    for (int i = 0; i < 8; i++) {
        uint8_t row = ((input[i] & 0x20) >> 4) | (input[i] & 0x01);
        uint8_t col = (input[i] >> 1) & 0x0F;
        output[i] = (uint8_t)sbox_table[i][row][col];
    }
    printf("Output after S-Box substitution: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", output[i]);
    }
    printf("\n");
}

void swap_halves(uint32_t *left_half, uint32_t *right_half) {
    uint32_t temp = *left_half;
    *left_half = *right_half;
    *right_half = temp;
}

void xor_with_left_half(uint32_t *left_half, const uint32_t *right_half) {
    for (int i = 0; i < 4; i++) {
        ((uint8_t *)left_half)[i] ^= ((uint8_t *)right_half)[i];
    }
}

void permutation(const uint8_t *input, uint8_t *output) {
    apply_permutation(input, output, permutation_table, 32);
}

void des_decrypt_block(const uint8_t *input, const uint8_t *key, uint8_t *output) {
    uint8_t round_keys[16][6];
    uint8_t perm_input[8]; 
    uint32_t left_half, right_half, temp;
    generate_round_keys(key, round_keys,1);
    apply_permutation(input, perm_input, initial_permutation_table, 64);
    left_half = *((uint32_t *)perm_input);
    right_half = *((uint32_t *)(perm_input + 4));
    for (int round = 15; round >= 0; round--) {
        uint8_t expanded_right[6];
        apply_permutation((uint8_t *)&right_half, expanded_right, expansion_table, 48);
        for (int i = 0; i < 6; i++) {
            expanded_right[i] ^= round_keys[round][i];
        }

        uint8_t sbox_output[6];
        sbox_substitution(expanded_right, sbox_output);

        uint8_t permuted_sbox_output[4];
        permutation(sbox_output, permuted_sbox_output);

        xor_with_left_half(&left_half, (uint32_t *)permuted_sbox_output);

        if (round != 0) {
            swap_halves(&left_half, &right_half);
        }
    }
    apply_permutation((uint8_t *)&left_half, output, final_permutation_table, 64);}


void initial_permutation(uint8_t *block) {
    apply_permutation(block, block, initial_permutation_table, 64);
    printf("Output after initial permutation: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", block[i]);
    }
    printf("\n");
}

void final_permutation(uint8_t *block) {
    apply_permutation(block, block, final_permutation_table, 64);
    printf("Output after final permutation: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", block[i]);
    }
    printf("\n");
}
