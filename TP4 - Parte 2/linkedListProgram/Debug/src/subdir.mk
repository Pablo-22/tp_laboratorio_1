################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Employee.c \
../src/LinkedList.c \
../src/Menu.c \
../src/getFunctions.c \
../src/main.c \
../src/parser.c \
../src/terminalFunctions.c 

OBJS += \
./src/Controller.o \
./src/Employee.o \
./src/LinkedList.o \
./src/Menu.o \
./src/getFunctions.o \
./src/main.o \
./src/parser.o \
./src/terminalFunctions.o 

C_DEPS += \
./src/Controller.d \
./src/Employee.d \
./src/LinkedList.d \
./src/Menu.d \
./src/getFunctions.d \
./src/main.d \
./src/parser.d \
./src/terminalFunctions.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


