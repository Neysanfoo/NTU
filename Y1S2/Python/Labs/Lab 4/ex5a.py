from sense_hat import SenseHat
import time
from random import randint 

s = SenseHat()

s.clear()

p1x,p1y = randint(0,7),randint(0,7)
p2x,p2y = randint(0,7),randint(0,7)
p3x,p3y = randint(0,7),randint(0,7)
p4x,p4y = randint(0,7),randint(0,7)



red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
yellow = (255,255,0)

s.set_pixel(p1x,p1y,red)
time.sleep(1)
s.set_pixel(p2x,p2y,green)
time.sleep(1)
s.set_pixel(p3x,p3y,blue)
time.sleep(1)
s.set_pixel(p4x,p4y,yellow)
