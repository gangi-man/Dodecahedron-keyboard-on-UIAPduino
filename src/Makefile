
TARGET:=pentagon-key

ADDITIONAL_C_FILES+=key-input.c ../rv003usb/rv003usb/rv003usb.S ../rv003usb/rv003usb/rv003usb.c
EXTRA_CFLAGS:=-I../rv003usb/lib -I../rv003usb/rv003usb

TARGET_MCU?=CH32V003
include ../rv003usb/ch32fun/ch32fun/ch32fun.mk


flash : cv_flash
clean : cv_clean

