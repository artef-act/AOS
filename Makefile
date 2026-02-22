CROSS = riscv64-none-elf-gcc
CFLAGS = -nostdlib -nostartfiles -ffreestanding -O2 \
         -march=rv64imac -mabi=lp64 -mcmodel=medany \
		 -Isrc/inc
PK = /nix/store/0n1vfy9nnldf81wy3nmv4yq9vg6dsr5h-riscv-pk-riscv64-unknown-linux-gnu-1.0.0-unstable-2024-10-09/bin/pk

boot = -T src/boot/linker.ld \
	src/boot/start.s
src = src/main.c \
    src/io/console.c \
    src/io/io.c \
    src/drv/htif_uart/htif.c
bin = bin/main.elf

comp:
	$(CROSS) $(CFLAGS) $(boot) $(src) -o $(bin)

rund:
	spike -d $(bin)

run:
	spike $(bin)

clean:
	rm -f bin/*.elf
