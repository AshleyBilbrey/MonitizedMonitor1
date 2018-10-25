# MonitizedMonitor1

This is a system to have a user pay money to be able to type a message on a screen. This version is for a Arduino UNO.

What you will need for this project is:

- Arduino UNO
- Small Breadbord
- 16x2 LCD Monitor
- 4x4 Keypad
- 220Ω Resistor
- Wires
- Cardboard
- Tape
- Indipendent Power Supply (Optional)

The main components of this project is the monitor, keypad, and coin acceptor. The way the code has the keypad work, is to have a shift button, because the number of buttons is less than the numbers of letter in the English alphabet. The last character on the 16x2 display shows the what section of the keyboard you are using. One section is the first half of the alphabet which shows an up arrow, the second section is the second half the alphabet and shows a down arrow, and the third section is for numbers and other characters and shows the character #. There is also a dedicated space button, and a dedicated heart button, because why not. ❤️

Because the monitor and the keypad takes up all 12 digital ports on the Arduino, the solution for the coin accepter was to use the reset port instead. On the circuit diagram, there are two orange rectangles which represent peices of copper. Both coins and copper are conductive, so the concept is that when someone puts a coin in the coin slot, the coin will slide along the copper and complete the circut, resetting the Arduino and allowing people to type another message.

![Circuit Diagram](https://user-images.githubusercontent.com/44065883/46993197-3a4f1580-d0cb-11e8-9343-4b9aa5626b24.png)

![Photo of Prototype](https://user-images.githubusercontent.com/44065883/47469958-d7433a00-d7c0-11e8-8bd7-62811e10a915.png)

