#include <ti/devices/msp432p4xx/inc/msp.h>

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"
#include "Images/images.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// define button
#define BUTTON_PORT5 P5
#define BUTTON_BIT1 BIT1
#define BUTTON_PORT3 P3
#define BUTTON_BIT5 BIT5

// Define note length frequencies
#define half 60000
#define oneQuarter 150000
#define quarter 30000
#define eighth 15000
#define sixteenth 7500
#define eigth 16000
#define threeQuarter 90000
#define threeEighths 45000
#define fiveEighths 45000
#define resting 15000
#define one 120000
#define threeHalf 180000

// define note frequencies
#define rest    1
#define c3      130
#define e3      164
#define g3      196
#define gS3     207
#define a3      220
#define b3      246
#define c4      261
#define f4      349
#define e4      329
#define g4      392
#define gS4     415
#define g5      784
#define a4      440
#define b4      493
#define d4      294
#define d3      147
#define c5      523
#define d5      587
#define dS5     622
#define e5      659
#define f5      698
#define fs5     740
#define e6      1318
#define e7      2637
//#define oneLength 44
#define threeLength 43 //twinkle

#define twoLength 104 //banner
#define oneLength 145 //piano


/*
 
  anthem

*/

const unsigned songOneNotes[oneLength] = {rest,g4,g4,g4,g4,f4,e4,f4,e4,c4,
                                            rest,rest,c4,c4,c4,c4,c4,c4,d4,
                                            d4, rest, g4,g4,g4,g4,f4,e4,
                                            f4,e4,c4,a3,a3,a3,f4,f4,
                                            f4,e4,c4,c4,rest,rest,rest,g5,g5,
                                            g5,g5,g5,g5,f5,e5,f5,e5,c5,
                                            c5,c5,c5,c5,c5,d5,d5,
                                            d5,rest,e5,f5,g5,g5,g5,
                                            g5,f5,e5,f5,e5,e5,f5,c5,
                                            c5,c5,e5,f5,e5,c5,c5,
                                            a4,a4,a4,b4,c5,b4,a4,rest,
                                            rest,rest,a4,a4,b4,c5,b4,a4,
                                            g4, rest, rest, rest, g5,g5,g5,
                                            g5,f5,e5,f5,e5,c5,a4,c5,c5,
                                            c5,d5,d5,e5,f5,g5,g5,g5,
                                            g5,f5,f5,f5,e5,c5,rest,rest,g4,
                                            a4,c5,c5,f5,e5,c5,c5,
                                            rest,rest,rest//, g4 //,rest,rest

};

unsigned songOneBeats[oneLength] = {rest,quarter, half,quarter,quarter,threeEighths,eighth,eighth,eighth,half,
                                            quarter,quarter, quarter, threeEighths,eighth,quarter,quarter,quarter,quarter,
                                            one,quarter,eighth,eighth,quarter,one, eighth,eighth,
                                            quarter,quarter,threeQuarter,eighth,eighth,half, eighth,eighth,
                                            quarter,quarter,quarter,threeQuarter,half,half,quarter,quarter,quarter,
                                            quarter,quarter,quarter,quarter,quarter,quarter,eighth,eighth,one,
                                            quarter,quarter,quarter,quarter, half,eighth,eighth,one,quarter,eighth,eighth,quarter,half,eighth
                                            , half, eighth,eighth,quarter,quarter,quarter,half,quarter,
                                            quarter, half, eighth,half,eighth,quarter,threeHalf,
                                            half,quarter,half,eighth,eighth,quarter,half,one,
                                            quarter,quarter,quarter,half,eighth,eighth,threeHalf,quarter,
                                            threeHalf, quarter,quarter,quarter,quarter, half, eighth,
                                            quarter,half,eighth,quarter,quarter, threeHalf, quarter,half,eighth,
                                            half, quarter, threeHalf, quarter,quarter,quarter,half,eighth,
                                            quarter,half,eighth,eighth,eighth,half, quarter,quarter,quarter,
                                            quarter,quarter,quarter,quarter,quarter,quarter, threeHalf,
                                            quarter,quarter,quarter//,quarter //,quarter,quarter
};


