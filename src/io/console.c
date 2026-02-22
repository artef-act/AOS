#include <console.h>
#include <htif.h>

struct console_ops console;

void console_init(void) {
    console_htif_init();
}
