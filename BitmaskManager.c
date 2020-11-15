/*
* Ethan Trott
* Assignment 4 - COS 235
* a utility for managing bitsets using bitmasks
*/

#include <stdio.h>

// returns 0 if position bitpos in bitset is not set, 1 if it is
int ISSET(unsigned char bitset, int bitpos){
    unsigned char mask = 1 << bitpos;
    unsigned char result = bitset & mask;

    if (result > 0)
        return 1;
    else
        return 0;

}

// sets bit in position bitpos to 1
void ADDBIT(unsigned char *bitset, int bitpos){
    unsigned char mask = 1 << bitpos;
    *bitset = *bitset | mask;
}

// sets bit in position bitpos to 0
void DELBIT(unsigned char *bitset, int bitpos){
    unsigned char mask = 1 << bitpos;
    mask = ~mask;
    *bitset = *bitset & mask;
}

// prints value of all bits in bitset
void PRINTBITS(unsigned char bitset){
    for (int i=0; i<8; i++){
        if (ISSET(bitset, i))
            printf("The bit in position %d is 1.\n", i);
        else
            printf("The bit in position %d is 0.\n", i);
    }
}

int main(){
    while(1) { 
        // initialize variables
        int request = -2;

        unsigned char bitset;
        int bitpos = -1;

        // get a valid function code from user
        while (request < -1 || request > 3){
            printf("\nPlease enter function (0 = IS, 1 = ADD, 2 = DEL, 3 = PRINT, or -1 to quit) --> ");
            scanf("%d", &request);
        }

        // we're done if -1 is entered
        if (request == -1)
            break;

        // get the bitset from user
        unsigned int temp = -1;
        while (temp < 0 || temp > 255){
            printf("Please enter your bitset using either 0x$$ or $$ where $ is a digit in base 16 (0 - F) --> ") ;
            scanf("%x", &temp);
        }
        bitset = (unsigned char) temp;

        // get the bit position from user (if necessary)
        if (request != 3){
            while (bitpos < 0 || bitpos > 7){
                printf("Please enter bit position (0-7) --> ");
                scanf("%d", &bitpos);
            }
        }

        // execute the correct function given the request and output result
        switch (request){
            case 0:
                if (ISSET(bitset, bitpos))
                    printf("The bit in position %d of %p is SET\n", bitpos, bitset);
                else
                    printf("The bit in position %d of %p is NOT SET\n", bitpos, bitset);

                break;
            case 1:
                ADDBIT(&bitset, bitpos);
                printf("Old bitset was %p. New bitset is %p.\n", temp, bitset);
                break;
            case 2:
                DELBIT(&bitset, bitpos);
                printf("Old bitset was %p. New bitset is %p.\n", temp, bitset);
                break;
            case 3:
                PRINTBITS(bitset);
                break;
        }
    }
    return 0;
}