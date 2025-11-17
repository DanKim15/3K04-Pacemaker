/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_data.c
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

/* Block parameters (default storage) */
P_pacemaker_simulink_T pacemaker_simulink_P = {
  /* Expression: SampleTime
   * Referenced by: '<S1>/VENT_CMP_DETECT'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S1>/ATR_CMP_DETECT'
   */
  -1.0,

  /* Expression: 130
   * Referenced by: '<S1>/LOWER_RATE_LIMIT'
   */
  130.0,

  /* Expression: 120
   * Referenced by: '<S1>/UPPER_RATE_LIMIT'
   */
  120.0,

  /* Expression: 3.5
   * Referenced by: '<S1>/ATR_PULSE_AMP_REG'
   */
  3.5,

  /* Expression: 20
   * Referenced by: '<S1>/Gain'
   */
  20.0,

  /* Expression: 3.5
   * Referenced by: '<S1>/VENT_PULSE_AMP_REG'
   */
  3.5,

  /* Expression: 20
   * Referenced by: '<S1>/Gain1'
   */
  20.0,

  /* Expression: 0.4
   * Referenced by: '<S1>/ATR_PULSE_WIDTH'
   */
  0.4,

  /* Expression: 100
   * Referenced by: '<S1>/Gain2'
   */
  100.0,

  /* Expression: 0.4
   * Referenced by: '<S1>/VENT_PULSE_WIDTH'
   */
  0.4,

  /* Expression: 100
   * Referenced by: '<S1>/Gain3'
   */
  100.0,

  /* Expression: 0.75
   * Referenced by: '<S1>/ATR_SENS'
   */
  0.75,

  /* Expression: 100
   * Referenced by: '<S1>/Gain4'
   */
  100.0,

  /* Expression: 0.75
   * Referenced by: '<S1>/VENT_SENS'
   */
  0.75,

  /* Expression: 100
   * Referenced by: '<S1>/Gain5'
   */
  100.0,

  /* Computed Parameter: ATR_REFRAC_PERIOD_Value
   * Referenced by: '<S1>/ATR_REFRAC_PERIOD'
   */
  500,

  /* Computed Parameter: VENT_REFRAC_PERIOD_Value
   * Referenced by: '<S1>/VENT_REFRAC_PERIOD'
   */
  320,

  /* Computed Parameter: HYSTERESIS_INTERVAL_Value
   * Referenced by: '<S1>/HYSTERESIS_INTERVAL'
   */
  300,

  /* Expression: false
   * Referenced by: '<S1>/HYSTERESIS'
   */
  0,

  /* Computed Parameter: MODE_SELECT_Value
   * Referenced by: '<S1>/MODE_SELECT'
   */
  2
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
