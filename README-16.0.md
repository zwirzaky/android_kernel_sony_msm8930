# LineageOS 16.0 kernel — Sony Xperia L (taoshan)

This branch is the **working 3.4 kernel base** used by the LineageOS 16.0
bring-up:

- based on TeamButter `android_kernel_sony_msm8930`, branch `oreo`
  (commit `94995aaf349471f8a21dd22d8a0a3629e40ecf30`),
- `taoshan_defconfig` with `CONFIG_ANDROID_BINDER_IPC_32BIT=y`,
  `CONFIG_PRIMA_WLAN=y`, `CONFIG_WCNSS_CORE=y`, `CONFIG_SDCARD_FS=y`,
  SELinux/AUDIT/namespaces.

It boots Android 9, WiFi and Bluetooth work, sleep/wake works after the
device-tree sensor fix, and **USB ADB/MTP work through functionfs**
(`android.c` includes `f_fs.c`, the `ffs` function is aliased to `adb`,
and the device tree mounts functionfs).

## TODO

- deep-sleep/wakeup auditing,
- RIL/camera kernel side if needed.

## Build

The device tree `device/sony/taoshan` (branch `lineage-16.0-bringup`) has
`TARGET_KERNEL_SOURCE := kernel/sony/msm8930`,
`TARGET_KERNEL_CONFIG := taoshan_defconfig`.
