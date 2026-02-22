#include <console.h>
#include <io.h>

void kio_putc(char c) {
    if (c == '\n') console.putc('\r');
    console.putc(c);
}

void kio_puts(const char *s) {
    while (*s) kio_putc(*s++);
}

char kio_getc(void) {
    return console.getc();
}

void kio_gets(char *buf, int max) {
    int i = 0;
    char c;

    while (i < max - 1) {
        c = kio_getc();

        if (c == '\r' || c == '\n') break;

        if (c == '\x7f' || c == '\x08') {
            if (i > 0) {
                i--;
                kio_puts("\x08 \x08");
            }
            continue;
        }
        buf[i++] = c;
    }
    buf[i] = '\0';
}
