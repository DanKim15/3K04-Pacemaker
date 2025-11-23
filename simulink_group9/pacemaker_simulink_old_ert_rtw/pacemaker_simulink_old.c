/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink_old.c
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

/* Named constants for Chart: '<Root>/Pacemaker' */
#define pacemak_IN_Charging_and_Sensing ((uint8_T)1U)
#define pacemaker_si_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define pacemaker_simulin_IN_Hysteresis ((uint8_T)2U)
#define pacemaker_simulink__IN_Pacing_g ((uint8_T)3U)
#define pacemaker_simulink_ol_IN_Pacing ((uint8_T)2U)
#define pacemaker_simulink_old_IN_AAI  ((uint8_T)1U)
#define pacemaker_simulink_old_IN_AOO  ((uint8_T)2U)
#define pacemaker_simulink_old_IN_Start ((uint8_T)3U)
#define pacemaker_simulink_old_IN_VOO  ((uint8_T)4U)
#define pacemaker_simulink_old_IN_VVI  ((uint8_T)5U)

/* Named constants for Chart: '<S6>/UART_Interface' */
#define pacemaker_simulink_old_IN_INIT ((uint8_T)1U)
#define pacemaker_simulink_old_IN_RUN  ((uint8_T)2U)

/* Block signals (default storage) */
B_pacemaker_simulink_old_T pacemaker_simulink_old_B;

/* Block states (default storage) */
DW_pacemaker_simulink_old_T pacemaker_simulink_old_DW;

/* Real-time model */
RT_MODEL_pacemaker_simulink_o_T pacemaker_simulink_old_M_;
RT_MODEL_pacemaker_simulink_o_T *const pacemaker_simulink_old_M =
  &pacemaker_simulink_old_M_;

/* Forward declaration for local functions */
static void enter_atomic_Charging_and_Sen_m(const uint32_T *Gain1);
static void pacemaker_simulink_old_VVI(const uint16_T *sensor_LRI_ms, const
  uint16_T *base_LRI_ms, const uint8_T *DS_MODE_SELECT, const uint32_T *Gain1,
  const uint16_T *DS_VENT_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS);
static void enter_atomic_Charging_and_S_mil(const uint32_T *Gain);
static void pacemaker_simulink_old_AAI(const uint16_T *sensor_LRI_ms, const
  uint16_T *base_LRI_ms, const uint8_T *DS_MODE_SELECT, const uint32_T *Gain,
  const uint16_T *DS_ATR_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS);
static void enter_atomic_Charging_and_Sensi(const uint32_T *Gain);
static void enter_atomic_Charging_and_Se_mi(const uint32_T *Gain1);
static void p_SystemCore_rele_h(const freedomk64f_SCIRead_pacemaker_T *obj);
static void p_SystemCore_dele_h(const freedomk64f_SCIRead_pacemaker_T *obj);
static void pacemaker_sim_matlabCodegenHa_h(freedomk64f_SCIRead_pacemaker_T *obj);
static void p_SystemCore_rele_n(const freedomk64f_SCIWrite_pacemake_T *obj);
static void p_SystemCore_dele_n(const freedomk64f_SCIWrite_pacemake_T *obj);
static void pacemaker_sim_matlabCodegenHa_n(freedomk64f_SCIWrite_pacemake_T *obj);
static void SystemCore_relea_bwuptiarv0qumm(const
  freedomk64f_DigitalRead_pacem_T *obj);
static void SystemCore_delet_bwuptiarv0qumm(const
  freedomk64f_DigitalRead_pacem_T *obj);
static void matlabCodegenHan_bwuptiarv0qumm(freedomk64f_DigitalRead_pacem_T *obj);
static void SystemCore_release_bwuptiarv0qu(const
  freedomk64f_fxos8700_pacemake_T *obj);
static void SystemCore_delete_bwuptiarv0qu(const freedomk64f_fxos8700_pacemake_T
  *obj);
static void matlabCodegenHandl_bwuptiarv0qu(freedomk64f_fxos8700_pacemake_T *obj);
static void SystemCore_releas_bwuptiarv0qum(b_freedomk64f_I2CMasterWrite__T *obj);
static void SystemCore_delete_bwuptiarv0qum(b_freedomk64f_I2CMasterWrite__T *obj);
static void matlabCodegenHand_bwuptiarv0qum(b_freedomk64f_I2CMasterWrite__T *obj);
static void pacemaker_si_SystemCore_release(const
  freedomk64f_DigitalWrite_pace_T *obj);
static void pacemaker_sim_SystemCore_delete(const
  freedomk64f_DigitalWrite_pace_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_pace_T *obj);
static void pace_SystemCore_release_bwuptia(const
  freedomk64f_PWMOutput_pacemak_T *obj);
static void pacem_SystemCore_delete_bwuptia(const
  freedomk64f_PWMOutput_pacemak_T *obj);
