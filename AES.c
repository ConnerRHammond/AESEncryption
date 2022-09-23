#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned char sBox[16][16] = {
    { 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76 } ,
    { 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0 } ,
    { 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15 } ,
    { 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75 } ,
    { 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84 } ,
    { 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf } ,
    { 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8 } ,
    { 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2 } ,
    { 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73 } ,
    { 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb } ,
    { 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79 } ,
    { 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08 } ,
    { 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a } ,
    { 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e } ,
    { 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf } ,
    { 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }
};
unsigned char InvSbox[16][16] = {
    { 0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb } ,
    { 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb } ,
    { 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e } ,
    { 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25 } ,
    { 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92 } ,
    { 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84 } ,
    { 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06 } ,
    { 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b } ,
    { 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73 } ,
    { 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e } ,
    { 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b } ,
    { 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4 } ,
    { 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f } ,
    { 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef } ,
    { 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61 } ,
    { 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d }
};
struct keyStuct {
    unsigned char key[59][4];
};
struct state{
    unsigned char state[4][4];
};
unsigned char xtime(unsigned char hex1);
unsigned char ffAdd(unsigned char hex1, unsigned char hex2);
unsigned char ffMultiply(unsigned char hex1, unsigned char hex2);
void test();
void changeState(struct state * state, unsigned char newMatrix[4][4]) {
    for (int c = 0; c < 4; c++) {
        for(int r= 0; r < 4; r++) {
            state->state[r][c] = newMatrix[r][c];
        }
    }
}
void printState(struct state * state) {
    printf("---------------\n");
    for (int r = 0; r < 4; r++) {
        printf(" ");
        for(int c = 0; c < 4; c++) {
            if (c < 3){
                printf("%x, ",state->state[r][c]);
            }
            else { 
                printf("%x",state->state[r][c]);
            }
        }
        printf("\n");
    }
    printf("---------------\n");
}
void printOutput(struct state * state){
    unsigned char leftBit;
    unsigned char rightBit;
    for(int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            leftBit = (state->state[r][c] & 0xf0) >> 4;
            rightBit = state->state[r][c] & 0x0f;
            printf("%x",leftBit);
            printf("%x",rightBit);
        }
    }
    printf("\n");
}
void subBytes(struct state * state);
void shiftRows(struct state * state);
void mixColumns(struct state * ); 
void addRoundKey(struct state *,struct state *); 
void rotWord(unsigned char * word); 
void subWord(unsigned char * word);
struct keyStuct* expand(unsigned char * words,int nk, struct keyStuct* key);
void createState(int start, struct keyStuct* key, struct state* state);
unsigned char cToH(char hex);
void invShiftRows(struct state * state);
void invSubBytes(struct state * state);
void invMixColumns(struct state * state);
int main(int argc, char *argv[])
{
    if (atoi(argv[1]) == 0){
        struct keyStuct* key = malloc(sizeof(struct keyStuct));
        struct state* State = malloc(sizeof(struct state));
        struct state* keyState = malloc(sizeof(struct state));
        
        int round;
        int nk = strlen(argv[3]) / 8;
    
        int nr = 10;
        if (nk == 6) {
            nr = 12;
        }
        else if (nk == 8) {
            nr = 14;
        }
        unsigned char a[4][4] = {  
                    {(cToH(argv[2][0]) << 4) + cToH(argv[2][1]), (cToH(argv[2][8]) << 4) + cToH(argv[2][9]), (cToH(argv[2][16]) << 4) + cToH(argv[2][17]), (cToH(argv[2][24]) << 4) + cToH(argv[2][25])} ,   /*  initializers for row indexed by 0 */
                    {(cToH(argv[2][2]) << 4) + cToH(argv[2][3]), (cToH(argv[2][10]) << 4) + cToH(argv[2][11]), (cToH(argv[2][18]) << 4) + cToH(argv[2][19]), (cToH(argv[2][26]) << 4) + cToH(argv[2][27])} ,   /*  initializers for row indexed by 1 */
                    {(cToH(argv[2][4]) << 4) + cToH(argv[2][5]), (cToH(argv[2][12]) << 4) + cToH(argv[2][13]), (cToH(argv[2][20]) << 4) + cToH(argv[2][21]), (cToH(argv[2][28]) << 4) + cToH(argv[2][29])} ,   /*  initializers for row indexed by 2 */
                    {(cToH(argv[2][6]) << 4) + cToH(argv[2][7]), (cToH(argv[2][14]) << 4) + cToH(argv[2][15]), (cToH(argv[2][22]) << 4) + cToH(argv[2][23]), (cToH(argv[2][30]) << 4) + cToH(argv[2][31])} ,    /*  initializers for row indexed by 3 */
        };
        if (nk ==  4 ) {
            unsigned char words[16];
            for (int i = 0; i < 32; i = i + 2) {
                words[i/2] = (cToH(argv[3][i]) << 4) + cToH(argv[3][i + 1]);
            }
            expand(words,nk,key);
        }
        else if (nk == 6) {
            unsigned char words[24];
            for (int i = 0; i < 48; i = i + 2) {
                words[i/2] = (cToH(argv[3][i]) << 4) + cToH(argv[3][i + 1]);
            }
            expand(words,nk,key);

        }
        else if (nk == 8) {
            unsigned char words[32];
            for (int i = 0; i < 64; i = i + 2) {
                words[i/2] = (cToH(argv[3][i]) << 4) + cToH(argv[3][i + 1]);
            }
            expand(words,nk,key);
        }
        createState(0,key,keyState);
        changeState(State,a);
        printf("round[ 0].input "); printOutput(State);
        printf("round[ 0].k_sch "); printOutput(keyState);
        addRoundKey(State,keyState);
        for (round = 1; round < nr; round++) {
            printf("round[ %d].start ",round); printOutput(State);
            subBytes(State);
            printf("round[ %d].s_box ",round); printOutput(State);
            shiftRows(State);
            printf("round[ %d].s_row ",round); printOutput(State);
            mixColumns(State);
            printf("round[ %d].m_col ",round); printOutput(State);
            createState(round * 4,key,keyState);
            printf("round[ %d].k_sch ",round); printOutput(keyState);
            addRoundKey(State,keyState);
        }
        printf("round[ %d].start ",round); printOutput(State);
        subBytes(State);
        printf("round[ %d].s_box ",round); printOutput(State);
        shiftRows(State);
        printf("round[ %d].s_row ",round); printOutput(State);
        createState(round * 4,key,keyState);
        printf("round[ %d].k_sch ",round); printOutput(keyState);
        addRoundKey(State,keyState);
        printf("round[ %d].output ",round); printOutput(State);
    }
    else {
        int roundCounter = 1;
        struct keyStuct* key = malloc(sizeof(struct keyStuct));
        struct state* State = malloc(sizeof(struct state));
        struct state* keyState = malloc(sizeof(struct state));
        
        int round;
        int nk = strlen(argv[3]) / 8;
    
        int nr = 10;
        if (nk == 6) {
            nr = 12;
        }
        else if (nk == 8) {
            nr = 14;
        }
        unsigned char a[4][4] = {  
                    {(cToH(argv[2][0]) << 4) + cToH(argv[2][1]), (cToH(argv[2][8]) << 4) + cToH(argv[2][9]), (cToH(argv[2][16]) << 4) + cToH(argv[2][17]), (cToH(argv[2][24]) << 4) + cToH(argv[2][25])} ,   /*  initializers for row indexed by 0 */
                    {(cToH(argv[2][2]) << 4) + cToH(argv[2][3]), (cToH(argv[2][10]) << 4) + cToH(argv[2][11]), (cToH(argv[2][18]) << 4) + cToH(argv[2][19]), (cToH(argv[2][26]) << 4) + cToH(argv[2][27])} ,   /*  initializers for row indexed by 1 */
                    {(cToH(argv[2][4]) << 4) + cToH(argv[2][5]), (cToH(argv[2][12]) << 4) + cToH(argv[2][13]), (cToH(argv[2][20]) << 4) + cToH(argv[2][21]), (cToH(argv[2][28]) << 4) + cToH(argv[2][29])} ,   /*  initializers for row indexed by 2 */
                    {(cToH(argv[2][6]) << 4) + cToH(argv[2][7]), (cToH(argv[2][14]) << 4) + cToH(argv[2][15]), (cToH(argv[2][22]) << 4) + cToH(argv[2][23]), (cToH(argv[2][30]) << 4) + cToH(argv[2][31])} ,    /*  initializers for row indexed by 3 */
        };
        if (nk ==  4 ) {
            unsigned char words[16];
            for (int i = 0; i < 32; i = i + 2) {
                words[i/2] = (cToH(argv[3][i]) << 4) + cToH(argv[3][i + 1]);
            }
            expand(words,nk,key);
        }
        else if (nk == 6) {
            unsigned char words[24];
            for (int i = 0; i < 48; i = i + 2) {
                words[i/2] = (cToH(argv[3][i]) << 4) + cToH(argv[3][i + 1]);
            }
            expand(words,nk,key);

        }
        else if (nk == 8) {
            unsigned char words[32];
            for (int i = 0; i < 64; i = i + 2) {
                words[i/2] = (cToH(argv[3][i]) << 4) + cToH(argv[3][i + 1]);
            }
            expand(words,nk,key);
        }
        
        createState(nr*4,key,keyState);
        changeState(State,a);
        printf("round[ 0].iinput "); printOutput(State);
        printf("round[ 0].ik_sch "); printOutput(keyState);
        addRoundKey(State,keyState);
        for (round = nr-1; round > 0; round--) {
            printf("round[ %d].istart ",roundCounter); printOutput(State);
            invShiftRows(State);
            printf("round[ %d].is_row ",roundCounter); printOutput(State);
            invSubBytes(State);
            printf("round[ %d].is_box ",roundCounter); printOutput(State);
            createState(round * 4,key,keyState);
            printf("round[ %d].ik_sch ",roundCounter); printOutput(keyState);
            addRoundKey(State,keyState);
            printf("round[ %d].ik_add ",roundCounter); printOutput(State);
            invMixColumns(State);
            roundCounter ++;
        }
        printf("round[%d].istart ",roundCounter); printOutput(State);
        invShiftRows(State);
        printf("round[%d].is_row ",roundCounter); printOutput(State);
        invSubBytes(State);
        printf("round[%d].is_box ",roundCounter); printOutput(State);
        createState(0,key,keyState);
        printf("round[%d].ik_sch ",roundCounter); printOutput(keyState);
        addRoundKey(State,keyState);
        printf("round[%d].ioutput ",roundCounter); printOutput(State);
    }
    
    //test();
    // unsigned char test[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    // expand(test,4);
    // unsigned char test2[24] = {0x8e,0x73,0xb0,0xf7,0xda,0x0e,0x64,0x52,0xc8,0x10,0xf3,0x2b,0x80,0x90,0x79,0xe5,0x62,0xf8,0xea,0xd2,0x52,0x2c,0x6b,0x7b};
    // expand(test2,6);
    // unsigned char test2[32] ={0X60,0X3d,0Xeb,0X10,0X15,0Xca,0X71,0Xbe,0X2b,0X73,0Xae,0Xf0,0X85,0X7d,0X77,0X81,0X1f,0X35,0X2c,0X07,0X3b,0X61,0X08,0Xd7,0X2d,0X98,0X10,0Xa3,0X09,0X14,0Xdf,0Xf4};
    // expand(test2,8);
}
unsigned char ffMultiply(unsigned char hex1, unsigned char hex2) {
    unsigned char resultArray[8]; 
    unsigned char returnValue = 0x00;
    unsigned char i = 0x01;
    int j = 1;
    resultArray[0] = hex1;
    while (j < 8) {
        resultArray[j] = xtime(resultArray[j-1]);
        j += 1;
    }
    j = 0;
    while (j <= 8) {
        if (i & hex2) {
            returnValue = ffAdd(returnValue,resultArray[j]);
        }
        i = i * 0x02;
        j += 1;
    }
    return returnValue;
}

