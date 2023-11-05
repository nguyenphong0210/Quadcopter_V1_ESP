/*
 * File: Signal.c
 *
 * Code generated for Simulink model 'Signal'.
 *
 * Model version                  : 1.289
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Oct 22 13:39:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Signals.h"

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

/* Used by FromWorkspace Block: '<S6>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Exported block signals */
CommandBus cmd_inport;                 /* '<S1>/Bus Creator' */

/* Block signals and states (default storage) */
DW_Signal_T Signal_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Signal_T Signal_Y;

/* Real-time model */
RT_MODEL_Signal_T Signal_M_;
RT_MODEL_Signal_T *const Signal_M = &Signal_M_;

/* Model step function */
void Signal_step(void)
{
  /* local block i/o variables */
  real32_T rtb_YawPitchRoll[3];
  uint32_T rtb_FixPtSwitch;

  /* FromWorkspace: '<S6>/From Workspace' */
  {
    real_T t = Signal_M->Timing.t[0];
    real_T *pTimeValues = (real_T *) Signal_DW.FromWorkspace_PWORK.TimePtr;
    real32_T *pDataValues = (real32_T *) Signal_DW.FromWorkspace_PWORK.DataPtr;
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
      int_T currTimeIndex = Signal_DW.FromWorkspace_IWORK.PrevIndex;
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

      Signal_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* FromWorkspace: '<S6>/fromWS_Signal 1' */
  {
    real_T t = ((Signal_M->Timing.clockTick1) * 0.005);
    real_T *pTimeValues = (real_T *) Signal_DW.fromWS_Signal1_PWORK.TimePtr;
    real32_T *pDataValues = (real32_T *) Signal_DW.fromWS_Signal1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&Signal_DW.XYZ[0])[elIdx] = 0.0F;
        }
      }
    } else if (t >= pTimeValues[3]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&Signal_DW.XYZ[0])[elIdx] = pDataValues[3];
          pDataValues += 4;
        }
      }
    } else {
      int_T currTimeIndex = Signal_DW.fromWS_Signal1_IWORK.PrevIndex;
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
          (&Signal_DW.XYZ[0])[elIdx] = pDataValues[currTimeIndex];
          pDataValues += 4;
        }
      }

      Signal_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   */
  cmd_inport.controlModePosVSOrient = ((rtb_YawPitchRoll[2] == 0.0F) &&
    (rtb_YawPitchRoll[1] == 0.0F));

  /* RateTransition: '<S1>/Rate Transition3' incorporates:
   *  Clock: '<S1>/Clock'
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  cmd_inport.takeoff_flag = (Signal_M->Timing.t[0] < 1.0);

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  UnitDelay: '<S5>/Output'
   */
  cmd_inport.pos_ref[0] = Signal_DW.XYZ[0];
  cmd_inport.orient_ref[0] = rtb_YawPitchRoll[0];
  cmd_inport.pos_ref[1] = Signal_DW.XYZ[1];
  cmd_inport.orient_ref[1] = rtb_YawPitchRoll[1];
  cmd_inport.pos_ref[2] = Signal_DW.XYZ[2];
  cmd_inport.orient_ref[2] = rtb_YawPitchRoll[2];
  cmd_inport.live_time_ticks = Signal_DW.Output_DSTATE;

  /* Outport: '<Root>/AC Cmd' */
  Signal_Y.ACCmd = cmd_inport;

  /* Switch: '<S8>/FixPt Switch' incorporates:
   *  Constant: '<S7>/FixPt Constant'
   *  Sum: '<S7>/FixPt Sum1'
   *  UnitDelay: '<S5>/Output'
   */
  rtb_FixPtSwitch = Signal_DW.Output_DSTATE + 1U;

  /* Update for UnitDelay: '<S5>/Output' */
  Signal_DW.Output_DSTATE = rtb_FixPtSwitch;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Signal_M->Timing.t[0] =
    (++Signal_M->Timing.clockTick0) * Signal_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Signal_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Signal_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Signal_M->solverInfo, &Signal_M->Timing.simTimeStep);
    rtsiSetTPtr(&Signal_M->solverInfo, &rtmGetTPtr(Signal_M));
    rtsiSetStepSizePtr(&Signal_M->solverInfo, &Signal_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Signal_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(Signal_M))));
    rtsiSetRTModelPtr(&Signal_M->solverInfo, Signal_M);
  }

  rtsiSetSimTimeStep(&Signal_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Signal_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Signal_M, &Signal_M->Timing.tArray[0]);
  Signal_M->Timing.stepSize0 = 0.005;

  /* Start for FromWorkspace: '<S6>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 100.0 } ;

    static real32_T pDataValues0[] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

    Signal_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    Signal_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    Signal_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S6>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 100.0 } ;

    static real32_T pDataValues0[] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, -0.1F, -0.1F } ;

    Signal_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    Signal_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    Signal_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
