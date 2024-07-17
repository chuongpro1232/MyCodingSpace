#--------------------------------------Makefile-------------------------------------

CFILES = $(wildcard ./src/*.c)
#CFILES = "./src/kernel.c"

OFILES = $(CFILES:./src/%.c=./build/%.o) 
#OFILES = "./build/kernel.o"

GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib #later it will add chosen uart
LDFLAGS = -nostdlib # we make it a var, not directly put like previous.

all: clean ./build/uart.o kernel8.img run ##if you put uart in a seperated file, make it run here

./build/boot.o: ./src/boot.S 
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./src/boot.S -o ./build/boot.o 
	@echo --------- boot.o is built !!! ---------

./build/uart.o: ./src/uart/uart0.c #if you put uart in a seperated file, use this + specify the dependency
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./src/uart/uart0.c -o $@
	@echo --------- uart is built !!! ---------

./build/%.o: ./src/%.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@
	@echo --------- .o is built !!! ---------

kernel8.img: ./build/boot.o $(OFILES)
	aarch64-none-elf-ld $(LDFLAGS) ./build/boot.o ./build/uart.o $(OFILES) -T ./src/link.ld -o ./build/kernel8.elf
	@echo --------- kernel.8.elf is built !!! ---------
	aarch64-none-elf-objcopy -O binary ./build/kernel8.elf kernel8.img
	@echo --------- kernel.8.img is built !!! ---------
#If you use uart in a seperated folder, put ./build/uart.o in to build kernel8.elf

clean:
	del .\build\kernel8.elf .\build\*.o *.img

# Run emulation with QEMU
run:
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial stdio
	