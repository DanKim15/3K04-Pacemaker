/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'pacemaker_simulink'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Oct 27 15:49:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pacemaker_simulink.h"
#include "pacemaker_simulink_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "board.h"
#include "mw_cmsis_rtos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
mw_signal_event_t stopSem;
mw_signal_event_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(pacemaker_simulink_M) == (NULL));
  while (runModel) {
    mw_osSignalEventWaitEver(&baserateTaskSem);
    pacemaker_simulink_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(pacemaker_simulink_M) == (NULL)));
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(pacemaker_simulink_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  pacemaker_simulink_terminate();
  mw_osSignalEventRelease(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  SystemCoreClockUpdate();
  hardware_init();
  rtmSetErrorStatus(pacemaker_simulink_M, 0);

  /* Initialize model */
  pacemaker_simulink_initialize();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 0);

  /* Wait for stop semaphore */
  mw_osSignalEventWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSignalEventDelete(&timerTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
