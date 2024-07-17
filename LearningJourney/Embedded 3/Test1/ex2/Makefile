#--------------------------------------Makefile-------------------------------------

CFILES = $(wildcard ./kernel/*.c)
OFILES = $(CFILES:./kernel/%.c=./objects/%.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib

all: clean uart1_build kernel8.img run1

uart1: clean uart1_build ./objects/kernel8.img run1
uart0: clean uart0_build ./objects/kernel8.img run0

uart1_build: ./peripheral/uart1.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./peripheral/uart1.c -o ./objects/uart.o

uart0_build: ./peripheral/uart0.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./peripheral/uart1.c -o ./objects/uart.o


./objects/boot.o: ./kernel/boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./kernel/boot.S -o ./objects/boot.o

./objects/%.o: ./kernel/%.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

./objects/gpio.o: ./peripheral/gpio.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./peripheral/gpio.c -o ./objects/gpio.o

./objects/kernel8.img: ./objects/boot.o ./objects/uart.o ./objects/gpio.o $(OFILES)
	aarch64-none-elf-ld -nostdlib ./objects/boot.o ./objects/uart.o ./objects/gpio.o $(OFILES) -T ./kernel/link.ld -o ./objects/kernel8.elf
	aarch64-none-elf-objcopy -O binary ./objects/kernel8.elf ./objects/kernel8.img

clean:
	del .\objects\kernel8.elf .\objects\*.o .\objects\*.img

# Run emulation with QEMU
run0: 
	qemu-system-aarch64 -M raspi3 -kernel ./objects/kernel8.img -serial stdio
run1:
	qemu-system-aarch64 -M raspi3 -kernel ./objects/kernel8.img -serial null -serial stdio