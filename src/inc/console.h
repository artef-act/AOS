#ifndef CONSOLE_H
#define CONSOLE_H

extern struct console_ops {
    void (*putc)(char);
    char (*getc)(void);
} console;

void console_init(void);
#endif
