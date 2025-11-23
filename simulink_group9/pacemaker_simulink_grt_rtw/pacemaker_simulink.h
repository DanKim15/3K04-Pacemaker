/*
 * pacemaker_simulink.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pacemaker_simulink".
 *
 * Model version              : 1.198
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Sat Nov 22 22:40:51 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pacemaker_simulink_h_
#define RTW_HEADER_pacemaker_simulink_h_
#include <string.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#ifndef pacemaker_simulink_COMMON_INCLUDES_
# define pacemaker_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MW_I2C.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* pacemaker_simulink_COMMON_INCLUDES_ */

#include "pacemaker_simulink_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain4;                        /* '<S5>/Gain4' */
  real_T Gain5;                        /* '<S5>/Gain5' */
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Pacemaker' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Pacemaker' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Pacemaker' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Pacemaker' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Pacemaker' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Pacemaker' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Pacemaker' */
  real_T PACE_GND_CTRL;                /* '<Root>/Pacemaker' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Pacemaker' */
  real_T VENT_GND_CTRL;                /* '<Root>/Pacemaker' */
  real_T FRONTEND_CTRL;                /* '<Root>/Pacemaker' */
  real_T UnitDelay5;                   /* '<S8>/Unit Delay5' */
  real_T UnitDelay4;                   /* '<S8>/Unit Delay4' */
  real_T UnitDelay3;                   /* '<S8>/Unit Delay3' */
  uint32_T Gain;                       /* '<S5>/Gain' */
  uint32_T Gain1;                      /* '<S5>/Gain1' */
  uint32_T PACING_REF_PWM;             /* '<Root>/Pacemaker' */
  uint16_T DataStoreRead1;             /* '<S7>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S7>/Data Store Read2' */
  uint16_T DataStoreRead3;             /* '<S7>/Data Store Read3' */
  uint16_T DataStoreRead4;             /* '<S7>/Data Store Read4' */
  uint16_T DataStoreRead5;             /* '<S7>/Data Store Read5' */
  uint16_T DataStoreRead6;             /* '<S7>/Data Store Read6' */
  uint16_T DataStoreRead7;             /* '<S7>/Data Store Read7' */
  uint16_T DataStoreRead8;             /* '<S7>/Data Store Read8' */
  uint16_T DataStoreRead5_c;           /* '<S5>/Data Store Read5' */
  uint16_T DataStoreRead6_a;           /* '<S5>/Data Store Read6' */
  uint16_T DataStoreRead7_g;           /* '<S5>/Data Store Read7' */
  uint16_T DataStoreRead8_n;           /* '<S5>/Data Store Read8' */
  uint16_T Cast2;                      /* '<S2>/Cast2' */
  uint16_T Cast1;                      /* '<S2>/Cast1' */
  uint16_T LOWER_RATE_LIMIT_out;       /* '<S7>/UART_Interface' */
  uint16_T UPPER_RATE_LIMIT_out;       /* '<S7>/UART_Interface' */
  uint16_T ATR_PULSE_AMP_REG_out;      /* '<S7>/UART_Interface' */
  uint16_T VENT_PULSE_AMP_REG_out;     /* '<S7>/UART_Interface' */
  uint16_T ATR_PULSE_WIDTH_out;        /* '<S7>/UART_Interface' */
  uint16_T VENT_PULSE_WIDTH_out;       /* '<S7>/UART_Interface' */
  uint16_T ATR_REFRAC_PERIOD_out;      /* '<S7>/UART_Interface' */
  uint16_T VENT_REFRAC_PERIOD_out;     /* '<S7>/UART_Interface' */
  uint8_T DataStoreRead;               /* '<S7>/Data Store Read' */
  uint8_T DataStoreRead_h;             /* '<S5>/Data Store Read' */
  uint8_T DataTypeConversion1;         /* '<S15>/Data Type Conversion1' */
  uint8_T BytePack[20];                /* '<S15>/Byte Pack' */
  uint8_T MODE_SELECT_out;             /* '<S7>/UART_Interface' */
  boolean_T DataStoreRead9;            /* '<S5>/Data Store Read9' */
  boolean_T HYSTERESIS_out;            /* '<S7>/UART_Interface' */
  boolean_T ATR_CMP_DETECT;            /* '<S6>/ATR_CMP_DETECT' */
  boolean_T VENT_CMP_DETECT;           /* '<S6>/VENT_CMP_DETECT' */
} B_pacemaker_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_pacemake_T obj; /* '<S1>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_pacem_T obj_i;/* '<S6>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_pacem_T obj_n;/* '<S6>/VENT_CMP_DETECT' */
  freedomk64f_DigitalWrite_pace_T obj_l;/* '<S3>/Digital Write' */
  freedomk64f_DigitalWrite_pace_T obj_lo;/* '<S3>/Digital Write1' */
  freedomk64f_DigitalWrite_pace_T obj_na;/* '<S3>/Digital Write2' */
  freedomk64f_DigitalWrite_pace_T obj_e;/* '<S3>/Digital Write3' */
  freedomk64f_DigitalWrite_pace_T obj_m;/* '<S3>/Digital Write4' */
  freedomk64f_DigitalWrite_pace_T obj_ir;/* '<S3>/Digital Write5' */
  freedomk64f_DigitalWrite_pace_T obj_b;/* '<S3>/Digital Write6' */
  freedomk64f_DigitalWrite_pace_T obj_p;/* '<S3>/Digital Write7' */
  freedomk64f_DigitalWrite_pace_T obj_em;/* '<S3>/Digital Write8' */
  freedomk64f_PWMOutput_pacemak_T obj_o;/* '<S3>/PWM Output' */
  freedomk64f_PWMOutput_pacemak_T obj_f;/* '<S3>/PWM Output1' */
  freedomk64f_PWMOutput_pacemak_T obj_c;/* '<S3>/PWM Output2' */
  real_T PreviousRate_DSTATE;          /* '<S2>/Previous Rate' */
  real_T UnitDelay_DSTATE;             /* '<S8>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S8>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S8>/Unit Delay2' */
  real_T UnitDelay3_DSTATE;            /* '<S8>/Unit Delay3' */
  real_T UnitDelay4_DSTATE;            /* '<S8>/Unit Delay4' */
  real_T UnitDelay5_DSTATE;            /* '<S8>/Unit Delay5' */
  real_T UnitDelay6_DSTATE;            /* '<S8>/Unit Delay6' */
  real_T RateTransition_Buffer0;       /* '<Root>/Rate Transition' */
  uint32_T temporalCounter_i1;         /* '<Root>/Pacemaker' */
  uint16_T DS_VENT_PULSE_AMP_REG;      /* '<Root>/Data Store Memory' */
  uint16_T DS_ATR_PULSE_WIDTH;         /* '<Root>/Data Store Memory1' */
  uint16_T DS_VENT_PULSE_WIDTH;        /* '<Root>/Data Store Memory2' */
  uint16_T DS_ATR_REFRAC_PERIOD;       /* '<Root>/Data Store Memory3' */
  uint16_T DS_VENT_REFRAC_PERIOD;      /* '<Root>/Data Store Memory4' */
  uint16_T DS_LOWER_RATE_LIMIT;        /* '<Root>/Data Store Memory7' */
  uint16_T DS_UPPER_RATE_LIMIT;        /* '<Root>/Data Store Memory8' */
  uint16_T DS_ATR_PULSE_AMP_REG;       /* '<Root>/Data Store Memory9' */
  uint16_T temporalCounter_i1_k;       /* '<S7>/UART_Interface' */
  uint8_T DS_MODE_SELECT;              /* '<Root>/Data Store Memory5' */
  uint8_T is_active_c1_pacemaker_simulink;/* '<S7>/UART_Interface' */
  uint8_T is_c1_pacemaker_simulink;    /* '<S7>/UART_Interface' */
  uint8_T is_active_c3_pacemaker_simulink;/* '<Root>/Pacemaker' */
  uint8_T is_c3_pacemaker_simulink;    /* '<Root>/Pacemaker' */
  uint8_T is_AOO;                      /* '<Root>/Pacemaker' */
  uint8_T is_VVI;                      /* '<Root>/Pacemaker' */
  uint8_T is_VOO;                      /* '<Root>/Pacemaker' */
  uint8_T is_AAI;                      /* '<Root>/Pacemaker' */
  boolean_T DS_HYSTERESIS;             /* '<Root>/Data Store Memory6' */
  boolean_T objisempty;                /* '<S6>/ATR_CMP_DETECT' */
  boolean_T objisempty_j;              /* '<S6>/VENT_CMP_DETECT' */
  boolean_T objisempty_k;              /* '<S3>/Digital Write' */
  boolean_T objisempty_h;              /* '<S3>/PWM Output' */
  boolean_T objisempty_b;              /* '<S3>/Digital Write1' */
  boolean_T objisempty_n;              /* '<S3>/PWM Output1' */
  boolean_T objisempty_m;              /* '<S3>/PWM Output2' */
  boolean_T objisempty_o;              /* '<S3>/Digital Write2' */
  boolean_T objisempty_m3;             /* '<S3>/Digital Write3' */
  boolean_T objisempty_jb;             /* '<S3>/Digital Write4' */
  boolean_T objisempty_c;              /* '<S3>/Digital Write5' */
  boolean_T objisempty_d;              /* '<S3>/Digital Write6' */
  boolean_T objisempty_h1;             /* '<S3>/Digital Write7' */
  boolean_T objisempty_hr;             /* '<S3>/Digital Write8' */
  boolean_T objisempty_o1;             /* '<S1>/FXOS8700 6-Axes Sensor' */
} DW_pacemaker_simulink_T;

