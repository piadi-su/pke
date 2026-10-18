#!/bin/bash

make all

qemu-system-i386 -drive file=bin/bottom.bin,format=raw -display sdl &ls -l bin/bottom.bin &
