#include <xc.h>
#include <pic16f1939.h>
#include "sietesegmentos.h"
#include "config.h"
#define display3 LATAbits.LATA0
#define display2 LATAbits.LATA1
#define display1 LATAbits.LATA2
#define time 100

const int tmultiplex = 1;

char marca = 0;

int val_sec = 0, contador = 0, contadordos = 0, led = 0, Nibble1 = 0, Nibble2 = 0,
        unidad = 0, decena = 0, centena = 0, numero = 0, residuo = 0;

void PUNTO1(void) {
    TRISD = 0x00;

    LATD = 0b00000001;
    __delay_ms(time);

    LATD = 0b00000010;
    __delay_ms(time);

    LATD = 0b00000100;
    __delay_ms(time);

    LATD = 0b00001000;
    __delay_ms(time);

    LATD = 0b00010000;
    __delay_ms(time);

    LATD = 0b00100000;
    __delay_ms(time);

    LATD = 0b01000000;
    __delay_ms(time);

    LATD = 0b10000000;
    __delay_ms(time);

    LATD = 0b01000000;
    __delay_ms(time);

    LATD = 0b00100000;
    __delay_ms(time);

    LATD = 0b00010000;
    __delay_ms(time);

    LATD = 0b00001000;
    __delay_ms(time);

    LATD = 0b00000100;
    __delay_ms(time);

    LATD = 0b00000010;
    __delay_ms(time);

    LATD = 0b00000001;
    __delay_ms(time);
}

void PUNTO2(void) {
    TRISD = 0x00;
    LATD = 0x00;
    char i = 0;
    for (i = 0; i < 8; i++) {
        LATD |= (1 << i);
        LATD &= ~(1 << (i - 1));
        __delay_ms(time);

    }
    for (i = 8; i > 0; i--) {

        LATD |= (1 << i);
        LATD &= ~(1 << (i + 1));
        __delay_ms(time);
    }
}
void PUNTO3(void) {

    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSA0 = 0;
    TRISAbits.TRISA1 = 1;
    ANSELAbits.ANSA1 = 0;
    TRISAbits.TRISA2 = 0;
    ANSELAbits.ANSA2 = 0;
    TRISAbits.TRISA3 = 0;
    ANSELAbits.ANSA3 = 0;
    if ((PORTAbits.RA0 == 1 && PORTAbits.RA1 == 1) || (PORTAbits.RA0 == 0 && PORTAbits.RA1 == 0)) {
        LATAbits.LATA2 = 0;
        LATAbits.LATA3 = 0;
    }
    if (PORTAbits.RA0 == 0 && PORTAbits.RA1 == 1) {
        LATAbits.LATA2 = 0;
        LATAbits.LATA3 = 1;
    }
    if (PORTAbits.RA0 == 1 && PORTAbits.RA1 == 0) {

        LATAbits.LATA2 = 1;
        LATAbits.LATA3 = 0;
    }

}

void PUNTO4(void) {

    ANSELB = 0x00;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB7 = 0;

    while (1) {

        if (PORTBbits.RB0 == 0) {
            while (PORTBbits.RB0 == 0);
            marca++;
        }
        if (marca == 3) {
            LATBbits.LATB7 ^= 1;
            marca = 0;
        }
        __delay_ms(100);

    }
}

void PUNTO5(void) {

    TRISC = 0x00;
    ANSELB = 0x00;
    TRISB = 0xFF;

    val_sec = (PORTB & 0xF0); 

    switch (val_sec) {
        case 1: Secuencia01();
            break;
        case 2: Secuencia02();
            break;
        case 3: Secuencia03();
            break;
        case 4: Secuencia04();
            break;
        case 5: Secuencia05();
            break;
        case 6: Secuencia06();
            break;
        case 7: Secuencia07();
            break;
        case 8: Secuencia08();
            break;
        case 9: Secuencia09();
            break;
        default:
            break;
    }
    __delay_ms(100);

}

void PUNTO6 (void) {
    TRISA = 0x00;
    ANSELA = 0x00;

    LATAbits.LATA0 = 0;
    LATAbits.LATA1 = 1;
    LATAbits.LATA2 = 1;
    LATAbits.LATA3 = 0;
    LATAbits.LATA4 = 1;
    LATAbits.LATA5 = 0;

    __delay_ms(2000);

    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 0;

    LATAbits.LATA2 = 0;
    LATAbits.LATA3 = 1;

    LATAbits.LATA4 = 1;
    LATAbits.LATA5 = 0;

    __delay_ms(2000);

    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 0;

    LATAbits.LATA2 = 1;
    LATAbits.LATA3 = 0;

    LATAbits.LATA4 = 0;
    LATAbits.LATA5 = 1;

    __delay_ms(2000);

}

