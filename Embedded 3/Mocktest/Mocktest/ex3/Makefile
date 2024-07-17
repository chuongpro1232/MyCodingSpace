#--------------------------------------Makefile-------------------------------------

CFILES = $(wildcard ./src/*.c)
OFILES = $(CFILES:./src/%.c=./obj/%.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib

all: clean kernel8.img

RPI ?= 3
UART ?= 0

# ifeq ($(RPI), 3)
#     ifeq ($(UART), 0)
# 		run1:
# 	else
# 		run2:
# 	endif
# else ifeq ($(RPI), 4)
#     ifeq ($(UART), 0)
# 		run3:
# 	else
# 		run4:
# 	endif
# endif

uart1_build: ./serial/uart1.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./uart/uart1.c -o ./obj/uart.o

uart0_build: ./serial/uart0.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./uart/uart0.c -o ./obj/uart.o

./obj/boot.o: ./src/boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./src/boot.S -o ./obj/boot.o

./obj/%.o: ./src/%.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: ./obj/boot.o $(OFILES)
	aarch64-none-elf-ld -nostdlib ./obj/boot.o $(OFILES) -T ./inc/link.ld -o ./obj/kernel8.elf
	aarch64-none-elf-objcopy -O binary ./obj/kernel8.elf kernel8.img

clean:
	del .\obj\kernel8.elf .\obj\*.o *.img

# Run emulation with QEMU
run1: clean uart0_build kernel8.img
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial stdio
run2: clean uart1_build kernel8.img 
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial null -serial stdio
run3: clean uart0_build kernel8.img 
	qemu-system-aarch64 -M raspi4 -kernel kernel8.img -serial stdio
run4: clean uart1_build kernel8.img
	qemu-system-aarch64 -M raspi4 -kernel kernel8.img -serial null -serial stdio