static void matlabCodegenHandle_mat_bwuptia(freedomk64f_PWMOutput_pacemak_T *obj);
static void pacemaker_s_SystemCore_setup_bw(freedomk64f_SCIWrite_pacemake_T *obj);
static void pacemaker_si_SystemCore_setup_b(freedomk64f_SCIRead_pacemaker_T *obj);
static void pacemaker_simu_SystemCore_setup(freedomk64f_fxos8700_pacemake_T *obj);
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
static void enter_atomic_Charging_and_Sen_m(const uint32_T *Gain1)
{
  pacemaker_simulink_old_B.FRONTEND_CTRL = 1.0;
  pacemaker_simulink_old_B.PACING_REF_PWM = *Gain1;
  pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
  pacemaker_simulink_old_B.VENT_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_CMP_REF_PWM = pacemaker_simulink_old_B.Gain5;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void pacemaker_simulink_old_VVI(const uint16_T *sensor_LRI_ms, const
  uint16_T *base_LRI_ms, const uint8_T *DS_MODE_SELECT, const uint32_T *Gain1,
  const uint16_T *DS_VENT_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS)
{
  uint16_T current_LRI_ms;
  uint32_T qY;
  uint32_T tmp;

  /* DataStoreRead: '<S3>/Data Store Read' incorporates:
   *  Constant: '<S3>/HYSTERESIS_INTERVAL'
   *  DataStoreRead: '<S3>/Data Store Read6'
   *  DataStoreRead: '<S3>/Data Store Read8'
   *  DataStoreRead: '<S3>/Data Store Read9'
   */
  if ((*DS_MODE_SELECT != 3) && (*DS_MODE_SELECT != 7)) {
    pacemaker_simulink_old_DW.is_VVI = pacemaker_si_IN_NO_ACTIVE_CHILD;
    pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
      pacemaker_simulink_old_IN_Start;
  } else {
    if ((*DS_MODE_SELECT == 0) || (*DS_MODE_SELECT == 1) || (*DS_MODE_SELECT ==
         2) || (*DS_MODE_SELECT == 3)) {
      current_LRI_ms = *base_LRI_ms;
    } else {
      current_LRI_ms = *sensor_LRI_ms;
    }

    switch (pacemaker_simulink_old_DW.is_VVI) {
     case pacemak_IN_Charging_and_Sensing:
      pacemaker_simulink_old_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_old_B.VENT_GND_CTRL = 1.0;
      if ((*DS_HYSTERESIS) && pacemaker_simulink_old_B.VENT_CMP_DETECT &&
          (pacemaker_simulink_old_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH)
          && (pacemaker_simulink_old_DW.temporalCounter_i1 >=
              pacemaker_simulink_old_DW.DS_VENT_REFRAC_PERIOD)) {
        pacemaker_simulink_old_DW.is_VVI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(Gain1);
      } else {
        qY = (uint32_T)current_LRI_ms - /*MW:OvSatOk*/ *DS_VENT_PULSE_WIDTH;
        if (qY > current_LRI_ms) {
          qY = 0U;
        }

        if (pacemaker_simulink_old_DW.temporalCounter_i1 >= qY) {
          pacemaker_simulink_old_DW.is_VVI = pacemaker_simulink__IN_Pacing_g;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_old_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
          pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_old_B.VENT_PACE_CTRL = 1.0;
        } else {
          if ((!*DS_HYSTERESIS) && pacemaker_simulink_old_B.VENT_CMP_DETECT &&
              (pacemaker_simulink_old_DW.temporalCounter_i1 >=
               *DS_VENT_PULSE_WIDTH) &&
              (pacemaker_simulink_old_DW.temporalCounter_i1 >=
               pacemaker_simulink_old_DW.DS_VENT_REFRAC_PERIOD)) {
            pacemaker_simulink_old_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
            pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
            enter_atomic_Charging_and_Sen_m(Gain1);
          }
        }
      }
      break;

     case pacemaker_simulin_IN_Hysteresis:
      pacemaker_simulink_old_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_old_B.VENT_GND_CTRL = 1.0;
      if (pacemaker_simulink_old_B.VENT_CMP_DETECT &&
          (pacemaker_simulink_old_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH)
          && (pacemaker_simulink_old_DW.temporalCounter_i1 >=
              pacemaker_simulink_old_DW.DS_VENT_REFRAC_PERIOD)) {
        pacemaker_simulink_old_DW.is_VVI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(Gain1);
      } else {
        tmp = (uint32_T)current_LRI_ms +
          pacemaker_simulink_old_P.HYSTERESIS_INTERVAL_Value;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        qY = tmp - /*MW:OvSatOk*/ *DS_VENT_PULSE_WIDTH;
        if (qY > tmp) {
          qY = 0U;
        }

        if (pacemaker_simulink_old_DW.temporalCounter_i1 >= qY) {
          pacemaker_simulink_old_DW.is_VVI = pacemaker_simulink__IN_Pacing_g;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_old_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
          pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_old_B.VENT_PACE_CTRL = 1.0;
        }
      }
      break;

     default:
      /* case IN_Pacing: */
      pacemaker_simulink_old_B.FRONTEND_CTRL = 0.0;
      pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
      pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_old_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH)
      {
        pacemaker_simulink_old_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(Gain1);
      }
      break;
    }
  }

  /* End of DataStoreRead: '<S3>/Data Store Read' */
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_S_mil(const uint32_T *Gain)
{
  pacemaker_simulink_old_B.FRONTEND_CTRL = 1.0;
  pacemaker_simulink_old_B.PACING_REF_PWM = *Gain;
  pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_CMP_REF_PWM = pacemaker_simulink_old_B.Gain4;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void pacemaker_simulink_old_AAI(const uint16_T *sensor_LRI_ms, const
  uint16_T *base_LRI_ms, const uint8_T *DS_MODE_SELECT, const uint32_T *Gain,
  const uint16_T *DS_ATR_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS)
{
  uint16_T current_LRI_ms;
  uint32_T qY;
  uint32_T tmp;

  /* DataStoreRead: '<S3>/Data Store Read' incorporates:
   *  Constant: '<S3>/HYSTERESIS_INTERVAL'
   *  DataStoreRead: '<S3>/Data Store Read5'
   *  DataStoreRead: '<S3>/Data Store Read7'
   *  DataStoreRead: '<S3>/Data Store Read9'
   */
  if ((*DS_MODE_SELECT != 2) && (*DS_MODE_SELECT != 6)) {
    pacemaker_simulink_old_DW.is_AAI = pacemaker_si_IN_NO_ACTIVE_CHILD;
    pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
      pacemaker_simulink_old_IN_Start;
  } else {
    if ((*DS_MODE_SELECT == 0) || (*DS_MODE_SELECT == 1) || (*DS_MODE_SELECT ==
         2) || (*DS_MODE_SELECT == 3)) {
      current_LRI_ms = *base_LRI_ms;
    } else {
      current_LRI_ms = *sensor_LRI_ms;
    }

    switch (pacemaker_simulink_old_DW.is_AAI) {
     case pacemak_IN_Charging_and_Sensing:
      pacemaker_simulink_old_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_old_B.ATR_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
      qY = (uint32_T)current_LRI_ms - /*MW:OvSatOk*/ *DS_ATR_PULSE_WIDTH;
      if (qY > current_LRI_ms) {
        qY = 0U;
      }

      if (pacemaker_simulink_old_DW.temporalCounter_i1 >= qY) {
        pacemaker_simulink_old_DW.is_AAI = pacemaker_simulink__IN_Pacing_g;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        pacemaker_simulink_old_B.FRONTEND_CTRL = 0.0;
        pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_old_B.ATR_PACE_CTRL = 1.0;
        pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
        pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
      } else if ((!*DS_HYSTERESIS) && pacemaker_simulink_old_B.ATR_CMP_DETECT &&
                 (pacemaker_simulink_old_DW.temporalCounter_i1 >=
                  *DS_ATR_PULSE_WIDTH) &&
                 (pacemaker_simulink_old_DW.temporalCounter_i1 >=
                  pacemaker_simulink_old_DW.DS_ATR_REFRAC_PERIOD)) {
        pacemaker_simulink_old_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain);
      } else {
        if ((*DS_HYSTERESIS) && pacemaker_simulink_old_B.ATR_CMP_DETECT &&
            (pacemaker_simulink_old_DW.temporalCounter_i1 >= *DS_ATR_PULSE_WIDTH)
            && (pacemaker_simulink_old_DW.temporalCounter_i1 >=
                pacemaker_simulink_old_DW.DS_ATR_REFRAC_PERIOD)) {
          pacemaker_simulink_old_DW.is_AAI = pacemaker_simulin_IN_Hysteresis;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_S_mil(Gain);
        }
      }
      break;

     case pacemaker_simulin_IN_Hysteresis:
      pacemaker_simulink_old_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_old_B.ATR_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_old_B.ATR_CMP_DETECT &&
          (pacemaker_simulink_old_DW.temporalCounter_i1 >= *DS_ATR_PULSE_WIDTH) &&
          (pacemaker_simulink_old_DW.temporalCounter_i1 >=
           pacemaker_simulink_old_DW.DS_ATR_REFRAC_PERIOD)) {
        pacemaker_simulink_old_DW.is_AAI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain);
      } else {
        tmp = (uint32_T)current_LRI_ms +
          pacemaker_simulink_old_P.HYSTERESIS_INTERVAL_Value;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        qY = tmp - /*MW:OvSatOk*/ *DS_ATR_PULSE_WIDTH;
        if (qY > tmp) {
          qY = 0U;
        }

        if (pacemaker_simulink_old_DW.temporalCounter_i1 >= qY) {
          pacemaker_simulink_old_DW.is_AAI = pacemaker_simulink__IN_Pacing_g;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_old_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_old_B.ATR_PACE_CTRL = 1.0;
          pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
        }
      }
      break;

     default:
      /* case IN_Pacing: */
      pacemaker_simulink_old_B.FRONTEND_CTRL = 0.0;
      pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
      pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_old_DW.temporalCounter_i1 >= *DS_ATR_PULSE_WIDTH) {
        pacemaker_simulink_old_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain);
      }
      break;
    }
  }

  /* End of DataStoreRead: '<S3>/Data Store Read' */
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Sensi(const uint32_T *Gain)
{
  pacemaker_simulink_old_B.PACING_REF_PWM = *Gain;
  pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Se_mi(const uint32_T *Gain1)
{
  pacemaker_simulink_old_B.PACING_REF_PWM = *Gain1;
  pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
  pacemaker_simulink_old_B.VENT_GND_CTRL = 1.0;
}

static void p_SystemCore_rele_h(const freedomk64f_SCIRead_pacemaker_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void p_SystemCore_dele_h(const freedomk64f_SCIRead_pacemaker_T *obj)
{
  p_SystemCore_rele_h(obj);
}

static void pacemaker_sim_matlabCodegenHa_h(freedomk64f_SCIRead_pacemaker_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    p_SystemCore_dele_h(obj);
  }
}

static void p_SystemCore_rele_n(const freedomk64f_SCIWrite_pacemake_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void p_SystemCore_dele_n(const freedomk64f_SCIWrite_pacemake_T *obj)
{
  p_SystemCore_rele_n(obj);
}

static void pacemaker_sim_matlabCodegenHa_n(freedomk64f_SCIWrite_pacemake_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    p_SystemCore_dele_n(obj);
  }
}

static void SystemCore_relea_bwuptiarv0qumm(const
  freedomk64f_DigitalRead_pacem_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void SystemCore_delet_bwuptiarv0qumm(const
  freedomk64f_DigitalRead_pacem_T *obj)
{
  SystemCore_relea_bwuptiarv0qumm(obj);
}

static void matlabCodegenHan_bwuptiarv0qumm(freedomk64f_DigitalRead_pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_bwuptiarv0qumm(obj);
  }
}

static void SystemCore_release_bwuptiarv0qu(const
  freedomk64f_fxos8700_pacemake_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void SystemCore_delete_bwuptiarv0qu(const freedomk64f_fxos8700_pacemake_T
  *obj)
{
  SystemCore_release_bwuptiarv0qu(obj);
}

static void matlabCodegenHandl_bwuptiarv0qu(freedomk64f_fxos8700_pacemake_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_bwuptiarv0qu(obj);
  }
}

static void SystemCore_releas_bwuptiarv0qum(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void SystemCore_delete_bwuptiarv0qum(b_freedomk64f_I2CMasterWrite__T *obj)
{
  SystemCore_releas_bwuptiarv0qum(obj);
}

static void matlabCodegenHand_bwuptiarv0qum(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delete_bwuptiarv0qum(obj);
  }
}

static void pacemaker_si_SystemCore_release(const
  freedomk64f_DigitalWrite_pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void pacemaker_sim_SystemCore_delete(const
  freedomk64f_DigitalWrite_pace_T *obj)
{
  pacemaker_si_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacemaker_sim_SystemCore_delete(obj);
  }
}

static void pace_SystemCore_release_bwuptia(const
  freedomk64f_PWMOutput_pacemak_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void pacem_SystemCore_delete_bwuptia(const
  freedomk64f_PWMOutput_pacemak_T *obj)
{
  pace_SystemCore_release_bwuptia(obj);
}

static void matlabCodegenHandle_mat_bwuptia(freedomk64f_PWMOutput_pacemak_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacem_SystemCore_delete_bwuptia(obj);
  }
}

static void pacemaker_s_SystemCore_setup_bw(freedomk64f_SCIWrite_pacemake_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void pacemaker_si_SystemCore_setup_b(freedomk64f_SCIRead_pacemaker_T *obj)
{
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void pacemaker_simu_SystemCore_setup(freedomk64f_fxos8700_pacemake_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_RegisterValue;
  uint8_T b_SwappedDataBytes[2];
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 3U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 92U;
  b_SwappedDataBytes[1] = 32U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void pacemaker_simulink_old_step(void)
{
  real_T recovery_time;
  uint8_T status;
  uint8_T y[2];
  uint8_T b_x[2];
  int16_T y_0;
  real_T rtb_rs_bpm;
  real_T rtb_activity_sat;
  int32_T i;
  uint32_T Gain1;
  uint32_T Gain;
  uint16_T tmp;
  uint16_T tmp_0;

  /* MATLABSystem: '<S6>/UART Receive' */
  if (pacemaker_simulink_old_DW.obj_m.SampleTime !=
      pacemaker_simulink_old_P.UARTReceive_SampleTime) {
    pacemaker_simulink_old_DW.obj_m.SampleTime =
      pacemaker_simulink_old_P.UARTReceive_SampleTime;
  }

  status = MW_SCI_Receive(pacemaker_simulink_old_DW.obj_m.MW_SCIHANDLE,
    pacemaker_simulink_old_B.RxDataLocChar, 20U);
  memcpy((void *)&pacemaker_simulink_old_B.RxData[0], (void *)
         &pacemaker_simulink_old_B.RxDataLocChar[0], (uint32_T)((size_t)20 *
          sizeof(uint8_T)));

  /* Chart: '<S6>/UART_Interface' incorporates:
   *  MATLABSystem: '<S6>/UART Receive'
   */
  if (pacemaker_simulink_old_DW.is_active_c1_pacemaker_simulink == 0U) {
    pacemaker_simulink_old_DW.is_active_c1_pacemaker_simulink = 1U;
    pacemaker_simulink_old_DW.is_c1_pacemaker_simulink_old =
      pacemaker_simulink_old_IN_INIT;
    pacemaker_simulink_old_B.MODE_SELECT_out = 0U;
    pacemaker_simulink_old_B.HYSTERESIS_out = false;
    pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out = 60U;
    pacemaker_simulink_old_B.UPPER_RATE_LIMIT_out = 120U;
    pacemaker_simulink_old_B.ATR_PULSE_AMP_REG_out = 7U;
    pacemaker_simulink_old_B.VENT_PULSE_AMP_REG_out = 7U;
    pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out = 40U;
    pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out = 40U;
    pacemaker_simulink_old_B.ATR_REFRAC_PERIOD_out = 250U;
    pacemaker_simulink_old_B.VENT_REFRAC_PERIOD_out = 320U;
    pacemaker_simulink_old_B.echo_request = false;
  } else if (pacemaker_simulink_old_DW.is_c1_pacemaker_simulink_old == 1) {
    pacemaker_simulink_old_DW.is_c1_pacemaker_simulink_old =
      pacemaker_simulink_old_IN_RUN;
  } else {
    /* case IN_RUN: */
    pacemaker_simulink_old_B.echo_request = false;
    if ((status == 0) && (pacemaker_simulink_old_B.RxData[0] == 22)) {
      switch (pacemaker_simulink_old_B.RxData[1]) {
       case 1:
        pacemaker_simulink_old_B.MODE_SELECT_out =
          pacemaker_simulink_old_B.RxData[2];
        pacemaker_simulink_old_B.HYSTERESIS_out =
          (pacemaker_simulink_old_B.RxData[3] != 0);
        pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[4] << 8 |
           pacemaker_simulink_old_B.RxData[5]);
        pacemaker_simulink_old_B.UPPER_RATE_LIMIT_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[6] << 8 |
           pacemaker_simulink_old_B.RxData[7]);
        pacemaker_simulink_old_B.ATR_PULSE_AMP_REG_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[8] << 8 |
           pacemaker_simulink_old_B.RxData[9]);
        pacemaker_simulink_old_B.VENT_PULSE_AMP_REG_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[10] << 8 |
           pacemaker_simulink_old_B.RxData[11]);
        pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[12] << 8 |
           pacemaker_simulink_old_B.RxData[13]);
        pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[14] << 8 |
           pacemaker_simulink_old_B.RxData[15]);
        pacemaker_simulink_old_B.ATR_REFRAC_PERIOD_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[16] << 8 |
           pacemaker_simulink_old_B.RxData[17]);
        pacemaker_simulink_old_B.VENT_REFRAC_PERIOD_out = (uint16_T)
          (pacemaker_simulink_old_B.RxData[18] << 8 |
           pacemaker_simulink_old_B.RxData[19]);
        break;

       case 2:
        pacemaker_simulink_old_B.echo_request = true;
        break;
      }
    }
  }

  /* End of Chart: '<S6>/UART_Interface' */

  /* DataStoreWrite: '<S6>/Data Store Write8' */
  pacemaker_simulink_old_DW.DS_ATR_REFRAC_PERIOD =
    pacemaker_simulink_old_B.ATR_REFRAC_PERIOD_out;

  /* DataStoreWrite: '<S6>/Data Store Write9' */
  pacemaker_simulink_old_DW.DS_VENT_REFRAC_PERIOD =
    pacemaker_simulink_old_B.VENT_REFRAC_PERIOD_out;

  /* DataStoreRead: '<S6>/Data Store Read' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write'
   */
  pacemaker_simulink_old_B.DataStoreRead =
    pacemaker_simulink_old_B.MODE_SELECT_out;

  /* DataStoreRead: '<S6>/Data Store Read1' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write2'
   */
  pacemaker_simulink_old_B.DataStoreRead1 =
    pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out;

  /* DataStoreRead: '<S6>/Data Store Read2' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write3'
   */
  pacemaker_simulink_old_B.DataStoreRead2 =
    pacemaker_simulink_old_B.UPPER_RATE_LIMIT_out;

  /* DataStoreRead: '<S6>/Data Store Read3' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write4'
   */
  pacemaker_simulink_old_B.DataStoreRead3 =
    pacemaker_simulink_old_B.ATR_PULSE_AMP_REG_out;

  /* DataStoreRead: '<S6>/Data Store Read4' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write5'
   */
  pacemaker_simulink_old_B.DataStoreRead4 =
    pacemaker_simulink_old_B.VENT_PULSE_AMP_REG_out;

  /* DataStoreRead: '<S6>/Data Store Read5' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write6'
   */
  pacemaker_simulink_old_B.DataStoreRead5 =
    pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out;

  /* DataStoreRead: '<S6>/Data Store Read6' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write7'
   */
  pacemaker_simulink_old_B.DataStoreRead6 =
    pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out;

  /* DataStoreRead: '<S6>/Data Store Read7' */
  pacemaker_simulink_old_B.DataStoreRead7 =
    pacemaker_simulink_old_DW.DS_ATR_REFRAC_PERIOD;

  /* DataStoreRead: '<S6>/Data Store Read8' */
  pacemaker_simulink_old_B.DataStoreRead8 =
    pacemaker_simulink_old_DW.DS_VENT_REFRAC_PERIOD;

  /* Outputs for Enabled SubSystem: '<S6>/UART_Tx' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (pacemaker_simulink_old_B.echo_request) {
    /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
     *  DataStoreWrite: '<S6>/Data Store Write1'
     */
    pacemaker_simulink_old_B.DataTypeConversion1 =
      pacemaker_simulink_old_B.HYSTERESIS_out;

    /* S-Function (any2byte): '<S11>/Byte Pack' incorporates:
     *  Constant: '<S11>/MSGTYPE_TX'
     *  Constant: '<S11>/SYNC_TX'
     */

    /* Pack: <S11>/Byte Pack */
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[0],
                  &pacemaker_simulink_old_P.SYNC_TX_Value,
                  1);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[1],
                  &pacemaker_simulink_old_P.MSGTYPE_TX_Value,
                  1);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[2],
                  &pacemaker_simulink_old_B.DataStoreRead,
                  1);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[3],
                  &pacemaker_simulink_old_B.DataTypeConversion1,
                  1);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[4],
                  &pacemaker_simulink_old_B.DataStoreRead1,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[6],
                  &pacemaker_simulink_old_B.DataStoreRead2,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[8],
                  &pacemaker_simulink_old_B.DataStoreRead3,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[10],
                  &pacemaker_simulink_old_B.DataStoreRead4,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[12],
                  &pacemaker_simulink_old_B.DataStoreRead5,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[14],
                  &pacemaker_simulink_old_B.DataStoreRead6,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[16],
                  &pacemaker_simulink_old_B.DataStoreRead7,
                  2);
    (void) memcpy(&pacemaker_simulink_old_B.BytePack[18],
                  &pacemaker_simulink_old_B.DataStoreRead8,
                  2);

    /* MATLABSystem: '<S11>/Serial Transmit' */
    status = 1U;
    while (status != 0) {
      memcpy((void *)&pacemaker_simulink_old_B.RxDataLocChar[0], (void *)
             &pacemaker_simulink_old_B.BytePack[0], (uint32_T)((size_t)20 *
              sizeof(uint8_T)));
      status = MW_SCI_Transmit(pacemaker_simulink_old_DW.obj_k.MW_SCIHANDLE,
        pacemaker_simulink_old_B.RxDataLocChar, 20U);
    }

    /* End of MATLABSystem: '<S11>/Serial Transmit' */
  }

  /* End of Outputs for SubSystem: '<S6>/UART_Tx' */

  /* MATLABSystem: '<S5>/ATR_CMP_DETECT' */
  if (pacemaker_simulink_old_DW.obj_i.SampleTime !=
      pacemaker_simulink_old_P.ATR_CMP_DETECT_SampleTime) {
    pacemaker_simulink_old_DW.obj_i.SampleTime =
      pacemaker_simulink_old_P.ATR_CMP_DETECT_SampleTime;
  }

  pacemaker_simulink_old_B.ATR_CMP_DETECT = MW_digitalIO_read
    (pacemaker_simulink_old_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S5>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S5>/VENT_CMP_DETECT' */
  if (pacemaker_simulink_old_DW.obj_n.SampleTime !=
      pacemaker_simulink_old_P.VENT_CMP_DETECT_SampleTime) {
    pacemaker_simulink_old_DW.obj_n.SampleTime =
      pacemaker_simulink_old_P.VENT_CMP_DETECT_SampleTime;
  }

  pacemaker_simulink_old_B.VENT_CMP_DETECT = MW_digitalIO_read
    (pacemaker_simulink_old_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S5>/VENT_CMP_DETECT' */

  /* Gain: '<S3>/Gain' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write4'
   */
  Gain = (uint32_T)pacemaker_simulink_old_P.Gain_Gain *
    pacemaker_simulink_old_B.ATR_PULSE_AMP_REG_out;

  /* Gain: '<S3>/Gain1' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write5'
   */
  Gain1 = (uint32_T)pacemaker_simulink_old_P.Gain1_Gain *
    pacemaker_simulink_old_B.VENT_PULSE_AMP_REG_out;

  /* Gain: '<S3>/Gain4' incorporates:
   *  Constant: '<S3>/ATR_SENS'
   */
  pacemaker_simulink_old_B.Gain4 = pacemaker_simulink_old_P.Gain4_Gain *
    pacemaker_simulink_old_P.ATR_SENS_Value;

  /* Gain: '<S3>/Gain5' incorporates:
   *  Constant: '<S3>/VENT_SENS'
   */
  pacemaker_simulink_old_B.Gain5 = pacemaker_simulink_old_P.Gain5_Gain *
    pacemaker_simulink_old_P.VENT_SENS_Value;

  /* MATLABSystem: '<S4>/Accel' */
  if (pacemaker_simulink_old_DW.obj.SampleTime !=
      pacemaker_simulink_old_P.Accel_SampleTime) {
    pacemaker_simulink_old_DW.obj.SampleTime =
      pacemaker_simulink_old_P.Accel_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(pacemaker_simulink_old_DW.obj.i2cobj.MW_I2C_HANDLE,
    29U, &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(pacemaker_simulink_old_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
                      pacemaker_simulink_old_B.output_raw, 12U, false, true);
    memcpy((void *)&pacemaker_simulink_old_B.b_output[0], (void *)
           &pacemaker_simulink_old_B.output_raw[0], (uint32_T)((size_t)6 *
            sizeof(int16_T)));
    for (i = 0; i < 6; i++) {
      memcpy((void *)&y[0], (void *)&pacemaker_simulink_old_B.b_output[i],
             (uint32_T)((size_t)2 * sizeof(uint8_T)));
      b_x[0] = y[1];
      b_x[1] = y[0];
      memcpy((void *)&y_0, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
              (int16_T)));
      pacemaker_simulink_old_B.b_output[i] = y_0;
    }
  } else {
    for (i = 0; i < 6; i++) {
      pacemaker_simulink_old_B.b_output[i] = 0;
    }
  }

  /* Sum: '<S4>/activity_raw' incorporates:
   *  Abs: '<S4>/Abs_ax'
   *  Abs: '<S4>/Abs_ay'
   *  Abs: '<S4>/Abs_az'
   *  MATLABSystem: '<S4>/Accel'
   */
  rtb_activity_sat = (fabs((real_T)(int16_T)(pacemaker_simulink_old_B.b_output[0]
    >> 2) * 2.0 * 0.244 / 1000.0) + fabs((real_T)(int16_T)
    (pacemaker_simulink_old_B.b_output[1] >> 2) * 2.0 * 0.244 / 1000.0)) + fabs
    ((real_T)(int16_T)(pacemaker_simulink_old_B.b_output[2] >> 2) * 2.0 * 0.244 /
     1000.0);

  /* Saturate: '<S4>/activity_sat' */
  if (rtb_activity_sat > pacemaker_simulink_old_P.activity_sat_UpperSat) {
    rtb_activity_sat = pacemaker_simulink_old_P.activity_sat_UpperSat;
  } else {
    if (rtb_activity_sat < pacemaker_simulink_old_P.activity_sat_LowerSat) {
      rtb_activity_sat = pacemaker_simulink_old_P.activity_sat_LowerSat;
    }
  }

  /* End of Saturate: '<S4>/activity_sat' */

  /* MATLAB Function: '<S4>/map_activity_to_rate' incorporates:
   *  Constant: '<S4>/MAX_SENSOR_RATE'
   *  DataStoreWrite: '<S6>/Data Store Write2'
   */
  i = pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out;
  rtb_rs_bpm = pacemaker_simulink_old_P.MAX_SENSOR_RATE_Value;
  if (pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out <= 0) {
    i = 30;
  }

  if (pacemaker_simulink_old_P.MAX_SENSOR_RATE_Value < i) {
    rtb_rs_bpm = i;
  }

  if (rtb_activity_sat <= 0.2) {
    rtb_rs_bpm = i;
  } else {
    if (!(rtb_activity_sat >= 0.8)) {
      rtb_rs_bpm = (rtb_activity_sat - 0.2) / 0.60000000000000009 * (rtb_rs_bpm
        - (real_T)i) + (real_T)i;
    }
  }

  /* End of MATLAB Function: '<S4>/map_activity_to_rate' */

  /* MATLAB Function: '<S4>/time_response' incorporates:
   *  Constant: '<S4>/REACTION_TIME_s'
   *  Constant: '<S4>/RECOVERY_TIME_s'
   *  UnitDelay: '<S4>/Delay_rp'
   */
  rtb_activity_sat = pacemaker_simulink_old_P.REACTION_TIME_s_Value;
  recovery_time = pacemaker_simulink_old_P.RECOVERY_TIME_s_Value;
  if (rtb_rs_bpm < 30.0) {
    rtb_rs_bpm = 30.0;
  } else {
    if (rtb_rs_bpm > 175.0) {
      rtb_rs_bpm = 175.0;
    }
  }

  if (pacemaker_simulink_old_P.REACTION_TIME_s_Value <= 0.0) {
    rtb_activity_sat = 0.001;
  }

  if (pacemaker_simulink_old_P.RECOVERY_TIME_s_Value <= 0.0) {
    recovery_time = 0.001;
  }

  if (rtb_rs_bpm > pacemaker_simulink_old_DW.Delay_rp_DSTATE) {
    pacemaker_simulink_old_DW.Delay_rp_DSTATE += (rtb_rs_bpm -
      pacemaker_simulink_old_DW.Delay_rp_DSTATE) / (rtb_activity_sat / 0.001);
    if (pacemaker_simulink_old_DW.Delay_rp_DSTATE > rtb_rs_bpm) {
      pacemaker_simulink_old_DW.Delay_rp_DSTATE = rtb_rs_bpm;
    }
  } else if (rtb_rs_bpm < pacemaker_simulink_old_DW.Delay_rp_DSTATE) {
    pacemaker_simulink_old_DW.Delay_rp_DSTATE -=
      (pacemaker_simulink_old_DW.Delay_rp_DSTATE - rtb_rs_bpm) / (recovery_time /
      0.001);
    if (pacemaker_simulink_old_DW.Delay_rp_DSTATE < rtb_rs_bpm) {
      pacemaker_simulink_old_DW.Delay_rp_DSTATE = rtb_rs_bpm;
    }
  } else {
    pacemaker_simulink_old_DW.Delay_rp_DSTATE = rtb_rs_bpm;
  }

  /* End of MATLAB Function: '<S4>/time_response' */

  /* MATLAB Function: '<S4>/compute_intervals' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write2'
   *  UnitDelay: '<S4>/Delay_rp'
   */
  i = pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out;
  rtb_rs_bpm = pacemaker_simulink_old_DW.Delay_rp_DSTATE;
  if (pacemaker_simulink_old_B.LOWER_RATE_LIMIT_out <= 0) {
    i = 30;
  }

  if (pacemaker_simulink_old_DW.Delay_rp_DSTATE <= 0.0) {
    rtb_rs_bpm = 30.0;
  }

  rtb_activity_sat = rt_roundd_snf(60000.0 / (real_T)i);
  if (rtb_activity_sat < 65536.0) {
    tmp_0 = (uint16_T)rtb_activity_sat;
  } else {
    tmp_0 = MAX_uint16_T;
  }

  rtb_activity_sat = rt_roundd_snf(60000.0 / rtb_rs_bpm);
  if (rtb_activity_sat < 65536.0) {
    if (rtb_activity_sat >= 0.0) {
      tmp = (uint16_T)rtb_activity_sat;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  /* Chart: '<Root>/Pacemaker' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write'
   *  DataStoreWrite: '<S6>/Data Store Write3'
   *  DataStoreWrite: '<S6>/Data Store Write6'
   *  DataStoreWrite: '<S6>/Data Store Write7'
   *  MATLAB Function: '<S4>/compute_intervals'
   */
  if (pacemaker_simulink_old_DW.temporalCounter_i1 < MAX_uint32_T) {
    pacemaker_simulink_old_DW.temporalCounter_i1++;
  }

  if (pacemaker_simulink_old_DW.is_active_c3_pacemaker_simulink == 0U) {
    pacemaker_simulink_old_DW.is_active_c3_pacemaker_simulink = 1U;
    pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
      pacemaker_simulink_old_IN_Start;
  } else {
    switch (pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old) {
     case pacemaker_simulink_old_IN_AAI:
      pacemaker_simulink_old_AAI(&tmp, &tmp_0,
        &pacemaker_simulink_old_B.MODE_SELECT_out, &Gain,
        &pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out,
        &pacemaker_simulink_old_B.HYSTERESIS_out);
      break;

     case pacemaker_simulink_old_IN_AOO:
      if ((pacemaker_simulink_old_B.MODE_SELECT_out != 0) &&
          (pacemaker_simulink_old_B.MODE_SELECT_out != 4)) {
        pacemaker_simulink_old_DW.is_AOO = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
          pacemaker_simulink_old_IN_Start;
      } else if (pacemaker_simulink_old_DW.is_AOO == 1) {
        pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
        pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_old_B.ATR_GND_CTRL = 1.0;
        pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
        if ((pacemaker_simulink_old_B.MODE_SELECT_out == 0) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 1) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 2) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 3)) {
          tmp = tmp_0;
        }

        Gain = (uint32_T)tmp - /*MW:OvSatOk*/
          pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out;
        if (Gain > tmp) {
          Gain = 0U;
        }

        if (pacemaker_simulink_old_DW.temporalCounter_i1 >= Gain) {
          rtb_activity_sat = rt_roundd_snf(60000.0 / (real_T)
            pacemaker_simulink_old_B.UPPER_RATE_LIMIT_out);
          if (rtb_activity_sat < 65536.0) {
            tmp_0 = (uint16_T)rtb_activity_sat;
          } else {
            tmp_0 = MAX_uint16_T;
          }

          Gain = (uint32_T)tmp_0 - /*MW:OvSatOk*/
            pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out;
          if (Gain > tmp_0) {
            Gain = 0U;
          }

          if (pacemaker_simulink_old_DW.temporalCounter_i1 >= Gain) {
            pacemaker_simulink_old_DW.is_AOO = pacemaker_simulink_ol_IN_Pacing;
            pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
            pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
            pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
            pacemaker_simulink_old_B.ATR_PACE_CTRL = 1.0;
            pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
            pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
            pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
            pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
            pacemaker_simulink_old_B.VENT_PACE_CTRL = 0.0;
          }
        }
      } else {
        /* case IN_Pacing: */
        pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
        if (pacemaker_simulink_old_DW.temporalCounter_i1 >=
            pacemaker_simulink_old_B.ATR_PULSE_WIDTH_out) {
          pacemaker_simulink_old_DW.is_AOO = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Sensi(&Gain);
        }
      }
      break;

     case pacemaker_simulink_old_IN_Start:
      if ((pacemaker_simulink_old_B.MODE_SELECT_out == 0) ||
          (pacemaker_simulink_old_B.MODE_SELECT_out == 4)) {
        pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
          pacemaker_simulink_old_IN_AOO;
        pacemaker_simulink_old_DW.is_AOO = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sensi(&Gain);
      } else if ((pacemaker_simulink_old_B.MODE_SELECT_out == 1) ||
                 (pacemaker_simulink_old_B.MODE_SELECT_out == 5)) {
        pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
          pacemaker_simulink_old_IN_VOO;
        pacemaker_simulink_old_DW.is_VOO = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Se_mi(&Gain1);
      } else if ((pacemaker_simulink_old_B.MODE_SELECT_out == 2) ||
                 (pacemaker_simulink_old_B.MODE_SELECT_out == 6)) {
        pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
          pacemaker_simulink_old_IN_AAI;
        pacemaker_simulink_old_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(&Gain);
      } else {
        if ((pacemaker_simulink_old_B.MODE_SELECT_out == 3) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 7)) {
          pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
            pacemaker_simulink_old_IN_VVI;
          pacemaker_simulink_old_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Sen_m(&Gain1);
        }
      }
      break;

     case pacemaker_simulink_old_IN_VOO:
      if ((pacemaker_simulink_old_B.MODE_SELECT_out != 1) &&
          (pacemaker_simulink_old_B.MODE_SELECT_out != 5)) {
        pacemaker_simulink_old_DW.is_VOO = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_old_DW.is_c3_pacemaker_simulink_old =
          pacemaker_simulink_old_IN_Start;
      } else if (pacemaker_simulink_old_DW.is_VOO == 1) {
        pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 1.0;
        pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_old_B.VENT_GND_CTRL = 1.0;
        if ((pacemaker_simulink_old_B.MODE_SELECT_out == 0) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 1) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 2) ||
            (pacemaker_simulink_old_B.MODE_SELECT_out == 3)) {
          tmp = tmp_0;
        }

        Gain = (uint32_T)tmp - /*MW:OvSatOk*/
          pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out;
        if (Gain > tmp) {
          Gain = 0U;
        }

        if (pacemaker_simulink_old_DW.temporalCounter_i1 >= Gain) {
          rtb_activity_sat = rt_roundd_snf(60000.0 / (real_T)
            pacemaker_simulink_old_B.UPPER_RATE_LIMIT_out);
          if (rtb_activity_sat < 65536.0) {
            tmp_0 = (uint16_T)rtb_activity_sat;
          } else {
            tmp_0 = MAX_uint16_T;
          }

          Gain = (uint32_T)tmp_0 - /*MW:OvSatOk*/
            pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out;
          if (Gain > tmp_0) {
            Gain = 0U;
          }

          if (pacemaker_simulink_old_DW.temporalCounter_i1 >= Gain) {
            pacemaker_simulink_old_DW.is_VOO = pacemaker_simulink_ol_IN_Pacing;
            pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
            pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
            pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
            pacemaker_simulink_old_B.ATR_PACE_CTRL = 0.0;
            pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
            pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
            pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
            pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
            pacemaker_simulink_old_B.VENT_PACE_CTRL = 1.0;
          }
        }
      } else {
        /* case IN_Pacing: */
        pacemaker_simulink_old_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_old_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_old_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_old_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_old_B.VENT_GND_CTRL = 0.0;
        if (pacemaker_simulink_old_DW.temporalCounter_i1 >=
            pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out) {
          pacemaker_simulink_old_DW.is_VOO = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_old_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Se_mi(&Gain1);
        }
      }
      break;

     default:
      /* case IN_VVI: */
      pacemaker_simulink_old_VVI(&tmp, &tmp_0,
        &pacemaker_simulink_old_B.MODE_SELECT_out, &Gain1,
        &pacemaker_simulink_old_B.VENT_PULSE_WIDTH_out,
        &pacemaker_simulink_old_B.HYSTERESIS_out);
      break;
    }
  }

  /* End of Chart: '<Root>/Pacemaker' */

  /* MATLABSystem: '<S1>/Digital Write' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_l.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S1>/PWM Output' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_old_DW.obj_o.MW_PWM_HANDLE,
                      pacemaker_simulink_old_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S1>/Digital Write1' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_lo.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S1>/PWM Output1' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_old_DW.obj_f.MW_PWM_HANDLE, (real_T)
                      pacemaker_simulink_old_B.PACING_REF_PWM * 0.000244140625);

  /* MATLABSystem: '<S1>/PWM Output2' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_old_DW.obj_c.MW_PWM_HANDLE,
                      pacemaker_simulink_old_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S1>/Digital Write2' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_na.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S1>/Digital Write3' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_e.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S1>/Digital Write4' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_mm.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S1>/Digital Write5' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_ir.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S1>/Digital Write6' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_b.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S1>/Digital Write7' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_p.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S1>/Digital Write8' */
  MW_digitalIO_write(pacemaker_simulink_old_DW.obj_em.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_old_B.FRONTEND_CTRL != 0.0);
}

