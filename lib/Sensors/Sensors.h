#ifndef RTW_HEADER_Sensors_h_
#define RTW_HEADER_Sensors_h_
#include "rtwtypes.h"
#include <string.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#ifndef Sensors_COMMON_INCLUDES_
# define Sensors_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Sensors_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Sensors_T RT_MODEL_Sensors_T;

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

#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_

typedef struct {
  real32_T opticalFlow_data[3];
  real32_T posVIS_data[4];
  real32_T usePosVIS_flag;
} extraSensorData_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_acc_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_acc_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T temperature;
} HAL_acc_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_gyro_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_gyro_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T temperature;
  int32_T temperature_lsb;
} HAL_gyro_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_fifo_gyro_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_fifo_gyro_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
} HAL_fifo_gyro_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_magn_mG_t_
#define DEFINED_TYPEDEF_FOR_HAL_magn_mG_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
} HAL_magn_mG_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_pressure_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_pressure_SI_t_

typedef struct {
  real_T temperature;
  real32_T pressure;
} HAL_pressure_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_echo_t_
#define DEFINED_TYPEDEF_FOR_HAL_echo_t_

typedef struct {
  uint16_T begin_echo_index;
  uint16_T end_echo_index;
  int16_T max_value_index;
  int32_T max_value;
  uint16_T precedent;
  int16_T d_echo;
  uint16_T pre_max_index;
} HAL_echo_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_list_echo_t_
#define DEFINED_TYPEDEF_FOR_HAL_list_echo_t_

typedef struct {
  HAL_echo_t tab_echo[30];
  uint8_T number_of_echoes;
} HAL_list_echo_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_ultrasound_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_ultrasound_SI_t_

typedef struct {
  real32_T altitude;
  real32_T raw_altitude;
  uint16_T nb_echo;
  int32_T measure_ref;
  int32_T measure_status;
  uint8_T new_data;
  HAL_list_echo_t HAL_list_echo;
  HAL_list_echo_t HAL_list_echo_p;
} HAL_ultrasound_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_vbat_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_vbat_SI_t_

typedef struct {
  real32_T vbat_V;
  uint32_T vbat_percentage;
} HAL_vbat_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_acquisition_t_
#define DEFINED_TYPEDEF_FOR_HAL_acquisition_t_

typedef struct {
  int32_T number_HAL_read_call;
  uint32_T timestamp;
  uint16_T status;
  uint8_T used;
  uint8_T count_user;
  HAL_acc_SI_t HAL_acc_SI;
  HAL_gyro_SI_t HAL_gyro_SI;
  uint16_T HAL_fifo_count;
  uint32_T fifo_timestamp;
  HAL_fifo_gyro_SI_t HAL_fifo_gyro_SI_TempCorr[5];
  HAL_fifo_gyro_SI_t HAL_fifo_acce_SI_TempCorr[5];
  HAL_fifo_gyro_SI_t HAL_fifo_gyro_SI[5];
  HAL_fifo_gyro_SI_t HAL_fifo_acce_SI[5];
  real32_T HAL_ref_IMU_temp;
  uint8_T HAL_fifo_fsync[5];
  int32_T HAL_fifo_size;
  HAL_magn_mG_t HAL_magn_mG;
  HAL_pressure_SI_t HAL_pressure_SI;
  HAL_ultrasound_SI_t HAL_ultrasound_SI;
  uint8_T padding[196];
  HAL_vbat_SI_t HAL_vbat_SI;
} HAL_acquisition_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_

typedef struct {
  extraSensorData_t VisionSensors;
  HAL_acquisition_t HALSensors;
  real32_T SensorCalibration[8];
} SensorsBus;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  StatesBus Memory_PreviousInput;      /* '<S1>/Memory' */
} DW_Sensors_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: States
   * Referenced by: '<S1>/Memory'
   */
  StatesBus Memory_InitialCondition;

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S1>/Constant1'
   */
  real32_T Constant1_Value[8];

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S4>/Bias1'
   */
  real32_T Bias1_Bias[3];

  /* Computed Parameter: Bias2_Bias
   * Referenced by: '<S4>/Bias2'
   */
  real32_T Bias2_Bias[3];
} ConstP_Sensors_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  StatesBus States;                    /* '<Root>/States' */
  EnvironmentBus Environment;          /* '<Root>/Environment' */
} ExtU_Sensors_T;

/* Real-time Model Data Structure */
struct tag_RTM_Sensors_T {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW_Sensors_T Sensors_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Sensors_T Sensors_U;

/* Constant parameters (default storage) */
extern const ConstP_Sensors_T Sensors_ConstP;

extern SensorsBus sensor_inport;       /* '<S1>/Bus Creator1' */

/* Model entry point functions */
extern void Sensors_initialize(void);
extern void Sensors_step(void);

/* Real-time Model object */
extern RT_MODEL_Sensors_T *const Sensors_M;

#endif                                 /* RTW_HEADER_Sensors_h_ */