void PUNTO7 (void) {
    ANSELD = 0x00;
    ANSELB = 0x00;
    TRISB = 0x0F;

    display_init();

    if (PORTBbits.RB0 == 1 && PORTBbits.RB1 == 0) {
        display_cc(contador);
        display_ccdos(contadordos);
        contador++;
        if (contador > 9) {
            contador = 0;
            contadordos++;
        }

        if (contadordos > 9) {
            contador = 9;
            contadordos = 9;
        }

        if (contadordos == 9 && contador == 9) {
            display_cc(9);
            display_ccdos(9);
        }
    }

    if (PORTBbits.RB0 == 0 && PORTBbits.RB1 == 1) {
        display_cc(contador);
        display_ccdos(contadordos);
        contador--;

        if (contador < 0) {
            contador = 9;
            contadordos--;
        }
        if (contadordos < 0) {
            contador = 0;
            contadordos = 0;
        }
        if (contadordos == 0 && contador == 0) {
            display_cc(0);
            display_ccdos(0);
        }
    }

    if (PORTBbits.RB0 == 1 && PORTBbits.RB1 == 1) {
        display_cc(contador);
        display_ccdos(contadordos);
    }
    if (PORTBbits.RB0 == 0 && PORTBbits.RB1 == 0 && PORTBbits.RB2) {

        display_cc(contador);
        display_ccdos(contadordos);

        contador = contador + 2;

        if (contador > 9) {
            contadordos++;
            if (contador == 10) {
                contador = 0;
            }
            if (contador == 11) {
                contador = 1;
            }
        }
        if (contadordos > 9) {
            contador = 9;
            contadordos = 9;
        }
        if (contadordos == 9 && contador >= 9) {
            display_cc(9);
            display_ccdos(9);
        }
    }
    if (PORTBbits.RB0 == 0 && PORTBbits.RB1 == 0 && PORTBbits.RB3) {
        display_cc(contador);
        display_ccdos(contadordos);
        contador = contador - 2;

        if (contador < 0) {
            contadordos--;
            if (contador == -1) {
                contador = 9;
            }
            if (contador == -2) {
                contador = 8;
            }
        }
        if (contadordos < 0) {
            contador = 0;
            contadordos = 0;
        }

        if (contadordos == 0 && contador == 0) {
            display_cc(0);
            display_ccdos(0);
        }
    }

    __delay_ms(500);
}
void PUNTO8 (void) {

}

void PUNTO9 (void) {
#define dir_btn1 TRISCbits.TRISC0
#define dir_btn2 TRISCbits.TRISC0
#define dir_btn3 TRISCbits.TRISC2
#define dir_btn4 TRISCbits.TRISC3
#define btn1 PORTCbits.RC0
#define btn2 PORTCbits.RC1
#define btn3 PORTCbits.RC2
#define btn4 PORTCbits.RC3
#define dir_led1 TRISDbits.TRISD0
#define dir_led2 TRISDbits.TRISD1
#define dir_led3 TRISDbits.TRISD2
#define led1 LATDbits.LATD0
#define led2 LATDbits.LATD1
#define led3 LATDbits.LATD2    
    ANSELD = 0x00;
    dir_btn1 = 1;
    dir_btn2 = 1;
    dir_btn3 = 1;
    dir_btn4 = 1;
    dir_led1 = 0;
    dir_led2 = 0;
    dir_led3 = 0;
    led1 = 0;
    led2 = 0;
    led3 = 0;

    while (1) {
        if (btn1 == 0 && led1 == 0 && led2 == 0 && led3 == 0) {
            led1 = 1;
            led2 = 0;
            led3 = 0;
        }
        if (btn2 == 0 && led1 == 0 && led2 == 0 && led3 == 0) {
            led1 = 0;
            led2 = 1;
            led3 = 0;
        }
        if (btn3 == 0 && led1 == 0 && led2 == 0 && led3 == 0) {
            led1 = 0;
            led2 = 0;
            led3 = 1;
        }
        if (btn4 == 0) {
            led1 = 0;
            led2 = 0;
            led3 = 0;
        }
    }
}

void PUNTO10 (void) {

    TRISC = 0x00;
    TRISD = 0x0F;
    ANSELD = 0x00;
    if (PORTDbits.RD0 == 0) {
        LATCbits.LATC0 = ~PORTCbits.RC0;
        __delay_ms(100);
    }
    if (PORTDbits.RD1 == 0) {
        LATCbits.LATC0 = ~PORTCbits.RC0;
        __delay_ms(100);
    }

}