/* Model initialize function */
void pacemaker_simulink_old_initialize(void)
{
  {
    freedomk64f_DigitalRead_pacem_T *obj;
    freedomk64f_fxos8700_pacemake_T *obj_0;
    freedomk64f_DigitalWrite_pace_T *obj_1;
    freedomk64f_PWMOutput_pacemak_T *obj_2;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    pacemaker_simulink_old_DW.DS_ATR_REFRAC_PERIOD =
      pacemaker_simulink_old_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    pacemaker_simulink_old_DW.DS_VENT_REFRAC_PERIOD =
      pacemaker_simulink_old_P.DataStoreMemory4_InitialValue;

    /* InitializeConditions for UnitDelay: '<S4>/Delay_rp' */
    pacemaker_simulink_old_DW.Delay_rp_DSTATE =
      pacemaker_simulink_old_P.Delay_rp_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S6>/UART_Tx' */
    /* Start for MATLABSystem: '<S11>/Serial Transmit' */
    pacemaker_simulink_old_DW.obj_k.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_k.matlabCodegenIsDeleted = false;
    pacemaker_s_SystemCore_setup_bw(&pacemaker_simulink_old_DW.obj_k);

    /* End of SystemInitialize for SubSystem: '<S6>/UART_Tx' */

    /* Start for MATLABSystem: '<S6>/UART Receive' */
    pacemaker_simulink_old_DW.obj_m.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_m.matlabCodegenIsDeleted = false;
    pacemaker_simulink_old_DW.obj_m.SampleTime =
      pacemaker_simulink_old_P.UARTReceive_SampleTime;
    pacemaker_si_SystemCore_setup_b(&pacemaker_simulink_old_DW.obj_m);

    /* Start for MATLABSystem: '<S5>/ATR_CMP_DETECT' */
    pacemaker_simulink_old_DW.obj_i.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_i.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_i.SampleTime = -1.0;
    pacemaker_simulink_old_DW.obj_i.matlabCodegenIsDeleted = false;
    pacemaker_simulink_old_DW.obj_i.SampleTime =
      pacemaker_simulink_old_P.ATR_CMP_DETECT_SampleTime;
    obj = &pacemaker_simulink_old_DW.obj_i;
    pacemaker_simulink_old_DW.obj_i.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    pacemaker_simulink_old_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_CMP_DETECT' */
    pacemaker_simulink_old_DW.obj_n.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_n.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_n.SampleTime = -1.0;
    pacemaker_simulink_old_DW.obj_n.matlabCodegenIsDeleted = false;
    pacemaker_simulink_old_DW.obj_n.SampleTime =
      pacemaker_simulink_old_P.VENT_CMP_DETECT_SampleTime;
    obj = &pacemaker_simulink_old_DW.obj_n;
    pacemaker_simulink_old_DW.obj_n.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    pacemaker_simulink_old_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Accel' */
    pacemaker_simulink_old_DW.obj.i2cobj.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj.matlabCodegenIsDeleted = true;
    obj_0 = &pacemaker_simulink_old_DW.obj;
    pacemaker_simulink_old_DW.obj.isInitialized = 0;
    pacemaker_simulink_old_DW.obj.SampleTime = -1.0;
    obj_0->i2cobj.isInitialized = 0;
    obj_0->i2cobj.matlabCodegenIsDeleted = false;
    pacemaker_simulink_old_DW.obj.matlabCodegenIsDeleted = false;
    pacemaker_simulink_old_DW.obj.SampleTime =
      pacemaker_simulink_old_P.Accel_SampleTime;
    pacemaker_simu_SystemCore_setup(&pacemaker_simulink_old_DW.obj);

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    pacemaker_simulink_old_DW.obj_l.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_l.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_l;
    pacemaker_simulink_old_DW.obj_l.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_l.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    pacemaker_simulink_old_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output' */
    pacemaker_simulink_old_DW.obj_o.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_o.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_2 = &pacemaker_simulink_old_DW.obj_o;
    pacemaker_simulink_old_DW.obj_o.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_o.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_old_DW.obj_o.MW_PWM_HANDLE);
    pacemaker_simulink_old_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    pacemaker_simulink_old_DW.obj_lo.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_lo.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_lo.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_lo;
    pacemaker_simulink_old_DW.obj_lo.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_lo.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    pacemaker_simulink_old_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output1' */
    pacemaker_simulink_old_DW.obj_f.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_f.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_2 = &pacemaker_simulink_old_DW.obj_f;
    pacemaker_simulink_old_DW.obj_f.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_f.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_old_DW.obj_f.MW_PWM_HANDLE);
    pacemaker_simulink_old_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM Output2' */
    pacemaker_simulink_old_DW.obj_c.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_c.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_2 = &pacemaker_simulink_old_DW.obj_c;
    pacemaker_simulink_old_DW.obj_c.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_c.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_old_DW.obj_c.MW_PWM_HANDLE);
    pacemaker_simulink_old_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write2' */
    pacemaker_simulink_old_DW.obj_na.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_na.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_na.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_na;
    pacemaker_simulink_old_DW.obj_na.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_na.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    pacemaker_simulink_old_DW.obj_na.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write3' */
    pacemaker_simulink_old_DW.obj_e.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_e.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_e;
    pacemaker_simulink_old_DW.obj_e.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    pacemaker_simulink_old_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write4' */
    pacemaker_simulink_old_DW.obj_mm.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_mm.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_mm.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_mm;
    pacemaker_simulink_old_DW.obj_mm.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_mm.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    pacemaker_simulink_old_DW.obj_mm.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write5' */
    pacemaker_simulink_old_DW.obj_ir.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_ir.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_ir.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_ir;
    pacemaker_simulink_old_DW.obj_ir.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_ir.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    pacemaker_simulink_old_DW.obj_ir.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write6' */
    pacemaker_simulink_old_DW.obj_b.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_b.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_b;
    pacemaker_simulink_old_DW.obj_b.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    pacemaker_simulink_old_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write7' */
    pacemaker_simulink_old_DW.obj_p.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_p.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_p;
    pacemaker_simulink_old_DW.obj_p.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_p.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    pacemaker_simulink_old_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write8' */
    pacemaker_simulink_old_DW.obj_em.matlabCodegenIsDeleted = true;
    pacemaker_simulink_old_DW.obj_em.isInitialized = 0;
    pacemaker_simulink_old_DW.obj_em.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_old_DW.obj_em;
    pacemaker_simulink_old_DW.obj_em.isSetupComplete = false;
    pacemaker_simulink_old_DW.obj_em.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    pacemaker_simulink_old_DW.obj_em.isSetupComplete = true;
  }
}

