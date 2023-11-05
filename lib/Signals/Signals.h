/*
 * File: Signal.h
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

#ifndef RTW_HEADER_Signal_h_
#define RTW_HEADER_Signal_h_
#include "rtwtypes.h"
#include <math.h>
#ifndef Signal_COMMON_INCLUDES_
#define Signal_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Signal_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Signal_T RT_MODEL_Signal_T;

#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T XYZ[3];                     /* '<S6>/fromWS_Signal 1' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S6>/From Workspace' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S6>/fromWS_Signal 1' */

  uint32_T Output_DSTATE;              /* '<S5>/Output' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S6>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S6>/fromWS_Signal 1' */
} DW_Signal_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  CommandBus ACCmd;                    /* '<Root>/AC Cmd' */
} ExtY_Signal_T;

/* Real-time Model Data Structure */
struct tag_RTM_Signal_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

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
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_Signal_T Signal_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Signal_T Signal_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<S1>/Bus Creator' */

/* Model entry point functions */
extern void Signal_initialize(void);
extern void Signal_step(void);

/* Real-time Model object */
extern RT_MODEL_Signal_T *const Signal_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

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
 * hilite_system('asbQuadcopter/Command/Signal Editor')    - opens subsystem asbQuadcopter/Command/Signal Editor
 * hilite_system('asbQuadcopter/Command/Signal Editor/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'asbQuadcopter/Command'
 * '<S1>'   : 'asbQuadcopter/Command/Signal Editor'
 * '<S2>'   : 'asbQuadcopter/Command/Signal Editor/Compare To Constant'
 * '<S3>'   : 'asbQuadcopter/Command/Signal Editor/Compare To Zero'
 * '<S4>'   : 'asbQuadcopter/Command/Signal Editor/Compare To Zero1'
 * '<S5>'   : 'asbQuadcopter/Command/Signal Editor/Live Time  Ticks'
 * '<S6>'   : 'asbQuadcopter/Command/Signal Editor/Position//Attitude Reference'
 * '<S7>'   : 'asbQuadcopter/Command/Signal Editor/Live Time  Ticks/Increment Real World'
 * '<S8>'   : 'asbQuadcopter/Command/Signal Editor/Live Time  Ticks/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Signal_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
