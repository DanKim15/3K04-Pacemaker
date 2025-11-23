/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_data.c
 *
 * Code generated for Simulink model 'pacemaker_simulink'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 22 22:36:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pacemaker_simulink.h"
#include "pacemaker_simulink_private.h"

/* Block parameters (default storage) */
P_pacemaker_simulink_T pacemaker_simulink_P = {
  /* Expression: 0.02
   * Referenced by: '<S1>/FXOS8700 6-Axes Sensor'
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S10>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Switch'
   */
  0.0,

  /* Expression: SampleTime
   * Referenced by: '<S6>/VENT_CMP_DETECT'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S6>/ATR_CMP_DETECT'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S7>/UART Receive'
   */
  -1.0,

  /* Expression: 0.75
   * Referenced by: '<S5>/ATR_SENS'
   */
  0.75,

  /* Expression: 100
   * Referenced by: '<S5>/Gain4'
   */
  100.0,

  /* Expression: 0.75
   * Referenced by: '<S5>/VENT_SENS'
   */
  0.75,

  /* Expression: 100
   * Referenced by: '<S5>/Gain5'
   */
  100.0,

  /* Expression: 60000
   * Referenced by: '<S2>/Constant'
   */
  60000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Transition'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/ACTIVITY_THRESHOLD'
   */
  1.0,

  /* Expression: 8
   * Referenced by: '<S2>/Constant1'
   */
  8.0,

  /* Expression: 60
   * Referenced by: '<S2>/Previous Rate'
   */
  60.0,

  /* Expression: 120
   * Referenced by: '<S2>/MAX_SENSOR_RATE'
   */
  120.0,

  /* Expression: 5
   * Referenced by: '<S2>/RECOVERY_TIME_min'
   */
  5.0,

  /* Expression: 1000
   * Referenced by: '<S12>/Constant'
   */
  1000.0,

  /* Expression: 16
   * Referenced by: '<S9>/#ResponseFactors'
   */
  16.0,

  /* Expression: 16
   * Referenced by: '<S2>/RESPONSE_FACTOR'
   */
  16.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/REACTION_TIME_min'
   */
  0.5,

  /* Expression: 1000
   * Referenced by: '<S13>/Constant'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay6'
   */
  0.0,

  /* Expression: 8
   * Referenced by: '<S8>/Constant'
   */
  8.0,

  /* Expression: 1
   * Referenced by: '<S1>/Subtract Gravity'
   */
  1.0,

  /* Expression: 4
   * Referenced by: '<S1>/Constant'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<S1>/Clamp 0 - 1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Clamp 0 - 1'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S5>/Gain'
   */
  40960U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S5>/Gain1'
   */
  40960U,

  /* Computed Parameter: HYSTERESIS_INTERVAL_Value
   * Referenced by: '<S5>/HYSTERESIS_INTERVAL'
   */
  300U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  3U,

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
  3U,

  /* Expression: false
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0,

  /* Computed Parameter: SYNC_TX_Value
   * Referenced by: '<S15>/SYNC_TX'
   */
  22U,

  /* Computed Parameter: MSGTYPE_TX_Value
   * Referenced by: '<S15>/MSGTYPE_TX'
   */
  129U,

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
