#!/usr/bin/env python3
# jslist.py
#
# This little program just list the joysticks connected to the system.
# The ouput format is "index:JoystickName".
# It returns a non-zero value if no joystick was found; otherwise, zero.

import pygame

pygame.joystick.init()

num_joy = pygame.joystick.get_count()

if num_joy < 1:
    print("No joystick found!")
    pygame.joystick.quit()
    quit(-1)

for i in range(num_joy):
    print(i,":",pygame.joystick.Joystick(i).get_name(), sep="")

pygame.joystick.quit()
