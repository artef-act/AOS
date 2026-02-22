#ifndef IO_H
#define IO_H

void kio_putc(char c);
void kio_puts(const char *s);
char kio_getc(void);
void kio_gets(char *buf, int max);

#endif