const unsigned songTwoNotes[twoLength] = {g5,e4,c4,e4,g4,c5,e6,d5,c5,e4,f4,g4,g4,g4,e5, d5,c5, b4,a4,b4,c5,c5,g4,e4,c4,g4,e4,c4,e4,g4,c5,e5,d4,c4,e4,f4,g4,g4,g4,e5,d4,
                                          c4,b4,a4,b4,c4,c4,g4,e4,c4,e5,e5,e5,f5,g5,g5,f5,e5,d4,e5,f5,
                                          f5,f5,e5,d5,c5,b4,a4,b4,c5,e4,f4
                                          ,g4,g4,c5,c5,c5,b4,a4,a4,a4,
                                          d5,f5,e5,d5,c5,c5,b4,g4,g4,c5,d5,e5,f5,
                                          g5,c5,d5,e5,f5,d5,c5,
                                          rest};

const unsigned songTwoBeats[twoLength] = {threeEighths,rest, quarter,quarter,quarter,half, quarter,quarter, quarter, quarter,quarter,half,quarter,quarter,threeEighths,eighth,quarter,half,quarter,
                                        quarter,quarter, quarter,quarter,quarter,quarter,quarter,quarter,quarter,quarter,quarter,half,quarter,quarter,quarter,quarter,
                                        quarter,half,quarter,quarter,threeEighths,eighth,quarter,half,quarter,quarter,quarter,quarter,quarter,quarter,quarter,quarter,
                                        quarter,quarter,quarter,quarter,half,quarter,quarter,quarter,quarter,quarter,
                                        half,quarter,threeEighths,eighth,quarter,half,quarter,quarter,quarter,quarter,quarter
                                        ,half,quarter,quarter,quarter, eighth, eighth,quarter,quarter, quarter,quarter,
                                        quarter,threeEighths,rest,threeEighths,rest,threeQuarter,quarter,quarter,quarter,fiveEighths, eighth, quarter,quarter,
                                        threeEighths, quarter,quarter, half, half, quarter, oneQuarter
                                        ,quarter};


unsigned songThreeNotes[threeLength] = {c4,c4,g4,g4,a4,a4,g4, f5,f5,e5,e5,d5,d5,c5,g4,g4,f5,f5,e5,e5,d5,g4,g4,f5,f5,e5,e5,d5,c5,c5,g4,g4,a4,a4,g4,f5,f5,e5,e5,d5,d5,c5,rest};
const unsigned songThreeBeats[threeLength] = {quarter,quarter, quarter, quarter, quarter, quarter, half, quarter, quarter, quarter,quarter, quarter,
                                          quarter, half, quarter, quarter, quarter,quarter, quarter, quarter, half, quarter,quarter, quarter,quarter,quarter,
                                          quarter, half, quarter, quarter, quarter, quarter, quarter, quarter, half, quarter, quarter, quarter, quarter,
                                          quarter,quarter,half,quarter};


#define DEBOUNCE_COUNT 2000

volatile unsigned int debounce_counter;
const char *lyrics[34] = {"It's", "nine", "o", "clock", "on","a", "Sat-","ur","day",
                          "wait", "wait", "the", "reg","u","lar","crowd","shuf","fles",
                          "innnnn", "wait", "There's","an", "old", "mannnnn","sit-","ting",
                          "next", "to", "meeeeeee", "mak","in","love","to","his"
};
const char *anthem[103] = {"Oh__", "say","can","you", "see","by","the","dawn's","ear","ly",
                          "light,","what","so","proud","ly","we","hailed","at","the","twi","light's","last",
                          "gleam","ing;","whose","broad","stripes","and","bright","stars,","through","the","per","il","ous",
                          "fight", "o're","the","ram","parts","we","watched,","were","so","gal","lant","ly",
                          "stream", "ing","and","the","rock","ets'","red","glare,","the","bombs","burst","ing","in",
                          "air","gave","proof","through","the","night","that","our","flag","was","still",
                          "there.","Oh","say","does","thatttt","star","span","gled",
                          "ban","ner","yet","waveeeee","or","the","land","of","the",
                          "freeeeeee","and","the","home","of","the","brave",
};

