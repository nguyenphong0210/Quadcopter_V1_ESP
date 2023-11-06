/*
 * File: linearAirframe.c
 *
 * Code generated for Simulink model 'linearAirframe'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Nov  6 00:19:43 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "linearAirframe.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        (*((rtm)->Timing.simTimeStep))
#endif

#ifndef rtmGetSimTimeStepPointer
# define rtmGetSimTimeStepPointer(rtm) (rtm)->Timing.simTimeStep
#endif

#ifndef rtmSetSimTimeStepPointer
# define rtmSetSimTimeStepPointer(rtm, val) ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      (*((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) (*((rtm)->Timing.stopRequestedFlag) = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedPtr
# define rtmSetStopRequestedPtr(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

extern const real_T rtCP_pooled_sCLbtgmndWSw[67];
extern const real_T rtCP_pooled_1DG9mhjllGPJ[37];
extern const real_T rtCP_pooled_MPhBaapyGEbr[85];
extern const real_T rtCP_pooled_tFQ5582VhrTZ[35];
extern const real_T rtCP_pooled_8iBNt9Di3rjJ[9];

#define rtCP_LinearModel_A             rtCP_pooled_sCLbtgmndWSw  /* Computed Parameter: rtCP_LinearModel_A
                                                                  * Referenced by: '<S1>/Linear Model'
                                                                  */
#define rtCP_LinearModel_B             rtCP_pooled_1DG9mhjllGPJ  /* Computed Parameter: rtCP_LinearModel_B
                                                                  * Referenced by: '<S1>/Linear Model'
                                                                  */
#define rtCP_LinearModel_C             rtCP_pooled_MPhBaapyGEbr  /* Computed Parameter: rtCP_LinearModel_C
                                                                  * Referenced by: '<S1>/Linear Model'
                                                                  */
#define rtCP_LinearModel_D             rtCP_pooled_tFQ5582VhrTZ  /* Computed Parameter: rtCP_LinearModel_D
                                                                  * Referenced by: '<S1>/Linear Model'
                                                                  */
#define rtCP_DCM_beTrim_Bias           rtCP_pooled_8iBNt9Di3rjJ  /* Expression: opreport.Outputs(9).y
                                                                  * Referenced by: '<S1>/DCM_be Trim'
                                                                  */

/* System initialize for referenced model: 'linearAirframe' */
void linearAirframe_Init(X_linearAirframe_n_T *localX)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Linear' */
  /* InitializeConditions for StateSpace: '<S1>/Linear Model' */
  memset(&localX->LinearModel_CSTATE[0], 0, 12U * sizeof(real_T));

  /* End of SystemInitialize for SubSystem: '<Root>/Linear' */
}

