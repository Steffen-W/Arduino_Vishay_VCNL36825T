/*
  This file is part of the Vishay_VCNL36825T library.
  Copyright (c) 2021 Vishay Capella.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>
#include <Wire.h>

class VCNL36825TClass {
  public:
    VCNL36825TClass(TwoWire& wire);
    virtual ~VCNL36825TClass();

    int begin();
    void end();
    boolean read(uint8_t reg, volatile uint16_t *data);
    boolean write( uint8_t reg, uint16_t data);
    virtual boolean read_PS(uint16_t *ps);
    boolean PS_ST(boolean stop);
    boolean PS_INT(uint16_t prx_int);
    boolean PS_INT_with_threshold(uint16_t thdl, uint16_t thdh);
    boolean read_INT_FLAG(volatile uint16_t *int_flag);
    const uint16_t
      PS_IF_AWAY = (1 << 8),
      PS_IF_CLOSE = (1 << 9),
      PS_SPFLAG = (1 << 12),
      PS_ACFLAG = (1 << 13);
    const uint16_t
      PS_INT_DISABLE = 0,
      PS_INT_LOGICMODE = 1,
      PS_INT_FIRSTHIGH = 2,
      PS_INT_ENABLE = 3;
    enum PS_I_VCSEL_t {
      PS_I_VCSEL_10mA = 2,
      PS_I_VCSEL_12mA = 3,
      PS_I_VCSEL_14mA = 4,
      PS_I_VCSEL_16mA = 5,
      PS_I_VCSEL_18mA = 6,
      PS_I_VCSEL_20mA = 7};
    boolean set_PS_I_VCSEL(PS_I_VCSEL_t i_vcsel);
    PS_I_VCSEL_t get_PS_I_VCSEL(void);
    boolean read_PS_with_AC(uint16_t *ps, uint16_t *ps_ac);
      
  private:
    TwoWire* _wire;
    uint8_t slaveAddress;
    boolean bitsUpdate(uint8_t reg, uint16_t mask, uint16_t update);  
};

extern VCNL36825TClass vcnl36825t;
