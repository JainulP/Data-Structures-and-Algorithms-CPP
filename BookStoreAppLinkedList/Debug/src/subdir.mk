################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Book.cpp \
../src/BookList.cpp \
../src/BookListsApp.cpp \
../src/BookNode.cpp 

OBJS += \
./src/Book.o \
./src/BookList.o \
./src/BookListsApp.o \
./src/BookNode.o 

CPP_DEPS += \
./src/Book.d \
./src/BookList.d \
./src/BookListsApp.d \
./src/BookNode.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


