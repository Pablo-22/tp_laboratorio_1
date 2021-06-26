################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/ArrayEmployees.c \
../source/Córdoba_TP2.c \
../source/GetFunctions.c \
../source/Menu.c \
../source/TerminalFunctions.c 

OBJS += \
./source/ArrayEmployees.o \
./source/Córdoba_TP2.o \
./source/GetFunctions.o \
./source/Menu.o \
./source/TerminalFunctions.o 

C_DEPS += \
./source/ArrayEmployees.d \
./source/Córdoba_TP2.d \
./source/GetFunctions.d \
./source/Menu.d \
./source/TerminalFunctions.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


