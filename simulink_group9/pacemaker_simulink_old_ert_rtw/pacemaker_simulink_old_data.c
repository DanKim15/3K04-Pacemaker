/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_old_data.c
 *
 * Code generated for Simulink model 'pacemaker_simulink_old'.
 *
 * Model version                  : 1.121
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 22 18:34:54 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pacemaker_simulink_old.h"
#include "pacemaker_simulink_old_private.h"

/* Block parameters (default storage) */
P_pacemaker_simulink_old_T pacemaker_simulink_old_P = {
  /* Expression: 0.001
   * Referenced by: '<S4>/Accel'
   */
  0.001,

  /* Expression: SampleTime
   * Referenced by: '<S5>/VENT_CMP_DETECT'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S5>/ATR_CMP_DETECT'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S6>/UART Receive'
   */
  -1.0,

  /* Expression: 0.75
   * Referenced by: '<S3>/ATR_SENS'
   */
  0.75,

  /* Expression: 100
   * Referenced by: '<S3>/Gain4'
   */
  100.0,

  /* Expression: 0.75
   * Referenced by: '<S3>/VENT_SENS'
   */
  0.75,

  /* Expression: 100
   * Referenced by: '<S3>/Gain5'
   */
  100.0,

  /* Expression: 2
   * Referenced by: '<S4>/activity_sat'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S4>/activity_sat'
   */
  0.0,

  /* Expression: 120
   * Referenced by: '<S4>/MAX_SENSOR_RATE'
   */
  120.0,

  /* Expression: 60
   * Referenced by: '<S4>/Delay_rp'
   */
  60.0,

  /* Expression: 10
   * Referenced by: '<S4>/REACTION_TIME_s'
   */
  10.0,

  /* Expression: 60
   * Referenced by: '<S4>/RECOVERY_TIME_s'
   */
  60.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  40960U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S3>/Gain1'
   */
  40960U,

  /* Computed Parameter: HYSTERESIS_INTERVAL_Value
   * Referenced by: '<S3>/HYSTERESIS_INTERVAL'
   */
  300U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  7U,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  40U,

  /* Computed Parameter: DataStoreMemory2_InitialValue
   * Referenced by: '<Root>/Data Store Memory2'
   */
  40U,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  250U,

  /* Computed Parameter: DataStoreMemory4_InitialValue
   * Referenced by: '<Root>/Data Store Memory4'
   */
  320U,

  /* Computed Parameter: DataStoreMemory7_InitialValue
   * Referenced by: '<Root>/Data Store Memory7'
   */
  60U,

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  150U,

  /* Computed Parameter: DataStoreMemory9_InitialValue
   * Referenced by: '<Root>/Data Store Memory9'
   */
  7U,

  /* Expression: false
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0,

  /* Computed Parameter: SYNC_TX_Value
   * Referenced by: '<S11>/SYNC_TX'
   */
  22U,

  /* Computed Parameter: MSGTYPE_TX_Value
   * Referenced by: '<S11>/MSGTYPE_TX'
   */
  129U,

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  2U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