const char *twinkle[42] = {"Twin","kle","twin","kle","lit","le","star","how","I","won","der",
                           "what","you","are","up","a","bove","the","world","so","high",
                           "like","a","dia","mond","in","the","sky!","Twin","kle","twin","kle",
                           "lit","le","star","how","I","won","der", "what","you","are"
};

//vector<string> first;
unsigned int counter = 0;
unsigned int loops = 0;
unsigned int fast_forward = 0;
// Initialize iterator of songs
volatile int iter = 0;
unsigned int selection_tracker = 0;
unsigned int selection_tracker2 = 0;
unsigned int page_number = 0;

volatile uint8_t  button_flag2 = 0;
volatile int song = 1;         //variable to detect what the next state is

unsigned int a;
unsigned int b =0;
unsigned int c =0;

void mapports();         // connect TACCR0 to P2.7 using PMAP
void init_timer(void);   // routine to setup the timer
void init_button(void);  // routine to setup the button
void delay_clock(unsigned int);
void play_sound(float);


Graphics_Context g_sContext;

void init_graphics(){
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_BLACK);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);


}

void main()
{

    WDT_A->CTL = WDTPW + WDTHOLD; // Stop watchdog timer
    mapports();
    init_timer();  // initialize timer
    init_button(); // initialize the button
    MAP_CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_3);
    SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;   // Specify that after an interrupt, the CPU wakes up
    __enable_interrupt();
    NVIC->ISER[1] = 1 << ((PORT5_IRQn) & 31); // enable P5 to send interrupt signals
    NVIC->ISER[1] = 1<< ((PORT3_IRQn) & 31);    // * enable P1 interrupt

    /*Green LED*/
    P2->DIR |= BIT4;   // Direction is output
    P2->OUT &= ~BIT4;  // LED off
    /*Blue LED*/
    P5->DIR |= BIT6;
    P5->OUT &= ~BIT6;
    /*Red LED*/
    P2->DIR |= BIT6;
    P2->OUT &= ~BIT6;

    P2->OUT |= BIT4;       // Green on
    P5->OUT &= ~BIT6;       // Blue off
    P2->OUT &= ~BIT6;       // Red off
    init_graphics();

    a = 0;

    // horizontal, vertical

    while(1)
    {
        if (page_number ==0){
            display_home (0, 0, 0 ,0,0);
        }


        else if (page_number == 1){
            display_home (1, 0, 0 ,0,0);
        }

        else {


        // Play Piano Man
        if (selection_tracker == 1) {

            if (selection_tracker2==1){
            if (iter < (oneLength - 1)) {


                play_sound(rest);
                delay_clock(250);
                iter++;
                //__delay_cycles(782000);
               play_sound(songOneNotes[iter]);
               delay_clock(songOneBeats[iter]/500); //13

               if (a < 35){
                           //delay_clock(250);
                           Graphics_drawStringCentered(&g_sContext,lyrics[a],AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);
                           a= a+1;
                          // play_sound(rest);
                           delay_clock(400);
                           GrClearDisplay(&g_sContext);
               }


               // delay_clock(songOneBeats[iter]/10);
            }
            // If played the last note in the song
            else if (iter == (oneLength - 1) && loops < 3) {
                //play_sound(rest);
                //delay_clock(250);
              //iter = 0;
                loops ++;
                iter =0;

            }
            else {
            }

        }
            else if (selection_tracker2==2){
            if (iter < (oneLength - 1)) {


                play_sound(rest);
                delay_clock(250);
                iter++;
                //__delay_cycles(782000);
               play_sound(songOneNotes[iter]);
               delay_clock(songOneBeats[iter]/13); //13




               // delay_clock(songOneBeats[iter]/10);
            }
            // If played the last note in the song
            else if (iter == (oneLength - 1) && loops < 3) {
                //play_sound(rest);
                //delay_clock(250);
              //iter = 0;
                loops ++;
                iter =0;

            }
            else {
            }

        }
            else if (selection_tracker2==3){
            if (iter < (oneLength - 1)) {

                //Graphics_drawStringCentered(&g_sContext,lyrics[a],AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);

                //GrClearDisplay(&g_sContext);
                play_sound(rest);
                delay_clock(250);
                iter++;
                //__delay_cycles(782000);
               play_sound(songOneNotes[iter]);
               delay_clock(songOneBeats[iter]/30); //13




               // delay_clock(songOneBeats[iter]/10);
            }
            // If played the last note in the song
            else if (iter == (oneLength - 1) && loops < 3) {

              //iter = 0;
                loops ++;
                iter =0;

            }
            else {
            }

        }
            else if (selection_tracker2==4){
            if (iter < (oneLength - 1)) {

                //Graphics_drawStringCentered(&g_sContext,lyrics[a],AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);

                //GrClearDisplay(&g_sContext);
                play_sound(rest);
                delay_clock(250);
                iter++;
                //__delay_cycles(782000);
               play_sound(songOneNotes[iter]);
               delay_clock(songOneBeats[iter]/5); //13




               // delay_clock(songOneBeats[iter]/10);
            }
            // If played the last note in the song
            else if (iter == (oneLength - 1) && loops < 3) {

              //iter = 0;
                loops ++;
                iter =0;

            }
            else {
            }

        }
        }
        // Play Anthem
        else if (selection_tracker == 2) {
            if (selection_tracker2 == 1){
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songTwoNotes[iter]);
                 delay_clock(songTwoBeats[iter]/500);
                 if (b < 105){
                             //delay_clock(250);
                             Graphics_drawStringCentered(&g_sContext,anthem[b],AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);
                             b= b+1;
                            // play_sound(rest);
                             delay_clock(400);
                             GrClearDisplay(&g_sContext);
                 }
            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
            else if (selection_tracker2 == 2){
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songTwoNotes[iter]);
                 delay_clock(songTwoBeats[iter]/10);

            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
            else if (selection_tracker2 == 3){
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songTwoNotes[iter]);
                 delay_clock(songTwoBeats[iter]/30);

            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
            else if (selection_tracker2 == 4){
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songTwoNotes[iter]);
                 delay_clock(songTwoBeats[iter]/5);

            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
        }

        //play twinkle twinkle
        else if (selection_tracker == 3) {

            if (selection_tracker2==1) {
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songThreeNotes[iter]);
                 delay_clock(songThreeBeats[iter]/500);
                 if (c < 43){
                             //delay_clock(250);
                             Graphics_drawStringCentered(&g_sContext,twinkle[c],AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);
                             c= c+1;
                            // play_sound(rest);
                             delay_clock(400);
                             GrClearDisplay(&g_sContext);
                 }
            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
            else if (selection_tracker2==2) {
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songThreeNotes[iter]);
                 delay_clock(songThreeBeats[iter]/10);

            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
            else if (selection_tracker2==3) {
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songThreeNotes[iter]);
                 delay_clock(songThreeBeats[iter]/30);

            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
            else if (selection_tracker2==4) {
            if (iter < (twoLength - 1)) {
                play_sound(rest);
                delay_clock(250);
                iter++;
                play_sound(songThreeNotes[iter]);
                 delay_clock(songThreeBeats[iter]/5);

            }
            // If played the last note in the song
            else if (iter == (twoLength - 1) && loops < 1) {
                loops ++;
                //iter =0;
                //play_sound(songTwoNotes[iter]);
                //delay_clock(eigth/10);
            }
        }
        }
        else if (selection_tracker == 4) {
            unsigned int r = rand()%(3-1+1)+1;
            unsigned int r2 = rand()%(3-1+1)+1;

            selection_tracker = r;
            selection_tracker2 = r2;
        }

    }
    }
}

