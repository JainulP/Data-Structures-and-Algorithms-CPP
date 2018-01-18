################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MoneyMarketAccount.cpp \
../src/TesterMoneyMarketAccount.cpp \
../src/TesterTrafficLight.cpp \
../src/TrafficLight.cpp \
../src/prob1ut.cpp \
../src/prob2ut.cpp 

OBJS += \
./src/MoneyMarketAccount.o \
./src/TesterMoneyMarketAccount.o \
./src/TesterTrafficLight.o \
./src/TrafficLight.o \
./src/prob1ut.o \
./src/prob2ut.o 

CPP_DEPS += \
./src/MoneyMarketAccount.d \
./src/TesterMoneyMarketAccount.d \
./src/TesterTrafficLight.d \
./src/TrafficLight.d \
./src/prob1ut.d \
./src/prob2ut.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