void PUNTO11 (void) {

    TRISD = 0x00;
    TRISB = 0x0F;
    TRISC = 0x00;
    ANSELB = 0x00;
    ANSELD = 0x00;
    OPTION_REGbits.nWPUEN = 0; 
    WPUB = 0x0F; 
    if (PORTBbits.RB2 == 0) {
        led++;
        if (led > 8) {
            led = 8;
        }
        switch (led) {
            case 1:
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 0;
                segB = 1;
                segC = 1;
                segD = 0;
                segE = 0;
                segF = 0;
                segG = 0;
                break;
            case 2:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 1;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 1;
                segC = 0;
                segD = 1;
                segE = 1;
                segF = 0;
                segG = 1;
                break;
            case 3:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 1;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 1;
                segC = 1;
                segD = 1;
                segE = 0;
                segF = 0;
                segG = 1;
                break;
            case 4:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 1;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 0;
                segB = 1;
                segC = 1;
                segD = 0;
                segE = 0;
                segF = 1;
                segG = 1;
                break;
            case 5:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 1;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 0;
                segC = 1;
                segD = 1;
                segE = 0;
                segF = 1;
                segG = 1;
                break;
            case 6:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 1;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 0;
                segC = 1;
                segD = 1;
                segE = 1;
                segF = 1;
                segG = 1;
                break;
            case 7:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 1;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 1;
                segC = 1;
                segD = 0;
                segE = 0;
                segF = 0;
                segG = 0;
                break;
            case 8:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 1;
                segA = 1;
                segB = 1;
                segC = 1;
                segD = 1;
                segE = 1;
                segF = 1;
                segG = 1;
                break;
        }

    }

    if (PORTBbits.RB3 == 0) {

        led--;
        if (led < 0) {
            led = 1;
        }
        switch (led) {
            case 1:
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 0;
                segB = 1;
                segC = 1;
                segD = 0;
                segE = 0;
                segF = 0;
                segG = 0;
                break;
            case 2:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 1;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 1;
                segC = 0;
                segD = 1;
                segE = 1;
                segF = 0;
                segG = 1;
                break;
            case 3:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 1;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 1;
                segC = 1;
                segD = 1;
                segE = 0;
                segF = 0;
                segG = 1;
                break;
            case 4:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 1;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 0;
                segB = 1;
                segC = 1;
                segD = 0;
                segE = 0;
                segF = 1;
                segG = 1;
                break;
            case 5:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 1;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 0;
                segC = 1;
                segD = 1;
                segE = 0;
                segF = 1;
                segG = 1;
                break;
            case 6:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 1;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 0;
                segC = 1;
                segD = 1;
                segE = 1;
                segF = 1;
                segG = 1;
                break;
            case 7:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 1;
                LATDbits.LATD7 = 0;
                segA = 1;
                segB = 1;
                segC = 1;
                segD = 0;
                segE = 0;
                segF = 0;
                segG = 0;
                break;
            case 8:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                LATDbits.LATD3 = 0;
                LATDbits.LATD4 = 0;
                LATDbits.LATD5 = 0;
                LATDbits.LATD6 = 0;
                LATDbits.LATD7 = 1;
                segA = 1;
                segB = 1;
                segC = 1;
                segD = 1;
                segE = 1;
                segF = 1;
                segG = 1;
                break;
        }

    }

    if (PORTBbits.RB0 == 0) {

        switch (led) {
            case 1:
                LATDbits.LATD0 = 0;
                break;
            case 2:
                LATDbits.LATD1 = 0;
                break;
            case 3:
                LATDbits.LATD2 = 0;
                break;
            case 4:
                LATDbits.LATD3 = 0;
                break;
            case 5:
                LATDbits.LATD4 = 0;
                break;
            case 6:
                LATDbits.LATD5 = 0;
                break;
            case 7:
                LATDbits.LATD6 = 0;
                break;
            case 8:
                LATDbits.LATD7 = 0;
                break;
        }

    }

    if (PORTBbits.RB1 == 0) {

        switch (led) {
            case 1:
                LATDbits.LATD0 = 1;
                break;
            case 2:
                LATDbits.LATD1 = 1;
                break;
            case 3:
                LATDbits.LATD2 = 1;
                break;
            case 4:
                LATDbits.LATD3 = 1;
                break;
            case 5:
                LATDbits.LATD4 = 1;
                break;
            case 6:
                LATDbits.LATD5 = 1;
                break;
            case 7:
                LATDbits.LATD6 = 1;
                break;
            case 8:
                LATDbits.LATD7 = 1;
                break;
        }

    }

    __delay_ms(10);
}

void PUNTO 12 Y 13 (void) {
    


}

void main(void) {

    while (1) {
     
    }
    return;
}
