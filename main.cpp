// PowerPC disassembler.

#include <stdio.h>

#include "commondefs.h"
#include "ppcd.h"

#define MODULE_NAME "ppcd"
#define MODULE_VER  0.04

static void usage(void)
{
    printf ("PPCD PowerPC Disassembler. Version %.2f\n", MODULE_VER);
    printf ("All rights reserved to org\n\n");
    printf ("Use: %s <binary file>\n", MODULE_NAME);
}

static u32 Swap32(u32 data)
{
    return ((data >> 24)             ) |
           ((data >>  8) & 0x0000ff00) |
           ((data <<  8) & 0x00ff0000) |
           ((data << 24)             );
}

int main (int argc, char **argv)
{
    PPCD_CB disa;
    FILE *f;
    u32 pc = 0x80000000, instr;

    if (argc <= 1)
    {
        usage ();
        return (0);
    }

    f = fopen (argv[1], "rb");
    if (f == NULL) return (0);

    while (!feof(f))
    {
        fread (&instr, 1, 4, f);

        disa.pc = pc;
        disa.instr = Swap32 (instr);
        PPCDisasm (&disa);
        
        printf ("%08X  %08X  %-12s%-30s\n", pc, instr, disa.mnemonic, disa.operands);
        pc += 4;
    }

    fclose (f);
    return (1);
}
