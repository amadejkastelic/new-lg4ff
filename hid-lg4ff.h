/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __HID_LG4FF_H
#define __HID_LG4FF_H

#include <linux/hid.h>

#ifdef CONFIG_LOGIWHEELS_FF
/* Function declarations for when CONFIG_LOGIWHEELS_FF is enabled */
int lg4ff_init(struct hid_device *hdev);
int lg4ff_deinit(struct hid_device *hdev);
void lg4ff_handle_multimode_wheel(struct hid_device *hid, u16 bcdDevice, const u8 *rd, unsigned int rsize);
int lg4ff_adjust_input_event(struct hid_device *hid, struct hid_field *field,
                             struct hid_usage *usage, s32 value, struct lg_drv_data *drv_data);
int lg4ff_raw_event(struct hid_device *hdev, struct hid_report *report,
                    u8 *rd, int size, struct lg_drv_data *drv_data);
#else
/* Stub functions when CONFIG_LOGIWHEELS_FF is disabled */
static inline int lg4ff_init(struct hid_device *hdev) { return -1; }
static inline int lg4ff_deinit(struct hid_device *hdev) { return -1; }
static inline void lg4ff_handle_multimode_wheel(struct hid_device *hid, u16 bcdDevice, const u8 *rd, unsigned int rsize) { }
static inline int lg4ff_adjust_input_event(struct hid_device *hid, struct hid_field *field,
                                          struct hid_usage *usage, s32 value, struct lg_drv_data *drv_data) { return 0; }
static inline int lg4ff_raw_event(struct hid_device *hdev, struct hid_report *report,
                                  u8 *rd, int size, struct lg_drv_data *drv_data) { return 0; }
#endif

#endif /* __HID_LG4FF_H */
