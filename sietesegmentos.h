
#ifndef SIETESEGMENTOS_H
#define	SIETESEGMENTOS_H

#define DIR_segA   TRISCbits.TRISC0
#define DIR_segB   TRISCbits.TRISC1
#define DIR_segC   TRISCbits.TRISC2
#define DIR_segD   TRISCbits.TRISC3
#define DIR_segE   TRISCbits.TRISC4
#define DIR_segF   TRISCbits.TRISC5
#define DIR_segG   TRISCbits.TRISC6

#define segA  LATCbits.LATC0
#define segB  LATCbits.LATC1
#define segC  LATCbits.LATC2
#define segD  LATCbits.LATC3
#define segE  LATCbits.LATC4
#define segF  LATCbits.LATC5
#define segG  LATCbits.LATC6

#define DIR_segAdos   TRISDbits.TRISD0
#define DIR_segBdos   TRISDbits.TRISD1
#define DIR_segCdos   TRISDbits.TRISD2
#define DIR_segDdos   TRISDbits.TRISD3
#define DIR_segEdos   TRISDbits.TRISD4
#define DIR_segFdos   TRISDbits.TRISD5
#define DIR_segGdos   TRISDbits.TRISD6

#define segAdos  LATDbits.LATD0
#define segBdos  LATDbits.LATD1
#define segCdos  LATDbits.LATD2
#define segDdos  LATDbits.LATD3
#define segEdos  LATDbits.LATD4
#define segFdos  LATDbits.LATD5
#define segGdos  LATDbits.LATD6

#define OUT 0
#define IN  1

void display_init(void);
void display_cc(int dig);
void display_ccdos(int dig);

void display_init(void) {
    DIR_segA = OUT;
    DIR_segB = OUT;
    DIR_segC = OUT;
    DIR_segD = OUT;
    DIR_segE = OUT;
    DIR_segF = OUT;
    DIR_segG = OUT;

    DIR_segAdos = OUT;
    DIR_segBdos = OUT;
    DIR_segCdos = OUT;
    DIR_segDdos = OUT;
    DIR_segEdos = OUT;
    DIR_segFdos = OUT;
    DIR_segGdos = OUT;
    
    TRISC = 0x00;
    TRISD = 0x00;
}

void display_cc(int dig) {

    switch (dig) {
        case 0: 
            segA = 1;
            segB = 1;
            segC = 1;
            segD = 1;
            segE = 1;
            segF = 1;
            segG = 0;
            break;

        case 1: 
            segA = 0;
            segB = 1;
            segC = 1;
            segD = 0;
            segE = 0;
            segF = 0;
            segG = 0;
            break;

        case 2: 
            segA = 1;
            segB = 1;
            segC = 0;
            segD = 1;
            segE = 1;
            segF = 0;
            segG = 1;
            break;

        case 3: segA = 1;
            segB = 1;
            segC = 1;
            segD = 1;
            segE = 0;
            segF = 0;
            segG = 1;
            break;

        case 4: segA = 0;
            segB = 1;
            segC = 1;
            segD = 0;
            segE = 0;
            segF = 1;
            segG = 1;
            break;

        case 5: segA = 1;
            segB = 0;
            segC = 1;
            segD = 1;
            segE = 0;
            segF = 1;
            segG = 1;
            break;

        case 6: segA = 1;
            segB = 0;
            segC = 1;
            segD = 1;
            segE = 1;
            segF = 1;
            segG = 1;
            break;

        case 7: segA = 1;
            segB = 1;
            segC = 1;
            segD = 0;
            segE = 0;
            segF = 0;
            segG = 0;
            break;

        case 8: segA = 1;
            segB = 1;
            segC = 1;
            segD = 1;
            segE = 1;
            segF = 1;
            segG = 1;
            break;

        case 9: segA = 1;
            segB = 1;
            segC = 1;
            segD = 1;
            segE = 0;
            segF = 1;
            segG = 1;
            break;

    }
}

void display_ccdos(int digi){
    
    switch (digi) {
        case 0: 
            segAdos = 1;
            segBdos = 1;
            segCdos = 1;
            segDdos = 1;
            segEdos = 1;
            segFdos = 1;
            segGdos = 0;
            break;

        case 1: 
            segAdos = 0;
            segBdos = 1;
            segCdos = 1;
            segDdos = 0;
            segEdos = 0;
            segFdos = 0;
            segGdos = 0;
            break;

        case 2: 
            segAdos = 1;
            segBdos = 1;
            segCdos = 0;
            segDdos = 1;
            segEdos = 1;
            segFdos = 0;
            segGdos = 1;
            break;

        case 3: 
            segAdos = 1;
            segBdos = 1;
            segCdos = 1;
            segDdos = 1;
            segEdos = 0;
            segFdos = 0;
            segGdos = 1;
            break;

        case 4: 
            segAdos = 0;
            segBdos = 1;
            segCdos = 1;
            segDdos = 0;
            segEdos = 0;
            segFdos = 1;
            segGdos = 1;
            break;

        case 5: 
            segAdos = 1;
            segBdos = 0;
            segCdos = 1;
            segDdos = 1;
            segEdos = 0;
            segFdos = 1;
            segGdos = 1;
            break;

        case 6: 
            segAdos = 1;
            segBdos = 0;
            segCdos = 1;
            segDdos = 1;
            segEdos = 1;
            segFdos = 1;
            segGdos = 1;
            break;

        case 7: 
            segAdos = 1;
            segBdos = 1;
            segCdos = 1;
            segDdos = 0;
            segEdos = 0;
            segFdos = 0;
            segGdos = 0;
            break;

        case 8: 
            segAdos = 1;
            segBdos = 1;
            segCdos = 1;
            segDdos = 1;
            segEdos = 1;
            segFdos = 1;
            segGdos = 1;
            break;

        case 9: 
            segAdos = 1;
            segBdos = 1;
            segCdos = 1;
            segDdos = 1;
            segEdos = 0;
            segFdos = 1;
            segGdos = 1;
            break;

    }
    
}
#endif	/* SIETESEGMENTOS_H */

