/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pacemaker_simulink.c
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

/* Named constants for Chart: '<Root>/Pacemaker' */
#define pacemak_IN_Charging_and_Sensing ((uint8_T)1U)
#define pacemaker_si_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define pacemaker_simulin_IN_Hysteresis ((uint8_T)2U)
#define pacemaker_simulink_IN_AAI      ((uint8_T)1U)
#define pacemaker_simulink_IN_AOO      ((uint8_T)2U)
#define pacemaker_simulink_IN_Pacing   ((uint8_T)2U)
#define pacemaker_simulink_IN_Pacing_g ((uint8_T)3U)
#define pacemaker_simulink_IN_Start    ((uint8_T)3U)
#define pacemaker_simulink_IN_VOO      ((uint8_T)4U)
#define pacemaker_simulink_IN_VVI      ((uint8_T)5U)

/* Named constants for Chart: '<S7>/UART_Interface' */
#define pacemaker_simulink_IN_ECHO     ((uint8_T)1U)
#define pacemaker_simulink_IN_INIT     ((uint8_T)2U)
#define pacemaker_simulink_IN_SET      ((uint8_T)3U)
#define pacemaker_simulink_IN_STANDBY  ((uint8_T)4U)

/* Block signals (default storage) */
B_pacemaker_simulink_T pacemaker_simulink_B;

/* Block states (default storage) */
DW_pacemaker_simulink_T pacemaker_simulink_DW;

/* Real-time model */
RT_MODEL_pacemaker_simulink_T pacemaker_simulink_M_;
RT_MODEL_pacemaker_simulink_T *const pacemaker_simulink_M =
  &pacemaker_simulink_M_;

/* Forward declaration for local functions */
static void enter_atomic_Charging_and_Sen_m(const uint32_T *Gain1);
static void pacemaker_simulink_VVI(const uint16_T *Cast1, const uint16_T *Cast2,
  const uint8_T *DS_MODE_SELECT, const uint32_T *Gain1, const uint16_T
  *DS_VENT_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS);
static void enter_atomic_Charging_and_S_mil(const uint32_T *Gain);
static void pacemaker_simulink_AAI(const uint16_T *Cast1, const uint16_T *Cast2,
  const uint8_T *DS_MODE_SELECT, const uint32_T *Gain, const uint16_T
  *DS_ATR_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS);
static void enter_atomic_Charging_and_Sensi(const uint32_T *Gain);
static void enter_atomic_Charging_and_Se_mi(const uint32_T *Gain1);
static void p_SystemCore_rele_h(const freedomk64f_SCIRead_pacemaker_T *obj);
static void p_SystemCore_dele_h(const freedomk64f_SCIRead_pacemaker_T *obj);
static void pacemaker_sim_matlabCodegenHa_h(freedomk64f_SCIRead_pacemaker_T *obj);
static void p_SystemCore_rele_l(const freedomk64f_SCIWrite_pacemake_T *obj);
static void p_SystemCore_dele_l(const freedomk64f_SCIWrite_pacemake_T *obj);
static void pacemaker_sim_matlabCodegenHa_l(freedomk64f_SCIWrite_pacemake_T *obj);
static void SystemCore_relea_o3x4x4sg33se1r(const
  freedomk64f_DigitalRead_pacem_T *obj);
static void SystemCore_delet_o3x4x4sg33se1r(const
  freedomk64f_DigitalRead_pacem_T *obj);
static void matlabCodegenHan_o3x4x4sg33se1r(freedomk64f_DigitalRead_pacem_T *obj);
static void pacemaker_SystemCore_release_o3(const
  freedomk64f_DigitalWrite_pace_T *obj);
static void pacemaker__SystemCore_delete_o3(const
  freedomk64f_DigitalWrite_pace_T *obj);
static void matlabCodegenHandle_matlabCo_o3(freedomk64f_DigitalWrite_pace_T *obj);
static void pa_SystemCore_release_o3x4x4sg3(const
  freedomk64f_PWMOutput_pacemak_T *obj);
static void pac_SystemCore_delete_o3x4x4sg3(const
  freedomk64f_PWMOutput_pacemak_T *obj);
static void matlabCodegenHandle_m_o3x4x4sg3(freedomk64f_PWMOutput_pacemak_T *obj);
static void pacemaker_si_SystemCore_release(const
  freedomk64f_fxos8700_pacemake_T *obj);
static void pacemaker_sim_SystemCore_delete(const
  freedomk64f_fxos8700_pacemake_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_fxos8700_pacemake_T *obj);
