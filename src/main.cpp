#include <micro_ros_platformio.h>
#ifdef ESP_PLATFORM
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#endif
#include "ros.h"
#include "mpu9250.h"
// #include "motor_driver.h"
// #include "encoder.h"


imu_setup_t imu_setup = {
    .direction = 0x68
};

#define USE_WIFI // Serial mode not working currently :(

#ifdef USE_SERIAL
    void setup() 
    {
        Serial.begin(115200);
        Serial.println("Serial started");

        set_microros_serial_transports(Serial);

        Serial.println("Serial Connected ... ");
        Serial.println("Connecting to MicroROS Agent ... ");
        Serial.println("Serial Connection to MicroROS Agent established ... ");
        Serial.println("IMU Datastream open!");


        setup_imu(imu_setup);
        setupRos();

    }
#endif

#ifdef USE_WIFI
    void setup() 
    {
        Serial.begin(115200);
        Serial.println("Serial started");

        Serial.println("Connecting to Wifi ... ");
        IPAddress agent_ip(192, 168, 20, 15);
        size_t agent_port = 8888;
        char ssid[] = "CPS2.4G";
        char psk[]= "pac999CPS";

        set_microros_wifi_transports(ssid, psk, agent_ip, agent_port);

        Serial.println("MicroROS transport open on WiFi!");

        setup_imu(imu_setup);
        setupRos();
    }
#endif



// void setup() {
// // put your setup code here, to run once:
// IPAddress agent_ip(192, 168, 20, 15);
// size_t agent_port = 8888;
// char ssid[] = "CPS2.4G";
// char psk[]= "pac999CPS";
// set_microros_wifi_transports(ssid, psk, agent_ip, agent_port);

// // import functions
// // InitMotorDriver();
// // InitEncoder();
// setup_imu(imu_setup);
// setupRos();

// }

void loop() {
// put your main code here, to run repeatedly:

}