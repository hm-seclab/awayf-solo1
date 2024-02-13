#ifndef _AWAYF_H_H
#define _AWAYF_H_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cbor.h"

#define CTAP_CBOR_FEDERATION_ID 0x42

#define FM_cmd 0x01
#define FM_pinProtocol 0x02
#define FM_pinAuth 0x03

#define FM_cmdIdPBegin 0x01
#define FM_cmdIdPNext 0x02

typedef struct
{
    int cmd;

    struct {
        uint8_t cmd;
        uint8_t subCommandParamsCborCopy[sizeof(CTAP_credentialDescriptor) + 16];
    } hashed;
    uint32_t subCommandParamsCborSize;

    uint8_t pinAuth[16];
    uint8_t pinAuthPresent;
    int pinProtocol;
} CTAP_fedMgmt;

uint8_t ctap_fed_mgmt(CborEncoder * encoder, uint8_t * request, int length);

#endif
