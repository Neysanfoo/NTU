from sense_hat import SenseHat
import time

s = SenseHat()

b = [0,0,0]
w = [255,255,255]
r = [255, 0, 0]


board = [[r,r,r,r,r,r,r,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,b,b,b,b,b,b,r],
         [r,r,r,r,r,r,r,r]]
         
         
x=2
y=2


def move_marble(pitch,roll,x,y):
  new_x = x
  new_y = y
  if 1 < pitch < 179 and x != 0:
    new_x -= 1
  elif 359 > pitch > 179 and x != 7:
    new_x += 1
    
  if 1 < roll < 179 and y != 7:
    new_y += 1
  elif 359 > roll > 179 and y != 0:
    new_y -= 1
  return new_x, new_y


while True:
  pitch = round(s.get_orientation()["pitch"])
  roll = round(s.get_orientation()["roll"])
  board[y][x] = b
  x,y = move_marble(pitch,roll,x,y)
  board[y][x] = w
  board_1D = sum(board,[])
  s.set_pixels(board_1D)
  time.sleep(0.2)
