################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../onewire/OneWire.cpp 

LINK_OBJ += \
./onewire/OneWire.cpp.o 

CPP_DEPS += \
./onewire/OneWire.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
onewire/OneWire.cpp.o: C:/Users/Arnthor/Dropbox/FS2016/workspace/tempRef/onewire/OneWire.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\bin\eclipseArduino\arduinoPlugin\tools\arduino\avr-gcc\4.8.1-arduino5/bin/avr-g++" -c -g -Os -std=gnu++11 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10606 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"C:\bin\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\cores\arduino" -I"C:\bin\eclipseArduino\arduinoPlugin\packages\arduino\hardware\avr\1.6.10\variants\eightanaloginputs" -I"C:\Users\Arnthor\Dropbox\FS2016\workspace\tempRef\onewire" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


