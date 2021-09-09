from sense_hat import SenseHat
import time
from random import randint

s = SenseHat()
s.clear()

Y = (255,255,0)
G = (0,128,0)
O = (0,0,0)

def heart(col, orientation):
  C = col
  if orientation == 0:
    image = [
    O, O, O, O, O, O, O, O, 
    O, C, C, O, C, C, O, O,
    C, C, C, C, C, C, C, O, 
    C, C, C, C, C, C, C, O,
    O, C, C, C, C, C, O, O,
    O, O, C, C, C, O, O, O,
    O, O, O, C, O, O, O, O,
    O, O, O, O, O, O, O, O,
    ]
  if orientation == 1:
    image = [
    O, O, O, O, C, C, O, O, 
    O, O, O, C, C, C, C, O,
    O, O, C, C, C, C, C, O, 
    O, C, C, C, C, C, O, O,
    O, O, C, C, C, C, C, O,
    O, O, O, C, C, C, C, O,
    O, O, O, O, C, C, O, O,
    O, O, O, O, O, O, O, O,
    ]
  if orientation == 2:
    image = [
    O, O, O, O, O, O, O, O, 
    O, O, O, O, C, O, O, O,
    O, O, O, C, C, C, O, O, 
    O, O, C, C, C, C, C, O,
    O, C, C, C, C, C, C, C,
    O, C, C, C, C, C, C, C,
    O, O, C, C, O, C, C, O,
    O, O, O, O, O, O, O, O,
    ]
  if orientation == 3:
    image = [
    O, O, C, C, O, O, O, O, 
    O, C, C, C, C, O, O, O,
    O, C, C, C, C, C, O, O, 
    O, O, C, C, C, C, C, O,
    O, C, C, C, C, C, O, O,
    O, C, C, C, C, O, O, O,
    O, O, C, C, O, O, O, O,
    O, O, O, O, O, O, O, O,
    ]
  return image

while True:
  color = [Y,G][randint(0,1)]
  orientation = randint(0,3)
  s.set_pixels(heart(color,orientation))
  time.sleep(1)
  
  

