################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Node.cpp \
../src/SortedList.cpp \
../src/SortedVector.cpp \
../src/TestSuite.cpp \
../src/Week9Assignment.cpp 

OBJS += \
./src/Node.o \
./src/SortedList.o \
./src/SortedVector.o \
./src/TestSuite.o \
./src/Week9Assignment.o 

CPP_DEPS += \
./src/Node.d \
./src/SortedList.d \
./src/SortedVector.d \
./src/TestSuite.d \
./src/Week9Assignment.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


