/*
 * File: linearAirframe.h
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

/* Forward declaration for rtModel */
typedef struct tag_RTM_linearAirframe_T RT_MODEL_linearAirframe_T;

#ifndef DEFINED_TYPEDEF_FOR_AtmosphereBus_
#define DEFINED_TYPEDEF_FOR_AtmosphereBus_

typedef struct {
  real_T air_temp;
  real_T speed_sound;
  real_T pressure;
  real_T air_density;
} AtmosphereBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnvironmentBus_
#define DEFINED_TYPEDEF_FOR_EnvironmentBus_

typedef struct {
  real_T Gravity_ned[3];
  AtmosphereBus AtmosphereBus;
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

/* Block signals and states (default storage) for model 'linearAirframe' */
typedef struct {
  real_T TmpSignalConversionAtLinearMode[14];
} DW_linearAirframe_f_T;

/* Continuous states for model 'linearAirframe' */
typedef struct {
  real_T LinearModel_CSTATE[12];       /* '<S1>/Linear Model' */
} X_linearAirframe_n_T;

/* State derivatives for model 'linearAirframe' */
typedef struct {
  real_T LinearModel_CSTATE[12];       /* '<S1>/Linear Model' */
} XDot_linearAirframe_n_T;

/* State Disabled for model 'linearAirframe' */
typedef struct {
  boolean_T LinearModel_CSTATE[12];    /* '<S1>/Linear Model' */
} XDis_linearAirframe_n_T;

/* Real-time Model Data Structure */
struct tag_RTM_linearAirframe_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
    boolean_T *stopRequestedFlag;
  } Timing;
};

typedef struct {
  DW_linearAirframe_f_T rtdw;
  RT_MODEL_linearAirframe_T rtm;
} MdlrefDW_linearAirframe_T;

/* Model reference registration function */
extern void linearAirframe_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_linearAirframe_T *
  const linearAirframe_M);
extern void linearAirframe_Init(X_linearAirframe_n_T *localX);
extern void linearAirframe_Deriv(DW_linearAirframe_f_T *localDW,
  X_linearAirframe_n_T *localX, XDot_linearAirframe_n_T *localXdot);
extern void linearAirframe_Update(void);
extern void linearAirframe(const real32_T rtu_Actuators[4], const EnvironmentBus
  *rtu_Environment, StatesBus *rty_States, DW_linearAirframe_f_T *localDW,
  X_linearAirframe_n_T *localX);

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
