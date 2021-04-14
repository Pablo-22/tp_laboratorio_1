################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Menu.c \
../source/Operations.c \
../source/Show.c \
../source/Validations.c \
../source/tp_laboratorio_1.c 

OBJS += \
./source/Menu.o \
./source/Operations.o \
./source/Show.o \
./source/Validations.o \
./source/tp_laboratorio_1.o 

C_DEPS += \
./source/Menu.d \
./source/Operations.d \
./source/Show.d \
./source/Validations.d \
./source/tp_laboratorio_1.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


