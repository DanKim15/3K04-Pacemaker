/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_d1.c
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

#include "pacemaker_simulink_d1.h"
#include "pacemaker_simulink_d1_private.h"

/* Named constants for Chart: '<Root>/Pacemaker' */
#define pacemak_IN_Charging_and_Sensing ((uint8_T)1U)
#define pacemaker_si_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define pacemaker_simulin_IN_Hysteresis ((uint8_T)2U)
#define pacemaker_simulink__IN_Pacing_g ((uint8_T)3U)
#define pacemaker_simulink_d1_IN_AAI   ((uint8_T)1U)
#define pacemaker_simulink_d1_IN_AOO   ((uint8_T)2U)
#define pacemaker_simulink_d1_IN_Pacing ((uint8_T)2U)
#define pacemaker_simulink_d1_IN_Start ((uint8_T)3U)
#define pacemaker_simulink_d1_IN_VOO   ((uint8_T)4U)
#define pacemaker_simulink_d1_IN_VVI   ((uint8_T)5U)

/* Block signals (default storage) */
B_pacemaker_simulink_d1_T pacemaker_simulink_d1_B;

/* Block states (default storage) */
DW_pacemaker_simulink_d1_T pacemaker_simulink_d1_DW;

/* Real-time model */
RT_MODEL_pacemaker_simulink_d_T pacemaker_simulink_d1_M_;
RT_MODEL_pacemaker_simulink_d_T *const pacemaker_simulink_d1_M =
  &pacemaker_simulink_d1_M_;

/* Forward declaration for local functions */
static void enter_atomic_Charging_and_Sen_m(const real_T *Gain5, const real_T
  *Gain1);
static void enter_atomic_Charging_and_S_mil(const real_T *Gain4, const real_T
  *Gain);
static void pacemaker_simulink_d1_AAI(const real_T *Gain2, const boolean_T
  *ATR_CMP_DETECT, const real_T *Gain4, const real_T *Gain);
static void enter_atomic_Charging_and_Sensi(const real_T *Gain);
static void enter_atomic_Charging_and_Se_mi(const real_T *Gain1);
static void pacemaker_si_SystemCore_release(const
  freedomk64f_DigitalRead_pacem_T *obj);
static void pacemaker_sim_SystemCore_delete(const
  freedomk64f_DigitalRead_pacem_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_pacem_T *obj);
static void pacemaker_SystemCore_release_id(const
  freedomk64f_DigitalWrite_pace_T *obj);
static void pacemaker__SystemCore_delete_id(const
  freedomk64f_DigitalWrite_pace_T *obj);
static void matlabCodegenHandle_matlabCo_id(freedomk64f_DigitalWrite_pace_T *obj);
static void pa_SystemCore_release_idbp2dkpv(const
  freedomk64f_PWMOutput_pacemak_T *obj);
static void pac_SystemCore_delete_idbp2dkpv(const
  freedomk64f_PWMOutput_pacemak_T *obj);
