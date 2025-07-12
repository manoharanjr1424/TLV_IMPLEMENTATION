#include "tlv.h"

int8_t tlvEncode(tlvEncode_t *pEncodeObj) {

   
    if( (pEncodeObj->data == NULL) || (pEncodeObj->dataLen <= 0)) {
        return -1;
    }

     uint8_t *pDataBuffer = (uint8_t *)pEncodeObj->data;
     uint32_t Index = 0;
    /*here I Implement the TLV in the [ID 1 Byte] [DATALEN 4 Byte] [ENCODED DATA]*/
    
    /* Store the Id in the 0th Index*/
    pEncodeObj->pBuffer[Index++] = pEncodeObj->ID;

    /*Storing the Len in the in the 4 Bytes*/
    pEncodeObj->pBuffer[Index++] = (uint8_t)((pEncodeObj->dataLen) & 0xFF);
    pEncodeObj->pBuffer[Index++] = (uint8_t)((pEncodeObj->dataLen >> 8) & 0xFF);
    pEncodeObj->pBuffer[Index++] = (uint8_t)((pEncodeObj->dataLen >> 16) & 0xFF);
    pEncodeObj->pBuffer[Index++] = (uint8_t)((pEncodeObj->dataLen >> 24) & 0xFF);

    uint32_t Itteration = 0;
    

    for(; Itteration < pEncodeObj->dataLen; ) {
        pEncodeObj->pBuffer[Index++] = pDataBuffer[Itteration++];
        pEncodeObj->pBuffer[Index++] = pDataBuffer[Itteration++];
        pEncodeObj->pBuffer[Index++] = pDataBuffer[Itteration++];
        pEncodeObj->pBuffer[Index++] = pDataBuffer[Itteration++];
        pEncodeObj->pBuffer[Index++] = pDataBuffer[Itteration++];
    }

    // for(int i = 0 ;i  < Index; i++ ){
    //     printf("0x%x ",pEncodeObj->pBuffer[i]);
    // }
   

    return 0;
}

int8_t tlvDecode(void *pEncodedBuffer,tlvDecode_t *pDecodedObj)
{


    if( (pEncodedBuffer == NULL) || (pDecodedObj == NULL) ) {
        printf("Decoding Failed \n");
        return -1;
    }

    uint32_t Index = 0;
    uint32_t Itteration = 0;

    uint8_t *pDataBuffer = (uint8_t *)pEncodedBuffer;
    pDecodedObj->ID = pDataBuffer[Index++];
    
    pDecodedObj->dataLen = 0;
    pDecodedObj->dataLen |= (uint32_t)pDataBuffer[Index++];
    pDecodedObj->dataLen |= ( ( (uint32_t)pDataBuffer[Index++]) << 8);
    pDecodedObj->dataLen |= ( ( (uint32_t)pDataBuffer[Index++]) << 16);
    pDecodedObj->dataLen |= ( ( (uint32_t)pDataBuffer[Index++]) << 24);

    if( pDecodedObj->dataLen <= 0 ) {
        printf("Data Length was Invalid \n");
        return -1;
    }

    while(Itteration < pDecodedObj->dataLen) {
        pDecodedObj->pDataBuffer[Itteration] = pDataBuffer[Index++];
        Itteration++;
    }

    // for(int i = 0 ;i  < Index; i++ ){
    //     printf("0x%x ",pDecodedObj->pDataBuffer[i]);
    // }
    return 0;
}
