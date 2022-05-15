# SBD-DL22-Public
SBD-DL22 program files for use in PCB manufacturing

## Requirements
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
2. Unzip/install LaunchPad drivers: available at 'SBD-DL22-Public/Energia_installation'

## Step 2. Prepare for Program Upload
### Now, we will connect a computer to the PCB board and become familiar with the Energia IDE.
1. Connect the MSP-FET debug probe from a computer, with Energia pre-installed, to the on-board JTAG header.
2. To open .ino files: 
	* Open the Energia IDE. Within the IDE, select "File>Open" and select the relevant .ino file
3. To upload/run .ino files:
	* In the IDE, click "Upload" (arrow icon, top left). This will run the program and display any program outputs to the "Serial Monitor"
(magnifying glass icon, top right).

## Step 3. Upload Program Data
### First, we will modify and run a program to set the RTC clock. 
1. Update'SBD-DL22-Public/set_clock.ino' with the current time:
	* "t.hour" = hh (current hour)
	* "t.min" = mm (current minute)
	* "t.sec" = ss (current second)
	* "t.mday" = dd (current day of the month)
	* "t.mon" = mm (current month)
	* "t.year" = yyyy (current year)
2. Upload/Run 'SBD-DL22-Public/set_clock.ino'
        * Open Serial Monitor and verify that the current time readout is correct (Date: dd/mm/yyyy hh:mm.ss)
### Then, run a program which allows the MSP430 to begin data collection.
3. Upload/Run 'SBD-DL22-Public/MainV8.ino'

### Troubleshooting
* Ensure that "Tools > Board: MSP430FR5969LP" and "Tools > Port" is specified correctly

