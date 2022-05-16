# SBD-DL22-Public
SBD-DL22 program files for use in PCB manufacturing

## Step 0. Requirements
Hardware Requirements:
* Texas Instruments MSP430 microcontroller - *on-board*
* 14-pin MSP430 JTAG header- *on-board*
* MSP-FET debug probe

Software Requirements:
* Windows OS
* Energia IDE- *a modified version of the Arduino Genuino IDE for the TI MSP430*
* SBD-DL22-Public GitHub repository files

## Step 1. Install Energia
1. Download Energia for Windows: available at https://energia.nu/download/ 
2. Download LaunchPad drivers: available at 'SBD-DL22-Public/Energia_installation'

## Step 2. Prepare for Program Upload
#### Now, we will connect a computer to the PCB board and set-up Energia
1. Connect the MSP-FET debug probe from a computer, with Energia pre-installed, to the on-board JTAG header.
2. Download the following files from our repository:
	* 'clock_sync.ino' : available at 'SBD-DL22-Public/set_clock.ino'
	* 'MainV8.ino': available at 'SBD-DL22-Public/MainV8.ino'
3. Download the 'Libraries' file from our repository
	* Open the folder containing Energia on the computer, and move all files in 'Libraries' to Energia's 'libraries' folder
5. Open Energia IDE, and verify the following settings under the "Tools" menu:
	* in "Tools>Board", "MSP-EXP430FR5969LP" is selected
	* in "Tools>Port", the USB port that the MSP-FET is plugged into is selected

## Step 3. Upload Program Data
#### First, we will modify and run a program to set the RTC clock. 
1. *Open* 'clock_sync.ino'
2. *Edit/Compile* 'clock_sync.ino' with the current time (24-hr clock):
	* "t.hour" = hh (current hour)
	* "t.min" = mm (current minute)
	* "t.sec" = ss (current second)
	* "t.mday" = dd (current day of the month)
	* "t.mon" = mm (current month)
	* "t.year" = yyyy (current year)
3. *Run* 'clock_sync.ino'
	* Open Serial Monitor and verify that the current time readout is correct (Date: dd/mm/yyyy hh:mm.ss)

#### Then, run a program which allows the MSP430 to begin data collection.
4. *Open* 'MainV8.ino'
5. *Run* 'MainV8.ino'

#### Repeat Step 3, if uploading program data to multiple PCB boards.

## Energia IDE Reference
#### This is a general reference on how to use the Energia IDE, if any of the terminology used in the steps above is unclear:
* To *Open* .ino files: 
	* Open the Energia IDE. In the application, select "File>Open" and select the relevant .ino file
* To *Edit/Compile* an .ino file:
	* In the application, edit the .ino file as you would a .txt file. Once finished, click the "Verify" checkmark (top left) to compile the program. The program should compile and there should be no "error" messages in the black terminal window below.
* To *Run* .ino files:
	* In the application, click the "Upload" arrow icon (top left). This will run the program and display any program outputs to the "Serial Monitor"
magnifying glass icon (top right).

