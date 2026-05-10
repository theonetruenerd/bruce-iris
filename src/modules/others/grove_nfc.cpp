//
// Created by tarun on 09/05/2026.
//

#include "grove_nfc.h"
#include "PN532/PN532_HSU/PN532_HSU.h"
#include "core/display.h"
#include "globals.h"
#include <NfcAdapter.h>

// This currently just reads. Broken due to PN532 clash with pre-existing module.

void nfcApp() {
    PN532_HSU pn532hsu(Serial1);
    NfcAdapter nfc(pn532hsu);
    nfc.begin();

    bool endApp = false;

    while (!endApp) {
        if (nfc.tagPresent()) {
            NfcTag tag = nfc.read();
            tag.print();
            displayInfo(tag.getTagType());
        }
        if (check(AnyKeyPress)) {
            endApp = true;
        }
    }
}