/* Outputs for referenced model: 'linearAirframe' */
void linearAirframe(const real32_T rtu_Actuators[4], const EnvironmentBus
                    *rtu_Environment, StatesBus *rty_States,
                    DW_linearAirframe_f_T *localDW, X_linearAirframe_n_T *localX)
{
  /* local block i/o variables */
  real_T rtb_AirTempTrim;
  real_T rtb_SpeedofSoundTrim;
  real_T rtb_PressureTrim;
  real_T rtb_DensityTrim;
  real_T rtb_ActuatorTrim[4];
  real_T rtb_Accel_bTrim[3];
  int_T ci;
  real_T rtb_DCM_be[9];
  real_T rtb_DCM_beTrim[9];
  real_T rtb_LinearModel[33];
  int32_T i;
  static const int8_T ir[34] = { 0, 7, 15, 17, 18, 21, 24, 26, 27, 30, 31, 33,
    35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 53, 59, 64, 65, 66, 67,
    73, 79, 85 };

  static const int8_T ir_0[34] = { 0, 8, 16, 22, 22, 22, 22, 22, 22, 22, 22, 22,
    22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
    26, 30, 35 };

  static const int8_T jc[85] = { 1, 3, 4, 5, 9, 10, 11, 0, 1, 3, 4, 5, 9, 10, 11,
    0, 1, 1, 0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 6, 7, 8,
    9, 10, 11, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 3, 4, 5, 6, 7,
    8, 3, 4, 5, 9, 10, 11, 3, 4, 5, 9, 10, 11, 3, 4, 5, 9, 10, 11 };

  static const int8_T jc_0[35] = { 0, 1, 2, 3, 4, 8, 9, 10, 0, 1, 2, 3, 4, 8, 9,
    10, 0, 1, 2, 3, 4, 10, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 4 };

  /* Outputs for Atomic SubSystem: '<Root>/Linear' */
  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_ActuatorTrim[0] = rtu_Actuators[0];

  /* Bias: '<S1>/Actuator Trim' */
  rtb_ActuatorTrim[0] += -255.27934378890362;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_ActuatorTrim[1] = rtu_Actuators[1];

  /* Bias: '<S1>/Actuator Trim' */
  rtb_ActuatorTrim[1] += 255.27934378890583;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_ActuatorTrim[2] = rtu_Actuators[2];

  /* Bias: '<S1>/Actuator Trim' */
  rtb_ActuatorTrim[2] += -255.27934378890805;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_ActuatorTrim[3] = rtu_Actuators[3];

  /* Bias: '<S1>/Actuator Trim' */
  rtb_ActuatorTrim[3] += 255.27934378890583;

  /* Bias: '<S1>/Air Temp Trim' */
  rtb_AirTempTrim = rtu_Environment->AtmosphereBus.air_temp + -288.0;

  /* Bias: '<S1>/Speed of Sound Trim' */
  rtb_SpeedofSoundTrim = rtu_Environment->AtmosphereBus.speed_sound + -340.0;

  /* Bias: '<S1>/Pressure Trim' */
  rtb_PressureTrim = rtu_Environment->AtmosphereBus.pressure + -101300.0;

  /* Bias: '<S1>/Density Trim' */
  rtb_DensityTrim = rtu_Environment->AtmosphereBus.air_density + -1.184;

  /* Bias: '<S1>/Gravity NED Trim' */
  rtb_Accel_bTrim[0] = rtu_Environment->Gravity_ned[0];
  rtb_Accel_bTrim[1] = rtu_Environment->Gravity_ned[1];
  rtb_Accel_bTrim[2] = rtu_Environment->Gravity_ned[2] + -9.81;

  /* SignalConversion generated from: '<S1>/Linear Model' */
  localDW->TmpSignalConversionAtLinearMode[0] = rtb_ActuatorTrim[0];
  localDW->TmpSignalConversionAtLinearMode[1] = rtb_ActuatorTrim[1];
  localDW->TmpSignalConversionAtLinearMode[2] = rtb_ActuatorTrim[2];
  localDW->TmpSignalConversionAtLinearMode[3] = rtb_ActuatorTrim[3];
  localDW->TmpSignalConversionAtLinearMode[4] = rtb_AirTempTrim;
  localDW->TmpSignalConversionAtLinearMode[5] = rtb_SpeedofSoundTrim;
  localDW->TmpSignalConversionAtLinearMode[6] = rtb_PressureTrim;
  localDW->TmpSignalConversionAtLinearMode[7] = rtb_DensityTrim;
  localDW->TmpSignalConversionAtLinearMode[8] = rtb_Accel_bTrim[0];
  localDW->TmpSignalConversionAtLinearMode[11] =
    rtu_Environment->MagneticField_ned[0];
  localDW->TmpSignalConversionAtLinearMode[9] = rtb_Accel_bTrim[1];
  localDW->TmpSignalConversionAtLinearMode[12] =
    rtu_Environment->MagneticField_ned[1];
  localDW->TmpSignalConversionAtLinearMode[10] = rtb_Accel_bTrim[2];
  localDW->TmpSignalConversionAtLinearMode[13] =
    rtu_Environment->MagneticField_ned[2];

  /* StateSpace: '<S1>/Linear Model' */
  for (i = 0; i < 33; i++) {
    rtb_LinearModel[i] = 0.0;
    for (ci = ir[i]; ci < ir[i + 1]; ci++) {
      rtb_LinearModel[i] += rtCP_LinearModel_C[ci] * localX->
        LinearModel_CSTATE[jc[ci]];
    }
  }

  for (i = 0; i < 33; i++) {
    for (ci = ir_0[i]; ci < ir_0[i + 1]; ci++) {
      rtb_LinearModel[i] += rtCP_LinearModel_D[ci] *
        localDW->TmpSignalConversionAtLinearMode[jc_0[ci]];
    }
  }

  /* End of StateSpace: '<S1>/Linear Model' */

  /* Bias: '<S1>/DCM_be Trim' */
  for (i = 0; i < 9; i++) {
    rtb_DCM_beTrim[i] = rtb_LinearModel[i + 3] + rtCP_DCM_beTrim_Bias[i];
  }

  /* End of Bias: '<S1>/DCM_be Trim' */

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[0] = rtb_DCM_beTrim[0];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[3] = rtb_DCM_beTrim[3];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[6] = rtb_DCM_beTrim[6];

  /* Bias: '<S1>/Accel_b Trim' */
  rtb_Accel_bTrim[0] = rtb_LinearModel[0] + 5.1184781305897922E-11;

  /* Bias: '<S1>/Vb Trim' */
  rty_States->V_body[0] = rtb_LinearModel[21] + 3.5087306067171784E-13;

  /* Bias: '<S1>/Omega Trim' */
  rty_States->Omega_body[0] = rtb_LinearModel[18] + -6.8346634702081575E-13;

  /* Bias: '<S1>/Euler Trim' */
  rty_States->Euler[0] = rtb_LinearModel[12] + -5.2294605937771943E-12;

  /* Bias: '<S1>/dOmega_b Trim' */
  rty_States->dOmega_body[0] = rtb_LinearModel[30] + 1.6268279495833624E-29;

  /* Bias: '<S1>/V_ned Trim' */
  rty_States->V_ned[0] = rtb_LinearModel[24] + 3.5087306067171784E-13;

  /* Bias: '<S1>/X_ned Trim' */
  rty_States->X_ned[0] = rtb_LinearModel[27] + 57.0;

  /* Bias: '<S1>/LLA Trim' */
  rty_States->LLA[0] = rtb_LinearModel[15] + 42.300399147790976;

  /* BusCreator: '<S2>/Bus Creator5' */
  rty_States->Accel_body[0] = rtb_Accel_bTrim[0];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[1] = rtb_DCM_beTrim[1];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[4] = rtb_DCM_beTrim[4];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[7] = rtb_DCM_beTrim[7];

  /* Bias: '<S1>/Accel_b Trim' */
  rtb_Accel_bTrim[1] = rtb_LinearModel[1] + -5.1184797737517628E-11;

  /* Bias: '<S1>/Vb Trim' */
  rty_States->V_body[1] = rtb_LinearModel[22] + -3.2919802336754485E-13;

  /* Bias: '<S1>/Omega Trim' */
  rty_States->Omega_body[1] = rtb_LinearModel[19] + -6.8347177408767424E-13;

  /* Bias: '<S1>/Euler Trim' */
  rty_States->Euler[1] = rtb_LinearModel[13] + -5.2296012979151076E-12;

  /* Bias: '<S1>/dOmega_b Trim' */
  rty_States->dOmega_body[1] = rtb_LinearModel[31] + 4.7139224890674086E-14;

  /* Bias: '<S1>/V_ned Trim' */
  rty_States->V_ned[1] = rtb_LinearModel[25] + -3.2919802336754485E-13;

  /* Bias: '<S1>/X_ned Trim' */
  rty_States->X_ned[1] = rtb_LinearModel[28] + 95.0;

  /* Bias: '<S1>/LLA Trim' */
  rty_States->LLA[1] = rtb_LinearModel[16] + -71.349294934908414;

  /* BusCreator: '<S2>/Bus Creator5' */
  rty_States->Accel_body[1] = rtb_Accel_bTrim[1];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[2] = rtb_DCM_beTrim[2];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[5] = rtb_DCM_beTrim[5];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' */
  rtb_DCM_be[8] = rtb_DCM_beTrim[8];

  /* Bias: '<S1>/Accel_b Trim' */
  rtb_Accel_bTrim[2] = rtb_LinearModel[2] + -1.0237061851809164E-6;

  /* Bias: '<S1>/Vb Trim' */
  rty_States->V_body[2] = rtb_LinearModel[23] + 1.3477834347136587E-19;

  /* Bias: '<S1>/Omega Trim' */
  rty_States->Omega_body[2] = rtb_LinearModel[20] + 3.6610890988247328E-17;

  /* Bias: '<S1>/Euler Trim' */
  rty_States->Euler[2] = rtb_LinearModel[14] + 1.496916591715698E-18;

  /* Bias: '<S1>/dOmega_b Trim' */
  rty_States->dOmega_body[2] = rtb_LinearModel[32] + -7.9370583645301078E-16;

  /* Bias: '<S1>/V_ned Trim' */
  rty_States->V_ned[2] = rtb_LinearModel[26] + 1.3478189992567012E-19;

  /* Bias: '<S1>/X_ned Trim' */
  rty_States->X_ned[2] = rtb_LinearModel[29] + -0.046;

  /* Bias: '<S1>/LLA Trim' */
  rty_States->LLA[2] = rtb_LinearModel[17] + 71.3692;

  /* BusCreator: '<S2>/Bus Creator5' */
  rty_States->Accel_body[2] = rtb_Accel_bTrim[2];
  memcpy(&rty_States->DCM_be[0], &rtb_DCM_be[0], 9U * sizeof(real_T));

  /* End of Outputs for SubSystem: '<Root>/Linear' */
}

