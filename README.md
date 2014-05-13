keyboardDecoder
===============

An emulation of the SMC KR2376-17 chip

The old PMOS keyboard decoder chip made by SMC, KR2376-17, had failed in the Decwriter LA30 that I am restoring. Instead of buying an old chip I assembled a small emulator circuit based on a AVR AtMega 1284p chip.

[Restoration blog](http://www.datormuseum.se/computers/digital-equipment-corporation/pdp-11-04 "Restoration blog")

Original chip to the left and my kludge to the right

![Keyboard decoder](https://dl.dropboxusercontent.com/u/96935524/Datormusuem/KBD_decoder.png "Keyboard decoder")

I used the [datasheet] (https://dl.dropboxusercontent.com/u/96935524/Datormusuem/KR2376.pdf) and created a simple Arduino project. I used the keypad libray which I modifed to support three different key maps. One to be used when the control key was pressed, one when the shift key was pressed and one key map when neither was pressed. I also modifed a constant the control the size of the scanner so that it could handle the 8x11 matrix of the LA30 keyboard.

This chip is also used in the DEC VT05 terminal.

Since it was rather cheap to roder ten small PCBs from China I just made a small PCB. The gerber files are in the repo as well as the DipTrace CAD file.

Top layer:
![PCB top](https://dl.dropboxusercontent.com/u/96935524/Datormusuem/LA30keyboardDecoder/LA30top.png "PCB top")

Bottom layer:
![PCB bottom](https://dl.dropboxusercontent.com/u/96935524/Datormusuem/LA30keyboardDecoder/LA30bottom.png "PCB top")
