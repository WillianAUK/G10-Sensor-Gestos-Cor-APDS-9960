import serial #Serial imported for Serial communication
import time #Required to use delay functions
import pyautogui

ArduinoSerial = serial.Serial('com1',9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

while True:
    incoming = str (ArduinoSerial.readline()) #read the serial data and print it as line
    print (incoming)

    if 'Play/Pause' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.hotkey('ctrl', 'left', interval=0.2)  

    if 'Forward' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.hotkey('ctrl', 'right', interval=0.2)   

    if 'Volume_UP' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.hotkey('ctrl', 'up', interval=0.2)  
        
    if 'Volume_DOWN' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.hotkey('ctrl', 'down', interval=0.2)  

    if 'Next' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.hotkey('n', interval=.2)

    if 'Previous' in incoming:
        pyautogui.hotkey('alt', 'tab', interval=0.1)
        pyautogui.hotkey('p', interval=0.2)  

    incoming = "";
