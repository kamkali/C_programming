/* Includes ------------------------------------------------------------------*/
#include <assert.h>
#include <string.h>

#include "ring_buffer.h"


bool RingBuffer_Init(RingBuffer *ringBuffer, char *dataBuffer, size_t dataBufferSize)
{
    assert(ringBuffer);
    assert(dataBuffer);
    assert(dataBufferSize > 0);

    if ((ringBuffer) && (dataBuffer) && (dataBufferSize > 0)) {
        ringBuffer->buf = dataBuffer;
        ringBuffer->head = 0;
        ringBuffer->tail = ringBuffer->head;
        ringBuffer->size = dataBufferSize;
        ringBuffer->len = 0;
        RingBuffer_Clear(ringBuffer);

        return true;
    }

    return false;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer)
{
    assert(ringBuffer);

    if (ringBuffer) {
        memset(ringBuffer->buf, 0, ringBuffer->size);
        ringBuffer->head = 0;
        ringBuffer->tail = ringBuffer->head;
        ringBuffer->len = 0;

        return true;
    }
    return false;
}

bool RingBuffer_IsEmpty(const RingBuffer *ringBuffer)
{
    assert(ringBuffer);

    return ringBuffer->len == 0 ? true : false;
}

size_t RingBuffer_GetLen(const RingBuffer *ringBuffer)
{
    assert(ringBuffer);

    if (ringBuffer) {
        return ringBuffer->len;
    }
    return 0;

}

size_t RingBuffer_GetCapacity(const RingBuffer *ringBuffer)
{
    assert(ringBuffer);

    if (ringBuffer) {
        return ringBuffer->size;
    }
    return 0;
}


bool RingBuffer_PutChar(RingBuffer *ringBuffer, char c)
{
    assert(ringBuffer);

    if (ringBuffer) {
        bool overflow = (ringBuffer->len >= ringBuffer->size);

        if (!overflow) {
            if (ringBuffer->head % ringBuffer->size == 0){
                ringBuffer->head = 0;
            }
            *(ringBuffer->buf + ringBuffer->head) = c;
            ringBuffer->head++;
            ringBuffer->len++;

            return true;
        }
    }
    return false;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, char *c)
{
    assert(ringBuffer);
    assert(c);

    if ((ringBuffer) && (c)) {
        if (!RingBuffer_IsEmpty(ringBuffer)) {
            *c = *(ringBuffer->buf + ringBuffer->tail);
            ringBuffer->tail = (ringBuffer->tail+1) % (ringBuffer->size);
            ringBuffer->len--;

            return true;
        }
    }
    return false;
}