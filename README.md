# SBD-DL22-Public
SBD-DL22 program files for use in PCB manufacturing

## Requirements
Hardware Requirements:
* Texas Instruments MSP430 microcontroller - *included in circuit design*
* 14-pin MSP430 JTAG header- *included in circuit design*
* MSP-FET debug probe

Software Requirements:
* Energia IDE- *this is a modified version of the Arduino Genuino IDE for the TI MSP430*
* SBD-DL22-Public GitHub repository files

## General Upload Procedure
To uploading program data to the MSP430 on-board the PCB:
1. Connect the MSP-FET debug probe from a computer (with Energia installed) to the on-board JTAG header.
2. Open the Energia IDE and the .ino file you wish to upload.
3. Click Upload (arrow icon, top left). This will run the program and display outputs, if any, to the Serial Monitor
(magnifying glass icon, top right).

## Program Upload Sequence
Program Upload Sequence specific to our PCB:
1. Upload/Run set_clock.ino:
	* Open Serial Monitor and ensure the correct current time printout before proceeding (Date : dd/mm/yyyy	hh:mm.ss)
2) Upload/Run main.ino