/*
 * PORT MAPPING
 * We want the output from TA0.0 to go to P2.7
 * This can be done through the portmapper since P2.7 is reconfigurable
 *
 * In general, the portmap unit PMAP has to be unlocked to be configured
 * By default it can be unlocked only once after a hardware reset.
 *
 */


void delay_clock(unsigned int time )
{
    unsigned int i;
    for (i = 0; i<= time; i++)
       __delay_cycles(500); //Built-in function that suspends the execution for 500 cycles
}

void mapports(){
    PMAP->KEYID=PMAP_KEYID_VAL; // unlock PMAP
    P2MAP->PMAP_REGISTER7=PMAP_TA0CCR0A;  // map TA0CCR0 to P2.7 as primary module
    PMAP->KEYID=0;              // relock PMAP until next hard reset
}

/*
 * Sound Production System
 *
 * In this example, we simply run TA0 in up mode
 * (TA0R goes from 0 to TA0CCR0 and then back to 0)
 * And when we want the sound on, we activate output mode 4 (toggle),
 * which makes the CCR0 output signal toggle each time TA0R hits TA0CCR0's value.
 * Thus, the half-period of the tone is TACCR0+1 timer ticks.
 *
 * The timer clock source is SMCLK (3Mhz), prescaled by 1, then divided by 3.
 * Thus it is about 1MHz.
 * Note: possible prescale factors are 1,2,4,8.
 *       possible additional EX0 dividers are 1,2,3,4,5,6,7,8
 *
 */

