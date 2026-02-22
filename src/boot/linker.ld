ENTRY(_start)

MEMORY {
    RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 128M
}

SECTIONS {
    . = 0x80000000;

    .text : {
        *(.text.entry)
        *(.text*)
    } > RAM

    .rodata : { *(.rodata*) } > RAM
    .data   : { *(.data*)   } > RAM

    .tohost : {
        . = ALIGN(8);
        PROVIDE(tohost   = .); . += 8;
        PROVIDE(fromhost = .); . += 8;
    } > RAM

    .bss : { *(.bss*) } > RAM

    _end = .;
}