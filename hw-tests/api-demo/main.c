#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "card10.h"
#include "tmr_utils.h"
#include "api.h"

void Core1_Start(void) {
    //MXC_GCR->gp0 = (uint32_t)(&__isr_vector_core1);
    MXC_GCR->gp0 = 0x10040000;
    MXC_GCR->perckcn1 &= ~MXC_F_GCR_PERCKCN1_CPU1;
}

void Core1_Stop(void) {
    MXC_GCR->perckcn1 |= MXC_F_GCR_PERCKCN1_CPU1;
}

int main(void)
{
    int count = 0;
    led_color_t red = {0x10, 0, 0};

    card10_init();
    card10_diag();

    printf("API Test.\n");
    printf("core0: Starting dispatcher on core1\n");
    Core1_Start();
    TMR_Delay(MXC_TMR0, MSEC(100), 0);

    api_set_buzzer(1);
    TMR_Delay(MXC_TMR0, MSEC(300), 0);
    api_set_buzzer(0);
    api_set_led(5, red);
    api_test(0xAB, 0x7DEF, 0x01, 0x02);

    while(1) {
        printf("count = %d\n", count++);

        TMR_Delay(MXC_TMR0, SEC(1), 0);
    }
}