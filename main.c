/*----------------------------------------------------------------------------
 *
 * This file presents basic timing functions of RTX RTOS
 * just to have everything in one place
 *
 * Bartlomiej Buczek 2014
 * AGH Kraków
 *
 * works with freescale freedom board, Cortex-M0+ Core
 * board_led drivers included
 * Keil RTX on CMSIS-RTOS
 *
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions
#include "Board_LED.h"											// LED on/off functions
#include "MKL25Z4.h"												// uC support

/*----------------------------------------------------------------------------
* Thread definitions
* User timers and thread count in system wizard should be set on
* Threads dont use suspension and have the same priority
*------------------------------------------------------------------------------*/

extern int Init_Thread_1 (void);							// thread with simple Delay function
extern int Init_Thread_2 (void);							// thread with osDelay function
extern void Init_Timer(void);									// Virtual Timer usage for blinking led

// CMSIS osWait() function not supported on RTX RTOS
// os_idle_demon could be set to __wfe() - power saving mode

/*----------------------------------------------------------------------------
*
* Main function
*
*------------------------------------------------------------------------------*/
 
int main (void) {
	int32_t tick, delayPeriod;								// variables for sub milisecond delay block 
  osKernelInitialize ();                    // initialize CMSIS-RTOS
	LED_Initialize();													// initialize LEDs
	
	Init_Thread_1();													// initialize Threads 
	Init_Thread_2();
	Init_Timer();														  // initialize Periodic Virtual Timer
  osKernelStart ();                         // start thread execution 
	
/*----------------------------------------------------------------------------
* Sub milisecond delays using SysTick
*------------------------------------------------------------------------------*/

	
	tick= osKernelSysTick();
	delayPeriod = osKernelSysTickMicroSec(100);		//every some quick time
	do{
  FPTD->PTOR|=(1<<1);														// Toggle Blue LED
	}while((osKernelSysTick()-tick<delayPeriod));
	
	
}
