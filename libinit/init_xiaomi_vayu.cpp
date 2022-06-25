/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

#define FINGERPRINT "POCO/vayu_global/vayu:12/RKQ1.200826.002/V13.0.4.0.SJUMIXM:user/release-keys"

static const variant_info_t vayu_global_info = {
    .hwc_value = "GLOBAL",
    .sku_value = "",

    .brand = "POCO",
    .device = "vayu",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SG",
    .build_fingerprint = FINGERPRINT,

    .nfc = NFC_TYPE_NFC,
};

static const variant_info_t vayu_eea_info = {
    .hwc_value = "EEA",
    .sku_value = "",

    .brand = "POCO",
    .device = "vayu",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SG",
    .build_fingerprint = FINGERPRINT,

    .nfc = NFC_TYPE_NFC,
};

static const variant_info_t bhima_info = {
    .hwc_value = "INDIA",
    .sku_value = "",

    .brand = "POCO",
    .device = "bhima",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SI",
    .build_fingerprint = FINGERPRINT,

    .nfc = NFC_TYPE_NONE,
};

static const std::vector<variant_info_t> variants = {
    vayu_global_info,
    vayu_eea_info,
    bhima_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);
}
