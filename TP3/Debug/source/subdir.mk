################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Controller.c \
../source/Employee.c \
../source/Menu.c \
../source/getFunctions.c \
../source/main.c \
../source/parser.c \
../source/terminalFunctions.c 

OBJS += \
./source/Controller.o \
./source/Employee.o \
./source/Menu.o \
./source/getFunctions.o \
./source/main.o \
./source/parser.o \
./source/terminalFunctions.o 

C_DEPS += \
./source/Controller.d \
./source/Employee.d \
./source/Menu.d \
./source/getFunctions.d \
./source/main.d \
./source/parser.d \
./source/terminalFunctions.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