void init_timer(){              // initialization and start of timer
    TIMER_A0->CTL |= TIMER_A_CTL_CLR ;// reset clock
    TIMER_A0->CTL =  TIMER_A_CTL_TASSEL_2  // clock source = SMCLK
                    +TIMER_A_CTL_ID_0      // clock prescale=1
                    +TIMER_A_CTL_MC_1;     // Up Mode
    TIMER_A0->EX0 = TIMER_A_EX0_TAIDEX_2;  // additional divisor=3

    TIMER_A0->CCTL[0]=TIMER_A_CCTLN_OUTMOD_4; // compare mode, output mode 4 (toggle)
    if (debounce_counter) {

        --debounce_counter==0;

    }
    play_sound(songOneNotes[iter]);
    delay_clock(songOneBeats[iter]/10000);

}


void play_sound(float note) {
    // play rest

    if (note == 1) {
        TIMER_A0->CCR[0] = note-1; // in up mode TAR=0... TACCRO-1
        P2->SEL0|=BIT7; // connect timer output to pin (select alternate function for pin)
        P2->DIR |=BIT7;

    }



 else {
        unsigned int N = (1/note) * 500000;
        TIMER_A0->CCR[0] = N-1; // in up mode TAR=0... TACCRO-1
        P2->SEL0|=BIT7; // connect timer output to pin (select alternate function for pin)
        P2->DIR |=BIT7; // output mode on P2.7 (direction output completes setting the function)

    }

}





/*
 * Button input System
 *
 * The Button toggles the state of the sound (on or off)
 * Action will be interrupt driven on a downgoing signal on the pin
 * no debouncing in this code, but MSP432P401R has glitch suppression which may help.
 */
