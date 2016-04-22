
#include "cmsis_os.h"                       // CMSIS RTOS header file
#include "Board_LED.h"											// LED on/off functions
#define DELAY (500)
/*----------------------------------------------------------------------------
 *      Thread 2 - osDelay() function usage
 *---------------------------------------------------------------------------*/
 
void Thread_2 (void const *argument);                             // thread function
osThreadId tid_2;                                          				// thread id
osThreadDef (Thread_2, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_2 (void) {

  tid_2 = osThreadCreate (osThread(Thread_2), NULL);
  if (!tid_2) return(-1);
  
  return(0);
}

void Thread_2 (void const *argument) {

  while (1) {
    LED_On(1);
		osDelay(DELAY);
		LED_Off(1);
		osDelay(DELAY);
		

    //osThreadYield ();                                           // suspend thread
  }
}
