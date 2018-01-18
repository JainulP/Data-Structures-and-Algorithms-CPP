################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AvlTree.cpp \
../src/BSTApp.cpp \
../src/BinaryNode.cpp \
../src/BinarySearchTree.cpp \
../src/BinaryTreeChecker.cpp \
../src/BinaryTreePrinter.cpp 

OBJS += \
./src/AvlTree.o \
./src/BSTApp.o \
./src/BinaryNode.o \
./src/BinarySearchTree.o \
./src/BinaryTreeChecker.o \
./src/BinaryTreePrinter.o 

CPP_DEPS += \
./src/AvlTree.d \
./src/BSTApp.d \
./src/BinaryNode.d \
./src/BinarySearchTree.d \
./src/BinaryTreeChecker.d \
./src/BinaryTreePrinter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


