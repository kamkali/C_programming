#include <stdio.h>
#include "ring_buffer_unit_test.h"

int main()
{
    printf("Running ring buffer unit test...\n");
    if (true == RingBuffer_UnitTest()) {
        return 0;
    }

    return 1;
}
