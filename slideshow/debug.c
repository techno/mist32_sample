#include "common.h"
#include "debug.h"

unsigned int cpos;

void debug_init(void)
{
  cpos = 0;
}

void debug_putc(char c)
{
  display_putc(gci_nodes[GCI_DISPLAY_NUM].device_area, cpos++, c, 0xfff, 0x000);
}

void debug_puts(char *str)
{
  while(*str) {
    debug_putc(*(str++));
  }
}

void debug_put_uint(unsigned int value)
{
  int i;
  unsigned char c;

  debug_putc('0');
  debug_putc('x');

  for(i = 0; i < 8; i++) {
    c = (value & 0xf0000000) >> 28;
    
    if(c < 10) {
      debug_putc('0' + c);
    }
    else {
      debug_putc('A' + (c - 10));
    }
    
    value = (value & 0x0fffffff) << 4;
  }

  debug_putc(' ');
}
