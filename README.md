# Dragonw1nd Kernel Kit

This repo houses manifests, scripts, binaries, patches, build configs and prebuilt files for [Dragonw1nd CI](https://github.com/nullptr-t-oss/Dragonw1nd-Kernels)

## Repo Tree

```
.
|-- README.md                                           -- Readme file for this repo
|-- bin
|   `-- *                                               -- prebuilt binaries used in CI
|-- device
|   |-- generic
|   |   `-- *                                           -- generic files that can be used/inherited by any device
|   |-- salami-oos16                                    -- files for OnePlus 11 5G
|   |   |-- build_config
|   |   |   `-- build.config.salami.oos16               -- build config for OnePls 11 5G
|   |   |-- proprietary
|   |   |   `-- *                                       -- proprietary kernel modules
|   |   |-- system_dlkm
|   |   |   `-- etc
|   |   |       `-- build.prop                          -- system_dlkm extra file
|   |   |-- vendor_boot
|   |   |   |-- bootconfig                              -- vendor_boot bootconfig
|   |   |   |-- cmdline.txt                             -- vendor_boot cmdline
|   |   |   |-- dtb                                     -- vendor_boot dtb
|   |   |   |-- first_stage_ramdisk
|   |   |   |   `-- fstab.qcom                          -- vendor_boot fstab
|   |   |   |-- proprietary -> ../proprietary           -- symlink to proprietary kernel modules
|   |   |   |-- vendor_boot.modules.blocklist           -- vendor_boot modules blocklist file
|   |   |   |-- vendor_boot.modules.include             -- vendor_boot modules list
|   |   |   |-- vendor_boot.modules.load                -- vendor_boot modules load
|   |   |   `-- vendor_boot.modules.load.recovery       -- vendor_boot recovery modules load
|   |   `-- vendor_dlkm
|   |       |-- etc
|   |       |   `-- build.prop                          -- vendor_boot extra file
|   |       |-- proprietary -> ../proprietary           -- symlink to proprietary kernel modules
|   |       |-- system_dlkm.modules.blocklist           -- system_dlkm modules blocklist file
|   |       |-- vendor_dlkm.modules.blocklist           -- vendor_dlkm modules blocklist file
|   |       |-- vendor_dlkm.modules.include             -- vendor_dlkm modules list
|   |       |-- vendor_dlkm.modules.include.extra       -- vendor_dlkm extra modules list
|   |       |-- vendor_dlkm.modules.load                -- vendor_dlkm modules load
|   |       `-- vendor_dlkm.modules.load.extra          -- vendor_dlkm extra modules load
|   `-- * -> other device files
|-- kernel_manifest
|   |-- oneplus
|   |   `-- *                                           -- kernel manifest for oneplus devices
|   |-- scamsung
|   |   `-- *                                           -- kernel manifest for scamsung devices
|   `-- xiaomeme
|       `-- *                                           -- kernel manifest for xiaomeme devices
|-- kernel_patches
|   |-- backports
|   |   `-- *                                           -- backport patches
|   |-- generic
|   |   `-- *                                           -- generic patches
|   |-- salami-oos14
|   |   |-- common
|   |   |   |-- *                                       -- patches for ack of OnePlus 11 5G (OxygenOS 14)
|   |   `-- msm
|   |       `-- *                                       -- patches for msm-kernel of OnePlus 11 5G (OxygenOS 14)
|   `-- *                                               -- patches for other devices
|-- lib
|   `-- *                                               -- extra libs
|-- misc
|   |-- ak3
|   |   `-- *                                           -- extra misc ak3 stuff
|   |-- default_modules.txt                             -- deprecated stock modules list
|   `-- patches
|       `-- *                                           -- misc patches
`-- scripts
    `-- *                                               -- extra scripts
```