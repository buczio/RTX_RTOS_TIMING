
#include "cmsis_os.h"                       // CMSIS RTOS header file

#include "MKL25Z4.h"	

/*----------------------------------------------------------------------------
 * Timer: Sample timer functions
 *---------------------------------------------------------------------------*/
 

/*----- Periodic Timer Example -----*/
static void Timer2_Callback (void const *arg);                  // prototype for timer callback function

static osTimerId id2;                                           // timer id
static uint32_t  exec2;                                         // argument for the timer call back function
static osTimerDef (Timer2, Timer2_Callback);
 
// Periodic Timer Example
static void Timer2_Callback (void const *arg) {
  FPTD->PTOR|=(1<<1);																						//Toggle blue LED
	
}


// Example: Create and Start timers
void Init_Timer (void) {
  osStatus status;                                              // function return status
 
  // Create periodic timer
  exec2 = 2;
  id2 = osTimerCreate (osTimer(Timer2), osTimerPeriodic, &exec2);
  if (id2 != NULL) {    // Periodic timer created
    // start timer with periodic 1000ms interval
    status = osTimerStart (id2, 1000);            
    if (status != osOK) {
      // Timer could not be started
    }
  }
}
