#include"tlv.h"

uint8_t EncodedBuffer[1024];
char data[] = "Hey Mano";

char decodeddata[15];
tlvEncode_t tlv;
tlvDecode_t decodeTlv;
int main(void){
    tlv.data = (void *)data;
    tlv.dataLen = strlen(data);
    tlv.ID = 10;
    tlv.pBuffer = EncodedBuffer;


    if ( tlvEncode(&tlv) != 0 ) {
        printf("Encoding was Failed\n");
        return -1;
    }

    decodeTlv.pDataBuffer = decodeddata;
    if( tlvDecode((void *)&EncodedBuffer,&decodeTlv) != 0 ) {
        printf("Decoding was Failed\n");
        return -1;
    }

    printf("Decode Message was %s \n", decodeTlv.pDataBuffer);

    return 0;
}