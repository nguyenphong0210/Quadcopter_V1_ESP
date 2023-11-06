/*
 * File: asbQuadcopter.c
 *
 * Code generated for Simulink model 'asbQuadcopter'.
 *
 * Model version                  : 1.292
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Nov  6 00:19:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "asbQuadcopter.h"
// #include "rt_nrand_Upu32_Yd_f_pw_snf.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<S12>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Exported block signals */
SensorsBus sensor_inport;              /* '<S16>/Bus Creator1' */
CommandBus cmd_inport;                 /* '<S7>/Bus Creator' */
real32_T motors_outport[4];            /* '<Root>/FCS' */
uint8_T flag_outport;                  /* '<Root>/FCS' */

/* Continuous states */
X_asbQuadcopter_T asbQuadcopter_X;

/* Periodic continuous states */
PeriodicIndX_asbQuadcopter_T asbQuadcopter_PeriodicIndX;
PeriodicRngX_asbQuadcopter_T asbQuadcopter_PeriodicRngX;

/* Block signals and states (default storage) */
DW_asbQuadcopter_T asbQuadcopter_DW;

/* Real-time model */
RT_MODEL_asbQuadcopter_T asbQuadcopter_M_;
RT_MODEL_asbQuadcopter_T *const asbQuadcopter_M = &asbQuadcopter_M_;
extern const real_T rtCP_pooled_OlAt8KbpQEG0[3];
extern const real_T rtCP_pooled_NSXVAJI3vmgJ[3];
extern const real_T rtCP_pooled_qUKJar9kp1Eq[9];
extern const real_T rtCP_pooled_j4u5Z8yaBUeg[3];
extern const real_T rtCP_pooled_uzBfKM7wqk2k[9];
extern const real_T rtCP_pooled_zwuq7z9w9Fhh[3];
extern const real32_T rtCP_pooled_t2xxtwyJQBKA[8];

#define rtCP_Gravity_Value             rtCP_pooled_OlAt8KbpQEG0  /* Expression: [0 0 g]
                                                                  * Referenced by: '<S15>/Gravity'
                                                                  */
#define rtCP_Measurementbias_Value     rtCP_pooled_NSXVAJI3vmgJ  /* Expression: a_bias
                                                                  * Referenced by: '<S37>/Measurement bias'
                                                                  */
#define rtCP_ScalefactorsCrosscouplingerrors_Value rtCP_pooled_qUKJar9kp1Eq/* Expression: a_sf_cc
                                                                      * Referenced by: '<S37>/Scale factors & Cross-coupling  errors'
                                                                      */
#define rtCP_Measurementbias_Value_a   rtCP_pooled_j4u5Z8yaBUeg  /* Expression: g_bias
                                                                  * Referenced by: '<S38>/Measurement bias'
                                                                  */
#define rtCP_ScalefactorsCrosscouplingerrors_Value_o rtCP_pooled_uzBfKM7wqk2k/* Expression: g_sf_cc
                                                                      * Referenced by: '<S38>/Scale factors & Cross-coupling  errors '
                                                                      */
#define rtCP_Gain_Gain                 rtCP_pooled_zwuq7z9w9Fhh  /* Expression: [1 -1 1]
                                                                  * Referenced by: '<S37>/Gain'
                                                                  */
#define rtCP_Constant_Value_h          rtCP_pooled_t2xxtwyJQBKA  /* Computed Parameter: rtCP_Constant_Value_h
                                                                  * Referenced by: '<S16>/Constant'
                                                                  */

