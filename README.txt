Zane Grasso-Monroe
Emily Filmer
Brandon Cornel

cd to the "Morse-Code-CMPE-240" folder and run
make -f MAKEFILE
Navigate to the bin folder and drag the kernel7.img file to the root directory of the SD card

Connect the UART cable and the LED(GPIO 16) to the Raspberry PI 
Connect the power to the Raspberry PI
Navigate to the Device Manager in Windows and locate the COM port for the Raspberry PI(ex. COM5)
Open up Putty and select "Serial" for the connection type. For the serial line put the COM number(ex. COM5). For the speed 
use 115200. Then click open.
Input whatever you would like converted to morse and enjoy!