/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_old.h
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

#ifndef RTW_HEADER_pacemaker_simulink_old_h_
#define RTW_HEADER_pacemaker_simulink_old_h_
#include <string.h>
#include <math.h>
#include <stddef.h>
#ifndef pacemaker_simulink_old_COMMON_INCLUDES_
# define pacemaker_simulink_old_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#include "MW_SCI.h"
#endif                             /* pacemaker_simulink_old_COMMON_INCLUDES_ */

#include "pacemaker_simulink_old_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[20];
  uint8_T RxDataLocChar[20];
  int16_T b_output[6];
  uint8_T output_raw[12];
  real_T Gain4;                        /* '<S3>/Gain4' */
  real_T Gain5;                        /* '<S3>/Gain5' */
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
  uint32_T PACING_REF_PWM;             /* '<Root>/Pacemaker' */
  uint16_T DataStoreRead1;             /* '<S6>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S6>/Data Store Read2' */
  uint16_T DataStoreRead3;             /* '<S6>/Data Store Read3' */
  uint16_T DataStoreRead4;             /* '<S6>/Data Store Read4' */
  uint16_T DataStoreRead5;             /* '<S6>/Data Store Read5' */
  uint16_T DataStoreRead6;             /* '<S6>/Data Store Read6' */
  uint16_T DataStoreRead7;             /* '<S6>/Data Store Read7' */
  uint16_T DataStoreRead8;             /* '<S6>/Data Store Read8' */
  uint16_T LOWER_RATE_LIMIT_out;       /* '<S6>/UART_Interface' */
  uint16_T UPPER_RATE_LIMIT_out;       /* '<S6>/UART_Interface' */
  uint16_T ATR_PULSE_AMP_REG_out;      /* '<S6>/UART_Interface' */
  uint16_T VENT_PULSE_AMP_REG_out;     /* '<S6>/UART_Interface' */
  uint16_T ATR_PULSE_WIDTH_out;        /* '<S6>/UART_Interface' */
  uint16_T VENT_PULSE_WIDTH_out;       /* '<S6>/UART_Interface' */
  uint16_T ATR_REFRAC_PERIOD_out;      /* '<S6>/UART_Interface' */
  uint16_T VENT_REFRAC_PERIOD_out;     /* '<S6>/UART_Interface' */
  uint8_T DataStoreRead;               /* '<S6>/Data Store Read' */
  uint8_T DataTypeConversion1;         /* '<S11>/Data Type Conversion1' */
  uint8_T BytePack[20];                /* '<S11>/Byte Pack' */
  uint8_T MODE_SELECT_out;             /* '<S6>/UART_Interface' */
  boolean_T HYSTERESIS_out;            /* '<S6>/UART_Interface' */
  boolean_T echo_request;              /* '<S6>/UART_Interface' */
  boolean_T ATR_CMP_DETECT;            /* '<S5>/ATR_CMP_DETECT' */
  boolean_T VENT_CMP_DETECT;           /* '<S5>/VENT_CMP_DETECT' */
} B_pacemaker_simulink_old_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_pacemake_T obj; /* '<S4>/Accel' */
  freedomk64f_DigitalRead_pacem_T obj_i;/* '<S5>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_pacem_T obj_n;/* '<S5>/VENT_CMP_DETECT' */
  freedomk64f_SCIRead_pacemaker_T obj_m;/* '<S6>/UART Receive' */
  freedomk64f_DigitalWrite_pace_T obj_l;/* '<S1>/Digital Write' */
  freedomk64f_DigitalWrite_pace_T obj_lo;/* '<S1>/Digital Write1' */
  freedomk64f_DigitalWrite_pace_T obj_na;/* '<S1>/Digital Write2' */
  freedomk64f_DigitalWrite_pace_T obj_e;/* '<S1>/Digital Write3' */
  freedomk64f_DigitalWrite_pace_T obj_mm;/* '<S1>/Digital Write4' */
  freedomk64f_DigitalWrite_pace_T obj_ir;/* '<S1>/Digital Write5' */
  freedomk64f_DigitalWrite_pace_T obj_b;/* '<S1>/Digital Write6' */
  freedomk64f_DigitalWrite_pace_T obj_p;/* '<S1>/Digital Write7' */
  freedomk64f_DigitalWrite_pace_T obj_em;/* '<S1>/Digital Write8' */
  freedomk64f_PWMOutput_pacemak_T obj_o;/* '<S1>/PWM Output' */
  freedomk64f_PWMOutput_pacemak_T obj_f;/* '<S1>/PWM Output1' */
  freedomk64f_PWMOutput_pacemak_T obj_c;/* '<S1>/PWM Output2' */
  freedomk64f_SCIWrite_pacemake_T obj_k;/* '<S11>/Serial Transmit' */
  real_T Delay_rp_DSTATE;              /* '<S4>/Delay_rp' */
  uint32_T temporalCounter_i1;         /* '<Root>/Pacemaker' */
  uint16_T DS_ATR_REFRAC_PERIOD;       /* '<Root>/Data Store Memory3' */
  uint16_T DS_VENT_REFRAC_PERIOD;      /* '<Root>/Data Store Memory4' */
  uint8_T is_active_c1_pacemaker_simulink;/* '<S6>/UART_Interface' */
  uint8_T is_c1_pacemaker_simulink_old;/* '<S6>/UART_Interface' */
  uint8_T is_active_c3_pacemaker_simulink;/* '<Root>/Pacemaker' */
  uint8_T is_c3_pacemaker_simulink_old;/* '<Root>/Pacemaker' */
  uint8_T is_AOO;                      /* '<Root>/Pacemaker' */
  uint8_T is_VVI;                      /* '<Root>/Pacemaker' */
  uint8_T is_VOO;                      /* '<Root>/Pacemaker' */
  uint8_T is_AAI;                      /* '<Root>/Pacemaker' */
} DW_pacemaker_simulink_old_T;

