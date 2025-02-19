#ifndef SYS__SMP_H__
#define SYS__SMP_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mm/vmm.h>
#define LIMINE_NO_POINTERS
#include <limine.h>

#if defined (__x86_64__) || defined (__i386__)

struct limine_mp_info *init_smp(size_t   *cpu_count,
                                 uint32_t *_bsp_lapic_id,
                                 int       paging_mode,
                                 pagemap_t pagemap,
                                 bool      x2apic,
                                 bool      nx,
                                 uint64_t  hhdm,
                                 bool      wp);

#elif defined (__aarch64__)

struct limine_mp_info *init_smp(const char *config,
                                 size_t   *cpu_count,
                                 uint64_t *bsp_mpidr,
                                 pagemap_t pagemap,
                                 uint64_t  mair,
                                 uint64_t  tcr,
                                 uint64_t  sctlr,
                                 uint64_t  hhdm_offset);

#elif defined (__riscv)

struct limine_mp_info *init_smp(size_t   *cpu_count,
                                 pagemap_t pagemap,
                                 uint64_t  hhdm_offset);

#elif defined (__loongarch64)
#else
#error Unknown architecture
#endif

#endif
