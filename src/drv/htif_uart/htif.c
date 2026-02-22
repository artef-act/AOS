#include <stdint.h>
#include <console.h>
#include <htif.h>

#define HTIF_DEV_CONSOLE      1
#define HTIF_CONSOLE_CMD_GETC 0
#define HTIF_CONSOLE_CMD_PUTC 1

#define TOHOST_CMD(dev, cmd, payload) \
    (((uint64_t)(dev) << 56) | ((uint64_t)(cmd) << 48) | (uint64_t)(payload))

#define FROMHOST_DATA(x) ((x) & 0xFFFF)

volatile uint64_t tohost;
volatile uint64_t fromhost;

static void htif_putc(char c) {
    tohost = TOHOST_CMD(HTIF_DEV_CONSOLE, HTIF_CONSOLE_CMD_PUTC, c);
    while (tohost != 0);
}

static char htif_getc(void) {
    fromhost = 0;
    tohost = TOHOST_CMD(HTIF_DEV_CONSOLE, HTIF_CONSOLE_CMD_GETC, 0);
    while (fromhost == 0);

    char c = (char)FROMHOST_DATA(fromhost);

    fromhost = 0;
    tohost   = 0;

    return c;
}

void console_htif_init(void) {
    console.putc = htif_putc;
    console.getc = htif_getc;
}