/* Model terminate function */
void pacemaker_simulink_old_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/UART Receive' */
  pacemaker_sim_matlabCodegenHa_h(&pacemaker_simulink_old_DW.obj_m);

  /* Terminate for Enabled SubSystem: '<S6>/UART_Tx' */
  /* Terminate for MATLABSystem: '<S11>/Serial Transmit' */
  pacemaker_sim_matlabCodegenHa_n(&pacemaker_simulink_old_DW.obj_k);

  /* End of Terminate for SubSystem: '<S6>/UART_Tx' */

  /* Terminate for MATLABSystem: '<S5>/ATR_CMP_DETECT' */
  matlabCodegenHan_bwuptiarv0qumm(&pacemaker_simulink_old_DW.obj_i);

  /* Terminate for MATLABSystem: '<S5>/VENT_CMP_DETECT' */
  matlabCodegenHan_bwuptiarv0qumm(&pacemaker_simulink_old_DW.obj_n);

  /* Terminate for MATLABSystem: '<S4>/Accel' */
  matlabCodegenHandl_bwuptiarv0qu(&pacemaker_simulink_old_DW.obj);
  matlabCodegenHand_bwuptiarv0qum(&pacemaker_simulink_old_DW.obj.i2cobj);

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_l);

  /* Terminate for MATLABSystem: '<S1>/PWM Output' */
  matlabCodegenHandle_mat_bwuptia(&pacemaker_simulink_old_DW.obj_o);

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_lo);

  /* Terminate for MATLABSystem: '<S1>/PWM Output1' */
  matlabCodegenHandle_mat_bwuptia(&pacemaker_simulink_old_DW.obj_f);

  /* Terminate for MATLABSystem: '<S1>/PWM Output2' */
  matlabCodegenHandle_mat_bwuptia(&pacemaker_simulink_old_DW.obj_c);

  /* Terminate for MATLABSystem: '<S1>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_na);

  /* Terminate for MATLABSystem: '<S1>/Digital Write3' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_e);

  /* Terminate for MATLABSystem: '<S1>/Digital Write4' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_mm);

  /* Terminate for MATLABSystem: '<S1>/Digital Write5' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_ir);

  /* Terminate for MATLABSystem: '<S1>/Digital Write6' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_b);

  /* Terminate for MATLABSystem: '<S1>/Digital Write7' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_p);

  /* Terminate for MATLABSystem: '<S1>/Digital Write8' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_old_DW.obj_em);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
