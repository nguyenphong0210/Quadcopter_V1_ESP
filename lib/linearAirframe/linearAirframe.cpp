/*
 * File: linearAirframe.c
 *
 * Code generated for Simulink model 'linearAirframe'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov  5 22:35:47 2023
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
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* private model entry point functions */
extern void linearAirframe_derivatives(void);

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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  linearAirframe_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  linearAirframe_step();
  linearAirframe_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  linearAirframe_step();
  linearAirframe_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void linearAirframe_step(void)
{
  int_T ci;
  real_T rtb_DCM_beTrim[9];
  real_T rtb_LinearModel[33];
  int32_T i;
  static const int8_T ir_0[34] = { 0, 7, 15, 17, 18, 21, 24, 26, 27, 30, 31, 33,
    35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 53, 59, 64, 65, 66, 67,
    73, 79, 85 };

  static const int8_T ir_1[34] = { 0, 8, 16, 22, 22, 22, 22, 22, 22, 22, 22, 22,
    22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
    26, 30, 35 };

  static const int8_T jc_0[85] = { 1, 3, 4, 5, 9, 10, 11, 0, 1, 3, 4, 5, 9, 10,
    11, 0, 1, 1, 0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 6,
    7, 8, 9, 10, 11, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 3, 4, 5,
    6, 7, 8, 3, 4, 5, 9, 10, 11, 3, 4, 5, 9, 10, 11, 3, 4, 5, 9, 10, 11 };

  static const int8_T jc_1[35] = { 0, 1, 2, 3, 4, 8, 9, 10, 0, 1, 2, 3, 4, 8, 9,
    10, 0, 1, 2, 3, 4, 10, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 4 };

  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  /* Outputs for Atomic SubSystem: '<Root>/Linear' */
  /* SignalConversion generated from: '<S1>/Linear Model' incorporates:
   *  Bias: '<S1>/Actuator Trim'
   *  Bias: '<S1>/Air Temp Trim'
   *  Bias: '<S1>/Density Trim'
   *  Bias: '<S1>/Gravity NED Trim'
   *  Bias: '<S1>/Pressure Trim'
   *  Bias: '<S1>/Speed of Sound Trim'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Inport: '<Root>/Actuators'
   *  Inport: '<Root>/Environment'
   */
  rtDW.TmpSignalConversionAtLinearMode[0] = rtU.Actuators[0] +
    -255.27934378890362;
  rtDW.TmpSignalConversionAtLinearMode[1] = rtU.Actuators[1] +
    255.27934378890583;
  rtDW.TmpSignalConversionAtLinearMode[2] = rtU.Actuators[2] +
    -255.27934378890805;
  rtDW.TmpSignalConversionAtLinearMode[3] = rtU.Actuators[3] +
    255.27934378890583;
  rtDW.TmpSignalConversionAtLinearMode[4] =
    rtU.Environment.AtmosphereBus.air_temp + -288.0;
  rtDW.TmpSignalConversionAtLinearMode[5] =
    rtU.Environment.AtmosphereBus.speed_sound + -340.0;
  rtDW.TmpSignalConversionAtLinearMode[6] =
    rtU.Environment.AtmosphereBus.pressure + -101300.0;
  rtDW.TmpSignalConversionAtLinearMode[7] =
    rtU.Environment.AtmosphereBus.air_density + -1.184;
  rtDW.TmpSignalConversionAtLinearMode[8] = rtU.Environment.Gravity_ned[0];
  rtDW.TmpSignalConversionAtLinearMode[11] = rtU.Environment.MagneticField_ned[0];
  rtDW.TmpSignalConversionAtLinearMode[9] = rtU.Environment.Gravity_ned[1];
  rtDW.TmpSignalConversionAtLinearMode[12] = rtU.Environment.MagneticField_ned[1];
  rtDW.TmpSignalConversionAtLinearMode[10] = rtU.Environment.Gravity_ned[2] +
    -9.81;
  rtDW.TmpSignalConversionAtLinearMode[13] = rtU.Environment.MagneticField_ned[2];

  /* StateSpace: '<S1>/Linear Model' */
  for (i = 0; i < 33; i++) {
    rtb_LinearModel[i] = 0.0;
    for (ci = ir_0[i]; ci < ir_0[i + 1]; ci++) {
      rtb_LinearModel[i] += rtConstP.LinearModel_C[ci] *
        rtX.LinearModel_CSTATE[jc_0[ci]];
    }
  }

  for (i = 0; i < 33; i++) {
    for (ci = ir_1[i]; ci < ir_1[i + 1]; ci++) {
      rtb_LinearModel[i] += rtConstP.LinearModel_D[ci] *
        rtDW.TmpSignalConversionAtLinearMode[jc_1[ci]];
    }
  }

  /* End of StateSpace: '<S1>/Linear Model' */

  /* Bias: '<S1>/DCM_be Trim' */
  for (i = 0; i < 9; i++) {
    rtb_DCM_beTrim[i] = rtb_LinearModel[i + 3] + rtConstP.DCM_beTrim_Bias[i];
  }

  /* End of Bias: '<S1>/DCM_be Trim' */

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[0] = rtb_DCM_beTrim[0];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[3] = rtb_DCM_beTrim[3];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[6] = rtb_DCM_beTrim[6];

  /* Outport: '<Root>/States' incorporates:
   *  Bias: '<S1>/Accel_b Trim'
   *  Bias: '<S1>/Euler Trim'
   *  Bias: '<S1>/LLA Trim'
   *  Bias: '<S1>/Omega Trim'
   *  Bias: '<S1>/V_ned Trim'
   *  Bias: '<S1>/Vb Trim'
   *  Bias: '<S1>/X_ned Trim'
   *  Bias: '<S1>/dOmega_b Trim'
   */
  rtY.States.V_body[0] = rtb_LinearModel[21] + 3.5087306067171784E-13;
  rtY.States.Omega_body[0] = rtb_LinearModel[18] + -6.8346634702081575E-13;
  rtY.States.Euler[0] = rtb_LinearModel[12] + -5.2294605937771943E-12;
  rtY.States.Accel_body[0] = rtb_LinearModel[0] + 5.1184781305897922E-11;
  rtY.States.dOmega_body[0] = rtb_LinearModel[30] + 1.6268279495833624E-29;
  rtY.States.V_ned[0] = rtb_LinearModel[24] + 3.5087306067171784E-13;
  rtY.States.X_ned[0] = rtb_LinearModel[27] + 57.0;
  rtY.States.LLA[0] = rtb_LinearModel[15] + 42.300399147790976;

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[1] = rtb_DCM_beTrim[1];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[4] = rtb_DCM_beTrim[4];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[7] = rtb_DCM_beTrim[7];

  /* Outport: '<Root>/States' incorporates:
   *  Bias: '<S1>/Accel_b Trim'
   *  Bias: '<S1>/Euler Trim'
   *  Bias: '<S1>/LLA Trim'
   *  Bias: '<S1>/Omega Trim'
   *  Bias: '<S1>/V_ned Trim'
   *  Bias: '<S1>/Vb Trim'
   *  Bias: '<S1>/X_ned Trim'
   *  Bias: '<S1>/dOmega_b Trim'
   */
  rtY.States.V_body[1] = rtb_LinearModel[22] + -3.2919802336754485E-13;
  rtY.States.Omega_body[1] = rtb_LinearModel[19] + -6.8347177408767424E-13;
  rtY.States.Euler[1] = rtb_LinearModel[13] + -5.2296012979151076E-12;
  rtY.States.Accel_body[1] = rtb_LinearModel[1] + -5.1184797737517628E-11;
  rtY.States.dOmega_body[1] = rtb_LinearModel[31] + 4.7139224890674086E-14;
  rtY.States.V_ned[1] = rtb_LinearModel[25] + -3.2919802336754485E-13;
  rtY.States.X_ned[1] = rtb_LinearModel[28] + 95.0;
  rtY.States.LLA[1] = rtb_LinearModel[16] + -71.349294934908414;

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[2] = rtb_DCM_beTrim[2];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[5] = rtb_DCM_beTrim[5];

  /* SignalConversion generated from: '<S2>/Vector Concatenate' incorporates:
   *  Outport: '<Root>/States'
   */
  rtY.States.DCM_be[8] = rtb_DCM_beTrim[8];

  /* Outport: '<Root>/States' incorporates:
   *  Bias: '<S1>/Accel_b Trim'
   *  Bias: '<S1>/Euler Trim'
   *  Bias: '<S1>/LLA Trim'
   *  Bias: '<S1>/Omega Trim'
   *  Bias: '<S1>/V_ned Trim'
   *  Bias: '<S1>/Vb Trim'
   *  Bias: '<S1>/X_ned Trim'
   *  Bias: '<S1>/dOmega_b Trim'
   */
  rtY.States.V_body[2] = rtb_LinearModel[23] + 1.3477834347136587E-19;
  rtY.States.Omega_body[2] = rtb_LinearModel[20] + 3.6610890988247328E-17;
  rtY.States.Euler[2] = rtb_LinearModel[14] + 1.496916591715698E-18;
  rtY.States.Accel_body[2] = rtb_LinearModel[2] + -1.0237061851809164E-6;
  rtY.States.dOmega_body[2] = rtb_LinearModel[32] + -7.9370583645301078E-16;
  rtY.States.V_ned[2] = rtb_LinearModel[26] + 1.3478189992567012E-19;
  rtY.States.X_ned[2] = rtb_LinearModel[29] + -0.046;
  rtY.States.LLA[2] = rtb_LinearModel[17] + 71.3692;

  /* End of Outputs for SubSystem: '<Root>/Linear' */
  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void linearAirframe_derivatives(void)
{
  int_T is;
  int_T ci;
  static const int8_T ir_2[13] = { 0, 4, 7, 11, 18, 26, 32, 38, 44, 49, 55, 61,
    67 };

  static const int8_T ir_3[13] = { 0, 0, 0, 0, 8, 16, 22, 22, 22, 22, 27, 32, 37
  };

  static const int8_T jc_2[67] = { 1, 9, 10, 11, 0, 10, 11, 0, 1, 10, 11, 1, 3,
    4, 5, 9, 10, 11, 0, 1, 3, 4, 5, 9, 10, 11, 0, 1, 3, 4, 9, 10, 0, 1, 2, 3, 4,
    5, 0, 1, 2, 3, 4, 5, 0, 1, 3, 4, 5, 3, 4, 5, 9, 10, 11, 3, 4, 5, 9, 10, 11,
    3, 4, 5, 9, 10, 11 };

  static const int8_T jc_3[37] = { 0, 1, 2, 3, 4, 8, 9, 10, 0, 1, 2, 3, 4, 8, 9,
    10, 0, 1, 2, 3, 4, 10, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };

  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/Linear' */
  /* Derivatives for StateSpace: '<S1>/Linear Model' */
  for (is = 0; is < 12; is++) {
    _rtXdot->LinearModel_CSTATE[is] = 0.0;
    for (ci = ir_2[is]; ci < ir_2[is + 1]; ci++) {
      _rtXdot->LinearModel_CSTATE[is] += rtConstP.LinearModel_A[ci] *
        rtX.LinearModel_CSTATE[jc_2[ci]];
    }
  }

  for (is = 0; is < 12; is++) {
    for (ci = ir_3[is]; ci < ir_3[is + 1]; ci++) {
      _rtXdot->LinearModel_CSTATE[is] += rtConstP.LinearModel_B[ci] *
        rtDW.TmpSignalConversionAtLinearMode[jc_3[ci]];
    }
  }

  /* End of Derivatives for StateSpace: '<S1>/Linear Model' */
  /* End of Derivatives for SubSystem: '<Root>/Linear' */
}

/* Model initialize function */
void linearAirframe_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.005;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Linear' */
  /* InitializeConditions for StateSpace: '<S1>/Linear Model' */
  memset(&rtX.LinearModel_CSTATE[0], 0, 12U * sizeof(real_T));

  /* End of SystemInitialize for SubSystem: '<Root>/Linear' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
