// license:BSD-3-Clause
// copyright-holders:Olivier Galibert

// Yamaha SWP20, rompler

#ifndef DEVICES_SOUND_SWP20_H
#define DEVICES_SOUND_SWP20_H

#pragma once

#include "dirom.h"

class swp20_device : public device_t, public device_sound_interface, public device_rom_interface<23+2, 1, 0, ENDIANNESS_LITTLE>
{
public:
	swp20_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 11289600);

	void map(address_map &map);

protected:
	virtual void device_start() override;
	virtual void device_reset() override;
	virtual void sound_stream_update(sound_stream &stream, std::vector<read_stream_view> const &inputs, std::vector<write_stream_view> &outputs) override;

private:
	sound_stream *m_stream;

	std::array<u32, 0x20>  m_sample_address;

	u16 m_waverom_val;
	u8 m_waverom_access;

	u8 m_p3c_port;
	bool m_p3c_address;
	u8 m_voice;
	u32 m_keyon;
	u32 m_keyoff;

	void voice_w(u8 data);
	template<int sel> void sample_address_w(offs_t offset, u8 data);
	template<int sel> u8 sample_address_r(offs_t offset);

	void waverom_access_w(u8 data);
	template<int sel> u8 waverom_val_r();

	// Generic upload port
	void p3c_w(u8 data);

	// Generic catch-all
	u8 snd_r(offs_t offset);
	void snd_w(offs_t offset, u8 data);
};

DECLARE_DEVICE_TYPE(SWP20, swp20_device)

#endif
