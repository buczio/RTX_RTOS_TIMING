
#include "cmsis_os.h"                       // CMSIS RTOS header file
#include "Board_LED.h"											// LED on/off functions
#include "MKL25Z4.h"												// uC support
#define DELAY (5000000)
/*----------------------------------------------------------------------------
 * Thread_1 - Simple Delay() function usage
 *---------------------------------------------------------------------------*/
 
void Thread_1 (void const *argument);                             // thread function
osThreadId tid_1;                                          				// thread id
osThreadDef (Thread_1, osPriorityNormal, 1, 0);                   // thread object

/*----------------------------------------------------------------------------
 * Simple delay function
 *---------------------------------------------------------------------------*/
void delay (unsigned int count)
{
unsigned int index;

	for(index =0;index<count;index++)
	{
		;
	}
}


int Init_Thread_1 (void) {

  tid_1 = osThreadCreate (osThread(Thread_1), NULL);
  if (!tid_1) return(-1);
  
  return(0);
}

void Thread_1 (void const *argument) {

  while (1) {
    LED_On(0);
		delay(DELAY);
		LED_Off(0);
		delay(DELAY);
	
    //osThreadYield ();                                           // suspend thread
  }
}
