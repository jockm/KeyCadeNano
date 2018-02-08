/*********************************************************************
* Filename:   base64.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding Base64 implementation.
*********************************************************************/

#ifndef BASE64_H
#define BASE64_H

/*************************** HEADER FILES ***************************/
#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*********************** FUNCTION DECLARATIONS **********************/
// Returns the size of the output. If called with out = NULL, will just return
// the size of what the output would have been (without a terminating NULL).
uint16_t b64Encode(const uint8_t in[], uint8_t out[], uint16_t len, int newline_flag);

// Returns the size of the output. If called with out = NULL, will just return
// the size of what the output would have been (without a terminating NULL).
uint16_t b64Decode(const uint8_t in[], uint8_t out[], uint16_t len);

#ifdef __cplusplus
}
#endif

#endif   // BASE64_H
