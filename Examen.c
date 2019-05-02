//Examen
#include <18F4620.h>
//#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOFCMEN                  //Fail-safe clock monitor disabled
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOPBADEN                 //PORTB pins are configured as digital I/O on RESET
#FUSES NOLPT1OSC                //Timer1 configured for higher power operation
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)

#use delay(crystal=16000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

#int_timer0

void timer0
{

}

unsigned char cadena[20];
char palabra[10], numero[9];
int indice = 0;
int mostrar = 0;
int num = 0;

void main()
{
    setup_oscillator(OSC_16MHZ);
    setup_timer_0(rtcc_internal|rtcc_div_8);
    set_timer0(15536);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
    set_tris_a(0x00); 
    int i,j,k;
    int mos=0;
    printf("\fIngresa los datos de la forma [palabra 3-10][espacio][numero escrito]:");
    while(TRUE)
    {
        
        if(kbhit())
        {
            cadena[i] = getch();
            if(cadena[i] == 32)
                mostrar = 1;
        }
        if(mostrar==1)
        {
            while(cadena[indice] != 32)
            {
                palabra[j] = cadena[indice];
                indice++;
                j++;
            }
         }
         indice++;
         while(cadena[indice] != 13)
         {
            numero[k] = cadena[indice]
            indice++;
            k++;
         }
         if(numero == 'uno')
         {
             for(mos;mos<=j;mos++)
             {
                 printf("%c",palabra[mos]);
             }
             printf("\n");
         }         
    }
}
