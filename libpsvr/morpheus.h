/*
 * Copyright (C) 2016 Adawarp Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define MORPHEUS_VID		0x054c
#define MORPHEUS_PID		0x09af

enum morpheus_usb_configurations {
	MORPHEUS_CONFIGURATION_PSVR = 1
};

enum morpheus_usb_interfaces {
	PSVR_INTERFACE_AUDIO_3D = 0,
	PSVR_INTERFACE_AUDIO_CONTROL = 1,
	PSVR_INTERFACE_AUDIO_MIC = 2,
	PSVR_INTERFACE_AUDIO_CHAT = 3,
	PSVR_INTERFACE_HID_SENSOR = 4,
	PSVR_INTERFACE_HID_CONTROL = 5,
	PSVR_INTERFACE_VS_H264 = 6,
	PSVR_INTERFACE_VS_BULK_IN = 7,
	PSVR_INTERFACE_HID_CONTROL2 = 8
};

#define ENDPOINT_IN 0x80;

#pragma pack(1)
struct morpheus_control_command_header {
	uint8_t id;
	uint8_t status;
	uint8_t magic;
	uint8_t length;
};

#define MORPHEUS_COMMAND_HEADER_SIZE (sizeof (struct morpheus_control_command_header))

struct morpheus_control_command {
	struct morpheus_control_command_header header;
	uint8_t payload[64 - MORPHEUS_COMMAND_HEADER_SIZE];
};
#pragma pack()