/* Parameters (default storage) */
struct P_pacemaker_simulink_old_T_ {
  real_T Accel_SampleTime;             /* Expression: 0.001
                                        * Referenced by: '<S4>/Accel'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S5>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S5>/ATR_CMP_DETECT'
                                        */
  real_T UARTReceive_SampleTime;       /* Expression: -1
                                        * Referenced by: '<S6>/UART Receive'
                                        */
  real_T ATR_SENS_Value;               /* Expression: 0.75
                                        * Referenced by: '<S3>/ATR_SENS'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T VENT_SENS_Value;              /* Expression: 0.75
                                        * Referenced by: '<S3>/VENT_SENS'
                                        */
  real_T Gain5_Gain;                   /* Expression: 100
                                        * Referenced by: '<S3>/Gain5'
                                        */
  real_T activity_sat_UpperSat;        /* Expression: 2
                                        * Referenced by: '<S4>/activity_sat'
                                        */
  real_T activity_sat_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S4>/activity_sat'
                                        */
  real_T MAX_SENSOR_RATE_Value;        /* Expression: 120
                                        * Referenced by: '<S4>/MAX_SENSOR_RATE'
                                        */
  real_T Delay_rp_InitialCondition;    /* Expression: 60
                                        * Referenced by: '<S4>/Delay_rp'
                                        */
  real_T REACTION_TIME_s_Value;        /* Expression: 10
                                        * Referenced by: '<S4>/REACTION_TIME_s'
                                        */
  real_T RECOVERY_TIME_s_Value;        /* Expression: 60
                                        * Referenced by: '<S4>/RECOVERY_TIME_s'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S3>/Gain1'
                                        */
  uint16_T HYSTERESIS_INTERVAL_Value;
                                /* Computed Parameter: HYSTERESIS_INTERVAL_Value
                                 * Referenced by: '<S3>/HYSTERESIS_INTERVAL'
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
                                        * Referenced by: '<S11>/SYNC_TX'
                                        */
  uint8_T MSGTYPE_TX_Value;            /* Computed Parameter: MSGTYPE_TX_Value
                                        * Referenced by: '<S11>/MSGTYPE_TX'
                                        */
  uint8_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_pacemaker_simulink_ol_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_pacemaker_simulink_old_T pacemaker_simulink_old_P;

/* Block signals (default storage) */
extern B_pacemaker_simulink_old_T pacemaker_simulink_old_B;

/* Block states (default storage) */
extern DW_pacemaker_simulink_old_T pacemaker_simulink_old_DW;

/* Model entry point functions */
extern void pacemaker_simulink_old_initialize(void);
extern void pacemaker_simulink_old_step(void);
extern void pacemaker_simulink_old_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pacemaker_simulink_o_T *const pacemaker_simulink_old_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion9' : Eliminate redundant data type conversion
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
 * '<Root>' : 'pacemaker_simulink_old'
 * '<S1>'   : 'pacemaker_simulink_old/Outputs'
 * '<S2>'   : 'pacemaker_simulink_old/Pacemaker'
 * '<S3>'   : 'pacemaker_simulink_old/Programmable Parameters'
 * '<S4>'   : 'pacemaker_simulink_old/RateAdaptive'
 * '<S5>'   : 'pacemaker_simulink_old/Sensor Inputs'
 * '<S6>'   : 'pacemaker_simulink_old/UART_Comm'
 * '<S7>'   : 'pacemaker_simulink_old/RateAdaptive/compute_intervals'
 * '<S8>'   : 'pacemaker_simulink_old/RateAdaptive/map_activity_to_rate'
 * '<S9>'   : 'pacemaker_simulink_old/RateAdaptive/time_response'
 * '<S10>'  : 'pacemaker_simulink_old/UART_Comm/UART_Interface'
 * '<S11>'  : 'pacemaker_simulink_old/UART_Comm/UART_Tx'
 */
#endif                                /* RTW_HEADER_pacemaker_simulink_old_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
