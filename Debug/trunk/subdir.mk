################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../trunk/arbre.c \
../trunk/fonctionInterface.c \
../trunk/fonction_evaluation.c \
../trunk/main.c \
../trunk/min-max.c \
../trunk/moteur.c \
../trunk/plateau.c \
../trunk/regles.c 

OBJS += \
./trunk/arbre.o \
./trunk/fonctionInterface.o \
./trunk/fonction_evaluation.o \
./trunk/main.o \
./trunk/min-max.o \
./trunk/moteur.o \
./trunk/plateau.o \
./trunk/regles.o 

C_DEPS += \
./trunk/arbre.d \
./trunk/fonctionInterface.d \
./trunk/fonction_evaluation.d \
./trunk/main.d \
./trunk/min-max.d \
./trunk/moteur.d \
./trunk/plateau.d \
./trunk/regles.d 


# Each subdirectory must supply rules for building sources it contributes
trunk/%.o: ../trunk/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


