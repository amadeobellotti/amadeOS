#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/keyboard.h>
#include <kernel/paging.h>
#include <kernel/kheap.h>

void kernel_early(void)
{
	terminal_initialize();
	
	init_gdt();
	init_idt();
	init_paging();
	init_keyboard();

	// Allow interrupts
	asm volatile ("sti");
}
void testpage(){
	uint32_t a = malloc(8);

	uint32_t b = malloc(8);
	uint32_t c = malloc(8);
	printf("a: %x, b: %x\n",a,b);
	printf("c: %x",c);


	kfree(c);
	kfree(b);
	uint32_t d = malloc(12);
	printf(",d: %x\n",d);
}

void kernel_main(void)
{
	printf("Hello, kernel World!\nTest\n");
	
	
}