/* Parameters (default storage) */
struct P_pacemaker_simulink_T_ {
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: 0.02
                                         * Referenced by: '<S1>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S6>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S6>/ATR_CMP_DETECT'
                                        */
  real_T ATR_SENS_Value;               /* Expression: 0.75
                                        * Referenced by: '<S5>/ATR_SENS'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T VENT_SENS_Value;              /* Expression: 0.75
                                        * Referenced by: '<S5>/VENT_SENS'
                                        */
  real_T Gain5_Gain;                   /* Expression: 100
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Constant_Value;               /* Expression: 60000
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<Root>/Rate Transition'
                                          */
  real_T ACTIVITY_THRESHOLD_Value;     /* Expression: 1
                                        * Referenced by: '<S2>/ACTIVITY_THRESHOLD'
                                        */
  real_T Constant1_Value;              /* Expression: 8
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T PreviousRate_InitialCondition;/* Expression: 60
                                        * Referenced by: '<S2>/Previous Rate'
                                        */
  real_T MAX_SENSOR_RATE_Value;        /* Expression: 120
                                        * Referenced by: '<S2>/MAX_SENSOR_RATE'
                                        */
  real_T RECOVERY_TIME_min_Value;      /* Expression: 5
                                        * Referenced by: '<S2>/RECOVERY_TIME_min'
                                        */
  real_T Constant_Value_k;             /* Expression: 1000
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T ResponseFactors_Value;        /* Expression: 16
                                        * Referenced by: '<S9>/#ResponseFactors'
                                        */
  real_T RESPONSE_FACTOR_Value;        /* Expression: 16
                                        * Referenced by: '<S2>/RESPONSE_FACTOR'
                                        */
  real_T REACTION_TIME_min_Value;      /* Expression: 0.5
                                        * Referenced by: '<S2>/REACTION_TIME_min'
                                        */
  real_T Constant_Value_b;             /* Expression: 1000
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay1'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay2'
                                        */
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay3'
                                        */
  real_T UnitDelay4_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay4'
                                        */
  real_T UnitDelay5_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay5'
                                        */
  real_T UnitDelay6_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay6'
                                        */
  real_T Constant_Value_l;             /* Expression: 8
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T SubtractGravity_Value;        /* Expression: 1
                                        * Referenced by: '<S1>/Subtract Gravity'
                                        */
  real_T Constant_Value_c;             /* Expression: 4
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Clamp01_UpperSat;             /* Expression: 1
                                        * Referenced by: '<S1>/Clamp 0 - 1'
                                        */
  real_T Clamp01_LowerSat;             /* Expression: 0
                                        * Referenced by: '<S1>/Clamp 0 - 1'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S5>/Gain'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S5>/Gain1'
                                        */
  uint16_T HYSTERESIS_INTERVAL_Value;
                                /* Computed Parameter: HYSTERESIS_INTERVAL_Value
                                 * Referenced by: '<S5>/HYSTERESIS_INTERVAL'
                                 */
  uint16_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  uint16_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  uint16_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint16_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  uint16_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  uint16_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  uint16_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  boolean_T DataStoreMemory6_InitialValue;/* Expression: false
                                           * Referenced by: '<Root>/Data Store Memory6'
                                           */
  uint8_T SYNC_TX_Value;               /* Computed Parameter: SYNC_TX_Value
                                        * Referenced by: '<S15>/SYNC_TX'
                                        */
  uint8_T MSGTYPE_TX_Value;            /* Computed Parameter: MSGTYPE_TX_Value
                                        * Referenced by: '<S15>/MSGTYPE_TX'
                                        */
  uint8_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_pacemaker_simulink_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;

