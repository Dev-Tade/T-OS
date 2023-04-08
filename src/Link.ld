ENTRY(_start)

SECTIONS {
    /* bootloader code */
    . = 0x7c00;
    .text : { *(.text.bootloader) }

    /* kernel code */
    . = 0x1000;
    .text : { *(.text.kernel) }
    .data : { *(.data.kernel) }
    .bss : { *(.bss.kernel) }
}