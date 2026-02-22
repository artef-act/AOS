#include <io.h>

int main(void) {
    char buf[64];

    while (1) {
        kio_puts("> ");
        kio_gets(buf, sizeof(buf));
        kio_puts(buf);
        kio_putc('\n');
    }
}