    struct {
      uint8_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_pacemaker_simulink_T pacemaker_simulink_P;

/* Block signals (default storage) */
extern B_pacemaker_simulink_T pacemaker_simulink_B;

/* Block states (default storage) */
extern DW_pacemaker_simulink_T pacemaker_simulink_DW;

/* Model entry point functions */
extern void pacemaker_simulink_initialize(void);
extern void pacemaker_simulink_step(int_T tid);
extern void pacemaker_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pacemaker_simulink_T *const pacemaker_simulink_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion9' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'pacemaker_simulink'
 * '<S1>'   : 'pacemaker_simulink/Accel to Activity Level'
 * '<S2>'   : 'pacemaker_simulink/Heart Rate Calculation, Rate-Adaptive'
 * '<S3>'   : 'pacemaker_simulink/Outputs'
 * '<S4>'   : 'pacemaker_simulink/Pacemaker'
 * '<S5>'   : 'pacemaker_simulink/Programmable Parameters'
 * '<S6>'   : 'pacemaker_simulink/Sensor Inputs'
 * '<S7>'   : 'pacemaker_simulink/UART_Comm'
 * '<S8>'   : 'pacemaker_simulink/Accel to Activity Level/Moving Average'
 * '<S9>'   : 'pacemaker_simulink/Heart Rate Calculation, Rate-Adaptive/Desired Rate Increase'
 * '<S10>'  : 'pacemaker_simulink/Heart Rate Calculation, Rate-Adaptive/If Action Subsystem'
 * '<S11>'  : 'pacemaker_simulink/Heart Rate Calculation, Rate-Adaptive/If Action Subsystem1'
 * '<S12>'  : 'pacemaker_simulink/Heart Rate Calculation, Rate-Adaptive/Slope Calculation Decrease'
 * '<S13>'  : 'pacemaker_simulink/Heart Rate Calculation, Rate-Adaptive/Slope Calculation Increase'
 * '<S14>'  : 'pacemaker_simulink/UART_Comm/UART_Interface'
 * '<S15>'  : 'pacemaker_simulink/UART_Comm/UART_Tx'
 */
#endif                                 /* RTW_HEADER_pacemaker_simulink_h_ */