static void matlabCodegenHandle_m_idbp2dkpv(freedomk64f_PWMOutput_pacemak_T *obj);

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Sen_m(const real_T *Gain5, const real_T
  *Gain1)
{
  pacemaker_simulink_d1_B.FRONTEND_CTRL = 1.0;
  pacemaker_simulink_d1_B.PACING_REF_PWM = *Gain1;
  pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
  pacemaker_simulink_d1_B.VENT_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_CMP_REF_PWM = *Gain5;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_S_mil(const real_T *Gain4, const real_T
  *Gain)
{
  pacemaker_simulink_d1_B.FRONTEND_CTRL = 1.0;
  pacemaker_simulink_d1_B.PACING_REF_PWM = *Gain;
  pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_CMP_REF_PWM = *Gain4;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void pacemaker_simulink_d1_AAI(const real_T *Gain2, const boolean_T
  *ATR_CMP_DETECT, const real_T *Gain4, const real_T *Gain)
{
  real_T tmp;
  int16_T tmp_0;

  /* Constant: '<S1>/MODE_SELECT' */
  if (pacemaker_simulink_d1_P.MODE_SELECT_Value != 2) {
    pacemaker_simulink_d1_DW.is_AAI = pacemaker_si_IN_NO_ACTIVE_CHILD;
    pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
      pacemaker_simulink_d1_IN_Start;
  } else {
    switch (pacemaker_simulink_d1_DW.is_AAI) {
     case pacemak_IN_Charging_and_Sensing:
      pacemaker_simulink_d1_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_d1_B.ATR_GND_CTRL = 1.0;
      pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil(60000.0 /
           pacemaker_simulink_d1_P.LOWER_RATE_LIMIT_Value - *Gain2)) {
        pacemaker_simulink_d1_DW.is_AAI = pacemaker_simulink__IN_Pacing_g;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        pacemaker_simulink_d1_B.FRONTEND_CTRL = 0.0;
        pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_d1_B.ATR_PACE_CTRL = 1.0;
        pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
        pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
      } else if ((!pacemaker_simulink_d1_P.HYSTERESIS_Value) && (*ATR_CMP_DETECT)
                 && (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
                     ceil(*Gain2)) &&
                 (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
                  pacemaker_simulink_d1_P.ATR_REFRAC_PERIOD_Value)) {
        pacemaker_simulink_d1_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain4, Gain);
      } else {
        /* Constant: '<S1>/HYSTERESIS' */
        if (pacemaker_simulink_d1_P.HYSTERESIS_Value && (*ATR_CMP_DETECT) &&
            (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
             (*Gain2))) {
          /* Constant: '<S1>/ATR_REFRAC_PERIOD' */
          if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
              pacemaker_simulink_d1_P.ATR_REFRAC_PERIOD_Value) {
            pacemaker_simulink_d1_DW.is_AAI = pacemaker_simulin_IN_Hysteresis;
            pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
            enter_atomic_Charging_and_S_mil(Gain4, Gain);
          }

          /* End of Constant: '<S1>/ATR_REFRAC_PERIOD' */
        }

        /* End of Constant: '<S1>/HYSTERESIS' */
      }
      break;

     case pacemaker_simulin_IN_Hysteresis:
      pacemaker_simulink_d1_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_d1_B.ATR_GND_CTRL = 1.0;
      pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
      if ((*ATR_CMP_DETECT) && (pacemaker_simulink_d1_DW.temporalCounter_i1 >=
           (uint32_T)ceil(*Gain2)) &&
          (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
           pacemaker_simulink_d1_P.ATR_REFRAC_PERIOD_Value)) {
        pacemaker_simulink_d1_DW.is_AAI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain4, Gain);
      } else {
        /* Constant: '<S1>/LOWER_RATE_LIMIT' incorporates:
         *  Constant: '<S1>/HYSTERESIS_INTERVAL'
         */
        tmp = rt_roundd_snf(60000.0 /
                            pacemaker_simulink_d1_P.LOWER_RATE_LIMIT_Value +
                            (real_T)
                            pacemaker_simulink_d1_P.HYSTERESIS_INTERVAL_Value);
        if (tmp < 32768.0) {
          if (tmp >= -32768.0) {
            tmp_0 = (int16_T)tmp;
          } else {
            tmp_0 = MIN_int16_T;
          }
        } else {
          tmp_0 = MAX_int16_T;
        }

        tmp = rt_roundd_snf((real_T)tmp_0 - *Gain2);
        if (tmp < 32768.0) {
          if (tmp >= -32768.0) {
            tmp_0 = (int16_T)tmp;
          } else {
            tmp_0 = MIN_int16_T;
          }
        } else {
          tmp_0 = MAX_int16_T;
        }

        if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)tmp_0) {
          pacemaker_simulink_d1_DW.is_AAI = pacemaker_simulink__IN_Pacing_g;
          pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_d1_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_d1_B.ATR_PACE_CTRL = 1.0;
          pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
        }
      }
      break;

     default:
      /* case IN_Pacing: */
      pacemaker_simulink_d1_B.FRONTEND_CTRL = 0.0;
      pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
      pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil(*Gain2))
      {
        pacemaker_simulink_d1_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain4, Gain);
      }
      break;
    }
  }

  /* End of Constant: '<S1>/MODE_SELECT' */
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Sensi(const real_T *Gain)
{
  pacemaker_simulink_d1_B.PACING_REF_PWM = *Gain;
  pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Se_mi(const real_T *Gain1)
{
  pacemaker_simulink_d1_B.PACING_REF_PWM = *Gain1;
  pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
  pacemaker_simulink_d1_B.VENT_GND_CTRL = 1.0;
}

static void pacemaker_si_SystemCore_release(const
  freedomk64f_DigitalRead_pacem_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void pacemaker_sim_SystemCore_delete(const
  freedomk64f_DigitalRead_pacem_T *obj)
{
  pacemaker_si_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacemaker_sim_SystemCore_delete(obj);
  }
}

static void pacemaker_SystemCore_release_id(const
  freedomk64f_DigitalWrite_pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void pacemaker__SystemCore_delete_id(const
  freedomk64f_DigitalWrite_pace_T *obj)
{
  pacemaker_SystemCore_release_id(obj);
}

static void matlabCodegenHandle_matlabCo_id(freedomk64f_DigitalWrite_pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacemaker__SystemCore_delete_id(obj);
  }
}

static void pa_SystemCore_release_idbp2dkpv(const
  freedomk64f_PWMOutput_pacemak_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void pac_SystemCore_delete_idbp2dkpv(const
  freedomk64f_PWMOutput_pacemak_T *obj)
{
  pa_SystemCore_release_idbp2dkpv(obj);
}

static void matlabCodegenHandle_m_idbp2dkpv(freedomk64f_PWMOutput_pacemak_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pac_SystemCore_delete_idbp2dkpv(obj);
  }
}

/* Model step function */
void pacemaker_simulink_d1_step(void)
{
  boolean_T tmp;
  real_T Gain3;
  real_T Gain2;
  boolean_T ATR_CMP_DETECT;
  real_T Gain5;
  real_T Gain4;
  real_T Gain1;
  real_T Gain;
  int16_T tmp_0;

  /* MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  if (pacemaker_simulink_d1_DW.obj.SampleTime !=
      pacemaker_simulink_d1_P.ATR_CMP_DETECT_SampleTime) {
    pacemaker_simulink_d1_DW.obj.SampleTime =
      pacemaker_simulink_d1_P.ATR_CMP_DETECT_SampleTime;
  }

  ATR_CMP_DETECT = MW_digitalIO_read
    (pacemaker_simulink_d1_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  if (pacemaker_simulink_d1_DW.obj_n.SampleTime !=
      pacemaker_simulink_d1_P.VENT_CMP_DETECT_SampleTime) {
    pacemaker_simulink_d1_DW.obj_n.SampleTime =
      pacemaker_simulink_d1_P.VENT_CMP_DETECT_SampleTime;
  }

  tmp = MW_digitalIO_read(pacemaker_simulink_d1_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<S1>/ATR_PULSE_AMP_REG'
   */
  Gain = pacemaker_simulink_d1_P.Gain_Gain *
    pacemaker_simulink_d1_P.ATR_PULSE_AMP_REG_Value;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Constant: '<S1>/VENT_PULSE_AMP_REG'
   */
  Gain1 = pacemaker_simulink_d1_P.Gain1_Gain *
    pacemaker_simulink_d1_P.VENT_PULSE_AMP_REG_Value;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Constant: '<S1>/ATR_PULSE_WIDTH'
   */
  Gain2 = pacemaker_simulink_d1_P.Gain2_Gain *
    pacemaker_simulink_d1_P.ATR_PULSE_WIDTH_Value;

  /* Gain: '<S1>/Gain3' incorporates:
   *  Constant: '<S1>/VENT_PULSE_WIDTH'
   */
  Gain3 = pacemaker_simulink_d1_P.Gain3_Gain *
    pacemaker_simulink_d1_P.VENT_PULSE_WIDTH_Value;

  /* Gain: '<S1>/Gain4' incorporates:
   *  Constant: '<S1>/ATR_SENS'
   */
  Gain4 = pacemaker_simulink_d1_P.Gain4_Gain *
    pacemaker_simulink_d1_P.ATR_SENS_Value;

  /* Gain: '<S1>/Gain5' incorporates:
   *  Constant: '<S1>/VENT_SENS'
   */
  Gain5 = pacemaker_simulink_d1_P.Gain5_Gain *
    pacemaker_simulink_d1_P.VENT_SENS_Value;

  /* Chart: '<Root>/Pacemaker' incorporates:
   *  Constant: '<S1>/HYSTERESIS'
   *  Constant: '<S1>/HYSTERESIS_INTERVAL'
   *  Constant: '<S1>/LOWER_RATE_LIMIT'
   *  Constant: '<S1>/MODE_SELECT'
   *  Constant: '<S1>/VENT_REFRAC_PERIOD'
   *  MATLABSystem: '<S1>/VENT_CMP_DETECT'
   */
  if (pacemaker_simulink_d1_DW.temporalCounter_i1 < MAX_uint32_T) {
    pacemaker_simulink_d1_DW.temporalCounter_i1++;
  }

  if (pacemaker_simulink_d1_DW.is_active_c3_pacemaker_simulink == 0U) {
    pacemaker_simulink_d1_DW.is_active_c3_pacemaker_simulink = 1U;
    pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
      pacemaker_simulink_d1_IN_Start;
  } else {
    switch (pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1) {
     case pacemaker_simulink_d1_IN_AAI:
      pacemaker_simulink_d1_AAI(&Gain2, &ATR_CMP_DETECT, &Gain4, &Gain);
      break;

     case pacemaker_simulink_d1_IN_AOO:
      if (pacemaker_simulink_d1_P.MODE_SELECT_Value != 0) {
        pacemaker_simulink_d1_DW.is_AOO = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_Start;
      } else if (pacemaker_simulink_d1_DW.is_AOO ==
                 pacemak_IN_Charging_and_Sensing) {
        pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
        pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_d1_B.ATR_GND_CTRL = 1.0;
        pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
        if ((pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
             (60000.0 / pacemaker_simulink_d1_P.LOWER_RATE_LIMIT_Value - Gain2))
            && (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
                (60000.0 / pacemaker_simulink_d1_P.UPPER_RATE_LIMIT_Value -
                 Gain2))) {
          pacemaker_simulink_d1_DW.is_AOO = pacemaker_simulink_d1_IN_Pacing;
          pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_d1_B.ATR_PACE_CTRL = 1.0;
          pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_PACE_CTRL = 0.0;
        }
      } else {
        /* case IN_Pacing: */
        pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
        if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil(Gain2))
        {
          pacemaker_simulink_d1_DW.is_AOO = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Sensi(&Gain);
        }
      }
      break;

     case pacemaker_simulink_d1_IN_Start:
      switch (pacemaker_simulink_d1_P.MODE_SELECT_Value) {
       case 0:
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_AOO;
        pacemaker_simulink_d1_DW.is_AOO = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sensi(&Gain);
        break;

       case 1:
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_VOO;
        pacemaker_simulink_d1_DW.is_VOO = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Se_mi(&Gain1);
        break;

       case 2:
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_AAI;
        pacemaker_simulink_d1_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(&Gain4, &Gain);
        break;

       case 3:
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_VVI;
        pacemaker_simulink_d1_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(&Gain5, &Gain1);
        break;
      }
      break;

     case pacemaker_simulink_d1_IN_VOO:
      if (pacemaker_simulink_d1_P.MODE_SELECT_Value != 1) {
        pacemaker_simulink_d1_DW.is_VOO = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_Start;
      } else if (pacemaker_simulink_d1_DW.is_VOO ==
                 pacemak_IN_Charging_and_Sensing) {
        pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
        pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_d1_B.VENT_GND_CTRL = 1.0;
        if ((pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
             (60000.0 / pacemaker_simulink_d1_P.LOWER_RATE_LIMIT_Value - Gain3))
            && (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
                (60000.0 / pacemaker_simulink_d1_P.UPPER_RATE_LIMIT_Value -
                 Gain3))) {
          pacemaker_simulink_d1_DW.is_VOO = pacemaker_simulink_d1_IN_Pacing;
          pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
          pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_PACE_CTRL = 1.0;
        }
      } else {
        /* case IN_Pacing: */
        pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
        if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil(Gain3))
        {
          pacemaker_simulink_d1_DW.is_VOO = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Se_mi(&Gain1);
        }
      }
      break;

     default:
      /* case IN_VVI: */
      if (pacemaker_simulink_d1_P.MODE_SELECT_Value != 3) {
        pacemaker_simulink_d1_DW.is_VVI = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_d1_DW.is_c3_pacemaker_simulink_d1 =
          pacemaker_simulink_d1_IN_Start;
      } else {
        switch (pacemaker_simulink_d1_DW.is_VVI) {
         case pacemak_IN_Charging_and_Sensing:
          pacemaker_simulink_d1_B.FRONTEND_CTRL = 1.0;
          pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
          pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_GND_CTRL = 1.0;
          if (pacemaker_simulink_d1_P.HYSTERESIS_Value && tmp &&
              (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
               (Gain3)) && (pacemaker_simulink_d1_DW.temporalCounter_i1 >=
                            (uint32_T)
                            pacemaker_simulink_d1_P.VENT_REFRAC_PERIOD_Value)) {
            pacemaker_simulink_d1_DW.is_VVI = pacemaker_simulin_IN_Hysteresis;
            pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
            enter_atomic_Charging_and_Sen_m(&Gain5, &Gain1);
          } else if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
                     ceil(60000.0 /
                          pacemaker_simulink_d1_P.LOWER_RATE_LIMIT_Value - Gain3))
          {
            pacemaker_simulink_d1_DW.is_VVI = pacemaker_simulink__IN_Pacing_g;
            pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
            pacemaker_simulink_d1_B.FRONTEND_CTRL = 0.0;
            pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
            pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
            pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
            pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
            pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
            pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
            pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
            pacemaker_simulink_d1_B.VENT_PACE_CTRL = 1.0;
          } else {
            if ((!pacemaker_simulink_d1_P.HYSTERESIS_Value) && tmp &&
                (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
                 (Gain3)) && (pacemaker_simulink_d1_DW.temporalCounter_i1 >=
                              (uint32_T)
                              pacemaker_simulink_d1_P.VENT_REFRAC_PERIOD_Value))
            {
              pacemaker_simulink_d1_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
              pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
              enter_atomic_Charging_and_Sen_m(&Gain5, &Gain1);
            }
          }
          break;

         case pacemaker_simulin_IN_Hysteresis:
          pacemaker_simulink_d1_B.FRONTEND_CTRL = 1.0;
          pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 1.0;
          pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_GND_CTRL = 1.0;
          if (tmp && (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
                      ceil(Gain3)) &&
              (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)
               pacemaker_simulink_d1_P.VENT_REFRAC_PERIOD_Value)) {
            pacemaker_simulink_d1_DW.is_VVI = pacemaker_simulin_IN_Hysteresis;
            pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
            enter_atomic_Charging_and_Sen_m(&Gain5, &Gain1);
          } else {
            Gain = rt_roundd_snf(60000.0 /
                                 pacemaker_simulink_d1_P.LOWER_RATE_LIMIT_Value
                                 + (real_T)
                                 pacemaker_simulink_d1_P.HYSTERESIS_INTERVAL_Value);
            if (Gain < 32768.0) {
              if (Gain >= -32768.0) {
                tmp_0 = (int16_T)Gain;
              } else {
                tmp_0 = MIN_int16_T;
              }
            } else {
              tmp_0 = MAX_int16_T;
            }

            Gain = rt_roundd_snf((real_T)tmp_0 - Gain3);
            if (Gain < 32768.0) {
              if (Gain >= -32768.0) {
                tmp_0 = (int16_T)Gain;
              } else {
                tmp_0 = MIN_int16_T;
              }
            } else {
              tmp_0 = MAX_int16_T;
            }

            if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)tmp_0)
            {
              pacemaker_simulink_d1_DW.is_VVI = pacemaker_simulink__IN_Pacing_g;
              pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
              pacemaker_simulink_d1_B.FRONTEND_CTRL = 0.0;
              pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
              pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
              pacemaker_simulink_d1_B.ATR_PACE_CTRL = 0.0;
              pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
              pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
              pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
              pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
              pacemaker_simulink_d1_B.VENT_PACE_CTRL = 1.0;
            }
          }
          break;

         default:
          /* case IN_Pacing: */
          pacemaker_simulink_d1_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_d1_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_d1_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_d1_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_d1_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_d1_B.VENT_GND_CTRL = 0.0;
          if (pacemaker_simulink_d1_DW.temporalCounter_i1 >= (uint32_T)ceil
              (Gain3)) {
            pacemaker_simulink_d1_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
            pacemaker_simulink_d1_DW.temporalCounter_i1 = 0U;
            enter_atomic_Charging_and_Sen_m(&Gain5, &Gain1);
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Pacemaker' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_l.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/PWM Output' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_d1_DW.obj_o.MW_PWM_HANDLE,
                      pacemaker_simulink_d1_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_lo.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S2>/PWM Output1' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_d1_DW.obj_f.MW_PWM_HANDLE,
                      pacemaker_simulink_d1_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/PWM Output2' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_d1_DW.obj_c.MW_PWM_HANDLE,
                      pacemaker_simulink_d1_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S2>/Digital Write2' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_na.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_e.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_i.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_b.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_p.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(pacemaker_simulink_d1_DW.obj_em.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_d1_B.FRONTEND_CTRL != 0.0);
}