/* Update for referenced model: 'linearAirframe' */
void linearAirframe_Update(void)
{
}

/* Derivatives for referenced model: 'linearAirframe' */
void linearAirframe_Deriv(DW_linearAirframe_f_T *localDW, X_linearAirframe_n_T
  *localX, XDot_linearAirframe_n_T *localXdot)
{
  int_T is;
  int_T ci;
  static const int8_T ir[13] = { 0, 4, 7, 11, 18, 26, 32, 38, 44, 49, 55, 61, 67
  };

  static const int8_T ir_0[13] = { 0, 0, 0, 0, 8, 16, 22, 22, 22, 22, 27, 32, 37
  };

  static const int8_T jc[67] = { 1, 9, 10, 11, 0, 10, 11, 0, 1, 10, 11, 1, 3, 4,
    5, 9, 10, 11, 0, 1, 3, 4, 5, 9, 10, 11, 0, 1, 3, 4, 9, 10, 0, 1, 2, 3, 4, 5,
    0, 1, 2, 3, 4, 5, 0, 1, 3, 4, 5, 3, 4, 5, 9, 10, 11, 3, 4, 5, 9, 10, 11, 3,
    4, 5, 9, 10, 11 };

  static const int8_T jc_0[37] = { 0, 1, 2, 3, 4, 8, 9, 10, 0, 1, 2, 3, 4, 8, 9,
    10, 0, 1, 2, 3, 4, 10, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };

  /* Derivatives for Atomic SubSystem: '<Root>/Linear' */
  /* Derivatives for StateSpace: '<S1>/Linear Model' */
  for (is = 0; is < 12; is++) {
    localXdot->LinearModel_CSTATE[is] = 0.0;
    for (ci = ir[is]; ci < ir[is + 1]; ci++) {
      localXdot->LinearModel_CSTATE[is] += rtCP_LinearModel_A[ci] *
        localX->LinearModel_CSTATE[jc[ci]];
    }
  }

  for (is = 0; is < 12; is++) {
    for (ci = ir_0[is]; ci < ir_0[is + 1]; ci++) {
      localXdot->LinearModel_CSTATE[is] += rtCP_LinearModel_B[ci] *
        localDW->TmpSignalConversionAtLinearMode[jc_0[ci]];
    }
  }

  /* End of Derivatives for StateSpace: '<S1>/Linear Model' */
  /* End of Derivatives for SubSystem: '<Root>/Linear' */
}

/* Model initialize function */
void linearAirframe_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_linearAirframe_T *
  const linearAirframe_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(linearAirframe_M, rt_errorStatus);

  /* initialize stop requested flag */
  rtmSetStopRequestedPtr(linearAirframe_M, rt_stopRequested);

  /* initialize RTWSolverInfo */
  linearAirframe_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(linearAirframe_M, rtsiGetSimTimeStepPtr
    (linearAirframe_M->solverInfo));
  linearAirframe_M->Timing.stepSize0 = (rtsiGetStepSize
    (linearAirframe_M->solverInfo));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
