/*
 * File: linearAirframe.h
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

#ifndef RTW_HEADER_linearAirframe_h_
#define RTW_HEADER_linearAirframe_h_
#include "rtwtypes.h"
#include <string.h>
#ifndef linearAirframe_COMMON_INCLUDES_
# define linearAirframe_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* linearAirframe_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_AtmosphereBus_
#define DEFINED_TYPEDEF_FOR_AtmosphereBus_

typedef struct {
  real_T air_temp;
  real_T speed_sound;
  real_T pressure;
  real_T air_density;
} _AtmosphereBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnvironmentBus_
#define DEFINED_TYPEDEF_FOR_EnvironmentBus_

typedef struct {
  real_T Gravity_ned[3];
  _AtmosphereBus AtmosphereBus;
  real_T MagneticField_ned[3];
} EnvironmentBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_StatesBus_
#define DEFINED_TYPEDEF_FOR_StatesBus_

typedef struct {
  real_T V_body[3];
  real_T Omega_body[3];
  real_T Euler[3];
  real_T Accel_body[3];
  real_T dOmega_body[3];
  real_T V_ned[3];
  real_T X_ned[3];

  /* Latitude, Longitude, Altitude */
  real_T LLA[3];
  real_T DCM_be[9];
} StatesBus;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T TmpSignalConversionAtLinearMode[14];
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T LinearModel_CSTATE[12];       /* '<S1>/Linear Model' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T LinearModel_CSTATE[12];       /* '<S1>/Linear Model' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T LinearModel_CSTATE[12];    /* '<S1>/Linear Model' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: LinearModel_A
   * Referenced by: '<S1>/Linear Model'
   */
  real_T LinearModel_A[67];

  /* Computed Parameter: LinearModel_B
   * Referenced by: '<S1>/Linear Model'
   */
  real_T LinearModel_B[37];

  /* Computed Parameter: LinearModel_C
   * Referenced by: '<S1>/Linear Model'
   */
  real_T LinearModel_C[85];

  /* Computed Parameter: LinearModel_D
   * Referenced by: '<S1>/Linear Model'
   */
  real_T LinearModel_D[35];

  /* Expression: opreport.Outputs(9).y
   * Referenced by: '<S1>/DCM_be Trim'
   */
  real_T DCM_beTrim_Bias[9];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Actuators[4];               /* '<Root>/Actuators' */
  EnvironmentBus Environment;          /* '<Root>/Environment' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  StatesBus States;                    /* '<Root>/States' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void linearAirframe_initialize(void);
extern void linearAirframe_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Magnetic Field Trim' : Eliminated nontunable bias of 0
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
 * '<Root>' : 'linearAirframe'
 * '<S1>'   : 'linearAirframe/Linear'
 * '<S2>'   : 'linearAirframe/Linear/Bus setup'
 */
#endif                                 /* RTW_HEADER_linearAirframe_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
