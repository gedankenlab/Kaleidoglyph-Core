// -*- c++ -*-

/* Kaleidoscope-LEDEffect-Rainbow - Rainbow LED effects for Kaleidoscope.
 * Copyright (C) 2017-2018  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

// -*- c++ -*-

#pragma once

#include <Kaleidoglyph.h>

#include <kaleidoglyph/KeyAddr.h>
#include <kaleidoglyph/Color.h>
#include <kaleidoglyph/led/utils.h>
#include "kaleidoglyph/led/LedBackgroundMode.h"


namespace kaleidoglyph {
//namespace led {

// Forward declaration; we can't include the header
class LedController;

class LedRainbowMode : public LedBackgroundMode {

 public:

  LedRainbowMode() {}

  void update(LedController& led_controller) override;

  void setBrightness(byte value) {
    value_ = value;
  }
  void setInterval(byte ms) {
    update_interval_ = ms;
  }


 private:

  byte current_hue_{0}; // stores 0 to 614

  //byte rainbow_steps_{1};  //  number of hues we skip in a 360 range per update
  uint16_t last_update_time_{0};
  uint16_t update_interval_{64}; // delay between updates (ms)

  byte saturation_{255};
  byte value_{150};

};

class LedRainbowWaveMode : public LedBackgroundMode {

 public:

  LedRainbowWaveMode() {}

  void update(LedController& led_controller) override;

  void setBrightness(byte value) {
    value_ = value;
  }
  void setInterval(byte ms) {
    update_interval_ = ms;
  }


 private:

  uint16_t current_base_hue_{0};  //  stores 0 to 614

  //uint8_t wave_steps_{1};  //  number of hues we skip in a 360 range per update
  uint16_t last_update_time_{0};
  uint16_t update_interval_{64}; // delay between updates (ms)

  byte saturation_{255};
  byte value_{150};

};

//} // namespace led {
} // namespace kaleidoglyph {