/* private model entry point functions */
extern void asbQuadcopter_derivatives(void);

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 16;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  asbQuadcopter_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  asbQuadcopter_step0();
  asbQuadcopter_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  asbQuadcopter_step0();
  asbQuadcopter_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(x, rtsiGetPeriodicContStateIndices(si), 4,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function for TID0 */
void asbQuadcopter_step0(void)         /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  uint32_T rtb_FixPtSwitch;
  real32_T rtb_YawPitchRoll[3];
  real_T rtb_TrigonometricFunction_h;
  real_T rtb_Product2_b;
  real_T rtb_Sum_a;
  real_T rtb_Product1_p;
  real_T rtb_Sum_cy;
  real_T rtb_Sum_b;
  real_T rtb_Sum_l[3];
  real_T rtb_Product1_c;
  real_T rtb_Product_g;
  real_T rtb_Saturation[3];
  HAL_echo_t rtb_HAL_echo_t;
  HAL_fifo_gyro_SI_t rtb_HAL_fifo_gyro_SI_TempCorr;
  real32_T rtb_DataTypeConversion2[3];
  real_T rtb_Sum4[3];
  int32_T i;
  real_T tmp[3];
  real_T tmp_0[3];
  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&asbQuadcopter_M->solverInfo,
                          ((asbQuadcopter_M->Timing.clockTick0+1)*
      asbQuadcopter_M->Timing.stepSize0));

    /* Update the flag to indicate when data transfers from
     *  Sample time: [0.005s, 0.0s] to Sample time: [0.06s, 0.0s]  */
    asbQuadcopter_M->Timing.RateInteraction.b_TID1_2 =
      (asbQuadcopter_M->Timing.RateInteraction.TID1_2 == 0);
    (asbQuadcopter_M->Timing.RateInteraction.TID1_2)++;
    if ((asbQuadcopter_M->Timing.RateInteraction.TID1_2) > 11) {
      asbQuadcopter_M->Timing.RateInteraction.TID1_2 = 0;
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(asbQuadcopter_M)) {
    asbQuadcopter_M->Timing.t[0] = rtsiGetT(&asbQuadcopter_M->solverInfo);
  }

  /* FromWorkspace: '<S12>/From Workspace' */
  {
    real_T t = asbQuadcopter_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      asbQuadcopter_DW.FromWorkspace_PWORK.TimePtr;
    real32_T *pDataValues = (real32_T *)
      asbQuadcopter_DW.FromWorkspace_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = 0.0F;
        }
      }
    } else if (t == pTimeValues[1]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = pDataValues[1];
          pDataValues += 2;
        }
      }
    } else if (t > pTimeValues[1]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = 0.0F;
        }
      }
    } else {
      int_T currTimeIndex = asbQuadcopter_DW.FromWorkspace_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = pDataValues[currTimeIndex];
          pDataValues += 2;
        }
      }

      asbQuadcopter_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
    }
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    /* FromWorkspace: '<S12>/fromWS_Signal 1' */
    {
      real_T t = ((asbQuadcopter_M->Timing.clockTick1) * 0.005);
      real_T *pTimeValues = (real_T *)
        asbQuadcopter_DW.fromWS_Signal1_PWORK.TimePtr;
      real32_T *pDataValues = (real32_T *)
        asbQuadcopter_DW.fromWS_Signal1_PWORK.DataPtr;
      if (t < pTimeValues[0]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&asbQuadcopter_DW.XYZ[0])[elIdx] = 0.0F;
          }
        }
      } else if (t >= pTimeValues[3]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&asbQuadcopter_DW.XYZ[0])[elIdx] = pDataValues[3];
            pDataValues += 4;
          }
        }
      } else {
        int_T currTimeIndex = asbQuadcopter_DW.fromWS_Signal1_IWORK.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&asbQuadcopter_DW.XYZ[0])[elIdx] = pDataValues[currTimeIndex];
            pDataValues += 4;
          }
        }

        asbQuadcopter_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
      }
    }

    /* RateTransition: '<S7>/Rate Transition3' incorporates:
     *  Clock: '<S7>/Clock'
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S8>/Compare'
     */
    if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
      asbQuadcopter_DW.takeoff_flag = (asbQuadcopter_M->Timing.t[0] < 1.0);
    }

    /* End of RateTransition: '<S7>/Rate Transition3' */

    /* UnitDelay: '<S11>/Output' */
    asbQuadcopter_DW.Output = asbQuadcopter_DW.Output_DSTATE;
  }

  /* BusCreator: '<S7>/Bus Creator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  cmd_inport.controlModePosVSOrient = ((rtb_YawPitchRoll[2] == 0.0F) &&
    (rtb_YawPitchRoll[1] == 0.0F));
  cmd_inport.takeoff_flag = asbQuadcopter_DW.takeoff_flag;
  cmd_inport.pos_ref[0] = asbQuadcopter_DW.XYZ[0];
  cmd_inport.orient_ref[0] = rtb_YawPitchRoll[0];
  cmd_inport.pos_ref[1] = asbQuadcopter_DW.XYZ[1];
  cmd_inport.orient_ref[1] = rtb_YawPitchRoll[1];
  cmd_inport.pos_ref[2] = asbQuadcopter_DW.XYZ[2];
  cmd_inport.orient_ref[2] = rtb_YawPitchRoll[2];
  cmd_inport.live_time_ticks = asbQuadcopter_DW.Output;
  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    /* Outputs for Atomic SubSystem: '<S3>/Environment (Constant)' */
    /* BusCreator: '<S15>/Bus Creator' incorporates:
     *  BusCreator: '<S15>/Bus Creator1'
     *  Constant: '<S15>/Air Density'
     *  Constant: '<S15>/Air Temp'
     *  Constant: '<S15>/Pressure'
     *  Constant: '<S15>/Speed of Sound'
     */
    asbQuadcopter_DW.BusCreator.AtmosphereBus.air_temp = 288.0;
    asbQuadcopter_DW.BusCreator.AtmosphereBus.speed_sound = 340.0;
    asbQuadcopter_DW.BusCreator.AtmosphereBus.pressure = 101300.0;
    asbQuadcopter_DW.BusCreator.AtmosphereBus.air_density = 1.184;

    /* End of Outputs for SubSystem: '<S3>/Environment (Constant)' */

    /* Outputs for Atomic SubSystem: '<S4>/Sensors (Dynamics)' */
    /* BusCreator: '<S34>/Bus Creator6' incorporates:
     *  Constant: '<S34>/begin_echo_index'
     *  Constant: '<S34>/begin_echo_index1'
     *  Constant: '<S34>/begin_echo_index2'
     *  Constant: '<S34>/begin_echo_index3'
     *  Constant: '<S34>/begin_echo_index4'
     *  Constant: '<S34>/begin_echo_index5'
     *  Constant: '<S34>/begin_echo_index6'
     */
    rtb_HAL_echo_t.begin_echo_index = 0U;
    rtb_HAL_echo_t.end_echo_index = 0U;
    rtb_HAL_echo_t.max_value_index = 0;
    rtb_HAL_echo_t.max_value = 0;
    rtb_HAL_echo_t.precedent = 0U;
    rtb_HAL_echo_t.d_echo = 0;
    rtb_HAL_echo_t.pre_max_index = 0U;

    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  Concatenate: '<S32>/Vector Concatenate'
     */
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[0] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[1] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[2] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[3] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[4] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[5] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[6] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[7] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[8] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[9] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[10] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[11] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[12] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[13] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[14] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[15] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[16] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[17] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[18] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[19] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[20] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[21] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[22] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[23] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[24] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[25] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[26] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[27] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[28] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.tab_echo[29] =
      rtb_HAL_echo_t;

    /* BusCreator: '<S35>/Bus Creator6' incorporates:
     *  Constant: '<S35>/begin_echo_index'
     *  Constant: '<S35>/begin_echo_index1'
     *  Constant: '<S35>/begin_echo_index2'
     *  Constant: '<S35>/begin_echo_index3'
     *  Constant: '<S35>/begin_echo_index4'
     *  Constant: '<S35>/begin_echo_index5'
     *  Constant: '<S35>/begin_echo_index6'
     */
    rtb_HAL_echo_t.begin_echo_index = 0U;
    rtb_HAL_echo_t.end_echo_index = 0U;
    rtb_HAL_echo_t.max_value_index = 0;
    rtb_HAL_echo_t.max_value = 0;
    rtb_HAL_echo_t.precedent = 0U;
    rtb_HAL_echo_t.d_echo = 0;
    rtb_HAL_echo_t.pre_max_index = 0U;

    /* BusCreator: '<S23>/Bus Creator' incorporates:
     *  Constant: '<S23>/z'
     *  Constant: '<S23>/z1'
     *  Constant: '<S23>/z2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  Concatenate: '<S23>/Vector Concatenate'
     */
    sensor_inport.HALSensors.HAL_fifo_gyro_SI_TempCorr[0] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI_TempCorr[1] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI_TempCorr[2] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI_TempCorr[3] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI_TempCorr[4] =
      rtb_HAL_fifo_gyro_SI_TempCorr;

    /* BusCreator: '<S24>/Bus Creator' incorporates:
     *  Constant: '<S24>/x'
     *  Constant: '<S24>/x1'
     *  Constant: '<S24>/x2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  Concatenate: '<S24>/Vector Concatenate'
     */
    sensor_inport.HALSensors.HAL_fifo_acce_SI_TempCorr[0] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI_TempCorr[1] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI_TempCorr[2] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI_TempCorr[3] =
      rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI_TempCorr[4] =
      rtb_HAL_fifo_gyro_SI_TempCorr;

    /* BusCreator: '<S25>/Bus Creator' incorporates:
     *  Constant: '<S25>/z'
     *  Constant: '<S25>/z1'
     *  Constant: '<S25>/z2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  Concatenate: '<S25>/Vector Concatenate'
     */
    sensor_inport.HALSensors.HAL_fifo_gyro_SI[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_gyro_SI[4] = rtb_HAL_fifo_gyro_SI_TempCorr;

    /* BusCreator: '<S26>/Bus Creator' incorporates:
     *  Constant: '<S26>/z'
     *  Constant: '<S26>/z1'
     *  Constant: '<S26>/z2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* Outputs for Atomic SubSystem: '<S3>/Environment (Constant)' */
    /* Unit Conversion - from: m/s^2 to: gn
       Expression: output = (0.101972*input) + (0) */
    for (i = 0; i < 3; i++) {
      /* BusCreator: '<S15>/Bus Creator' incorporates:
       *  Constant: '<S15>/Gravity'
       */
      asbQuadcopter_DW.BusCreator.Gravity_ned[i] = rtCP_Gravity_Value[i];
      asbQuadcopter_DW.BusCreator.MagneticField_ned[i] = 0.0;

      /* Sum: '<S38>/Sum1' incorporates:
       *  Constant: '<S38>/Measurement bias'
       *  Constant: '<S38>/Scale factors & Cross-coupling  errors '
       *  Memory: '<S16>/Memory1'
       *  Product: '<S38>/Product'
       *  Product: '<S38>/Product1'
       *  Product: '<S54>/Product'
       *  RandomNumber: '<S54>/White Noise'
       *  Sum: '<S38>/Sum4'
       *  UnitConversion: '<S36>/Unit Conversion'
       */
      rtb_Product_g = asbQuadcopter_ConstB.Divide_l[i] *
        asbQuadcopter_DW.NextOutput[i] + (0.10197162129779282 *
        asbQuadcopter_DW.Memory1_PreviousInput.Accel_body[i] * 0.0 +
        ((rtCP_ScalefactorsCrosscouplingerrors_Value_o[i + 6] *
          asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[2] +
          (rtCP_ScalefactorsCrosscouplingerrors_Value_o[i + 3] *
           asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[1] +
           rtCP_ScalefactorsCrosscouplingerrors_Value_o[i] *
           asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[0])) +
         rtCP_Measurementbias_Value_a[i]));

      /* Saturate: '<S38>/Saturation' */
      if (rtb_Product_g > 10.0) {
        /* DataTypeConversion: '<S19>/Data Type Conversion2' */
        rtb_DataTypeConversion2[i] = 10.0F;
      } else if (rtb_Product_g < -10.0) {
        /* DataTypeConversion: '<S19>/Data Type Conversion2' */
        rtb_DataTypeConversion2[i] = -10.0F;
      } else {
        /* DataTypeConversion: '<S19>/Data Type Conversion2' */
        rtb_DataTypeConversion2[i] = (real32_T)rtb_Product_g;
      }

      /* End of Saturate: '<S38>/Saturation' */

      /* Product: '<S38>/Product' incorporates:
       *  Constant: '<S38>/Scale factors & Cross-coupling  errors '
       *  Gain: '<S37>/Gain'
       *  Sum: '<S37>/Sum7'
       */
      rtb_Sum_l[i] = rtCP_Gain_Gain[i] * 0.0;
    }

    /* End of Outputs for SubSystem: '<S3>/Environment (Constant)' */

    /* Sum: '<S46>/Sum' incorporates:
     *  Memory: '<S16>/Memory1'
     *  Product: '<S49>/i x j'
     *  Product: '<S49>/j x k'
     *  Product: '<S49>/k x i'
     *  Product: '<S50>/i x k'
     *  Product: '<S50>/j x i'
     *  Product: '<S50>/k x j'
     */
    rtb_Saturation[0] = asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[1] *
      rtb_Sum_l[2] - asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[2] *
      rtb_Sum_l[1];
    rtb_Saturation[1] = asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[2] *
      rtb_Sum_l[0] - asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[0] *
      rtb_Sum_l[2];
    rtb_Saturation[2] = asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[0] *
      rtb_Sum_l[1] - asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[1] *
      rtb_Sum_l[0];

    /* Product: '<S47>/k x i' */
    rtb_Product2_b = rtb_Saturation[0];

    /* Product: '<S47>/i x j' */
    rtb_Sum_b = rtb_Saturation[1];

    /* Product: '<S48>/j x i' */
    rtb_Sum_cy = rtb_Saturation[0];

    /* Sum: '<S45>/Sum' incorporates:
     *  Memory: '<S16>/Memory1'
     *  Product: '<S47>/i x j'
     *  Product: '<S47>/j x k'
     *  Product: '<S47>/k x i'
     *  Product: '<S48>/i x k'
     *  Product: '<S48>/j x i'
     *  Product: '<S48>/k x j'
     */
    rtb_Saturation[0] = asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[1] *
      rtb_Saturation[2] - asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[2] *
      rtb_Saturation[1];
    rtb_Saturation[1] = asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[2] *
      rtb_Product2_b - asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[0] *
      rtb_Saturation[2];
    rtb_Saturation[2] = asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[0] *
      rtb_Sum_b - asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[1] *
      rtb_Sum_cy;

    /* Sum: '<S42>/Sum' incorporates:
     *  Memory: '<S16>/Memory1'
     *  Product: '<S51>/i x j'
     *  Product: '<S51>/j x k'
     *  Product: '<S51>/k x i'
     *  Product: '<S52>/i x k'
     *  Product: '<S52>/j x i'
     *  Product: '<S52>/k x j'
     */
    tmp[0] = asbQuadcopter_DW.Memory1_PreviousInput.dOmega_body[1] * rtb_Sum_l[2];
    tmp[1] = asbQuadcopter_DW.Memory1_PreviousInput.dOmega_body[2] * rtb_Sum_l[0];
    tmp[2] = asbQuadcopter_DW.Memory1_PreviousInput.dOmega_body[0] * rtb_Sum_l[1];
    tmp_0[0] = asbQuadcopter_DW.Memory1_PreviousInput.dOmega_body[2] *
      rtb_Sum_l[1];
    tmp_0[1] = asbQuadcopter_DW.Memory1_PreviousInput.dOmega_body[0] *
      rtb_Sum_l[2];
    tmp_0[2] = asbQuadcopter_DW.Memory1_PreviousInput.dOmega_body[1] *
      rtb_Sum_l[0];

    /* Sum: '<S37>/Sum' incorporates:
     *  Memory: '<S16>/Memory1'
     *  Product: '<S19>/Product'
     *  Sum: '<S42>/Sum'
     */
    for (i = 0; i < 3; i++) {
      rtb_Sum4[i] = ((asbQuadcopter_DW.Memory1_PreviousInput.Accel_body[i] -
                      ((asbQuadcopter_DW.Memory1_PreviousInput.DCM_be[i + 3] *
                        asbQuadcopter_DW.BusCreator.Gravity_ned[1] +
                        asbQuadcopter_DW.Memory1_PreviousInput.DCM_be[i] *
                        asbQuadcopter_DW.BusCreator.Gravity_ned[0]) +
                       asbQuadcopter_DW.Memory1_PreviousInput.DCM_be[i + 6] *
                       asbQuadcopter_DW.BusCreator.Gravity_ned[2])) +
                     rtb_Saturation[i]) + (tmp[i] - tmp_0[i]);
    }

    /* End of Sum: '<S37>/Sum' */
    for (i = 0; i < 3; i++) {
      /* Sum: '<S37>/Sum4' incorporates:
       *  Constant: '<S37>/Measurement bias'
       *  Constant: '<S37>/Scale factors & Cross-coupling  errors'
       *  Product: '<S37>/Product'
       */
      rtb_Sum_l[i] = (rtCP_ScalefactorsCrosscouplingerrors_Value[i + 6] *
                      rtb_Sum4[2] +
                      (rtCP_ScalefactorsCrosscouplingerrors_Value[i + 3] *
                       rtb_Sum4[1] +
                       rtCP_ScalefactorsCrosscouplingerrors_Value[i] * rtb_Sum4
                       [0])) + rtCP_Measurementbias_Value[i];
    }

    /* Sum: '<S37>/Sum1' incorporates:
     *  Product: '<S40>/Product'
     *  RandomNumber: '<S40>/White Noise'
     *  Switch: '<S39>/Switch'
     */
    rtb_Product_g = 0.20895707637033364 * asbQuadcopter_DW.NextOutput_k[0] +
      rtb_Sum_l[0];
    rtb_Product2_b = 0.19308726138552304 * asbQuadcopter_DW.NextOutput_k[1] +
      rtb_Sum_l[1];
    rtb_Sum_b = 0.27295079520021048 * asbQuadcopter_DW.NextOutput_k[2] +
      rtb_Sum_l[2];

    /* Saturate: '<S19>/Saturation' incorporates:
     *  Gain: '<S19>/altToprs_gain1'
     *  Memory: '<S16>/Memory1'
     */
    if ((real32_T)-asbQuadcopter_DW.Memory1_PreviousInput.X_ned[2] <= 0.44F) {
      /* BusCreator: '<S16>/Bus Creator1' */
      sensor_inport.HALSensors.HAL_ultrasound_SI.altitude = 0.44F;
    } else {
      /* BusCreator: '<S16>/Bus Creator1' */
      sensor_inport.HALSensors.HAL_ultrasound_SI.altitude = (real32_T)
        -asbQuadcopter_DW.Memory1_PreviousInput.X_ned[2];
    }

    /* End of Saturate: '<S19>/Saturation' */

    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  BusCreator: '<S16>/Bus Creator2'
     *  BusCreator: '<S20>/Bus Creator4'
     *  Constant: '<S16>/_DUMMY_FLAG_usePosVIS'
     *  Constant: '<S20>/number_HAL_read_call'
     *  Constant: '<S20>/number_HAL_read_call1'
     *  Constant: '<S20>/number_HAL_read_call2'
     *  Constant: '<S20>/number_HAL_read_call3'
     *  Constant: '<S20>/number_HAL_read_call4'
     *  DataTypeConversion: '<S18>/Data Type Conversion'
     *  Gain: '<S18>/Gain1'
     *  Gain: '<S18>/Gain2'
     *  Memory: '<S16>/Memory1'
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Add1'
     */
    sensor_inport.VisionSensors.opticalFlow_data[0] = (real32_T)(0.8 *
      asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[1] *
      -asbQuadcopter_DW.Memory1_PreviousInput.X_ned[2] +
      asbQuadcopter_DW.Memory1_PreviousInput.V_body[0]);
    sensor_inport.VisionSensors.opticalFlow_data[1] = (real32_T)(-0.8 *
      asbQuadcopter_DW.Memory1_PreviousInput.Omega_body[0] *
      -asbQuadcopter_DW.Memory1_PreviousInput.X_ned[2] +
      asbQuadcopter_DW.Memory1_PreviousInput.V_body[1]);
    sensor_inport.VisionSensors.opticalFlow_data[2] = (real32_T)
      asbQuadcopter_DW.Memory1_PreviousInput.V_body[2];
    sensor_inport.VisionSensors.posVIS_data[0] = -99.0F;
    sensor_inport.VisionSensors.posVIS_data[1] = 0.0F;
    sensor_inport.VisionSensors.posVIS_data[2] = 0.0F;
    sensor_inport.VisionSensors.posVIS_data[3] = -9.0F;
    sensor_inport.VisionSensors.usePosVIS_flag = 0.0F;
    sensor_inport.HALSensors.number_HAL_read_call = 0;
    sensor_inport.HALSensors.timestamp = 0U;
    sensor_inport.HALSensors.status = 0U;
    sensor_inport.HALSensors.used = 0U;
    sensor_inport.HALSensors.count_user = 0U;

    /* Saturate: '<S37>/Saturation' */
    if (rtb_Product_g > 50.0) {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.x = 50.0F;
    } else if (rtb_Product_g < -50.0) {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.x = -50.0F;
    } else {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.x = (real32_T)rtb_Product_g;
    }

    if (rtb_Product2_b > 50.0) {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.y = 50.0F;
    } else if (rtb_Product2_b < -50.0) {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.y = -50.0F;
    } else {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.y = (real32_T)rtb_Product2_b;
    }

    if (rtb_Sum_b > 50.0) {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.z = 50.0F;
    } else if (rtb_Sum_b < -50.0) {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.z = -50.0F;
    } else {
      /* BusCreator: '<S16>/Bus Creator1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       */
      sensor_inport.HALSensors.HAL_acc_SI.z = (real32_T)rtb_Sum_b;
    }

    /* End of Saturate: '<S37>/Saturation' */

    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  Bias: '<S19>/Assumes takeoff was level1'
     *  BusCreator: '<S20>/Bus Creator4'
     *  BusCreator: '<S30>/Bus Creator2'
     *  BusCreator: '<S32>/Bus Creator7'
     *  BusCreator: '<S33>/Bus Creator7'
     *  Concatenate: '<S26>/Vector Concatenate'
     *  Concatenate: '<S33>/Vector Concatenate'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S20>/number_HAL_read_call5'
     *  Constant: '<S20>/number_HAL_read_call6'
     *  Constant: '<S20>/number_HAL_read_call7'
     *  Constant: '<S20>/number_HAL_read_call8'
     *  Constant: '<S22>/temperature'
     *  Constant: '<S27>/temperature'
     *  Constant: '<S27>/temperature_lsb'
     *  Constant: '<S28>/z'
     *  Constant: '<S28>/z1'
     *  Constant: '<S28>/z2'
     *  Constant: '<S29>/temperature'
     *  Constant: '<S30>/raw_altitude'
     *  Constant: '<S30>/raw_altitude1'
     *  Constant: '<S30>/raw_altitude2'
     *  Constant: '<S30>/raw_altitude3'
     *  Constant: '<S30>/raw_altitude4'
     *  Constant: '<S32>/number_of_echoes'
     *  Constant: '<S33>/number_of_echoes'
     *  Gain: '<S19>/altToprs_gain'
     *  Memory: '<S16>/Memory1'
     * */
    sensor_inport.HALSensors.HAL_acc_SI.temperature = 0.0F;
    sensor_inport.HALSensors.HAL_gyro_SI.x = rtb_DataTypeConversion2[0];
    sensor_inport.HALSensors.HAL_gyro_SI.y = rtb_DataTypeConversion2[1];
    sensor_inport.HALSensors.HAL_gyro_SI.z = rtb_DataTypeConversion2[2];
    sensor_inport.HALSensors.HAL_gyro_SI.temperature = 0.0F;
    sensor_inport.HALSensors.HAL_gyro_SI.temperature_lsb = 0;
    sensor_inport.HALSensors.HAL_fifo_count = 0U;
    sensor_inport.HALSensors.fifo_timestamp = 0U;
    sensor_inport.HALSensors.HAL_fifo_acce_SI[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_fifo_acce_SI[4] = rtb_HAL_fifo_gyro_SI_TempCorr;
    sensor_inport.HALSensors.HAL_ref_IMU_temp = 0.0F;
    for (i = 0; i < 5; i++) {
      sensor_inport.HALSensors.HAL_fifo_fsync[i] = 0U;
    }

    sensor_inport.HALSensors.HAL_fifo_size = 0;
    sensor_inport.HALSensors.HAL_magn_mG.x = 0.0F;
    sensor_inport.HALSensors.HAL_magn_mG.y = 0.0F;
    sensor_inport.HALSensors.HAL_magn_mG.z = 0.0F;
    sensor_inport.HALSensors.HAL_pressure_SI.temperature = 0.0;
    sensor_inport.HALSensors.HAL_pressure_SI.pressure = (real32_T)
      (12.017250061035156 * asbQuadcopter_DW.Memory1_PreviousInput.X_ned[2]) +
      101270.953F;
    sensor_inport.HALSensors.HAL_ultrasound_SI.raw_altitude = 0.0F;
    sensor_inport.HALSensors.HAL_ultrasound_SI.nb_echo = 0U;
    sensor_inport.HALSensors.HAL_ultrasound_SI.measure_ref = 0;
    sensor_inport.HALSensors.HAL_ultrasound_SI.measure_status = 0;
    sensor_inport.HALSensors.HAL_ultrasound_SI.new_data = 0U;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.number_of_echoes =
      0U;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[0] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[1] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[2] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[3] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[4] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[5] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[6] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[7] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[8] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[9] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[10] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[11] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[12] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[13] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[14] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[15] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[16] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[17] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[18] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[19] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[20] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[21] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[22] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[23] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[24] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[25] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[26] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[27] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[28] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.tab_echo[29] =
      rtb_HAL_echo_t;
    sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo_p.number_of_echoes =
      0U;
    memset(&sensor_inport.HALSensors.padding[0], 0, 196U * sizeof(uint8_T));
    sensor_inport.HALSensors.HAL_vbat_SI.vbat_V = 3.5F;
    sensor_inport.HALSensors.HAL_vbat_SI.vbat_percentage = 70U;
    for (i = 0; i < 8; i++) {
      sensor_inport.SensorCalibration[i] = rtCP_Constant_Value_h[i];
    }

    /* End of Outputs for SubSystem: '<S4>/Sensors (Dynamics)' */

    /* ModelReference: '<Root>/FCS' */
    // flightControlSystem();

    /* Gain: '<S70>/Visualization Gain' incorporates:
     *  DataTypeConversion: '<S70>/Data Type Conversion'
     *  Gain: '<S70>/Gain'
     */
    asbQuadcopter_DW.VisualizationGain[0] = -13840.8 * motors_outport[0] *
      0.0001;
    asbQuadcopter_DW.VisualizationGain[1] = -13840.8 * motors_outport[1] *
      0.0001;
    asbQuadcopter_DW.VisualizationGain[2] = -13840.8 * motors_outport[2] *
      0.0001;
    asbQuadcopter_DW.VisualizationGain[3] = -13840.8 * motors_outport[3] *
      0.0001;
  }

  /* ModelReference: '<S1>/Linear Airframe' */
  linearAirframe(&motors_outport[0], &asbQuadcopter_DW.BusCreator,
                 &asbQuadcopter_DW.LinearAirframe,
                 &(asbQuadcopter_DW.LinearAirframe_InstanceData.rtdw),
                 &(asbQuadcopter_X.LinearAirframe_CSTATE));

  /* Gain: '<S75>/1//2' */
  rtb_Product2_b = 0.5 * asbQuadcopter_DW.LinearAirframe.Euler[1];

  /* Trigonometry: '<S75>/Trigonometric Function' */
  rtb_Product_g = sin(rtb_Product2_b);

  /* Product: '<S75>/Product' */
  rtb_Sum_l[0] = rtb_Product_g * 0.0;
  rtb_Sum_l[1] = rtb_Product_g * 0.0;
  rtb_Sum_l[2] = rtb_Product_g;

  /* RateTransition: '<S65>/Rate Transition3' incorporates:
   *  Bias: '<S65>/Camera bias Chase'
   *  Bias: '<S65>/Camera bias Iso'
   *  Gain: '<S67>/rad-->deg1'
   *  Gain: '<S68>/rad-->deg1'
   *  RateTransition: '<S65>/Rate Transition2'
   */
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      (asbQuadcopter_M->Timing.RateInteraction.TID1_2 == 1)) {
    asbQuadcopter_DW.RateTransition3_Buffer[0] =
      asbQuadcopter_DW.LinearAirframe.X_ned[0] + -4.0;
    asbQuadcopter_DW.RateTransition3_Buffer[1] =
      -(asbQuadcopter_DW.LinearAirframe.X_ned[2] + -0.9558);
    asbQuadcopter_DW.RateTransition3_Buffer[2] =
      asbQuadcopter_DW.LinearAirframe.X_ned[1];
    asbQuadcopter_DW.RateTransition2_Buffer[0] =
      asbQuadcopter_DW.LinearAirframe.X_ned[0] + 0.9009;
    asbQuadcopter_DW.RateTransition2_Buffer[1] =
      -(asbQuadcopter_DW.LinearAirframe.X_ned[2] + -0.6247);
    asbQuadcopter_DW.RateTransition2_Buffer[2] =
      asbQuadcopter_DW.LinearAirframe.X_ned[1] + 0.99;
  }

  /* End of RateTransition: '<S65>/Rate Transition3' */

  /* Gain: '<S74>/1//2' */
  rtb_Product_g = 0.5 * asbQuadcopter_DW.LinearAirframe.Euler[0];

  /* Trigonometry: '<S74>/Trigonometric Function' */
  rtb_Product1_c = sin(rtb_Product_g);

  /* Product: '<S74>/Product' */
  rtb_Sum4[0] = rtb_Product1_c;
  rtb_Sum4[1] = rtb_Product1_c * 0.0;
  rtb_Sum4[2] = rtb_Product1_c * 0.0;

  /* Gain: '<S76>/1//2' */
  rtb_Product1_c = 0.5 * asbQuadcopter_DW.LinearAirframe.Euler[2];

  /* Trigonometry: '<S76>/Trigonometric Function' */
  rtb_TrigonometricFunction_h = sin(rtb_Product1_c);

  /* Product: '<S76>/Product' */
  rtb_Saturation[0] = rtb_TrigonometricFunction_h * 0.0;
  rtb_Saturation[1] = -rtb_TrigonometricFunction_h;
  rtb_Saturation[2] = rtb_TrigonometricFunction_h * 0.0;

  /* Trigonometry: '<S76>/Trigonometric Function1' */
  rtb_Product1_c = cos(rtb_Product1_c);

  /* Trigonometry: '<S75>/Trigonometric Function1' */
  rtb_Product2_b = cos(rtb_Product2_b);

  /* Sum: '<S77>/Sum' incorporates:
   *  Product: '<S76>/Product'
   *  Product: '<S77>/Product'
   *  Product: '<S77>/Product1'
   *  Product: '<S77>/Product2'
   *  Product: '<S77>/Product3'
   */
  rtb_Sum_a = ((rtb_Product1_c * rtb_Product2_b - rtb_Saturation[0] * rtb_Sum_l
                [0]) - -rtb_TrigonometricFunction_h * rtb_Sum_l[1]) -
    rtb_Saturation[2] * rtb_Sum_l[2];

  /* Trigonometry: '<S74>/Trigonometric Function1' */
  rtb_Product_g = cos(rtb_Product_g);

  /* Sum: '<S78>/Sum' incorporates:
   *  Product: '<S76>/Product'
   *  Product: '<S78>/Product'
   *  Product: '<S78>/Product1'
   *  Product: '<S78>/Product2'
   *  Product: '<S78>/Product3'
   */
  rtb_Product1_p = ((rtb_Product1_c * rtb_Sum_l[0] + rtb_Saturation[0] *
                     rtb_Product2_b) + -rtb_TrigonometricFunction_h * rtb_Sum_l
                    [2]) - rtb_Saturation[2] * rtb_Sum_l[1];

  /* Sum: '<S79>/Sum' incorporates:
   *  Product: '<S76>/Product'
   *  Product: '<S79>/Product'
   *  Product: '<S79>/Product1'
   *  Product: '<S79>/Product2'
   *  Product: '<S79>/Product3'
   */
  rtb_TrigonometricFunction_h = ((rtb_Product1_c * rtb_Sum_l[1] -
    rtb_Saturation[0] * rtb_Sum_l[2]) + -rtb_TrigonometricFunction_h *
    rtb_Product2_b) + rtb_Saturation[2] * rtb_Sum_l[0];

  /* Product: '<S80>/Product' */
  rtb_Product1_c *= rtb_Sum_l[2];

  /* Product: '<S80>/Product3' */
  rtb_Product2_b *= rtb_Saturation[2];

  /* Sum: '<S80>/Sum' incorporates:
   *  Product: '<S80>/Product1'
   *  Product: '<S80>/Product2'
   */
  rtb_Product1_c = ((rtb_Saturation[0] * rtb_Sum_l[1] + rtb_Product1_c) -
                    rtb_Saturation[1] * rtb_Sum_l[0]) + rtb_Product2_b;

  /* Sum: '<S82>/Sum' incorporates:
   *  Product: '<S82>/Product'
   *  Product: '<S82>/Product1'
   *  Product: '<S82>/Product2'
   *  Product: '<S82>/Product3'
   */
  rtb_Product2_b = ((rtb_Sum_a * rtb_Sum4[0] + rtb_Product1_p * rtb_Product_g) +
                    rtb_TrigonometricFunction_h * rtb_Sum4[2]) - rtb_Product1_c *
    rtb_Sum4[1];

  /* Sum: '<S83>/Sum' incorporates:
   *  Product: '<S83>/Product'
   *  Product: '<S83>/Product1'
   *  Product: '<S83>/Product2'
   *  Product: '<S83>/Product3'
   */
  rtb_Sum_b = ((rtb_Sum_a * rtb_Sum4[1] - rtb_Product1_p * rtb_Sum4[2]) +
               rtb_TrigonometricFunction_h * rtb_Product_g) + rtb_Product1_c *
    rtb_Sum4[0];

  /* Sum: '<S84>/Sum' incorporates:
   *  Product: '<S84>/Product'
   *  Product: '<S84>/Product1'
   *  Product: '<S84>/Product2'
   *  Product: '<S84>/Product3'
   */
  rtb_Sum_cy = ((rtb_Sum_a * rtb_Sum4[2] + rtb_Product1_p * rtb_Sum4[1]) -
                rtb_TrigonometricFunction_h * rtb_Sum4[0]) + rtb_Product1_c *
    rtb_Product_g;

  /* Product: '<S81>/Product1' */
  rtb_Product1_p *= rtb_Sum4[0];

  /* Product: '<S81>/Product2' */
  rtb_TrigonometricFunction_h *= rtb_Sum4[1];

  /* Product: '<S81>/Product3' */
  rtb_Product1_c *= rtb_Sum4[2];

  /* Sum: '<S81>/Sum' incorporates:
   *  Product: '<S81>/Product'
   */
  rtb_Product_g = ((rtb_Sum_a * rtb_Product_g - rtb_Product1_p) -
                   rtb_TrigonometricFunction_h) - rtb_Product1_c;

  /* Trigonometry: '<S71>/Trigonometric Function2' */
  if (rtb_Product_g > 1.0) {
    rtb_Product_g = 1.0;
  } else {
    if (rtb_Product_g < -1.0) {
      rtb_Product_g = -1.0;
    }
  }

  rtb_TrigonometricFunction_h = acos(rtb_Product_g);

  /* End of Trigonometry: '<S71>/Trigonometric Function2' */

  /* Trigonometry: '<S71>/Trigonometric Function' */
  rtb_Product_g = sin(rtb_TrigonometricFunction_h);

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant'
   */
  if (!(rtb_Product_g != 0.0)) {
    rtb_Product_g = 1.0E-6;
  }

  /* End of Switch: '<S71>/Switch' */

  /* RateTransition: '<S65>/Rate Transition' incorporates:
   *  Gain: '<S66>/rad-->deg1'
   *  Gain: '<S71>/2'
   *  Integrator: '<S70>/Integrator'
   *  Product: '<S71>/Product'
   *  RateTransition: '<S65>/Rate Transition1'
   *  RateTransition: '<S70>/Rate Transition2'
   */
  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    if (asbQuadcopter_M->Timing.RateInteraction.TID1_2 == 1) {
      asbQuadcopter_DW.RateTransition_Buffer[0] = rtb_Product2_b / rtb_Product_g;
      asbQuadcopter_DW.RateTransition_Buffer[1] = rtb_Sum_b / rtb_Product_g;
      asbQuadcopter_DW.RateTransition_Buffer[2] = rtb_Sum_cy / rtb_Product_g;
      asbQuadcopter_DW.RateTransition_Buffer[3] = 2.0 *
        rtb_TrigonometricFunction_h;
    }

    /* Assertion: '<S62>/Assertion' incorporates:
     *  Constant: '<S62>/min_val'
     *  Gain: '<S71>/2'
     *  Product: '<S71>/Product'
     *  RelationalOperator: '<S62>/min_relop'
     */
    // utAssert(71.3232 <= asbQuadcopter_DW.LinearAirframe.LLA[2]);
    if (asbQuadcopter_M->Timing.RateInteraction.TID1_2 == 1) {
      asbQuadcopter_DW.RateTransition1_Buffer[0] =
        asbQuadcopter_DW.LinearAirframe.X_ned[0];
      asbQuadcopter_DW.RateTransition1_Buffer[1] =
        -asbQuadcopter_DW.LinearAirframe.X_ned[2];
      asbQuadcopter_DW.RateTransition1_Buffer[2] =
        asbQuadcopter_DW.LinearAirframe.X_ned[1];
    }

    /* Assertion: '<S5>/Flag has been triggered' incorporates:
     *  Constant: '<S57>/Constant'
     *  Gain: '<S66>/rad-->deg1'
     *  Logic: '<S5>/Logical Operator'
     *  RelationalOperator: '<S57>/Compare'
     */
    // utAssert(flag_outport <= 0);

    /* Switch: '<S14>/FixPt Switch' incorporates:
     *  Constant: '<S13>/FixPt Constant'
     *  Sum: '<S13>/FixPt Sum1'
     */
    rtb_FixPtSwitch = asbQuadcopter_DW.Output + 1U;
    if (asbQuadcopter_M->Timing.RateInteraction.TID1_2 == 1) {
      asbQuadcopter_DW.RateTransition2_Buffer_c[0] =
        asbQuadcopter_X.Integrator_CSTATE[0];
      asbQuadcopter_DW.RateTransition2_Buffer_c[1] =
        asbQuadcopter_X.Integrator_CSTATE[1];
      asbQuadcopter_DW.RateTransition2_Buffer_c[2] =
        asbQuadcopter_X.Integrator_CSTATE[2];
      asbQuadcopter_DW.RateTransition2_Buffer_c[3] =
        asbQuadcopter_X.Integrator_CSTATE[3];
    }
  }

  /* End of RateTransition: '<S65>/Rate Transition' */
  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
      /* Update for UnitDelay: '<S11>/Output' */
      asbQuadcopter_DW.Output_DSTATE = rtb_FixPtSwitch;

      /* Update for Atomic SubSystem: '<S4>/Sensors (Dynamics)' */
      /* Update for Memory: '<S16>/Memory1' */
      asbQuadcopter_DW.Memory1_PreviousInput = asbQuadcopter_DW.LinearAirframe;

      /* Update for RandomNumber: '<S54>/White Noise' */
      // asbQuadcopter_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      //   (&asbQuadcopter_DW.RandSeed[0]);

      /* Update for RandomNumber: '<S40>/White Noise' */
      // asbQuadcopter_DW.NextOutput_k[0] = rt_nrand_Upu32_Yd_f_pw_snf
      //   (&asbQuadcopter_DW.RandSeed_l[0]);

      /* Update for RandomNumber: '<S54>/White Noise' */
      // asbQuadcopter_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      //   (&asbQuadcopter_DW.RandSeed[1]);

      /* Update for RandomNumber: '<S40>/White Noise' */
      // asbQuadcopter_DW.NextOutput_k[1] = rt_nrand_Upu32_Yd_f_pw_snf
      //   (&asbQuadcopter_DW.RandSeed_l[1]);

      /* Update for RandomNumber: '<S54>/White Noise' */
      // asbQuadcopter_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      //   (&asbQuadcopter_DW.RandSeed[2]);

      /* Update for RandomNumber: '<S40>/White Noise' */
      // asbQuadcopter_DW.NextOutput_k[2] = rt_nrand_Upu32_Yd_f_pw_snf
      //   (&asbQuadcopter_DW.RandSeed_l[2]);

      /* End of Update for SubSystem: '<S4>/Sensors (Dynamics)' */
    }

    /* Update for ModelReference: '<S1>/Linear Airframe' */
    // linearAirframe_Update();
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    rt_ertODEUpdateContinuousStates(&asbQuadcopter_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++asbQuadcopter_M->Timing.clockTick0;
    asbQuadcopter_M->Timing.t[0] = rtsiGetSolverStopTime
      (&asbQuadcopter_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    asbQuadcopter_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void asbQuadcopter_derivatives(void)
{
  XDot_asbQuadcopter_T *_rtXdot;
  _rtXdot = ((XDot_asbQuadcopter_T *) asbQuadcopter_M->derivs);

  /* Derivatives for ModelReference: '<S1>/Linear Airframe' */
  linearAirframe_Deriv(&(asbQuadcopter_DW.LinearAirframe_InstanceData.rtdw),
                       &(asbQuadcopter_X.LinearAirframe_CSTATE),
                       &(((XDot_asbQuadcopter_T *) asbQuadcopter_M->derivs)
    ->LinearAirframe_CSTATE));

  /* Derivatives for Integrator: '<S70>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = asbQuadcopter_DW.VisualizationGain[0];
  _rtXdot->Integrator_CSTATE[1] = asbQuadcopter_DW.VisualizationGain[1];
  _rtXdot->Integrator_CSTATE[2] = asbQuadcopter_DW.VisualizationGain[2];
  _rtXdot->Integrator_CSTATE[3] = asbQuadcopter_DW.VisualizationGain[3];
}

/* Model step function for TID2 */
void asbQuadcopter_step2(void)         /* Sample time: [0.06s, 0.0s] */
{
  real_T rtb_TmpSignalConversionAtVRSinkInport3[4];
  real_T rtb_TmpSignalConversionAtVRSinkInport4[4];
  real_T rtb_TmpSignalConversionAtVRSinkInport5[4];
  real_T rtb_TmpSignalConversionAtVRSinkInport6[4];
  real_T rtb_RateTransition[4];
  real_T rtb_RateTransition1[3];
  real_T rtb_RateTransition2_e[3];
  real_T rtb_RateTransition3[3];

  /* SignalConversion generated from: '<S65>/VR Sink' incorporates:
   *  Bias: '<S70>/Bias'
   *  RateTransition: '<S70>/Rate Transition2'
   */
  rtb_TmpSignalConversionAtVRSinkInport3[3] =
    asbQuadcopter_DW.RateTransition2_Buffer_c[0] + 0.1;

  /* SignalConversion generated from: '<S65>/VR Sink' incorporates:
   *  Bias: '<S70>/Bias1'
   *  RateTransition: '<S70>/Rate Transition2'
   */
  rtb_TmpSignalConversionAtVRSinkInport4[3] =
    asbQuadcopter_DW.RateTransition2_Buffer_c[1] + -0.3;

  /* SignalConversion generated from: '<S65>/VR Sink' incorporates:
   *  Bias: '<S70>/Bias2'
   *  RateTransition: '<S70>/Rate Transition2'
   */
  rtb_TmpSignalConversionAtVRSinkInport5[3] =
    asbQuadcopter_DW.RateTransition2_Buffer_c[2] + 0.5;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport3[0] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport4[0] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport5[0] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport6[0] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport3[1] = 1.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport4[1] = 1.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport5[1] = 1.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport6[1] = 1.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport3[2] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport4[2] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' */
  rtb_TmpSignalConversionAtVRSinkInport5[2] = 0.0;

  /* SignalConversion generated from: '<S65>/VR Sink' incorporates:
   *  Bias: '<S70>/Bias3'
   *  RateTransition: '<S70>/Rate Transition2'
   */
  rtb_TmpSignalConversionAtVRSinkInport6[2] = 0.0;
  rtb_TmpSignalConversionAtVRSinkInport6[3] =
    asbQuadcopter_DW.RateTransition2_Buffer_c[3] + 0.7;

  /* RateTransition: '<S65>/Rate Transition' */
  rtb_RateTransition[0] = asbQuadcopter_DW.RateTransition_Buffer[0];
  rtb_RateTransition[1] = asbQuadcopter_DW.RateTransition_Buffer[1];
  rtb_RateTransition[2] = asbQuadcopter_DW.RateTransition_Buffer[2];
  rtb_RateTransition[3] = asbQuadcopter_DW.RateTransition_Buffer[3];

  /* RateTransition: '<S65>/Rate Transition1' */
  rtb_RateTransition1[0] = asbQuadcopter_DW.RateTransition1_Buffer[0];

  /* RateTransition: '<S65>/Rate Transition2' */
  rtb_RateTransition2_e[0] = asbQuadcopter_DW.RateTransition2_Buffer[0];

  /* RateTransition: '<S65>/Rate Transition3' */
  rtb_RateTransition3[0] = asbQuadcopter_DW.RateTransition3_Buffer[0];

  /* RateTransition: '<S65>/Rate Transition1' */
  rtb_RateTransition1[1] = asbQuadcopter_DW.RateTransition1_Buffer[1];

  /* RateTransition: '<S65>/Rate Transition2' */
  rtb_RateTransition2_e[1] = asbQuadcopter_DW.RateTransition2_Buffer[1];

  /* RateTransition: '<S65>/Rate Transition3' */
  rtb_RateTransition3[1] = asbQuadcopter_DW.RateTransition3_Buffer[1];

  /* RateTransition: '<S65>/Rate Transition1' */
  rtb_RateTransition1[2] = asbQuadcopter_DW.RateTransition1_Buffer[2];

  /* RateTransition: '<S65>/Rate Transition2' */
  rtb_RateTransition2_e[2] = asbQuadcopter_DW.RateTransition2_Buffer[2];

  /* RateTransition: '<S65>/Rate Transition3' */
  rtb_RateTransition3[2] = asbQuadcopter_DW.RateTransition3_Buffer[2];
}

/* Model initialize function */
void asbQuadcopter_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&asbQuadcopter_M->solverInfo,
                          &asbQuadcopter_M->Timing.simTimeStep);
    rtsiSetTPtr(&asbQuadcopter_M->solverInfo, &rtmGetTPtr(asbQuadcopter_M));
    rtsiSetStepSizePtr(&asbQuadcopter_M->solverInfo,
                       &asbQuadcopter_M->Timing.stepSize0);
    rtsiSetdXPtr(&asbQuadcopter_M->solverInfo, &asbQuadcopter_M->derivs);
    rtsiSetContStatesPtr(&asbQuadcopter_M->solverInfo, (real_T **)
                         &asbQuadcopter_M->contStates);
    rtsiSetNumContStatesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&asbQuadcopter_M->solverInfo, (&rtmGetErrorStatus
      (asbQuadcopter_M)));
    rtsiSetRTModelPtr(&asbQuadcopter_M->solverInfo, asbQuadcopter_M);
  }

  rtsiSetSimTimeStep(&asbQuadcopter_M->solverInfo, MAJOR_TIME_STEP);
  asbQuadcopter_M->intgData.y = asbQuadcopter_M->odeY;
  asbQuadcopter_M->intgData.f[0] = asbQuadcopter_M->odeF[0];
  asbQuadcopter_M->intgData.f[1] = asbQuadcopter_M->odeF[1];
  asbQuadcopter_M->intgData.f[2] = asbQuadcopter_M->odeF[2];
  asbQuadcopter_M->contStates = ((X_asbQuadcopter_T *) &asbQuadcopter_X);
  asbQuadcopter_M->periodicContStateIndices = ((int_T*)
    asbQuadcopter_PeriodicIndX);
  asbQuadcopter_M->periodicContStateRanges = ((real_T*)
    asbQuadcopter_PeriodicRngX);
  rtsiSetSolverData(&asbQuadcopter_M->solverInfo, (void *)
                    &asbQuadcopter_M->intgData);
  rtsiSetSolverName(&asbQuadcopter_M->solverInfo,"ode3");
  rtmSetTPtr(asbQuadcopter_M, &asbQuadcopter_M->Timing.tArray[0]);
  asbQuadcopter_M->Timing.stepSize0 = 0.005;

  /* Model Initialize function for ModelReference Block: '<S1>/Linear Airframe' */
  linearAirframe_initialize(rtmGetErrorStatusPointer(asbQuadcopter_M),
    rtmGetStopRequestedPtr(asbQuadcopter_M), &(asbQuadcopter_M->solverInfo),
    &(asbQuadcopter_DW.LinearAirframe_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/FCS' */
  // flightControlSystem_initialize(rtmGetErrorStatusPointer(asbQuadcopter_M));

  /* Start for FromWorkspace: '<S12>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 100.0 } ;

    static real32_T pDataValues0[] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

    asbQuadcopter_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    asbQuadcopter_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    asbQuadcopter_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S12>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 100.0 } ;

    static real32_T pDataValues0[] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, -1.5F, -1.5F } ;

    asbQuadcopter_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    asbQuadcopter_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    asbQuadcopter_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Integrator: '<S70>/Integrator' */
  asbQuadcopter_X.Integrator_CSTATE[0] = 0.1;
  asbQuadcopter_X.Integrator_CSTATE[1] = 0.2;
  asbQuadcopter_X.Integrator_CSTATE[2] = -0.3;
  asbQuadcopter_X.Integrator_CSTATE[3] = -0.4;

  /* SystemInitialize for ModelReference: '<S1>/Linear Airframe' */
  linearAirframe_Init(&(asbQuadcopter_X.LinearAirframe_CSTATE));

  /* SystemInitialize for ModelReference: '<Root>/FCS' */
  // flightControlSystem_Init();

  /* SystemInitialize for Atomic SubSystem: '<S4>/Sensors (Dynamics)' */
  /* InitializeConditions for Memory: '<S16>/Memory1' */
  asbQuadcopter_DW.Memory1_PreviousInput =
    asbQuadcopter_ConstP.Memory1_InitialCondition;

  /* InitializeConditions for RandomNumber: '<S54>/White Noise' */
  asbQuadcopter_DW.RandSeed[0] = 2686976U;
  // asbQuadcopter_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
  //   (&asbQuadcopter_DW.RandSeed[0]);
  // asbQuadcopter_DW.RandSeed[1] = 2686976U;
  // asbQuadcopter_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
  //   (&asbQuadcopter_DW.RandSeed[1]);
  // asbQuadcopter_DW.RandSeed[2] = 2686976U;
  // asbQuadcopter_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
  //   (&asbQuadcopter_DW.RandSeed[2]);

  /* InitializeConditions for RandomNumber: '<S40>/White Noise' */
  asbQuadcopter_DW.RandSeed_l[0] = 2686976U;
  // asbQuadcopter_DW.NextOutput_k[0] = rt_nrand_Upu32_Yd_f_pw_snf
  //   (&asbQuadcopter_DW.RandSeed_l[0]);
  // asbQuadcopter_DW.RandSeed_l[1] = 2686976U;
  // asbQuadcopter_DW.NextOutput_k[1] = rt_nrand_Upu32_Yd_f_pw_snf
  //   (&asbQuadcopter_DW.RandSeed_l[1]);
  // asbQuadcopter_DW.RandSeed_l[2] = 2686976U;
  // asbQuadcopter_DW.NextOutput_k[2] = rt_nrand_Upu32_Yd_f_pw_snf
  //   (&asbQuadcopter_DW.RandSeed_l[2]);

  /* End of SystemInitialize for SubSystem: '<S4>/Sensors (Dynamics)' */

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[4] = { 12, 13, 14, 15 };

    real_T rootPeriodicContStateRanges[8] = { -6.2831853071795862,
      6.2831853071795862, -6.2831853071795862, 6.2831853071795862,
      -6.2831853071795862, 6.2831853071795862, -6.2831853071795862,
      6.2831853071795862 };

    (void) memcpy((void*)asbQuadcopter_PeriodicIndX,
                  rootPeriodicContStateIndices,
                  4*sizeof(int_T));
    (void) memcpy((void*)asbQuadcopter_PeriodicRngX, rootPeriodicContStateRanges,
                  8*sizeof(real_T));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