void PORT4_IRQHandler(){

    // If Joystick button is pressed

    if (MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P4) & GPIO_PIN1){

        MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4,GPIO_PIN1); // reset the interrupt flag
        if (debounce_counter==0){ // has enough time elapsed?

                    debounce_counter=DEBOUNCE_COUNT;

        if(page_number == 0) {

                    if (selection_tracker ==4){
                        page_number = 2;
                        Graphics_clearDisplay(&g_sContext);

                    }
                    else {
                    page_number = 1;

                    Graphics_clearDisplay(&g_sContext);
                    }
                }


        else if (page_number == 1) {
            page_number = 2;

            Graphics_clearDisplay(&g_sContext);
        }


        else {
            page_number = 0;

            selection_tracker = 0;
            selection_tracker2 = 0;
          //  Delay();
            Graphics_clearDisplay(&g_sContext);

            iter = 0;
            play_sound(rest);
        }


}
}
    a= 0;
    b=0;
    c =0;
    debounce_counter =0;
    //page_number ++;
}
void init_button(){
// All GPIO's are already inputs if we are coming in after a reset
    BUTTON_PORT5->OUT |= BUTTON_BIT1; // pullup
    BUTTON_PORT5->REN |= BUTTON_BIT1; // enable resistor
    BUTTON_PORT5->IES |= BUTTON_BIT1; // set for 1->0 transition
    BUTTON_PORT5->IFG &= ~BUTTON_BIT1;// clear interrupt flag
    BUTTON_PORT5->IE  |= BUTTON_BIT1; // enable interrupt
    BUTTON_PORT3->OUT |= BUTTON_BIT5; // pullup
    BUTTON_PORT3->REN |= BUTTON_BIT5; // enable resistor
    BUTTON_PORT3->IES |= BUTTON_BIT5; // set for 1->0 transition
    BUTTON_PORT3->IFG &= ~BUTTON_BIT5;// clear interrupt flag
    BUTTON_PORT3->IE  |= BUTTON_BIT5; // enable interrupt
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4,GPIO_PIN1);

        MAP_GPIO_interruptEdgeSelect(GPIO_PORT_P4,GPIO_PIN1,GPIO_HIGH_TO_LOW_TRANSITION);

        MAP_GPIO_clearInterruptFlag(GPIO_PORT_P4,GPIO_PIN1);

        MAP_GPIO_registerInterrupt(GPIO_PORT_P4,PORT4_IRQHandler);

        MAP_GPIO_enableInterrupt(GPIO_PORT_P4,GPIO_PIN1);

}

// Interrupt for pause/play button
void PORT5_IRQHandler(){
// Good practice to check which of the 8 pins caused the interrupt.
// In general, we would take different actions for interrupts on different
// input pins, and this handler would be called for any of them.
// In this program, there should be only the one interrupt.
    if (BUTTON_PORT5->IFG & BUTTON_BIT1){

        if(page_number == 0) {

         }

        else {


        // check that it is the button interrupt flag
        BUTTON_PORT5->IFG &= ~BUTTON_BIT1; // clear the flag to allow for another interrupt later
        P2->OUT ^= BIT6;       // Red off
        // This handler changes the state of the timer CCTL0 control register!
        // Toggle OUTMOD between
        //    mode 0: output = constant value determined by CCTL0 bit 2, and
        //    mode 4: toggle, which when repeated produces a square wave.
        TIMER_A0->CCTL[0]^=TIMER_A_CCTLN_OUTMOD_4;
    }
    BUTTON_PORT5->IFG &= ~BUTTON_BIT1;

}
}


void PORT3_IRQHandler(){
// Good practice to check which of the 8 pins caused the interrupt.
// In general, we would take different actions for interrupts on different
// input pins, and this handler would be called for any of them.
// In this program, there should be only the one interrupt.
    if (BUTTON_PORT3->IFG & BUTTON_BIT5){ // check that it is the button interrupt flag




    if(page_number == 0) {
           //GrClearDisplay(&g_sContext);
           selection_tracker++;
           if (selection_tracker == 1){
            display_home (0, 1, 0 ,0,0);
            //display_home (page_number, 1, 0 ,0,0);
           }
           else if (selection_tracker==2 ){
               display_home (0, 0, 1 ,0,0);
               //selection_tracker++;
           }
           else if (selection_tracker==3 ){
               display_home (0, 0, 0 ,1,0);
               //selection_tracker=0;
           }
           else if (selection_tracker == 4){
               display_home (0, 0, 0 ,0,1);

           }

           else if (selection_tracker > 4)
               selection_tracker = 0;

           //page_number = 1;
        }

    else if (page_number == 1){
        selection_tracker2++;
        if (selection_tracker2 == 1){
                    display_home (1, 1, 0 ,0,0);
                    //display_home (page_number, 1, 0 ,0,0);
                   }
        else if (selection_tracker2==2 ){
              display_home (1, 0, 1 ,0,0);
                       //selection_tracker++;
                   }
        else if (selection_tracker2==3 ){
            display_home (1, 0, 0 ,1,0);
            //selection_tracker=0;
        }
        else if (selection_tracker2 == 4){
            display_home (1, 0, 0 ,0,1);

        }
        else if (selection_tracker2 > 4)
            selection_tracker2 = 0;

        //display_home (1,0,0,0,0);
    }


        else {
            song = 1;



            }

        //iter = 0;
        P5->OUT ^= BIT6;       // Blue off
        P2->OUT ^= BIT4;       // Green on
        BUTTON_PORT3->IFG &= ~BUTTON_BIT5; // clear the flag to allow for another interrupt later.
        // This handler changes the state of the timer CCTL0 control register!
        // Toggle OUTMOD between
        //    mode 0: output = constant value determined by CCTL0 bit 2, and
        //    mode 4: toggle, which when repeated produces a square wave.
    }
    BUTTON_PORT3->IFG &= ~BUTTON_BIT5;

}




