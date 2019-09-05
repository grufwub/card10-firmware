Outline:

- pressing button left / right cycles through other screens

- pressing buttons left + right together to enter screen settings if available

- pressing button select to toggle current screen functionality

- brightness control somehow

- screens:

	- digital clock -- allow setting

	- EKG monitor -- at first just display heart rate

	- flashlight

- files:

	- display.c/h --> handle display drawing (via framebuffer)

	- input.c/h --> handle button input logic

	- flashlight.c/h --> simple enable / disable flashlight logic

	- monitor.c/h --> read EKG data + convert to relevant heart data

	- clock.c/h --> handle time-keeping and time-setting logic

	- screens.c/h --> hold logic / loop for drawing each screen