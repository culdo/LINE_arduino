import LINE
import serial
import time

p="/dev/ttyUSB0"
while True:
    error_flag = False
    try:
        ser = serial.Serial(p, 115200)
    except Exception as e:
        error_flag = True
        if "ttyUSB0" in str(e):
            p = "/dev/ttyUSB1"
            print ("port is now", p)
        elif "ttyUSB1" in str(e):
            p = "/dev/ttyUSB0"
            print ("port is now", p)
        else:
            print (e)   # none of the above

    if not error_flag:
        break
    time.sleep(1)

LINE.login("george0228489372@yahoo.com.tw", "wuorsut", "wuorsut@gmail.com")
LINE.choose_room("Alo Smo")

while True:
    last_cmd = LINE.has_new("Own")
    if last_cmd:
        # print(last_cmd)
        if last_cmd == u"前進":
            ser.write("1".encode())
            print(1)
        elif last_cmd == u"後退":
            ser.write("2".encode())
            print(2)
        elif last_cmd == u"左轉":
            ser.write("3".encode())
            print(3)
        elif last_cmd == u"右轉":
            ser.write("4".encode())
            print(4)
        elif last_cmd == u"停":
            ser.write("5".encode())
            print(5)
# print 'loop'
#     if ser.in_waiting > 0:
    elif ser.in_waiting > 0:
        read_ser = ser.readline().decode()
        print(read_ser)
        LINE.send(read_ser)
        ser.reset_input_buffer()

