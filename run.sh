#!/bin/bash

# //run.sh
make all

qemu-system-i386 -drive file=bin/pke.bin,format=raw -display sdl &ls -l bin/pke.bin &

