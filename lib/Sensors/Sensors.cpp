#include "Sensors.h"

/* Exported block signals */
SensorsBus sensor_inport;              /* '<S1>/Bus Creator1' */

Adafruit_MPU6050 mpu;

/* Block signals and states (default storage) */
DW_Sensors_T Sensors_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Sensors_T Sensors_U;

/* Real-time model */
RT_MODEL_Sensors_T Sensors_M_;
RT_MODEL_Sensors_T *const Sensors_M = &Sensors_M_;

/* Model step function */
void Sensors_step(void)
{
  HAL_echo_t rtb_HAL_echo_t;
  HAL_fifo_gyro_SI_t rtb_HAL_fifo_gyro_SI_TempCorr;
  int32_T i;

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  rtb_HAL_echo_t.begin_echo_index = 0U;
  rtb_HAL_echo_t.end_echo_index = 0U;
  rtb_HAL_echo_t.max_value_index = 0;
  rtb_HAL_echo_t.max_value = 0;
  rtb_HAL_echo_t.precedent = 0U;
  rtb_HAL_echo_t.d_echo = 0;
  rtb_HAL_echo_t.pre_max_index = 0U;

    /* BusCreator: '<S14>/Bus Creator2' incorporates:
   *  Concatenate: '<S16>/Vector Concatenate'
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

  rtb_HAL_echo_t.begin_echo_index = 0U;
  rtb_HAL_echo_t.end_echo_index = 0U;
  rtb_HAL_echo_t.max_value_index = 0;
  rtb_HAL_echo_t.max_value = 0;
  rtb_HAL_echo_t.precedent = 0U;
  rtb_HAL_echo_t.d_echo = 0;
  rtb_HAL_echo_t.pre_max_index = 0U;

  rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

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

  rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

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

  rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

  sensor_inport.HALSensors.HAL_fifo_gyro_SI[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
  sensor_inport.HALSensors.HAL_fifo_gyro_SI[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
  sensor_inport.HALSensors.HAL_fifo_gyro_SI[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
  sensor_inport.HALSensors.HAL_fifo_gyro_SI[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
  sensor_inport.HALSensors.HAL_fifo_gyro_SI[4] = rtb_HAL_fifo_gyro_SI_TempCorr;\
  
  rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
  rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

  sensor_inport.VisionSensors.opticalFlow_data[0] = (real32_T)(0.8 *
    Sensors_DW.Memory_PreviousInput.Omega_body[1] *
    -Sensors_DW.Memory_PreviousInput.X_ned[2] +
    Sensors_DW.Memory_PreviousInput.V_body[0]);
  sensor_inport.VisionSensors.opticalFlow_data[1] = (real32_T)(-0.8 *
    Sensors_DW.Memory_PreviousInput.Omega_body[0] *
    -Sensors_DW.Memory_PreviousInput.X_ned[2] +
    Sensors_DW.Memory_PreviousInput.V_body[1]);
  sensor_inport.VisionSensors.opticalFlow_data[2] = (real32_T)
    Sensors_DW.Memory_PreviousInput.V_body[2];

  sensor_inport.HALSensors.HAL_vbat_SI.vbat_V = 3.5F;
  sensor_inport.HALSensors.HAL_vbat_SI.vbat_percentage = 70U;

  sensor_inport.HALSensors.HAL_acc_SI.x = a.acceleration.x;
  sensor_inport.HALSensors.HAL_acc_SI.y = a.acceleration.y;
  sensor_inport.HALSensors.HAL_acc_SI.z = a.acceleration.z;
  sensor_inport.HALSensors.HAL_acc_SI.temperature = 0.0F;

  sensor_inport.HALSensors.HAL_gyro_SI.x = g.gyro.x;
  sensor_inport.HALSensors.HAL_gyro_SI.y = g.gyro.y;
  sensor_inport.HALSensors.HAL_gyro_SI.z = g.gyro.z;
  sensor_inport.HALSensors.HAL_gyro_SI.temperature = 0.0F;
  sensor_inport.HALSensors.HAL_gyro_SI.temperature_lsb = 0;

  sensor_inport.HALSensors.HAL_magn_mG.x = 0.0F;
  sensor_inport.HALSensors.HAL_magn_mG.y = 0.0F;
  sensor_inport.HALSensors.HAL_magn_mG.z = 0.0F;

  sensor_inport.HALSensors.HAL_pressure_SI.pressure = (real32_T)
  (12.017250061035156 * Sensors_DW.Memory_PreviousInput.X_ned[2]) +
  101270.953F;

  sensor_inport.HALSensors.HAL_pressure_SI.temperature = 0.0F;
  if ((real32_T)-Sensors_DW.Memory_PreviousInput.X_ned[2] <= 0.44F) {
    /* BusCreator: '<S14>/Bus Creator2' */
    sensor_inport.HALSensors.HAL_ultrasound_SI.altitude = 0.44F;
  } else {
    /* BusCreator: '<S14>/Bus Creator2' */
    sensor_inport.HALSensors.HAL_ultrasound_SI.altitude = (real32_T)
      -Sensors_DW.Memory_PreviousInput.X_ned[2];
  }

  sensor_inport.HALSensors.HAL_ultrasound_SI.raw_altitude = 0.0F;
  sensor_inport.HALSensors.HAL_ultrasound_SI.nb_echo = 0U;
  sensor_inport.HALSensors.HAL_ultrasound_SI.measure_ref = 0;
  sensor_inport.HALSensors.HAL_ultrasound_SI.measure_status = 0;
  sensor_inport.HALSensors.HAL_ultrasound_SI.new_data = 0U;
  sensor_inport.HALSensors.HAL_ultrasound_SI.HAL_list_echo.number_of_echoes = 0U;
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

  sensor_inport.HALSensors.number_HAL_read_call = 0;
  sensor_inport.HALSensors.timestamp = 0U;
  sensor_inport.HALSensors.status = 0U;
  sensor_inport.HALSensors.used = 0U;
  sensor_inport.HALSensors.count_user = 0U;
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
  memset(&sensor_inport.HALSensors.padding[0], 0, 196U * sizeof(uint8_T));

  sensor_inport.VisionSensors.posVIS_data[0] = -99.0F;
  sensor_inport.VisionSensors.posVIS_data[1] = 0.0F;
  sensor_inport.VisionSensors.posVIS_data[2] = 0.0F;
  sensor_inport.VisionSensors.posVIS_data[3] = -9.0F;
  sensor_inport.VisionSensors.usePosVIS_flag = 0.0F;

  for (i = 0; i < 8; i++) {
    sensor_inport.SensorCalibration[i] = Sensors_ConstP.Constant1_Value[i];
  }

  Sensors_DW.Memory_PreviousInput = Sensors_U.States;
}

/* Model initialize function */
void Sensors_initialize(void)
{
  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
  Sensors_DW.Memory_PreviousInput = Sensors_ConstP.Memory_InitialCondition;
}