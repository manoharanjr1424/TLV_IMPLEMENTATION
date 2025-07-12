#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

typedef struct {
    uint8_t ID;
    uint8_t *pBuffer;
    void *data;
    uint32_t dataLen;
}tlvEncode_t;


typedef struct {
    uint8_t ID;
    uint8_t *pDataBuffer;
    uint32_t dataLen;
}tlvDecode_t;


int8_t tlvEncode(tlvEncode_t *pEncodeObj);
int8_t tlvDecode(void *pEncodedBuffer,tlvDecode_t *pDecodedObj);
