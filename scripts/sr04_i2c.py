import smbus
import time

bus = smbus.SMBus(1)  # Rev 2 Pi uses 1

address = 0x50 #I2C address


while True:
    
    cmd = 1
    bus.write_byte(address, cmd)
    time.sleep(0.2) #wait for the echo 

    data = bus.read_i2c_block_data(address, 0, 3) #read three bytes into array

    distance = (data[0] * 65535 + data[1] * 256 + data[2])/10000
    print("distance : " + format(distance, '.2f'))
