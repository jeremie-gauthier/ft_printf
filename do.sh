#!/bin/sh

make
gcc maintest.c libftprintf.a
./a.out
