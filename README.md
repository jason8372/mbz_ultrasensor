#################################################################################

Directly connect HC-SR04(ultrasonic sensor) to Jetson Nano(applicable to Raspberry Pi)

Check whether target is detected

#################################################################################

SETUP:

HC-SR04 needs to be powered with 5V

Current setup(scripts/sensor.py line 27~29):

gpio is set to BCM Mode

Trigger -> 10

Echo    -> 6

#################################################################################

Start using the sensor and get robot_on_target as rostopic

$roslaunch sensor_direct ultrasonic_detection.launch -threshold(default 5) -consec_count(default 3)

**threshold(distance from the sensor in cm) 

**consec_count(how much time has passed. Check the sensor specs for actual frequency)
