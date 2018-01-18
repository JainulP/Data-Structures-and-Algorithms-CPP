################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RomanNumerals.cpp \
../src/RomanNumeralsTest.cpp 

OBJS += \
./src/RomanNumerals.o \
./src/RomanNumeralsTest.o 

CPP_DEPS += \
./src/RomanNumerals.d \
./src/RomanNumeralsTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


