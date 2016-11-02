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

typedef struct psvr_context psvr_context;

#pragma pack(1)
struct psvr_sensor_frame {
	struct {
	 	uint8_t reserved:1;
	 	uint8_t plus:1;
	 	uint8_t minus:1;
	 	uint8_t mute:1;
	} button;
	uint8_t reserved0;
	uint8_t volume;
	uint8_t reserved1[5];
	union {
		uint8_t as_byte;
		struct {
			uint8_t worn:1;
			uint8_t display_active:1;
			uint8_t hdmi_disconnected:1;	// XXX
			uint8_t microphone_muted:1;
			uint8_t headphone_connected:1;
			uint8_t reserved:2;
			uint8_t tick:1;
		};
	} status;
	uint8_t reserved2[11];
	struct {
		struct {
			int16_t yaw;
			int16_t pitch;
			int16_t roll;
		} gyro;
		struct  {
			int16_t x;
			int16_t y;
			int16_t z;
		} accel;
		uint8_t reserved[4];
	} data[2];
	uint8_t reserved3[12];
};
#pragma pack()

int psvr_open(psvr_context **ctx);
void psvr_close(psvr_context *ctx);
int psvr_send_command_sync(psvr_context *ctx, uint8_t id, uint8_t *payload, uint32_t length);
int psvr_read_sensor_sync(psvr_context *ctx, uint8_t *payload, uint32_t length);