#!/bin/bash

make all

qemu-system-i386 -drive file=bin/kernel.bin,format=raw -display sdl &ls -l bin/kernel.bin &

