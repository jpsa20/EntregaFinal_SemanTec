from pynput import keyboard
import serial

ser = serial.Serial('COM4', 9600)

def on_activate_a():
    bs = 'a\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('A pressed')

def on_activate_s():
    bs = 's\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('S pressed')

def on_activate_d():
    bs = 'd\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('D pressed')

def on_activate_w():
    bs = 'w\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('w pressed')

def on_activate_1():
    bs = '1\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('1 pressed')

def on_activate_2():
    bs = '2\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('2 pressed')

def on_activate_3():
    bs = '3\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('3 pressed')

def on_activate_4():
    bs = '4\n'
    bs = str.encode(bs)
    ser.write(bs)
    print('4 pressed')

def quit():
    print('QUIT')
    h.stop()

with keyboard.GlobalHotKeys({
        'a': on_activate_a,
        's': on_activate_s,
        'd': on_activate_d,
        'w': on_activate_w,
        '1': on_activate_1,
        '2': on_activate_2,
        '3': on_activate_3,
        '4': on_activate_4,
        '<ctrl>+c': quit}) as h:
    h.join()
