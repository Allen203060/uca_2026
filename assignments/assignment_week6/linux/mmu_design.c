#include <stdio.h>
#include <stdint.h>

void address_translation(uint32_t virtual_address) {
    uint32_t pageNumber = 0;
    uint32_t pageOffset = 0;

    // 12-32 bits are the page number bits 
    pageNumber = virtual_address >> 12;

    // 0-11 bits are page offset number bits
    pageOffset = virtual_address & 0xFFF;

    printf("Address: 0x%08X -> Page: %u (0x%X), Offset: %u (0x%X)\n", virtual_address, pageNumber, pageNumber, pageOffset, pageOffset);
}

int main(void) {
    address_translation(0x00123456);
    
    address_translation(0x00001000);

    address_translation(0x00001FFF);

    address_translation(0x00000000);

    address_translation(0xFFFFFFFF);

    return 0;
}