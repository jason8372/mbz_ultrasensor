# Connect HC-SR04 to Jetson (GPIO Connection)

#### *HC-SR04 needs to be powered with 5V


#### scripts/sensor.py  : Measures the distance from the sensor to the object (2cm ~ 400cm)
#### src/bag_bool.cpp   : Logic to return boolean value if the object is close enough to the sensor


### Current setup (scripts/sensor.py line 27~29):

Mode : BCM

Trigger : 10

Echo : 6


### Get robot_on_target as rostopic
```

roslaunch sensor_direct ultrasonic_detection.launch -threshold(default 5) -consec_count(default 3)

```

**threshold(distance from the sensor in cm) 

**consec_count(how much time has passed. Check the sensor specs for actual frequency)


## Source
https://github.com/engcang/HC-SR04-UltraSonicSensor-ROS-RaspberryPi

https://github.com/NVIDIA/jetson-gpio
