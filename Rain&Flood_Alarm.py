from gpiozero import Buzzer, InputDevice, OutputDevice
from time import sleep

# LCD
from RPLCD import *             # intall the RPLCD and import it
from RPLCD.i2c import CharLCD   # CharLCD
                                # In the argument on CharLCD() you can pass the I2C name and the address of it.
lcd = CharLCD('PCF8574', 0x27)  # Store it in lcd variable

#RGB Led
red = OutputDevice(16)
green = OutputDevice(20)
blue = OutputDevice(21)

#buzzer and Sensors
buzz = Buzzer(13)
rainS = InputDevice(12)
floodS = InputDevice(6)

# Rain Alarm function
def rainAlarm(iterations):
    for i in range(iterations):
        buzz.on()
        blue.on()
        red.off()
        green.off()
        sleep(0.1)
        buzz.off()
        blue.off()
        sleep(0.1)

# Flood Alarm function
def floodAlarm(iterations):
    for i in range(iterations):
        buzz.on()
        red.on()
        green.off()
        blue.off()
        sleep(0.1)
        buzz.off()
        red.off()
        sleep(0.1)
        
        
while True:
    if  floodS.is_active:
        lcd.clear()
        floodAlarm(5)
        lcd.cursor_pos = (0, 1)
        lcd.write_string('Warning Flood' )
    elif not rainS.is_active:
        lcd.clear()
        rainAlarm(2)
        lcd.cursor_pos = (0, 0)
        lcd.write_string('Warning Raining' )
    else:
        lcd.clear()
        lcd.cursor_pos = (0, 0)
        lcd.write_string('Sunny Day (^_^)' )
        red.on()
        green.on()
        blue.off()
    sleep(1)

