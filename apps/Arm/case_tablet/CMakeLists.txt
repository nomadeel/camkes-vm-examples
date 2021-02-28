#
# Copyright 2020, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

cmake_minimum_required(VERSION 3.8.2)

project(case-tablet C)

include(${CAMKES_ARM_VM_HELPERS_PATH})

find_package(camkes-vm-linux REQUIRED)
include(${CAMKES_VM_LINUX_HELPERS_PATH})
set(cpp_flags "-DKERNELARMPLATFORM_EXYNOS5422")

AddToFileServer("linux" "${CAMKES_VM_IMAGES_DIR}/exynos5422/case_tablet/linux")
# Generate overlayed rootfs
set(rootfs_file "${CAMKES_VM_IMAGES_DIR}/exynos5422/case_tablet/rootfs.cpio.gz")
AddToFileServer("linux-initrd" ${rootfs_file})
# Updated dtb based on initrd
UpdateDtbFromInitrd(
    "${CAMKES_VM_IMAGES_DIR}/exynos5422/case_tablet/linux-dtb"
    ${rootfs_file}
    "0x4d700000"
    dtb_gen_target
    output_dtb_location
)
AddToFileServer("linux-dtb" "${output_dtb_location}" DEPENDS dtb_gen_target)

AddCamkesCPPFlag(cpp_flags CONFIG_VARS VmEmmc2NoDMA VmVUSB)

DefineCAmkESVMFileServer()

CAmkESAddImportPath(${KernelARMPlatform})

# Declare root server
DeclareCAmkESRootserver(
    case_tablet.camkes
    CPP_FLAGS
    ${cpp_flags}
    CPP_INCLUDES
    ${CAMKES_VM_DIR}/components/VM_Arm
)