unsigned char xtime(unsigned char hex1) {
    if (hex1 & 0x80) {
        return (hex1 * 0x02) ^ 0x1b;
    }
    else {
        return (hex1 * 0x02);
    }


}

unsigned char ffAdd(unsigned char hex1,unsigned char hex2) { 
    return hex1 ^ hex2;
}

void mixColumns(struct state * state) {
    unsigned char newMatrix [4][4];
    for (int c = 0; c < 4; c++){
        //s0,c = ({02} · s0,c,) + ({03} · s1,c) + s2c, + s3c
        newMatrix [0][c] = ffAdd(ffAdd(ffAdd( ffMultiply(0x02, state->state[0][c]), ffMultiply(0x03, state->state[1][c])), state->state[2][c]), state->state[3][c]); 
        newMatrix [1][c] = ffAdd(ffAdd(ffAdd( state->state[0][c], ffMultiply(0x02, state->state[1][c])), ffMultiply(0x03, state->state[2][c])), state->state[3][c]);
        newMatrix [2][c] = ffAdd(ffAdd(ffAdd( state->state[0][c], state->state[1][c]), ffMultiply(0x02, state->state[2][c])), ffMultiply(0x03,state->state[3][c]));
        newMatrix [3][c] = ffAdd(ffAdd(ffAdd( ffMultiply(0x03, state->state[0][c]), state->state[1][c]), state->state[2][c]), ffMultiply(0x02,state->state[3][c]));
    }
    changeState(state,newMatrix);
}
void subBytes(struct state * state) {
    unsigned char leftBit;
    unsigned char rightBit;
    unsigned char newMatrix [4][4];
    for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            leftBit = (state->state[r][c] & 0xf0) >> 4;
            rightBit = state->state[r][c] & 0x0f;
            state->state[r][c] = sBox[leftBit][rightBit];
        }
    }    
}
void shiftRows(struct state * state) {
    unsigned char newMatrix [4][4];
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newMatrix [i][j] = state->state[i][(j+i)%4];
        }
    }
    changeState(state,newMatrix);
}
void addRoundKey(struct state * state,struct state * key) {
    unsigned char newMatrix [4][4];
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newMatrix [i][j] = ffAdd(state->state[i][j],key->state[i][j]);
        }
    }
    changeState(state,newMatrix);
}
void rotWord(unsigned char * word) {
    unsigned char firstHex =  word[0];
    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = firstHex;
}
void subWord(unsigned char * word) {
    unsigned char leftBit;
    unsigned char rightBit;
    for (int i = 0; i < 4; i++) {
        leftBit = (word[i] & 0xf0) >> 4;
        rightBit = word[i] & 0x0f;
        word[i] = sBox[leftBit][rightBit];
    }
}
struct keyStuct* expand(unsigned char * words, int nk, struct keyStuct* key){
    int endNumber = nk == 4 ? 43 : 51;
    if(nk == 8) {
        endNumber = 59;
    }
    unsigned char currentWord[4];
    unsigned char RCON = 0x01; 
    unsigned char changedWord[4];
    int i = 0;
    for(i = 0; i < nk; i++) {
        for(int j = 0; j < 4; j++){
            key->key[i][j]= words[(i * 4 + j)];
        }
        // for (int r = 0; r<4;r++){
        //     printf("%x, ",key->key[i][r]);
        // }
        // printf("\n");
    }
    // printf("\n");
    for(int i = nk-1; i < endNumber; i++){
        memcpy(currentWord,key->key[i],4);
        if ((i + 1) % nk == 0) {
            rotWord(currentWord);
            subWord(currentWord);
            currentWord[0] = currentWord[0] ^ RCON;
            RCON = xtime(RCON);
        }
        if (nk == 8 && ((i-3) % nk) == 0) {
            memcpy(changedWord,key->key[i],4);
            subWord(changedWord);
        }
        // printf("%d:    ",i+1);
        for(int j = 0; j < 4; j++) {
            if (nk == 8 && ((i-3) % nk) == 0 ) {
                key->key[i+1][j] = changedWord[j] ^ key->key[i+1-nk][j]; 
            }
            else {
                key->key[i+1][j] = currentWord[j] ^ key->key[i+1-nk][j];  
            }
        }
        // for (int r = 0; r<4;r++){
            // printf("%x, ",key->key[i+1][r]);
        // }
        // printf("\n");
    }
    return key;
}
void createState(int start, struct keyStuct* key, struct state* state){
    for (int c = 0; c < 4; c++){
        for (int r = 0; r < 4; r++){ 
            state->state[r][c] = key->key[c+start][r];
        }
    }
}
void invShiftRows(struct state * state) {
    unsigned char newMatrix [4][4] = {
        {state->state[0][0], state->state[0][1], state->state[0][2], state->state[0][3]},
        {state->state[1][3], state->state[1][0], state->state[1][1], state->state[1][2]},
        {state->state[2][2], state->state[2][3], state->state[2][0], state->state[2][1]},
        {state->state[3][1], state->state[3][2], state->state[3][3], state->state[3][0]},
    };
    changeState(state,newMatrix);
}
void invSubBytes(struct state * state) {
    unsigned char leftBit;
    unsigned char rightBit;
    unsigned char newMatrix [4][4];
    for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            leftBit = (state->state[r][c] & 0xf0) >> 4;
            rightBit = state->state[r][c] & 0x0f;
            state->state[r][c] = InvSbox[leftBit][rightBit];
        }
    }    
}
void invMixColumns(struct state * state) {
    unsigned char newMatrix [4][4];
    for (int c = 0; c < 4; c++){
        //s0,c = ({02} · s0,c,) + ({03} · s1,c) + s2c, + s3c
        newMatrix [0][c] = ffAdd(ffAdd(ffAdd( ffMultiply(0x0e, state->state[0][c]), ffMultiply(0x0b, state->state[1][c])), ffMultiply(0x0d, state->state[2][c])), ffMultiply(0x09, state->state[3][c])); 
        newMatrix [1][c] = ffAdd(ffAdd(ffAdd( ffMultiply(0x09, state->state[0][c]), ffMultiply(0x0e, state->state[1][c])), ffMultiply(0x0b, state->state[2][c])), ffMultiply(0x0d, state->state[3][c]));
        newMatrix [2][c] = ffAdd(ffAdd(ffAdd( ffMultiply(0x0d, state->state[0][c]), ffMultiply(0x09, state->state[1][c])), ffMultiply(0x0e, state->state[2][c])), ffMultiply(0x0b, state->state[3][c]));
        newMatrix [3][c] = ffAdd(ffAdd(ffAdd( ffMultiply(0x0b, state->state[0][c]), ffMultiply(0x0d, state->state[1][c])), ffMultiply(0x09, state->state[2][c])), ffMultiply(0x0e, state->state[3][c]));
    }
    changeState(state,newMatrix);
}

