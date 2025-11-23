/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_d1.h
 *
 * Code generated for Simulink model 'pacemaker_simulink_d1'.
 *
 * Model version                  : 1.58
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 22 18:55:15 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pacemaker_simulink_d1_h_
#define RTW_HEADER_pacemaker_simulink_d1_h_
#include <math.h>
#include <stddef.h>
#ifndef pacemaker_simulink_d1_COMMON_INCLUDES_
# define pacemaker_simulink_d1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                              /* pacemaker_simulink_d1_COMMON_INCLUDES_ */

#include "pacemaker_simulink_d1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Pacemaker' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Pacemaker' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Pacemaker' */
  real_T PACING_REF_PWM;               /* '<Root>/Pacemaker' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Pacemaker' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Pacemaker' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Pacemaker' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Pacemaker' */
  real_T PACE_GND_CTRL;                /* '<Root>/Pacemaker' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Pacemaker' */
  real_T VENT_GND_CTRL;                /* '<Root>/Pacemaker' */
  real_T FRONTEND_CTRL;                /* '<Root>/Pacemaker' */
} B_pacemaker_simulink_d1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_pacem_T obj; /* '<S1>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_pacem_T obj_n;/* '<S1>/VENT_CMP_DETECT' */
  freedomk64f_DigitalWrite_pace_T obj_l;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_pace_T obj_lo;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_pace_T obj_na;/* '<S2>/Digital Write2' */
  freedomk64f_DigitalWrite_pace_T obj_e;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_pace_T obj_m;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_pace_T obj_i;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_pace_T obj_b;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_pace_T obj_p;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_pace_T obj_em;/* '<S2>/Digital Write8' */
  freedomk64f_PWMOutput_pacemak_T obj_o;/* '<S2>/PWM Output' */
  freedomk64f_PWMOutput_pacemak_T obj_f;/* '<S2>/PWM Output1' */
  freedomk64f_PWMOutput_pacemak_T obj_c;/* '<S2>/PWM Output2' */
  uint32_T temporalCounter_i1;         /* '<Root>/Pacemaker' */
  uint8_T is_active_c3_pacemaker_simulink;/* '<Root>/Pacemaker' */
  uint8_T is_c3_pacemaker_simulink_d1; /* '<Root>/Pacemaker' */
  uint8_T is_AOO;                      /* '<Root>/Pacemaker' */
  uint8_T is_VVI;                      /* '<Root>/Pacemaker' */
  uint8_T is_VOO;                      /* '<Root>/Pacemaker' */
  uint8_T is_AAI;                      /* '<Root>/Pacemaker' */
} DW_pacemaker_simulink_d1_T;

/* Parameters (default storage) */
struct P_pacemaker_simulink_d1_T_ {
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S1>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S1>/ATR_CMP_DETECT'
                                        */
  real_T LOWER_RATE_LIMIT_Value;       /* Expression: 60
                                        * Referenced by: '<S1>/LOWER_RATE_LIMIT'
                                        */
  real_T UPPER_RATE_LIMIT_Value;       /* Expression: 120
                                        * Referenced by: '<S1>/UPPER_RATE_LIMIT'
                                        */
  real_T ATR_PULSE_AMP_REG_Value;      /* Expression: 3.5
                                        * Referenced by: '<S1>/ATR_PULSE_AMP_REG'
                                        */
  real_T Gain_Gain;                    /* Expression: 20
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T VENT_PULSE_AMP_REG_Value;     /* Expression: 3.5
                                        * Referenced by: '<S1>/VENT_PULSE_AMP_REG'
                                        */
  real_T Gain1_Gain;                   /* Expression: 20
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T ATR_PULSE_WIDTH_Value;        /* Expression: 0.4
                                        * Referenced by: '<S1>/ATR_PULSE_WIDTH'
                                        */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T VENT_PULSE_WIDTH_Value;       /* Expression: 0.4
                                        * Referenced by: '<S1>/VENT_PULSE_WIDTH'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T ATR_SENS_Value;               /* Expression: 0.75
                                        * Referenced by: '<S1>/ATR_SENS'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T VENT_SENS_Value;              /* Expression: 0.75
                                        * Referenced by: '<S1>/VENT_SENS'
                                        */
  real_T Gain5_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain5'
                                        */
  int16_T ATR_REFRAC_PERIOD_Value;/* Computed Parameter: ATR_REFRAC_PERIOD_Value
                                   * Referenced by: '<S1>/ATR_REFRAC_PERIOD'
                                   */
  int16_T VENT_REFRAC_PERIOD_Value;
                                 /* Computed Parameter: VENT_REFRAC_PERIOD_Value
                                  * Referenced by: '<S1>/VENT_REFRAC_PERIOD'
                                  */
  int16_T HYSTERESIS_INTERVAL_Value;
                                /* Computed Parameter: HYSTERESIS_INTERVAL_Value
                                 * Referenced by: '<S1>/HYSTERESIS_INTERVAL'
                                 */
  boolean_T HYSTERESIS_Value;          /* Expression: false
                                        * Referenced by: '<S1>/HYSTERESIS'
                                        */
  int8_T MODE_SELECT_Value;            /* Computed Parameter: MODE_SELECT_Value
                                        * Referenced by: '<S1>/MODE_SELECT'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pacemaker_simulink_d1_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_pacemaker_simulink_d1_T pacemaker_simulink_d1_P;

/* Block signals (default storage) */
extern B_pacemaker_simulink_d1_T pacemaker_simulink_d1_B;

/* Block states (default storage) */
extern DW_pacemaker_simulink_d1_T pacemaker_simulink_d1_DW;

/* Model entry point functions */
extern void pacemaker_simulink_d1_initialize(void);
extern void pacemaker_simulink_d1_step(void);
extern void pacemaker_simulink_d1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pacemaker_simulink_d_T *const pacemaker_simulink_d1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pacemaker_simulink_d1'
 * '<S1>'   : 'pacemaker_simulink_d1/Inputs and Programmable Parameters'
 * '<S2>'   : 'pacemaker_simulink_d1/Outputs'
 * '<S3>'   : 'pacemaker_simulink_d1/Pacemaker'
 */
#endif                                 /* RTW_HEADER_pacemaker_simulink_d1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