void display_home (page_number, first, second, third,fourth){

     if (page_number ==0){
    if (first == 1 || second == 1 || third == 1 || fourth){
        if (first == 1) {
            Graphics_drawStringCentered(&g_sContext,"SELECTED: PIANO MAN",AUTO_STRING_LENGTH,60,100, OPAQUE_TEXT);

        }
        else if (second == 1){
            //Graphics_drawStringCentered(&g_sContext,"Piano Man",AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);
            Graphics_drawStringCentered(&g_sContext,"SELECTED: USA ANTHEM",AUTO_STRING_LENGTH,60,100, OPAQUE_TEXT);

        }

        else if (third == 1){

            Graphics_drawStringCentered(&g_sContext,"SELECTED: Twinkle",AUTO_STRING_LENGTH,70,100, OPAQUE_TEXT);

        }

        else {
            Graphics_drawStringCentered(&g_sContext,"SELECTED: Random",AUTO_STRING_LENGTH,70,100, OPAQUE_TEXT);
        }

    }
    //else {
        Graphics_drawStringCentered(&g_sContext,"Piano Man",AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);
        //Graphics_drawStringCentered(&g_sContext,"SELECTED: PIANO MAN",AUTO_STRING_LENGTH,60,100, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext,"USA Anthem",AUTO_STRING_LENGTH,60,70, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext,"Twinkle",AUTO_STRING_LENGTH,60,80, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext,"Random ",AUTO_STRING_LENGTH,60,90, OPAQUE_TEXT);
    //}
     }
    else if (page_number ==1){
        if (first == 1 || second == 1 || third == 1 || fourth){
            if (first == 1) {
                Graphics_drawStringCentered(&g_sContext,"SELECTED: Karaoke",AUTO_STRING_LENGTH,60,100, OPAQUE_TEXT);


            }
            else if (second == 1){

                Graphics_drawStringCentered(&g_sContext,"SELECTED: Normal",AUTO_STRING_LENGTH,60,100, OPAQUE_TEXT);

            }
            else if (third == 1){

                Graphics_drawStringCentered(&g_sContext,"SELECTED: Fast",AUTO_STRING_LENGTH,70,100, OPAQUE_TEXT);

            }

            else {
                Graphics_drawStringCentered(&g_sContext,"SELECTED: Slow",AUTO_STRING_LENGTH,70,100, OPAQUE_TEXT);
            }


        }
        Graphics_drawStringCentered(&g_sContext,"Karaoke",AUTO_STRING_LENGTH,60,60, OPAQUE_TEXT);
  
        Graphics_drawStringCentered(&g_sContext,"Normal   ",AUTO_STRING_LENGTH,60,70, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext,"Fast    ",AUTO_STRING_LENGTH,60,80, OPAQUE_TEXT);
        Graphics_drawStringCentered(&g_sContext,"Slow     ",AUTO_STRING_LENGTH,60,90, OPAQUE_TEXT);
    }


}