void test(){
    if (ffAdd(0x57,0x83) == 0xd4 &&
        xtime(0x57) == 0xae &&
        xtime(0xae) == 0x47 &&
        xtime(0x47) == 0x8e &&
        xtime(0x8e) == 0x07 &&
        ffMultiply(0x57, 0x13) == 0xfe &&
        ffMultiply(0x05, 0x03) == 0x0F &&
        ffMultiply(0x02, 0x87) == 0x15 &&
        ffMultiply(0x70, 0x27) == 0xC9 &&
        ffMultiply(0xD4, 0x02) == 0xB3){
            struct state* testState = malloc(sizeof(struct state));
            struct state* state = malloc(sizeof(struct state));
            unsigned char a[4][4] = {  
                {0x19, 0xa0, 0x9a, 0xe9} ,   /*  initializers for row indexed by 0 */
                {0x3d, 0xf4, 0xc6, 0xf8},    /*  initializers for row indexed by 1 */
                {0xe3, 0xe2, 0x8d, 0x48},    /*  initializers for row indexed by 2 */
                {0xbe, 0x2b, 0x2a, 0x08}     /*  initializers for row indexed by 3 */
            };
            changeState(testState, a);
            subBytes(testState);
            // printState(testState);
            shiftRows(testState);
            // printState(testState);
            unsigned char k[4][4] = {  
                {0xa0, 0x88, 0x23, 0x2a} ,   /*  initializers for row indexed by 0 */
                {0xfa, 0x54, 0xa3, 0x6c},    /*  initializers for row indexed by 1 */
                {0xfe, 0x2c, 0x39, 0x76},    /*  initializers for row indexed by 2 */
                {0x17, 0xb1, 0x39, 0x05}     /*  initializers for row indexed by 3 */
            };
            changeState(state,k);
            // changeState(testState, c);
            mixColumns(testState);
            addRoundKey(testState,state);
            printState(testState);
            printf("Passed test!!\n");
            unsigned char word[4]= {0x09,0xcf,0x4f,0x3c}; 
            unsigned char changedWord [4]; 
            memcpy(changedWord, word, 4);
            rotWord(changedWord);
            subWord(changedWord);
            for (int i = 0; i<4;i++){
                printf("%x, ",changedWord[i]);
            }
            printf("\n");
        }
        else {
            printf("You are a failure!!\n");
        }
}
unsigned char cToH(char hex){
    switch (hex){
        case '0':
            return 0x0;
        case '1':
            return 0x1;
        case '2':
            return 0x2;
        case '3':
            return 0x3;
        case '4':
            return 0x4;
        case '5':
            return 0x5;
        case '6':
            return 0x6;
        case '7':
            return 0x7;
        case '8':
            return 0x8;
        case '9':
            return 0x9;
        case 'a':
            return 0xa;
        case 'b':
            return 0xb;
        case 'c':
            return 0xc;
        case 'd':
            return 0xd;
        case 'e':
            return 0xe;
        case 'f':
            return 0xf;
    }
    return 0x00;
}