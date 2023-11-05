/*
 * File: flightControlSystem.c
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 1.157
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Oct 24 22:49:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "flightControlSystem.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/controller' */
uint8_T flag_outport;                  /* '<S2>/Merge' */

/* Block signals and states (default storage) */
DW_flightControlSystem_T flightControlSystem_DW;
static void flightControlSystem_FlightControlSystem_Init(uint8_T *rty_Flag);
static void flightControlSystem_FlightControlSystem(const CommandBus
  *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors, real32_T
  rty_motorCmds[4], uint8_T *rty_Flag,
  DW_FlightControlSystem_flightControlSystem_T *localDW);

/* System initialize for atomic system: '<Root>/Flight Control System' */
static void flightControlSystem_FlightControlSystem_Init(uint8_T *rty_Flag)
{
  /* SystemInitialize for ModelReference: '<S1>/estimator' */
  stateEstimator_Init();

  /* SystemInitialize for Merge: '<S2>/Merge' */
  *rty_Flag = 0U;
}

/* Output and update for atomic system: '<Root>/Flight Control System' */
static void flightControlSystem_FlightControlSystem(const CommandBus
  *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors, real32_T
  rty_motorCmds[4], uint8_T *rty_Flag,
  DW_FlightControlSystem_flightControlSystem_T *localDW)
{
  /* local block i/o variables */
  sensordata_t rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1;
  CommandBus rtb_Switch;
  real32_T rtb_controller_o2[8];

  /* Switch: '<S4>/Switch' */
  rtb_Switch = *rtu_ReferenceValueServerCmds;

  /* BusCreator generated from: '<S1>/estimator' incorporates:
   *  SignalConversion generated from: '<S5>/Bus Selector1'
   *  SignalConversion generated from: '<S5>/Bus Selector3'
   *  SignalConversion generated from: '<S5>/Bus Selector4'
   *  SignalConversion generated from: '<S5>/Bus Selector5'
   *  SignalConversion generated from: '<S5>/Bus Selector6'
   * */
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddx =
    rtu_Sensors->HALSensors.HAL_acc_SI.x;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddy =
    rtu_Sensors->HALSensors.HAL_acc_SI.y;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.ddz =
    rtu_Sensors->HALSensors.HAL_acc_SI.z;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.p =
    rtu_Sensors->HALSensors.HAL_gyro_SI.x;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.q =
    rtu_Sensors->HALSensors.HAL_gyro_SI.y;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.r =
    rtu_Sensors->HALSensors.HAL_gyro_SI.z;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.altitude_sonar
    = rtu_Sensors->HALSensors.HAL_ultrasound_SI.altitude;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.prs =
    rtu_Sensors->HALSensors.HAL_pressure_SI.pressure;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_V =
    rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_V;
  rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1.vbat_percentage
    = rtu_Sensors->HALSensors.HAL_vbat_SI.vbat_percentage;

  /* ModelReference: '<S1>/estimator' */
  stateEstimator_run(rtb_Switch.controlModePosVSOrient,
                     &rtb_BusConversion_InsertedFor_estimator_at_inport_1_BusCreator1,
                     rtu_Sensors->VisionSensors.usePosVIS_flag,
                     &rtu_Sensors->VisionSensors.opticalFlow_data[0],
                     &rtu_Sensors->VisionSensors.posVIS_data[0],
                     &localDW->estimator, &rtu_Sensors->SensorCalibration[0]);

  /* ModelReference: '<S1>/controller' */
  flightController_run(&rtb_Switch, &localDW->estimator, &rty_motorCmds[0],
                       &rtb_controller_o2[0]);

  /* If: '<S2>/If' incorporates:
   *  Abs: '<S2>/Abs'
   *  Abs: '<S2>/Abs1'
   *  Abs: '<S2>/Abs2'
   *  Abs: '<S2>/Abs3'
   *  Abs: '<S2>/Abs4'
   *  Abs: '<S2>/Abs5'
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S2>/Logical Operator1'
   *  Logic: '<S2>/Logical Operator2'
   *  Logic: '<S2>/Logical Operator3'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Sum: '<S2>/Subtract'
   *  Sum: '<S2>/Subtract1'
   */
  if (((real32_T)fabs(localDW->estimator.X) > 10.0F) || ((real32_T)fabs
       (localDW->estimator.Y) > 10.0F)) {
    /* Outputs for IfAction SubSystem: '<S2>/Geofencing error' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Out1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    *rty_Flag = 1U;

    /* End of Outputs for SubSystem: '<S2>/Geofencing error' */
  } else if ((((real32_T)fabs(rtu_Sensors->VisionSensors.opticalFlow_data[0]) >
               0.01F) && ((real32_T)fabs
                          (rtu_Sensors->VisionSensors.opticalFlow_data[0] -
                localDW->estimator.dx) > 6.0F)) || (((real32_T)fabs
               (rtu_Sensors->VisionSensors.opticalFlow_data[1] -
                localDW->estimator.dy) > 6.0F) && ((real32_T)fabs
               (rtu_Sensors->VisionSensors.opticalFlow_data[1]) > 0.01F))) {
    /* Outputs for IfAction SubSystem: '<S2>/estimator//Optical flow error' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* SignalConversion generated from: '<S14>/Out1' incorporates:
     *  Constant: '<S14>/Constant'
     */
    *rty_Flag = 99U;

    /* End of Outputs for SubSystem: '<S2>/estimator//Optical flow error' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Normal condition' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* SignalConversion generated from: '<S13>/Out1' incorporates:
     *  Constant: '<S13>/Constant'
     */
    *rty_Flag = 0U;

    /* End of Outputs for SubSystem: '<S2>/Normal condition' */
  }

  /* End of If: '<S2>/If' */
}

/* Model step function */
void flightControlSystem_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Flight Control System' */

  /* Inport: '<Root>/AC cmd' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  flightControlSystem_FlightControlSystem(&cmd_inport, &sensor_inport,
    motors_outport, &flag_outport, &flightControlSystem_DW.FlightControlSystem);

  /* End of Outputs for SubSystem: '<Root>/Flight Control System' */
}

/* Model initialize function */
void flightControlSystem_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<S1>/estimator' */
  stateEstimator_o_initialize();

  /* SystemInitialize for Atomic SubSystem: '<Root>/Flight Control System' */

  /* SystemInitialize for Inport: '<Root>/Sensors' */
  flightControlSystem_FlightControlSystem_Init(&flag_outport);

  /* End of SystemInitialize for SubSystem: '<Root>/Flight Control System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
