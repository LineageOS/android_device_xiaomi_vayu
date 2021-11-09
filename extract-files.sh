#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# If we're being sourced by the common script that we called,
# stop right here. No need to go down the rabbit hole.
if [ "${BASH_SOURCE[0]}" != "${0}" ]; then
    return
fi

set -e

export DEVICE=vayu
export DEVICE_COMMON=sm8150-common
export VENDOR=xiaomi

function blob_fixup() {
    case "${1}" in
    vendor/lib64/hw/camera.qcom.so)
        patchelf --remove-needed "libmegface.so" "${2}"
        patchelf --remove-needed "libMegviiFacepp-0.5.2.so" "${2}"
        patchelf --add-needed "libshim_megvii.so" "${2}"
        ;;
    esac
}

"./../../${VENDOR}/${DEVICE_COMMON}/extract-files.sh" "$@"
