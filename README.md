# CMPE 240
The work in this repository it entirely my own. It should not be copied and passed off as anyone else's work.
CMPE 240 is a computer engineering course for software engineers. The focus of the course is to introduce computer engineering fundamentals upon which current computer systems are based. Students will learn the ARMv7/8-A instruction set, addressing modes, integrated peripheral input/output (I/O) devices and machine level data representations for the Cortex A53 CPU.Students will learn embedded systems concepts, such as boot configuration, kernel development, memory utilization, hardware and microcode controllers. Students will learn optimization in performance of embedded systems by  writing interrupt handlers, enforcing protection for critical code sections, and using limited stack memory. Students will learn optimization in software design by utilizing minimization strategies.
The labs in CMPE 240 are run on a Raspberry Pi 3 and each Makefile for each lab builds a .img file that runs on the Pi 3.

## OS Boot and Initial Lab Setup
1. Download and unzip Raspbian Jessie latest in a temporary location
2. Plug the microSD car reader into your machine and insert the microSD card
3. Image the mircoSD card with the Raspian image
4. Eject the microSD card and insert it into the microSD port on the Pi 3
5. Connect your monitor to the HDMI port on the Pi 3
6. Plug in the Pi 3 to your power supply
Your Pi 3 should now boot the Raspian Jessie OS.
7. Disconnect the Pi 3 from it's power supply and then remove the microSD card from the Pi 3
8. Insert the microSD card back into your PC
9. On the microSD card, rename "kernel.img" to "kernel.org" and "kernel7.img" to "kernel7.org"
Now every .img kernel made by the Makefile in the lab can be dragged and dropped onto the microSD card.

## Labs
### Lab 1 Blinky
The first lab and is designed to familiarize the student with the build environment and tools used in the lab. The objective of this lab is to make an LED connected to the GPIO pins to blink on and off (Note: A external LED and circuit board was used and the setup is not included in this README)
