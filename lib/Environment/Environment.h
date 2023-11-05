/*
 * File: Environment.h
 *
 * Code generated for Simulink model 'Environment'.
 *
 * Model version                  : 1.289
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Oct 22 13:54:30 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Environment_h_
#define RTW_HEADER_Environment_h_
#include "rtwtypes.h"
#ifndef Environment_COMMON_INCLUDES_
# define Environment_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Environment_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Environment_T RT_MODEL_Environment_T;

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

/* External inputs (root inport signals with default storage) */
typedef struct {
  StatesBus States;                    /* '<Root>/States' */
} ExtU_Environment_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  EnvironmentBus Environmentb;         /* '<Root>/Environmentb' */
} ExtY_Environment_T;

/* Real-time Model Data Structure */
struct tag_RTM_Environment_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_Environment_T Environment_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Environment_T Environment_Y;

/* Model entry point functions */
extern void Environment_initialize(void);
extern void Environment_step(void);

/* Real-time Model object */
extern RT_MODEL_Environment_T *const Environment_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('asbQuadcopter/Environment')    - opens subsystem asbQuadcopter/Environment
 * hilite_system('asbQuadcopter/Environment/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'asbQuadcopter'
 * '<S1>'   : 'asbQuadcopter/Environment'
 * '<S2>'   : 'asbQuadcopter/Environment/Environment (Constant)'
 */
#endif                                 /* RTW_HEADER_Environment_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