static void pacemaker__SystemCore_release_o(b_freedomk64f_I2CMasterWrite__T *obj);
static void pacemaker_s_SystemCore_delete_o(b_freedomk64f_I2CMasterWrite__T *obj);
static void matlabCodegenHandle_matlabCod_o(b_freedomk64f_I2CMasterWrite__T *obj);
static void pacemaker_s_SystemCore_setup_o3(freedomk64f_SCIWrite_pacemake_T *obj);
static void pacemaker_si_SystemCore_setup_o(freedomk64f_SCIRead_pacemaker_T *obj);
static void pacemaker_simu_SystemCore_setup(freedomk64f_fxos8700_pacemake_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void pacemaker_simulink_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(pacemaker_simulink_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  pacemaker_simulink_M->Timing.RateInteraction.TID0_1 =
    (pacemaker_simulink_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (pacemaker_simulink_M->Timing.TaskCounters.TID[1])++;
  if ((pacemaker_simulink_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.02s, 0.0s] */
    pacemaker_simulink_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Sen_m(const uint32_T *Gain1)
{
  pacemaker_simulink_B.FRONTEND_CTRL = 1.0;
  pacemaker_simulink_B.PACING_REF_PWM = *Gain1;
  pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
  pacemaker_simulink_B.VENT_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_CMP_REF_PWM = pacemaker_simulink_B.Gain5;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void pacemaker_simulink_VVI(const uint16_T *Cast1, const uint16_T *Cast2,
  const uint8_T *DS_MODE_SELECT, const uint32_T *Gain1, const uint16_T
  *DS_VENT_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS)
{
  uint16_T current_LRI_ms;
  uint32_T qY;
  uint32_T tmp;

  /* DataStoreRead: '<S5>/Data Store Read' incorporates:
   *  Constant: '<S5>/HYSTERESIS_INTERVAL'
   *  DataStoreRead: '<S5>/Data Store Read6'
   *  DataStoreRead: '<S5>/Data Store Read8'
   *  DataStoreRead: '<S5>/Data Store Read9'
   */
  if ((*DS_MODE_SELECT != 3) && (*DS_MODE_SELECT != 7)) {
    pacemaker_simulink_DW.is_VVI = pacemaker_si_IN_NO_ACTIVE_CHILD;
    pacemaker_simulink_DW.is_c3_pacemaker_simulink = pacemaker_simulink_IN_Start;
  } else {
    if ((*DS_MODE_SELECT == 0) || (*DS_MODE_SELECT == 1) || (*DS_MODE_SELECT ==
         2) || (*DS_MODE_SELECT == 3)) {
      current_LRI_ms = *Cast2;
    } else {
      current_LRI_ms = *Cast1;
    }

    switch (pacemaker_simulink_DW.is_VVI) {
     case pacemak_IN_Charging_and_Sensing:
      pacemaker_simulink_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_B.VENT_GND_CTRL = 1.0;
      if ((*DS_HYSTERESIS) && pacemaker_simulink_B.VENT_CMP_DETECT &&
          (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH) &&
          (pacemaker_simulink_DW.temporalCounter_i1 >=
           pacemaker_simulink_DW.DS_VENT_REFRAC_PERIOD)) {
        pacemaker_simulink_DW.is_VVI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(Gain1);
      } else {
        qY = (uint32_T)current_LRI_ms - /*MW:OvSatOk*/ *DS_VENT_PULSE_WIDTH;
        if (qY > current_LRI_ms) {
          qY = 0U;
        }

        if (pacemaker_simulink_DW.temporalCounter_i1 >= qY) {
          pacemaker_simulink_DW.is_VVI = pacemaker_simulink_IN_Pacing_g;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
          pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_B.VENT_PACE_CTRL = 1.0;
        } else {
          if ((!*DS_HYSTERESIS) && pacemaker_simulink_B.VENT_CMP_DETECT &&
              (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH)
              && (pacemaker_simulink_DW.temporalCounter_i1 >=
                  pacemaker_simulink_DW.DS_VENT_REFRAC_PERIOD)) {
            pacemaker_simulink_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
            pacemaker_simulink_DW.temporalCounter_i1 = 0U;
            enter_atomic_Charging_and_Sen_m(Gain1);
          }
        }
      }
      break;

     case pacemaker_simulin_IN_Hysteresis:
      pacemaker_simulink_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_B.VENT_GND_CTRL = 1.0;
      if (pacemaker_simulink_B.VENT_CMP_DETECT &&
          (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH) &&
          (pacemaker_simulink_DW.temporalCounter_i1 >=
           pacemaker_simulink_DW.DS_VENT_REFRAC_PERIOD)) {
        pacemaker_simulink_DW.is_VVI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(Gain1);
      } else {
        tmp = (uint32_T)current_LRI_ms +
          pacemaker_simulink_P.HYSTERESIS_INTERVAL_Value;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        qY = tmp - /*MW:OvSatOk*/ *DS_VENT_PULSE_WIDTH;
        if (qY > tmp) {
          qY = 0U;
        }

        if (pacemaker_simulink_DW.temporalCounter_i1 >= qY) {
          pacemaker_simulink_DW.is_VVI = pacemaker_simulink_IN_Pacing_g;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
          pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_B.VENT_PACE_CTRL = 1.0;
        }
      }
      break;

     default:
      /* case IN_Pacing: */
      pacemaker_simulink_B.FRONTEND_CTRL = 0.0;
      pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
      pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_VENT_PULSE_WIDTH) {
        pacemaker_simulink_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sen_m(Gain1);
      }
      break;
    }
  }

  /* End of DataStoreRead: '<S5>/Data Store Read' */
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_S_mil(const uint32_T *Gain)
{
  pacemaker_simulink_B.FRONTEND_CTRL = 1.0;
  pacemaker_simulink_B.PACING_REF_PWM = *Gain;
  pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_B.ATR_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
  pacemaker_simulink_B.ATR_CMP_REF_PWM = pacemaker_simulink_B.Gain4;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void pacemaker_simulink_AAI(const uint16_T *Cast1, const uint16_T *Cast2,
  const uint8_T *DS_MODE_SELECT, const uint32_T *Gain, const uint16_T
  *DS_ATR_PULSE_WIDTH, const boolean_T *DS_HYSTERESIS)
{
  uint16_T current_LRI_ms;
  uint32_T qY;
  uint32_T tmp;

  /* DataStoreRead: '<S5>/Data Store Read' incorporates:
   *  Constant: '<S5>/HYSTERESIS_INTERVAL'
   *  DataStoreRead: '<S5>/Data Store Read5'
   *  DataStoreRead: '<S5>/Data Store Read7'
   *  DataStoreRead: '<S5>/Data Store Read9'
   */
  if ((*DS_MODE_SELECT != 2) && (*DS_MODE_SELECT != 6)) {
    pacemaker_simulink_DW.is_AAI = pacemaker_si_IN_NO_ACTIVE_CHILD;
    pacemaker_simulink_DW.is_c3_pacemaker_simulink = pacemaker_simulink_IN_Start;
  } else {
    if ((*DS_MODE_SELECT == 0) || (*DS_MODE_SELECT == 1) || (*DS_MODE_SELECT ==
         2) || (*DS_MODE_SELECT == 3)) {
      current_LRI_ms = *Cast2;
    } else {
      current_LRI_ms = *Cast1;
    }

    switch (pacemaker_simulink_DW.is_AAI) {
     case pacemak_IN_Charging_and_Sensing:
      pacemaker_simulink_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_B.ATR_GND_CTRL = 1.0;
      pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
      qY = (uint32_T)current_LRI_ms - /*MW:OvSatOk*/ *DS_ATR_PULSE_WIDTH;
      if (qY > current_LRI_ms) {
        qY = 0U;
      }

      if (pacemaker_simulink_DW.temporalCounter_i1 >= qY) {
        pacemaker_simulink_DW.is_AAI = pacemaker_simulink_IN_Pacing_g;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        pacemaker_simulink_B.FRONTEND_CTRL = 0.0;
        pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_B.ATR_PACE_CTRL = 1.0;
        pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
        pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
      } else if ((!*DS_HYSTERESIS) && pacemaker_simulink_B.ATR_CMP_DETECT &&
                 (pacemaker_simulink_DW.temporalCounter_i1 >=
                  *DS_ATR_PULSE_WIDTH) &&
                 (pacemaker_simulink_DW.temporalCounter_i1 >=
                  pacemaker_simulink_DW.DS_ATR_REFRAC_PERIOD)) {
        pacemaker_simulink_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain);
      } else {
        if ((*DS_HYSTERESIS) && pacemaker_simulink_B.ATR_CMP_DETECT &&
            (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_ATR_PULSE_WIDTH) &&
            (pacemaker_simulink_DW.temporalCounter_i1 >=
             pacemaker_simulink_DW.DS_ATR_REFRAC_PERIOD)) {
          pacemaker_simulink_DW.is_AAI = pacemaker_simulin_IN_Hysteresis;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_S_mil(Gain);
        }
      }
      break;

     case pacemaker_simulin_IN_Hysteresis:
      pacemaker_simulink_B.FRONTEND_CTRL = 1.0;
      pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
      pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_B.ATR_GND_CTRL = 1.0;
      pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_B.ATR_CMP_DETECT &&
          (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_ATR_PULSE_WIDTH) &&
          (pacemaker_simulink_DW.temporalCounter_i1 >=
           pacemaker_simulink_DW.DS_ATR_REFRAC_PERIOD)) {
        pacemaker_simulink_DW.is_AAI = pacemaker_simulin_IN_Hysteresis;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain);
      } else {
        tmp = (uint32_T)current_LRI_ms +
          pacemaker_simulink_P.HYSTERESIS_INTERVAL_Value;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        qY = tmp - /*MW:OvSatOk*/ *DS_ATR_PULSE_WIDTH;
        if (qY > tmp) {
          qY = 0U;
        }

        if (pacemaker_simulink_DW.temporalCounter_i1 >= qY) {
          pacemaker_simulink_DW.is_AAI = pacemaker_simulink_IN_Pacing_g;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_B.FRONTEND_CTRL = 0.0;
          pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_B.ATR_PACE_CTRL = 1.0;
          pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
        }
      }
      break;

     default:
      /* case IN_Pacing: */
      pacemaker_simulink_B.FRONTEND_CTRL = 0.0;
      pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
      pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
      pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
      pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
      pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
      pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
      if (pacemaker_simulink_DW.temporalCounter_i1 >= *DS_ATR_PULSE_WIDTH) {
        pacemaker_simulink_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(Gain);
      }
      break;
    }
  }

  /* End of DataStoreRead: '<S5>/Data Store Read' */
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Sensi(const uint32_T *Gain)
{
  pacemaker_simulink_B.PACING_REF_PWM = *Gain;
  pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_B.ATR_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Pacemaker' */
static void enter_atomic_Charging_and_Se_mi(const uint32_T *Gain1)
{
  pacemaker_simulink_B.PACING_REF_PWM = *Gain1;
  pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
  pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
  pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
  pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
  pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
  pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
  pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
  pacemaker_simulink_B.VENT_GND_CTRL = 1.0;
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

static void p_SystemCore_rele_l(const freedomk64f_SCIWrite_pacemake_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void p_SystemCore_dele_l(const freedomk64f_SCIWrite_pacemake_T *obj)
{
  p_SystemCore_rele_l(obj);
}

static void pacemaker_sim_matlabCodegenHa_l(freedomk64f_SCIWrite_pacemake_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    p_SystemCore_dele_l(obj);
  }
}

static void SystemCore_relea_o3x4x4sg33se1r(const
  freedomk64f_DigitalRead_pacem_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void SystemCore_delet_o3x4x4sg33se1r(const
  freedomk64f_DigitalRead_pacem_T *obj)
{
  SystemCore_relea_o3x4x4sg33se1r(obj);
}

static void matlabCodegenHan_o3x4x4sg33se1r(freedomk64f_DigitalRead_pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_o3x4x4sg33se1r(obj);
  }
}

static void pacemaker_SystemCore_release_o3(const
  freedomk64f_DigitalWrite_pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void pacemaker__SystemCore_delete_o3(const
  freedomk64f_DigitalWrite_pace_T *obj)
{
  pacemaker_SystemCore_release_o3(obj);
}

static void matlabCodegenHandle_matlabCo_o3(freedomk64f_DigitalWrite_pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacemaker__SystemCore_delete_o3(obj);
  }
}

static void pa_SystemCore_release_o3x4x4sg3(const
  freedomk64f_PWMOutput_pacemak_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void pac_SystemCore_delete_o3x4x4sg3(const
  freedomk64f_PWMOutput_pacemak_T *obj)
{
  pa_SystemCore_release_o3x4x4sg3(obj);
}

static void matlabCodegenHandle_m_o3x4x4sg3(freedomk64f_PWMOutput_pacemak_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pac_SystemCore_delete_o3x4x4sg3(obj);
  }
}

static void pacemaker_si_SystemCore_release(const
  freedomk64f_fxos8700_pacemake_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void pacemaker_sim_SystemCore_delete(const
  freedomk64f_fxos8700_pacemake_T *obj)
{
  pacemaker_si_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_fxos8700_pacemake_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacemaker_sim_SystemCore_delete(obj);
  }
}

static void pacemaker__SystemCore_release_o(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void pacemaker_s_SystemCore_delete_o(b_freedomk64f_I2CMasterWrite__T *obj)
{
  pacemaker__SystemCore_release_o(obj);
}

static void matlabCodegenHandle_matlabCod_o(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    pacemaker_s_SystemCore_delete_o(obj);
  }
}

static void pacemaker_s_SystemCore_setup_o3(freedomk64f_SCIWrite_pacemake_T *obj)
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

static void pacemaker_si_SystemCore_setup_o(freedomk64f_SCIRead_pacemaker_T *obj)
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
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, b_SwappedDataBytes, 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void pacemaker_simulink_step0(void)    /* Sample time: [0.001s, 0.0s] */
{
  uint8_T RxDataLocChar[20];
  uint8_T status;
  real_T rtb_Add;
  boolean_T rtb_echo_request;
  uint16_T Cast1;
  uint16_T Cast2;
  uint32_T Gain1;
  uint32_T Gain;
  real_T rtb_Add_tmp;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S7>/UART Receive' */
  if (pacemaker_simulink_DW.obj_m.SampleTime !=
      pacemaker_simulink_P.UARTReceive_SampleTime) {
    pacemaker_simulink_DW.obj_m.SampleTime =
      pacemaker_simulink_P.UARTReceive_SampleTime;
  }

  status = MW_SCI_Receive(pacemaker_simulink_DW.obj_m.MW_SCIHANDLE,
    RxDataLocChar, 20U);
  memcpy((void *)&pacemaker_simulink_B.RxData[0], (void *)&RxDataLocChar[0],
         (uint32_T)((size_t)20 * sizeof(uint8_T)));

  /* Chart: '<S7>/UART_Interface' incorporates:
   *  MATLABSystem: '<S7>/UART Receive'
   */
  if (pacemaker_simulink_DW.temporalCounter_i1_k < 511U) {
    pacemaker_simulink_DW.temporalCounter_i1_k++;
  }

  if (pacemaker_simulink_DW.is_active_c1_pacemaker_simulink == 0U) {
    pacemaker_simulink_DW.is_active_c1_pacemaker_simulink = 1U;
    pacemaker_simulink_DW.is_c1_pacemaker_simulink = pacemaker_simulink_IN_INIT;
    pacemaker_simulink_B.MODE_SELECT_out = 0U;
    pacemaker_simulink_B.HYSTERESIS_out = false;
    pacemaker_simulink_B.LOWER_RATE_LIMIT_out = 60U;
    pacemaker_simulink_B.UPPER_RATE_LIMIT_out = 120U;
    pacemaker_simulink_B.ATR_PULSE_AMP_REG_out = 4U;
    pacemaker_simulink_B.VENT_PULSE_AMP_REG_out = 4U;
    pacemaker_simulink_B.ATR_PULSE_WIDTH_out = 40U;
    pacemaker_simulink_B.VENT_PULSE_WIDTH_out = 40U;
    pacemaker_simulink_B.ATR_REFRAC_PERIOD_out = 250U;
    pacemaker_simulink_B.VENT_REFRAC_PERIOD_out = 320U;
    rtb_echo_request = false;
  } else {
    switch (pacemaker_simulink_DW.is_c1_pacemaker_simulink) {
     case pacemaker_simulink_IN_ECHO:
      rtb_echo_request = true;
      if (pacemaker_simulink_DW.temporalCounter_i1_k >= 500U) {
        pacemaker_simulink_DW.is_c1_pacemaker_simulink =
          pacemaker_simulink_IN_STANDBY;
        rtb_echo_request = false;
      }
      break;

     case pacemaker_simulink_IN_INIT:
      pacemaker_simulink_DW.is_c1_pacemaker_simulink =
        pacemaker_simulink_IN_STANDBY;
      rtb_echo_request = false;
      break;

     case pacemaker_simulink_IN_SET:
      pacemaker_simulink_DW.is_c1_pacemaker_simulink =
        pacemaker_simulink_IN_STANDBY;
      rtb_echo_request = false;
      break;

     default:
      /* case IN_STANDBY: */
      rtb_echo_request = false;
      if (status == 0) {
        if (pacemaker_simulink_B.RxData[0] == 22) {
          if (pacemaker_simulink_B.RxData[1] == 2) {
            pacemaker_simulink_DW.is_c1_pacemaker_simulink =
              pacemaker_simulink_IN_ECHO;
            pacemaker_simulink_DW.temporalCounter_i1_k = 0U;
            rtb_echo_request = true;
          } else if (pacemaker_simulink_B.RxData[1] == 1) {
            pacemaker_simulink_DW.is_c1_pacemaker_simulink =
              pacemaker_simulink_IN_SET;
            pacemaker_simulink_B.MODE_SELECT_out = pacemaker_simulink_B.RxData[2];
            pacemaker_simulink_B.HYSTERESIS_out = (pacemaker_simulink_B.RxData[3]
              != 0);
            pacemaker_simulink_B.LOWER_RATE_LIMIT_out = (uint16_T)
              (pacemaker_simulink_B.RxData[5] << 8 |
               pacemaker_simulink_B.RxData[4]);
            pacemaker_simulink_B.UPPER_RATE_LIMIT_out = (uint16_T)
              (pacemaker_simulink_B.RxData[7] << 8 |
               pacemaker_simulink_B.RxData[6]);
            pacemaker_simulink_B.ATR_PULSE_AMP_REG_out = (uint16_T)
              (pacemaker_simulink_B.RxData[9] << 8 |
               pacemaker_simulink_B.RxData[8]);
            pacemaker_simulink_B.VENT_PULSE_AMP_REG_out = (uint16_T)
              (pacemaker_simulink_B.RxData[11] << 8 |
               pacemaker_simulink_B.RxData[10]);
            pacemaker_simulink_B.ATR_PULSE_WIDTH_out = (uint16_T)
              (pacemaker_simulink_B.RxData[13] << 8 |
               pacemaker_simulink_B.RxData[12]);
            pacemaker_simulink_B.VENT_PULSE_WIDTH_out = (uint16_T)
              (pacemaker_simulink_B.RxData[15] << 8 |
               pacemaker_simulink_B.RxData[14]);
            pacemaker_simulink_B.ATR_REFRAC_PERIOD_out = (uint16_T)
              (pacemaker_simulink_B.RxData[17] << 8 |
               pacemaker_simulink_B.RxData[16]);
            pacemaker_simulink_B.VENT_REFRAC_PERIOD_out = (uint16_T)
              (pacemaker_simulink_B.RxData[19] << 8 |
               pacemaker_simulink_B.RxData[18]);
          } else {
            pacemaker_simulink_DW.is_c1_pacemaker_simulink =
              pacemaker_simulink_IN_STANDBY;
          }
        } else {
          pacemaker_simulink_DW.is_c1_pacemaker_simulink =
            pacemaker_simulink_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S7>/UART_Interface' */

  /* DataStoreWrite: '<S7>/Data Store Write8' */
  pacemaker_simulink_DW.DS_ATR_REFRAC_PERIOD =
    pacemaker_simulink_B.ATR_REFRAC_PERIOD_out;

  /* DataStoreWrite: '<S7>/Data Store Write9' */
  pacemaker_simulink_DW.DS_VENT_REFRAC_PERIOD =
    pacemaker_simulink_B.VENT_REFRAC_PERIOD_out;

  /* DataStoreRead: '<S7>/Data Store Read' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write'
   */
  pacemaker_simulink_B.DataStoreRead = pacemaker_simulink_B.MODE_SELECT_out;

  /* DataStoreRead: '<S7>/Data Store Read1' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write2'
   */
  pacemaker_simulink_B.DataStoreRead1 =
    pacemaker_simulink_B.LOWER_RATE_LIMIT_out;

  /* DataStoreRead: '<S7>/Data Store Read2' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write3'
   */
  pacemaker_simulink_B.DataStoreRead2 =
    pacemaker_simulink_B.UPPER_RATE_LIMIT_out;

  /* DataStoreRead: '<S7>/Data Store Read3' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write4'
   */
  pacemaker_simulink_B.DataStoreRead3 =
    pacemaker_simulink_B.ATR_PULSE_AMP_REG_out;

  /* DataStoreRead: '<S7>/Data Store Read4' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write5'
   */
  pacemaker_simulink_B.DataStoreRead4 =
    pacemaker_simulink_B.VENT_PULSE_AMP_REG_out;

  /* DataStoreRead: '<S7>/Data Store Read5' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write6'
   */
  pacemaker_simulink_B.DataStoreRead5 = pacemaker_simulink_B.ATR_PULSE_WIDTH_out;

  /* DataStoreRead: '<S7>/Data Store Read6' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write7'
   */
  pacemaker_simulink_B.DataStoreRead6 =
    pacemaker_simulink_B.VENT_PULSE_WIDTH_out;

  /* DataStoreRead: '<S7>/Data Store Read7' */
  pacemaker_simulink_B.DataStoreRead7 =
    pacemaker_simulink_DW.DS_ATR_REFRAC_PERIOD;

  /* DataStoreRead: '<S7>/Data Store Read8' */
  pacemaker_simulink_B.DataStoreRead8 =
    pacemaker_simulink_DW.DS_VENT_REFRAC_PERIOD;

  /* Outputs for Enabled SubSystem: '<S7>/UART_Tx' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (rtb_echo_request) {
    /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
     *  DataStoreWrite: '<S7>/Data Store Write1'
     */
    pacemaker_simulink_B.DataTypeConversion1 =
      pacemaker_simulink_B.HYSTERESIS_out;

    /* S-Function (any2byte): '<S15>/Byte Pack' incorporates:
     *  Constant: '<S15>/MSGTYPE_TX'
     *  Constant: '<S15>/SYNC_TX'
     */

    /* Pack: <S15>/Byte Pack */
    (void) memcpy(&pacemaker_simulink_B.BytePack[0],
                  &pacemaker_simulink_P.SYNC_TX_Value,
                  1);
    (void) memcpy(&pacemaker_simulink_B.BytePack[1],
                  &pacemaker_simulink_P.MSGTYPE_TX_Value,
                  1);
    (void) memcpy(&pacemaker_simulink_B.BytePack[2],
                  &pacemaker_simulink_B.DataStoreRead,
                  1);
    (void) memcpy(&pacemaker_simulink_B.BytePack[3],
                  &pacemaker_simulink_B.DataTypeConversion1,
                  1);
    (void) memcpy(&pacemaker_simulink_B.BytePack[4],
                  &pacemaker_simulink_B.DataStoreRead1,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[6],
                  &pacemaker_simulink_B.DataStoreRead2,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[8],
                  &pacemaker_simulink_B.DataStoreRead3,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[10],
                  &pacemaker_simulink_B.DataStoreRead4,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[12],
                  &pacemaker_simulink_B.DataStoreRead5,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[14],
                  &pacemaker_simulink_B.DataStoreRead6,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[16],
                  &pacemaker_simulink_B.DataStoreRead7,
                  2);
    (void) memcpy(&pacemaker_simulink_B.BytePack[18],
                  &pacemaker_simulink_B.DataStoreRead8,
                  2);

    /* MATLABSystem: '<S15>/Serial Transmit' */
    status = 1U;
    while (status != 0) {
      memcpy((void *)&RxDataLocChar[0], (void *)&pacemaker_simulink_B.BytePack[0],
             (uint32_T)((size_t)20 * sizeof(uint8_T)));
      status = MW_SCI_Transmit(pacemaker_simulink_DW.obj_k.MW_SCIHANDLE,
        RxDataLocChar, 20U);
    }

    /* End of MATLABSystem: '<S15>/Serial Transmit' */
  }

  /* End of Outputs for SubSystem: '<S7>/UART_Tx' */

  /* MATLABSystem: '<S6>/ATR_CMP_DETECT' */
  if (pacemaker_simulink_DW.obj_i.SampleTime !=
      pacemaker_simulink_P.ATR_CMP_DETECT_SampleTime) {
    pacemaker_simulink_DW.obj_i.SampleTime =
      pacemaker_simulink_P.ATR_CMP_DETECT_SampleTime;
  }

  pacemaker_simulink_B.ATR_CMP_DETECT = MW_digitalIO_read
    (pacemaker_simulink_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S6>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S6>/VENT_CMP_DETECT' */
  if (pacemaker_simulink_DW.obj_n.SampleTime !=
      pacemaker_simulink_P.VENT_CMP_DETECT_SampleTime) {
    pacemaker_simulink_DW.obj_n.SampleTime =
      pacemaker_simulink_P.VENT_CMP_DETECT_SampleTime;
  }

  pacemaker_simulink_B.VENT_CMP_DETECT = MW_digitalIO_read
    (pacemaker_simulink_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S6>/VENT_CMP_DETECT' */

  /* Gain: '<S5>/Gain' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write4'
   */
  Gain = (uint32_T)pacemaker_simulink_P.Gain_Gain *
    pacemaker_simulink_B.ATR_PULSE_AMP_REG_out;

  /* Gain: '<S5>/Gain1' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write5'
   */
  Gain1 = (uint32_T)pacemaker_simulink_P.Gain1_Gain *
    pacemaker_simulink_B.VENT_PULSE_AMP_REG_out;

  /* Gain: '<S5>/Gain4' incorporates:
   *  Constant: '<S5>/ATR_SENS'
   */
  pacemaker_simulink_B.Gain4 = pacemaker_simulink_P.Gain4_Gain *
    pacemaker_simulink_P.ATR_SENS_Value;

  /* Gain: '<S5>/Gain5' incorporates:
   *  Constant: '<S5>/VENT_SENS'
   */
  pacemaker_simulink_B.Gain5 = pacemaker_simulink_P.Gain5_Gain *
    pacemaker_simulink_P.VENT_SENS_Value;

  /* DataTypeConversion: '<S2>/Cast2' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataStoreWrite: '<S7>/Data Store Write2'
   *  DataTypeConversion: '<S2>/Cast'
   *  Product: '<S2>/Divide2'
   */
  rtb_Add_tmp = floor(pacemaker_simulink_P.Constant_Value / (real_T)
                      pacemaker_simulink_B.LOWER_RATE_LIMIT_out);
  if (rtIsNaN(rtb_Add_tmp) || rtIsInf(rtb_Add_tmp)) {
    rtb_Add_tmp = 0.0;
  } else {
    rtb_Add_tmp = fmod(rtb_Add_tmp, 65536.0);
  }

  Cast2 = (uint16_T)(rtb_Add_tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                     -rtb_Add_tmp : (int32_T)(uint16_T)rtb_Add_tmp);

  /* End of DataTypeConversion: '<S2>/Cast2' */

  /* RateTransition: '<Root>/Rate Transition' */
  if (pacemaker_simulink_M->Timing.RateInteraction.TID0_1) {
    pacemaker_simulink_B.RateTransition =
      pacemaker_simulink_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Sum: '<S9>/Subtract1' incorporates:
   *  Constant: '<S2>/MAX_SENSOR_RATE'
   *  DataStoreWrite: '<S7>/Data Store Write2'
   *  DataTypeConversion: '<S2>/Cast'
   *  Sum: '<S12>/Subtract1'
   *  Sum: '<S13>/Subtract1'
   */
  rtb_Add_tmp = pacemaker_simulink_P.MAX_SENSOR_RATE_Value - (real_T)
    pacemaker_simulink_B.LOWER_RATE_LIMIT_out;

  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S2>/RESPONSE_FACTOR'
   *  Constant: '<S9>/#ResponseFactors'
   *  DataStoreWrite: '<S7>/Data Store Write2'
   *  DataTypeConversion: '<S2>/Cast'
   *  Product: '<S9>/ '
   *  Product: '<S9>/Scaling Factor'
   *  Sum: '<S9>/Subtract1'
   */
  rtb_Add = rtb_Add_tmp / pacemaker_simulink_P.ResponseFactors_Value *
    pacemaker_simulink_P.RESPONSE_FACTOR_Value + (real_T)
    pacemaker_simulink_B.LOWER_RATE_LIMIT_out;

  /* If: '<S2>/If Threshold exceeded' incorporates:
   *  Constant: '<S2>/ACTIVITY_THRESHOLD'
   *  Constant: '<S2>/Constant1'
   *  Product: '<S2>/Divide1'
   *  Sum: '<S2>/Subtract'
   */
  if (pacemaker_simulink_B.RateTransition -
      pacemaker_simulink_P.ACTIVITY_THRESHOLD_Value /
      pacemaker_simulink_P.Constant1_Value > 0.0) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Sum: '<S10>/Add1' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S2>/REACTION_TIME_min'
     *  Product: '<S13>/Divide'
     *  Product: '<S13>/Slope'
     *  UnitDelay: '<S2>/Previous Rate'
     */
    pacemaker_simulink_DW.PreviousRate_DSTATE += rtb_Add_tmp /
      pacemaker_simulink_P.REACTION_TIME_min_Value /
      pacemaker_simulink_P.Constant_Value_b;

    /* Switch: '<S10>/Switch' incorporates:
     *  Sum: '<S10>/Subtract'
     *  UnitDelay: '<S2>/Previous Rate'
     */
    if (!(rtb_Add - pacemaker_simulink_DW.PreviousRate_DSTATE >
          pacemaker_simulink_P.Switch_Threshold)) {
      pacemaker_simulink_DW.PreviousRate_DSTATE = rtb_Add;
    }

    /* End of Switch: '<S10>/Switch' */
    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Sum: '<S11>/Subtract1' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S2>/RECOVERY_TIME_min'
     *  Product: '<S12>/Divide'
     *  Product: '<S12>/Slope'
     *  UnitDelay: '<S2>/Previous Rate'
     */
    pacemaker_simulink_DW.PreviousRate_DSTATE -= rtb_Add_tmp /
      pacemaker_simulink_P.RECOVERY_TIME_min_Value /
      pacemaker_simulink_P.Constant_Value_k;

    /* Switch: '<S11>/Switch' incorporates:
     *  DataStoreWrite: '<S7>/Data Store Write2'
     *  DataTypeConversion: '<S2>/Cast'
     *  Sum: '<S11>/Subtract'
     *  UnitDelay: '<S2>/Previous Rate'
     */
    if (!(pacemaker_simulink_DW.PreviousRate_DSTATE - (real_T)
          pacemaker_simulink_B.LOWER_RATE_LIMIT_out >
          pacemaker_simulink_P.Switch_Threshold_f)) {
      pacemaker_simulink_DW.PreviousRate_DSTATE =
        pacemaker_simulink_B.LOWER_RATE_LIMIT_out;
    }

    /* End of Switch: '<S11>/Switch' */
    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  }

  /* End of If: '<S2>/If Threshold exceeded' */

  /* DataTypeConversion: '<S2>/Cast1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<S2>/Divide'
   *  UnitDelay: '<S2>/Previous Rate'
   */
  rtb_Add_tmp = floor(pacemaker_simulink_P.Constant_Value /
                      pacemaker_simulink_DW.PreviousRate_DSTATE);
  if (rtIsNaN(rtb_Add_tmp) || rtIsInf(rtb_Add_tmp)) {
    rtb_Add_tmp = 0.0;
  } else {
    rtb_Add_tmp = fmod(rtb_Add_tmp, 65536.0);
  }

  Cast1 = (uint16_T)(rtb_Add_tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                     -rtb_Add_tmp : (int32_T)(uint16_T)rtb_Add_tmp);

  /* End of DataTypeConversion: '<S2>/Cast1' */

  /* Chart: '<Root>/Pacemaker' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write'
   *  DataStoreWrite: '<S7>/Data Store Write6'
   *  DataStoreWrite: '<S7>/Data Store Write7'
   */
  if (pacemaker_simulink_DW.temporalCounter_i1 < MAX_uint32_T) {
    pacemaker_simulink_DW.temporalCounter_i1++;
  }

  if (pacemaker_simulink_DW.is_active_c3_pacemaker_simulink == 0U) {
    pacemaker_simulink_DW.is_active_c3_pacemaker_simulink = 1U;
    pacemaker_simulink_DW.is_c3_pacemaker_simulink = pacemaker_simulink_IN_Start;
  } else {
    switch (pacemaker_simulink_DW.is_c3_pacemaker_simulink) {
     case pacemaker_simulink_IN_AAI:
      pacemaker_simulink_AAI(&Cast1, &Cast2,
        &pacemaker_simulink_B.MODE_SELECT_out, &Gain,
        &pacemaker_simulink_B.ATR_PULSE_WIDTH_out,
        &pacemaker_simulink_B.HYSTERESIS_out);
      break;

     case pacemaker_simulink_IN_AOO:
      if ((pacemaker_simulink_B.MODE_SELECT_out != 0) &&
          (pacemaker_simulink_B.MODE_SELECT_out != 4)) {
        pacemaker_simulink_DW.is_AOO = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_DW.is_c3_pacemaker_simulink =
          pacemaker_simulink_IN_Start;
      } else if (pacemaker_simulink_DW.is_AOO == pacemak_IN_Charging_and_Sensing)
      {
        pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
        pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_B.ATR_GND_CTRL = 1.0;
        pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
        if ((pacemaker_simulink_B.MODE_SELECT_out == 0) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 1) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 2) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 3)) {
          Cast1 = Cast2;
        }

        Gain = (uint32_T)Cast1 - /*MW:OvSatOk*/
          pacemaker_simulink_B.ATR_PULSE_WIDTH_out;
        if (Gain > Cast1) {
          Gain = 0U;
        }

        if (pacemaker_simulink_DW.temporalCounter_i1 >= Gain) {
          pacemaker_simulink_DW.is_AOO = pacemaker_simulink_IN_Pacing;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_B.ATR_PACE_CTRL = 1.0;
          pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_B.VENT_PACE_CTRL = 0.0;
        }
      } else {
        /* case IN_Pacing: */
        pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
        if (pacemaker_simulink_DW.temporalCounter_i1 >=
            pacemaker_simulink_B.ATR_PULSE_WIDTH_out) {
          pacemaker_simulink_DW.is_AOO = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Sensi(&Gain);
        }
      }
      break;

     case pacemaker_simulink_IN_Start:
      if ((pacemaker_simulink_B.MODE_SELECT_out == 0) ||
          (pacemaker_simulink_B.MODE_SELECT_out == 4)) {
        pacemaker_simulink_DW.is_c3_pacemaker_simulink =
          pacemaker_simulink_IN_AOO;
        pacemaker_simulink_DW.is_AOO = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Sensi(&Gain);
      } else if ((pacemaker_simulink_B.MODE_SELECT_out == 1) ||
                 (pacemaker_simulink_B.MODE_SELECT_out == 5)) {
        pacemaker_simulink_DW.is_c3_pacemaker_simulink =
          pacemaker_simulink_IN_VOO;
        pacemaker_simulink_DW.is_VOO = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_Se_mi(&Gain1);
      } else if ((pacemaker_simulink_B.MODE_SELECT_out == 2) ||
                 (pacemaker_simulink_B.MODE_SELECT_out == 6)) {
        pacemaker_simulink_DW.is_c3_pacemaker_simulink =
          pacemaker_simulink_IN_AAI;
        pacemaker_simulink_DW.is_AAI = pacemak_IN_Charging_and_Sensing;
        pacemaker_simulink_DW.temporalCounter_i1 = 0U;
        enter_atomic_Charging_and_S_mil(&Gain);
      } else {
        if ((pacemaker_simulink_B.MODE_SELECT_out == 3) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 7)) {
          pacemaker_simulink_DW.is_c3_pacemaker_simulink =
            pacemaker_simulink_IN_VVI;
          pacemaker_simulink_DW.is_VVI = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Sen_m(&Gain1);
        }
      }
      break;

     case pacemaker_simulink_IN_VOO:
      if ((pacemaker_simulink_B.MODE_SELECT_out != 1) &&
          (pacemaker_simulink_B.MODE_SELECT_out != 5)) {
        pacemaker_simulink_DW.is_VOO = pacemaker_si_IN_NO_ACTIVE_CHILD;
        pacemaker_simulink_DW.is_c3_pacemaker_simulink =
          pacemaker_simulink_IN_Start;
      } else if (pacemaker_simulink_DW.is_VOO == pacemak_IN_Charging_and_Sensing)
      {
        pacemaker_simulink_B.PACE_CHARGE_CTRL = 1.0;
        pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_B.VENT_GND_CTRL = 1.0;
        if ((pacemaker_simulink_B.MODE_SELECT_out == 0) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 1) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 2) ||
            (pacemaker_simulink_B.MODE_SELECT_out == 3)) {
          Cast1 = Cast2;
        }

        Gain = (uint32_T)Cast1 - /*MW:OvSatOk*/
          pacemaker_simulink_B.VENT_PULSE_WIDTH_out;
        if (Gain > Cast1) {
          Gain = 0U;
        }

        if (pacemaker_simulink_DW.temporalCounter_i1 >= Gain) {
          pacemaker_simulink_DW.is_VOO = pacemaker_simulink_IN_Pacing;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
          pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
          pacemaker_simulink_B.ATR_PACE_CTRL = 0.0;
          pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
          pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
          pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
          pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
          pacemaker_simulink_B.VENT_PACE_CTRL = 1.0;
        }
      } else {
        /* case IN_Pacing: */
        pacemaker_simulink_B.PACE_CHARGE_CTRL = 0.0;
        pacemaker_simulink_B.PACE_GND_CTRL = 1.0;
        pacemaker_simulink_B.ATR_GND_CTRL = 0.0;
        pacemaker_simulink_B.Z_ATR_CTRL = 0.0;
        pacemaker_simulink_B.Z_VENT_CTRL = 0.0;
        pacemaker_simulink_B.VENT_GND_CTRL = 0.0;
        if (pacemaker_simulink_DW.temporalCounter_i1 >=
            pacemaker_simulink_B.VENT_PULSE_WIDTH_out) {
          pacemaker_simulink_DW.is_VOO = pacemak_IN_Charging_and_Sensing;
          pacemaker_simulink_DW.temporalCounter_i1 = 0U;
          enter_atomic_Charging_and_Se_mi(&Gain1);
        }
      }
      break;

     default:
      /* case IN_VVI: */
      pacemaker_simulink_VVI(&Cast1, &Cast2,
        &pacemaker_simulink_B.MODE_SELECT_out, &Gain1,
        &pacemaker_simulink_B.VENT_PULSE_WIDTH_out,
        &pacemaker_simulink_B.HYSTERESIS_out);
      break;
    }
  }

  /* End of Chart: '<Root>/Pacemaker' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_l.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_DW.obj_o.MW_PWM_HANDLE,
                      pacemaker_simulink_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write1' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_lo.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output1' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_DW.obj_f.MW_PWM_HANDLE, (real_T)
                      pacemaker_simulink_B.PACING_REF_PWM * 0.00048828125);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(pacemaker_simulink_DW.obj_c.MW_PWM_HANDLE,
                      pacemaker_simulink_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_na.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write3' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_e.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write4' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_mm.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write5' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_ir.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write6' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_b.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_p.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(pacemaker_simulink_DW.obj_em.MW_DIGITALIO_HANDLE,
                     pacemaker_simulink_B.FRONTEND_CTRL != 0.0);
}

/* Model step function for TID1 */
void pacemaker_simulink_step1(void)    /* Sample time: [0.02s, 0.0s] */
{
  int16_T b_output[3];
  uint8_T status;
  uint8_T output_raw[6];
  uint8_T y[2];
  uint8_T b_x[2];
  real_T rtb_UnitDelay2;
  real_T rtb_Clamp01;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;

  /* MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  if (pacemaker_simulink_DW.obj.SampleTime !=
      pacemaker_simulink_P.FXOS87006AxesSensor_SampleTime) {
    pacemaker_simulink_DW.obj.SampleTime =
      pacemaker_simulink_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(pacemaker_simulink_DW.obj.i2cobj.MW_I2C_HANDLE,
    29U, &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(pacemaker_simulink_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
                      output_raw, 6U, false, true);
    memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
            sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[0], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[1], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[1], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[2], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[2], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  } else {
    b_output[0] = 0;
    b_output[1] = 0;
    b_output[2] = 0;
  }

  rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)(b_output[0] >> 2) * 2.0 *
    0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_output[1] >> 2) * 2.0 *
    0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)(b_output[2] >> 2) * 2.0 *
    0.244 / 1000.0;

  /* End of MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */

  /* Sqrt: '<S1>/Calculate Norm' incorporates:
   *  Math: '<S1>/Square'
   *  Math: '<S1>/Square1'
   *  Math: '<S1>/Square2'
   *  Sum: '<S1>/Add'
   */
  rtb_FXOS87006AxesSensor_idx_0 = sqrt((rtb_FXOS87006AxesSensor_idx_0 *
    rtb_FXOS87006AxesSensor_idx_0 + rtb_FXOS87006AxesSensor_idx_1 *
    rtb_FXOS87006AxesSensor_idx_1) + rtb_FXOS87006AxesSensor_idx_2 *
    rtb_FXOS87006AxesSensor_idx_2);

  /* UnitDelay: '<S8>/Unit Delay' */
  rtb_FXOS87006AxesSensor_idx_1 = pacemaker_simulink_DW.UnitDelay_DSTATE;

  /* UnitDelay: '<S8>/Unit Delay1' */
  rtb_FXOS87006AxesSensor_idx_2 = pacemaker_simulink_DW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S8>/Unit Delay2' */
  rtb_UnitDelay2 = pacemaker_simulink_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S8>/Unit Delay3' */
  pacemaker_simulink_B.UnitDelay3 = pacemaker_simulink_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S8>/Unit Delay4' */
  pacemaker_simulink_B.UnitDelay4 = pacemaker_simulink_DW.UnitDelay4_DSTATE;

  /* UnitDelay: '<S8>/Unit Delay5' */
  pacemaker_simulink_B.UnitDelay5 = pacemaker_simulink_DW.UnitDelay5_DSTATE;

  /* Product: '<S1>/Normalize' incorporates:
   *  Abs: '<S1>/Abs'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Subtract Gravity'
   *  Constant: '<S8>/Constant'
   *  Product: '<S8>/Divide'
   *  Sum: '<S1>/Subtract'
   *  Sum: '<S8>/Add'
   *  UnitDelay: '<S8>/Unit Delay'
   *  UnitDelay: '<S8>/Unit Delay1'
   *  UnitDelay: '<S8>/Unit Delay2'
   *  UnitDelay: '<S8>/Unit Delay3'
   *  UnitDelay: '<S8>/Unit Delay4'
   *  UnitDelay: '<S8>/Unit Delay5'
   *  UnitDelay: '<S8>/Unit Delay6'
   */
  rtb_Clamp01 = fabs((((((((rtb_FXOS87006AxesSensor_idx_0 +
    pacemaker_simulink_DW.UnitDelay_DSTATE) +
    pacemaker_simulink_DW.UnitDelay1_DSTATE) +
    pacemaker_simulink_DW.UnitDelay2_DSTATE) +
    pacemaker_simulink_DW.UnitDelay3_DSTATE) +
                        pacemaker_simulink_DW.UnitDelay4_DSTATE) +
                       pacemaker_simulink_DW.UnitDelay5_DSTATE) +
                      pacemaker_simulink_DW.UnitDelay6_DSTATE) /
                     pacemaker_simulink_P.Constant_Value_l -
                     pacemaker_simulink_P.SubtractGravity_Value) /
    pacemaker_simulink_P.Constant_Value_c;

  /* Saturate: '<S1>/Clamp 0 - 1' */
  if (rtb_Clamp01 > pacemaker_simulink_P.Clamp01_UpperSat) {
    rtb_Clamp01 = pacemaker_simulink_P.Clamp01_UpperSat;
  } else {
    if (rtb_Clamp01 < pacemaker_simulink_P.Clamp01_LowerSat) {
      rtb_Clamp01 = pacemaker_simulink_P.Clamp01_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Clamp 0 - 1' */

  /* RateTransition: '<Root>/Rate Transition' */
  pacemaker_simulink_DW.RateTransition_Buffer0 = rtb_Clamp01;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  pacemaker_simulink_DW.UnitDelay_DSTATE = rtb_FXOS87006AxesSensor_idx_0;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  pacemaker_simulink_DW.UnitDelay1_DSTATE = rtb_FXOS87006AxesSensor_idx_1;

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  pacemaker_simulink_DW.UnitDelay2_DSTATE = rtb_FXOS87006AxesSensor_idx_2;

  /* Update for UnitDelay: '<S8>/Unit Delay3' */
  pacemaker_simulink_DW.UnitDelay3_DSTATE = rtb_UnitDelay2;

  /* Update for UnitDelay: '<S8>/Unit Delay4' */
  pacemaker_simulink_DW.UnitDelay4_DSTATE = pacemaker_simulink_B.UnitDelay3;

  /* Update for UnitDelay: '<S8>/Unit Delay5' */
  pacemaker_simulink_DW.UnitDelay5_DSTATE = pacemaker_simulink_B.UnitDelay4;

  /* Update for UnitDelay: '<S8>/Unit Delay6' */
  pacemaker_simulink_DW.UnitDelay6_DSTATE = pacemaker_simulink_B.UnitDelay5;
}

/* Model step wrapper function for compatibility with a static main program */
void pacemaker_simulink_step(int_T tid)
{
  switch (tid) {
   case 0 :
    pacemaker_simulink_step0();
    break;

   case 1 :
    pacemaker_simulink_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void pacemaker_simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_DigitalRead_pacem_T *obj;
    freedomk64f_DigitalWrite_pace_T *obj_0;
    freedomk64f_PWMOutput_pacemak_T *obj_1;
    freedomk64f_fxos8700_pacemake_T *obj_2;

    /* Start for RateTransition: '<Root>/Rate Transition' */
    pacemaker_simulink_B.RateTransition =
      pacemaker_simulink_P.RateTransition_InitialCondition;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    pacemaker_simulink_DW.DS_ATR_REFRAC_PERIOD =
      pacemaker_simulink_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    pacemaker_simulink_DW.DS_VENT_REFRAC_PERIOD =
      pacemaker_simulink_P.DataStoreMemory4_InitialValue;

    /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
    pacemaker_simulink_DW.RateTransition_Buffer0 =
      pacemaker_simulink_P.RateTransition_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S2>/Previous Rate' */
    pacemaker_simulink_DW.PreviousRate_DSTATE =
      pacemaker_simulink_P.PreviousRate_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    pacemaker_simulink_DW.UnitDelay_DSTATE =
      pacemaker_simulink_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
    pacemaker_simulink_DW.UnitDelay1_DSTATE =
      pacemaker_simulink_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay2' */
    pacemaker_simulink_DW.UnitDelay2_DSTATE =
      pacemaker_simulink_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay3' */
    pacemaker_simulink_DW.UnitDelay3_DSTATE =
      pacemaker_simulink_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay4' */
    pacemaker_simulink_DW.UnitDelay4_DSTATE =
      pacemaker_simulink_P.UnitDelay4_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay5' */
    pacemaker_simulink_DW.UnitDelay5_DSTATE =
      pacemaker_simulink_P.UnitDelay5_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay6' */
    pacemaker_simulink_DW.UnitDelay6_DSTATE =
      pacemaker_simulink_P.UnitDelay6_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S7>/UART_Tx' */
    /* Start for MATLABSystem: '<S15>/Serial Transmit' */
    pacemaker_simulink_DW.obj_k.isInitialized = 0;
    pacemaker_simulink_DW.obj_k.matlabCodegenIsDeleted = false;
    pacemaker_s_SystemCore_setup_o3(&pacemaker_simulink_DW.obj_k);

    /* End of SystemInitialize for SubSystem: '<S7>/UART_Tx' */

    /* Start for MATLABSystem: '<S7>/UART Receive' */
    pacemaker_simulink_DW.obj_m.isInitialized = 0;
    pacemaker_simulink_DW.obj_m.matlabCodegenIsDeleted = false;
    pacemaker_simulink_DW.obj_m.SampleTime =
      pacemaker_simulink_P.UARTReceive_SampleTime;
    pacemaker_si_SystemCore_setup_o(&pacemaker_simulink_DW.obj_m);

    /* Start for MATLABSystem: '<S6>/ATR_CMP_DETECT' */
    pacemaker_simulink_DW.obj_i.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_i.isInitialized = 0;
    pacemaker_simulink_DW.obj_i.SampleTime = -1.0;
    pacemaker_simulink_DW.obj_i.matlabCodegenIsDeleted = false;
    pacemaker_simulink_DW.obj_i.SampleTime =
      pacemaker_simulink_P.ATR_CMP_DETECT_SampleTime;
    obj = &pacemaker_simulink_DW.obj_i;
    pacemaker_simulink_DW.obj_i.isSetupComplete = false;
    pacemaker_simulink_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    pacemaker_simulink_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/VENT_CMP_DETECT' */
    pacemaker_simulink_DW.obj_n.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_n.isInitialized = 0;
    pacemaker_simulink_DW.obj_n.SampleTime = -1.0;
    pacemaker_simulink_DW.obj_n.matlabCodegenIsDeleted = false;
    pacemaker_simulink_DW.obj_n.SampleTime =
      pacemaker_simulink_P.VENT_CMP_DETECT_SampleTime;
    obj = &pacemaker_simulink_DW.obj_n;
    pacemaker_simulink_DW.obj_n.isSetupComplete = false;
    pacemaker_simulink_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    pacemaker_simulink_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    pacemaker_simulink_DW.obj_l.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_l.isInitialized = 0;
    pacemaker_simulink_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_l;
    pacemaker_simulink_DW.obj_l.isSetupComplete = false;
    pacemaker_simulink_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    pacemaker_simulink_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    pacemaker_simulink_DW.obj_o.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_o.isInitialized = 0;
    pacemaker_simulink_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_DW.obj_o;
    pacemaker_simulink_DW.obj_o.isSetupComplete = false;
    pacemaker_simulink_DW.obj_o.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_DW.obj_o.MW_PWM_HANDLE);
    pacemaker_simulink_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    pacemaker_simulink_DW.obj_lo.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_lo.isInitialized = 0;
    pacemaker_simulink_DW.obj_lo.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_lo;
    pacemaker_simulink_DW.obj_lo.isSetupComplete = false;
    pacemaker_simulink_DW.obj_lo.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    pacemaker_simulink_DW.obj_lo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    pacemaker_simulink_DW.obj_f.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_f.isInitialized = 0;
    pacemaker_simulink_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_DW.obj_f;
    pacemaker_simulink_DW.obj_f.isSetupComplete = false;
    pacemaker_simulink_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_DW.obj_f.MW_PWM_HANDLE);
    pacemaker_simulink_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    pacemaker_simulink_DW.obj_c.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_c.isInitialized = 0;
    pacemaker_simulink_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_1 = &pacemaker_simulink_DW.obj_c;
    pacemaker_simulink_DW.obj_c.isSetupComplete = false;
    pacemaker_simulink_DW.obj_c.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(pacemaker_simulink_DW.obj_c.MW_PWM_HANDLE);
    pacemaker_simulink_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    pacemaker_simulink_DW.obj_na.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_na.isInitialized = 0;
    pacemaker_simulink_DW.obj_na.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_na;
    pacemaker_simulink_DW.obj_na.isSetupComplete = false;
    pacemaker_simulink_DW.obj_na.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    pacemaker_simulink_DW.obj_na.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write3' */
    pacemaker_simulink_DW.obj_e.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_e.isInitialized = 0;
    pacemaker_simulink_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_e;
    pacemaker_simulink_DW.obj_e.isSetupComplete = false;
    pacemaker_simulink_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    pacemaker_simulink_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write4' */
    pacemaker_simulink_DW.obj_mm.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_mm.isInitialized = 0;
    pacemaker_simulink_DW.obj_mm.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_mm;
    pacemaker_simulink_DW.obj_mm.isSetupComplete = false;
    pacemaker_simulink_DW.obj_mm.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    pacemaker_simulink_DW.obj_mm.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write5' */
    pacemaker_simulink_DW.obj_ir.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_ir.isInitialized = 0;
    pacemaker_simulink_DW.obj_ir.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_ir;
    pacemaker_simulink_DW.obj_ir.isSetupComplete = false;
    pacemaker_simulink_DW.obj_ir.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    pacemaker_simulink_DW.obj_ir.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write6' */
    pacemaker_simulink_DW.obj_b.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_b.isInitialized = 0;
    pacemaker_simulink_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_b;
    pacemaker_simulink_DW.obj_b.isSetupComplete = false;
    pacemaker_simulink_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    pacemaker_simulink_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
    pacemaker_simulink_DW.obj_p.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_p.isInitialized = 0;
    pacemaker_simulink_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_p;
    pacemaker_simulink_DW.obj_p.isSetupComplete = false;
    pacemaker_simulink_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    pacemaker_simulink_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    pacemaker_simulink_DW.obj_em.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj_em.isInitialized = 0;
    pacemaker_simulink_DW.obj_em.matlabCodegenIsDeleted = false;
    obj_0 = &pacemaker_simulink_DW.obj_em;
    pacemaker_simulink_DW.obj_em.isSetupComplete = false;
    pacemaker_simulink_DW.obj_em.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    pacemaker_simulink_DW.obj_em.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
    pacemaker_simulink_DW.obj.i2cobj.matlabCodegenIsDeleted = true;
    pacemaker_simulink_DW.obj.matlabCodegenIsDeleted = true;
    obj_2 = &pacemaker_simulink_DW.obj;
    pacemaker_simulink_DW.obj.isInitialized = 0;
    pacemaker_simulink_DW.obj.SampleTime = -1.0;
    obj_2->i2cobj.isInitialized = 0;
    obj_2->i2cobj.matlabCodegenIsDeleted = false;
    pacemaker_simulink_DW.obj.matlabCodegenIsDeleted = false;
    pacemaker_simulink_DW.obj.SampleTime =
      pacemaker_simulink_P.FXOS87006AxesSensor_SampleTime;
    pacemaker_simu_SystemCore_setup(&pacemaker_simulink_DW.obj);
  }
}

/* Model terminate function */
void pacemaker_simulink_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/UART Receive' */
  pacemaker_sim_matlabCodegenHa_h(&pacemaker_simulink_DW.obj_m);

  /* Terminate for Enabled SubSystem: '<S7>/UART_Tx' */
  /* Terminate for MATLABSystem: '<S15>/Serial Transmit' */
  pacemaker_sim_matlabCodegenHa_l(&pacemaker_simulink_DW.obj_k);

  /* End of Terminate for SubSystem: '<S7>/UART_Tx' */

  /* Terminate for MATLABSystem: '<S6>/ATR_CMP_DETECT' */
  matlabCodegenHan_o3x4x4sg33se1r(&pacemaker_simulink_DW.obj_i);

  /* Terminate for MATLABSystem: '<S6>/VENT_CMP_DETECT' */
  matlabCodegenHan_o3x4x4sg33se1r(&pacemaker_simulink_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHandle_m_o3x4x4sg3(&pacemaker_simulink_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_lo);

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  matlabCodegenHandle_m_o3x4x4sg3(&pacemaker_simulink_DW.obj_f);

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  matlabCodegenHandle_m_o3x4x4sg3(&pacemaker_simulink_DW.obj_c);

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_na);

  /* Terminate for MATLABSystem: '<S3>/Digital Write3' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_mm);

  /* Terminate for MATLABSystem: '<S3>/Digital Write5' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_ir);

  /* Terminate for MATLABSystem: '<S3>/Digital Write6' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_p);

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  matlabCodegenHandle_matlabCo_o3(&pacemaker_simulink_DW.obj_em);

  /* Terminate for MATLABSystem: '<S1>/FXOS8700 6-Axes Sensor' */
  matlabCodegenHandle_matlabCodeg(&pacemaker_simulink_DW.obj);
  matlabCodegenHandle_matlabCod_o(&pacemaker_simulink_DW.obj.i2cobj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
