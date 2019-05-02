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
int count = 0;
void timer0()
{
   count = 1;
   set_timer0(15536);
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
    int mos=0,repe=0;
    int i,j,k;
    printf("\fIngresa los datos de la forma [palabra 3-10][espacio][numero escrito]:");
    while(TRUE)
    {
        
        if(kbhit())
        {
            cadena[i] = getch();
            if(cadena[i]>=97 && cadena<=122 || cadena[i]==13 || cadena[i]==32)
            {
                printf("%c",cadena[i]);
                if(cadena[i] == 32)
                   mostrar = 1;
            }
            i++;
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
            numero[k] = cadena[indice];
            indice++;
            k++;
         }
         switch(numero)
         {
            case "cero":
              printf("Problema al mostrar la palabra");
                 break;
            case "uno":
                 for(mos;mos<=j;mos++)
                 {
                 printf("%c",palabra[mos]);
                 }
                 printf("\n");
                 output_A0(count);
                 count = 0;
                 break;
            case "dos":
                 for(repe; repe<2; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
            case "tres":
                 for(repe; repe<3; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
            case "cuatro":
                 for(repe; repe<4; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
            case "cinco":
               for(repe; repe<5; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
           case "seis":
              for(repe; repe<6; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
            case "siete":
              for(repe; repe<7; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
            case "ocho":
              for(repe; repe<8; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
            case "nueve":
              for(repe; repe<9; repe++)
                 {
                     for(mos;mos<=j;mos++)
                     {
                         printf("%c",palabra[mos]);
                     }
                     printf("\n");
                     output_A0(count);
                     count = 0;
                 }
                 break;
         }
    }
}