/* Model initialize function */
void pacemaker_simulink_d1_initialize(void)
{
  {
    freedomk64f_DigitalRead_pacem_T *obj;
    freedomk64f_DigitalWrite_pace_T *obj_0;
    freedomk64f_PWMOutput_pacemak_T *obj_1;

    /* Start for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
    pacemaker_simulink_d1_DW.obj.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj.SampleTime = -1.0;
    pacemaker_simulink_d1_DW.obj.matlabCodegenIsDeleted = false;
    pacemaker_simulink_d1_DW.obj.SampleTime =
      pacemaker_simulink_d1_P.ATR_CMP_DETECT_SampleTime;
    obj = &pacemaker_simulink_d1_DW.obj;
    pacemaker_simulink_d1_DW.obj.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    pacemaker_simulink_d1_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
    pacemaker_simulink_d1_DW.obj_n.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_n.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_n.SampleTime = -1.0;
    pacemaker_simulink_d1_DW.obj_n.matlabCodegenIsDeleted = false;
    pacemaker_simulink_d1_DW.obj_n.SampleTime =
      pacemaker_simulink_d1_P.VENT_CMP_DETECT_SampleTime;
    obj = &pacemaker_simulink_d1_DW.obj_n;
    pacemaker_simulink_d1_DW.obj_n.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    pacemaker_simulink_d1_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    pacemaker_simulink_d1_DW.obj_l.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_l.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_l;
    pacemaker_simulink_d1_DW.obj_l.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    pacemaker_simulink_d1_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    pacemaker_simulink_d1_DW.obj_o.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_o.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_d1_DW.obj_o;
    pacemaker_simulink_d1_DW.obj_o.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_o.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_d1_DW.obj_o.MW_PWM_HANDLE);
    pacemaker_simulink_d1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    pacemaker_simulink_d1_DW.obj_lo.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_lo.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_lo.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_lo;
    pacemaker_simulink_d1_DW.obj_lo.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_lo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    pacemaker_simulink_d1_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output1' */
    pacemaker_simulink_d1_DW.obj_f.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_f.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_d1_DW.obj_f;
    pacemaker_simulink_d1_DW.obj_f.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_d1_DW.obj_f.MW_PWM_HANDLE);
    pacemaker_simulink_d1_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output2' */
    pacemaker_simulink_d1_DW.obj_c.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_c.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_d1_DW.obj_c;
    pacemaker_simulink_d1_DW.obj_c.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_c.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_d1_DW.obj_c.MW_PWM_HANDLE);
    pacemaker_simulink_d1_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write2' */
    pacemaker_simulink_d1_DW.obj_na.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_na.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_na.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_na;
    pacemaker_simulink_d1_DW.obj_na.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_na.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    pacemaker_simulink_d1_DW.obj_na.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    pacemaker_simulink_d1_DW.obj_e.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_e.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_e;
    pacemaker_simulink_d1_DW.obj_e.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    pacemaker_simulink_d1_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    pacemaker_simulink_d1_DW.obj_m.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_m.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_m;
    pacemaker_simulink_d1_DW.obj_m.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    pacemaker_simulink_d1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    pacemaker_simulink_d1_DW.obj_i.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_i.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_i;
    pacemaker_simulink_d1_DW.obj_i.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    pacemaker_simulink_d1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    pacemaker_simulink_d1_DW.obj_b.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_b.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_b;
    pacemaker_simulink_d1_DW.obj_b.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    pacemaker_simulink_d1_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    pacemaker_simulink_d1_DW.obj_p.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_p.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_p;
    pacemaker_simulink_d1_DW.obj_p.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    pacemaker_simulink_d1_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    pacemaker_simulink_d1_DW.obj_em.matlabCodegenIsDeleted = true;
    pacemaker_simulink_d1_DW.obj_em.isInitialized = 0;
    pacemaker_simulink_d1_DW.obj_em.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_d1_DW.obj_em;
    pacemaker_simulink_d1_DW.obj_em.isSetupComplete = false;
    pacemaker_simulink_d1_DW.obj_em.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    pacemaker_simulink_d1_DW.obj_em.isSetupComplete = true;
  }
}

/* Model terminate function */
void pacemaker_simulink_d1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_d1_DW.obj);

  /* Terminate for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_d1_DW.obj_n);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_l);

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  matlabCodegenHandle_m_idbp2dkpv(&pacemaker_simulink_d1_DW.obj_o);

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_lo);

  /* Terminate for MATLABSystem: '<S2>/PWM Output1' */
  matlabCodegenHandle_m_idbp2dkpv(&pacemaker_simulink_d1_DW.obj_f);

  /* Terminate for MATLABSystem: '<S2>/PWM Output2' */
  matlabCodegenHandle_m_idbp2dkpv(&pacemaker_simulink_d1_DW.obj_c);

  /* Terminate for MATLABSystem: '<S2>/Digital Write2' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_na);

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_e);

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_m);

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_i);

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_b);

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_p);

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  matlabCodegenHandle_matlabCo_id(&pacemaker_simulink_d1_DW.obj_em);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
