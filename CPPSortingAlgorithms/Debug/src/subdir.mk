################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CPPSortingAlgorithms.cpp \
../src/DataAllZeroes.cpp \
../src/DataGenerator.cpp \
../src/DataRandom.cpp \
../src/DataReverseSorted.cpp \
../src/DataSorted.cpp \
../src/Element.cpp \
../src/InsertionSort.cpp \
../src/LinkedList.cpp \
../src/ListSorter.cpp \
../src/MergeSort.cpp \
../src/Node.cpp \
../src/QuickSortOptimal.cpp \
../src/QuickSortSubOptimal.cpp \
../src/QuickSorter.cpp \
../src/SelectionSort.cpp \
../src/ShellSortOptimal.cpp \
../src/ShellSortSubOptimal.cpp \
../src/SortTests.cpp \
../src/Sorter.cpp \
../src/VectorSorter.cpp 

OBJS += \
./src/CPPSortingAlgorithms.o \
./src/DataAllZeroes.o \
./src/DataGenerator.o \
./src/DataRandom.o \
./src/DataReverseSorted.o \
./src/DataSorted.o \
./src/Element.o \
./src/InsertionSort.o \
./src/LinkedList.o \
./src/ListSorter.o \
./src/MergeSort.o \
./src/Node.o \
./src/QuickSortOptimal.o \
./src/QuickSortSubOptimal.o \
./src/QuickSorter.o \
./src/SelectionSort.o \
./src/ShellSortOptimal.o \
./src/ShellSortSubOptimal.o \
./src/SortTests.o \
./src/Sorter.o \
./src/VectorSorter.o 

CPP_DEPS += \
./src/CPPSortingAlgorithms.d \
./src/DataAllZeroes.d \
./src/DataGenerator.d \
./src/DataRandom.d \
./src/DataReverseSorted.d \
./src/DataSorted.d \
./src/Element.d \
./src/InsertionSort.d \
./src/LinkedList.d \
./src/ListSorter.d \
./src/MergeSort.d \
./src/Node.d \
./src/QuickSortOptimal.d \
./src/QuickSortSubOptimal.d \
./src/QuickSorter.d \
./src/SelectionSort.d \
./src/ShellSortOptimal.d \
./src/ShellSortSubOptimal.d \
./src/SortTests.d \
./src/Sorter.d \
./src/VectorSorter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


