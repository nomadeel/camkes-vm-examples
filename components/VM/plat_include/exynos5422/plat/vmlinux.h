/*
 * Copyright 2019, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */
#pragma once

#define LINUX_RAM_BASE    0x40000000
#define LINUX_RAM_PADDR_BASE LINUX_RAM_BASE
#define LINUX_RAM_SIZE    0x20000000
#define LINUX_RAM_OFFSET  0
#define DTB_ADDR          (LINUX_RAM_BASE + 0x0F000000)
#define INITRD_MAX_SIZE   0x1900000 //25 MB
#define INITRD_ADDR       (DTB_ADDR - INITRD_MAX_SIZE) //0x4D700000

#define IRQ_SPI_OFFSET 32

static const int linux_pt_irqs[] = {
    27, // VTCNT
};

static const int free_plat_interrupts[] =  { 92 + IRQ_SPI_OFFSET,
                                             93 + IRQ_SPI_OFFSET,
                                             101 + IRQ_SPI_OFFSET,
                                             102 + IRQ_SPI_OFFSET
                                           };
static const char *plat_keep_devices[] = {
    "/cpus/cpu@0",
    "/fixed-rate-clocks/oscclk",
    "/timer",
};
static const char *plat_keep_device_and_disable[] = {};
static const char *plat_keep_device_and_subtree[] = {};
static const char *plat_keep_device_and_subtree_and_disable[] = {};
static const char *plat_linux_bootcmdline =
    "console=ttySAC2,115200n8 root=/dev/ram0 nosmp rw debug loglevel=8 earlyprintk=serial pci=nomsi";
static const char *plat_linux_stdout = "serial2:115200n8";
