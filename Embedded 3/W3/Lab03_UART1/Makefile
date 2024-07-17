#--------------------------------------Makefile-------------------------------------
CFILES = $(wildcard ./src/*.c)
#./src/kerna\el.c

OFILES = $(CFILES:./src/%.c=./build/%.o)
#./build/kernel.o

GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib
LDFLAGS = -nostdlib

all: clean kernel8.img
#define uart1/uart0

# uart0
#uart0

ifdef UART0
UARTTYPE = 0
else #UART1
UARTTYPE = 1
endif

GCCFLAGS += -DUART$(UARTTYPE)
#-Dvar is to add variable to define for exp the above will add #define UART1(or #define UART0 depend on the value)

./build/boot.o: ./src/boot.S
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

./build/uart.o: 
	aarch64-none-elf-gcc $(GCCFLAGS) -c ./src/uart/uart$(UARTTYPE).c -o $@

./build/%.o: ./src/%.c
	aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: ./build/boot.o ./build/uart.o $(OFILES)
	@echo UART$(UARTTYPE) IS BUILDING !!!
	aarch64-none-elf-ld $(LDFLAGS) ./build/boot.o ./build/uart.o $(OFILES) -T ./src/link.ld -o ./build/kernel8.elf
	aarch64-none-elf-objcopy -O binary ./build/kernel8.elf kernel8.img

clean:
	del .\build\*.elf .\build\*.o *.img

run:
ifdef UART0
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial stdio
else #UART1
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial null -serial stdio
endif