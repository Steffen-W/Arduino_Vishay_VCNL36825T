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

#include "VCNL36825T.h"

#define VCNL36825T_ADDRESS          0x60
#define VCNL36825T_WHO_AM_I         0x26

#define VCNL36825T_REG_PS_CONF1     0x00
#define VCNL36825T_REG_PS_CONF2     0x03
#define VCNL36825T_REG_PS_CONF3     0x04
#define VCNL36825T_REG_PS_THDL      0x05
#define VCNL36825T_REG_PS_THDH      0x06
#define VCNL36825T_REG_PS_CANC      0x07
#define VCNL36825T_REG_PS_CONF4     0x08
#define VCNL36825T_REG_PS_DATA      0xF8
#define VCNL36825T_REG_INT_FLAG     0xF9
#define VCNL36825T_REG_ID           0xFA
#define VCNL36825T_REG_PS_AC_DATA   0xFB

// PS_CONF1
#define VCNL36825T_PS_ON            (1 << 1)
#define VCNL36825T_PS_CAL           (1 << 7)
// PS_CONF2
#define VCNL36825T_PS_ST            (1 << 0)
#define VCNL36825T_PS_SMART_PERS    (1 << 1)
#define VCNL36825T_PS_INT_SHIFT     2
#define VCNL36825T_PS_INT_MASK      (0x3 << VCNL36825T_PS_INT_SHIFT)
#define VCNL36825T_PS_INT_DISABLE   (PS_INT_DISABLE << VCNL36825T_PS_INT_SHIFT)
#define VCNL36825T_PS_INT_CLOSING   (PS_INT_CLOSING << VCNL36825T_PS_INT_SHIFT)
#define VCNL36825T_PS_INT_AWAY      (PS_INT_AWAY << VCNL36825T_PS_INT_SHIFT)
#define VCNL36825T_PS_INT_BOTH      (PS_INT_BOTH << VCNL36825T_PS_INT_SHIFT)
#define VCNL36825T_PS_PERS_SHIFT    4
#define VCNL36825T_PS_PERS_MASK     (0x3 << VCNL36825T_PS_PERS_SHIFT)
#define VCNL36825T_PS_PERS_1        (0x0 << VCNL36825T_PS_PERS_SHIFT)
#define VCNL36825T_PS_PERS_2        (0x1 << VCNL36825T_PS_PERS_SHIFT)
#define VCNL36825T_PS_PERS_3        (0x2 << VCNL36825T_PS_PERS_SHIFT)
#define VCNL36825T_PS_PERS_4        (0x3 << VCNL36825T_PS_PERS_SHIFT)
#define VCNL36825T_PS_PERIOD_SHIFT  6
#define VCNL36825T_PS_PERIOD_MASK   (0x3 << VCNL36825T_PS_PERIOD_SHIFT)
#define VCNL36825T_PS_PERIOD_10ms   (0x0 << VCNL36825T_PS_PERIOD_SHIFT)
#define VCNL36825T_PS_PERIOD_20ms   (0x1 << VCNL36825T_PS_PERIOD_SHIFT)
#define VCNL36825T_PS_PERIOD_40ms   (0x2 << VCNL36825T_PS_PERIOD_SHIFT)
#define VCNL36825T_PS_PERIOS_80ms   (0x3 << VCNL36825T_PS_PERIOD_SHIFT)
#define VCNL36825T_PS_HG            (1 << 10)
#define VCNL36825T_PS_ITB           (1 << 11)
#define VCNL36825T_PS_MPS_SHIFT     12
#define VCNL36825T_PS_MPS_MASK      (0x03 << VCNL36825T_PS_MPS_SHIFT)
#define VCNL36825T_PS_MPS_1P        (0x0 << VCNL36825T_PS_MPS_SHIFT)
#define VCNL36825T_PS_MPS_2P        (0x1 << VCNL36825T_PS_MPS_SHIFT)
#define VCNL36825T_PS_MPS_4P        (0x2 << VCNL36825T_PS_MPS_SHIFT)
#define VCNL36825T_PS_MPS_8P        (0x3 << VCNL36825T_PS_MPS_SHIFT)
#define VCNL36825T_PS_IT_SHIFT      14
#define VCNL36825T_PS_IT_MASK       (0x3 << VCNL36825T_PS_IT_SHIFT)
#define VCNL36825T_PS_IT_1T         (0x0 << VCNL36825T_PS_IT_SHIFT)
#define VCNL36825T_PS_IT_2T         (0x1 << VCNL36825T_PS_IT_SHIFT)
#define VCNL36825T_PS_IT_4T         (0x2 << VCNL36825T_PS_IT_SHIFT)
#define VCNL36825T_PS_IT_8T         (0x3 << VCNL36825T_PS_IT_SHIFT)
// PS_CONF3
#define VCNL36825T_PS_SP_INT        (1 << 2)
#define VCNL36825T_PS_FORCENUM      (1 << 4)
#define VCNL36825T_PS_TRIG          (1 << 5)
#define VCNL36825T_PS_AF            (1 << 6)
#define VCNL36825T_PS_I_VCSEL_SHIFT 8
#define VCNL36825T_PS_I_VCSEL_MASK  (0xF << VCNL36825T_PS_I_VCSEL_SHIFT)
#define VCNL36825T_PS_HD            (1 << 12)
#define VCNL36825T_PS_SC            (0x7 << 13)
// PS_CONF4
#define VCNL36825T_PS_AC_INT        (1 << 0)
#define VCNL36825T_PS_AC_TRIG       (1 << 2)
#define VCNL36825T_PS_AC            (1 << 3)
#define VCNL36825T_PS_AC_NUM_SHIFT  4
#define VCNL36825T_PS_AC_NUM_MASK   (0x3 << VCNL36825T_PS_AC_NUM_SHIFT)
#define VCNL36825T_PS_AC_NUM_1      (0x0 << VCNL36825T_PS_AC_NUM_SHIFT)
#define VCNL36825T_PS_AC_NUM_2      (0x1 << VCNL36825T_PS_AC_NUM_SHIFT)
#define VCNL36825T_PS_AC_NUM_4      (0x2 << VCNL36825T_PS_AC_NUM_SHIFT)
#define VCNL36825T_PS_AC_NUM_8      (0x3 << VCNL36825T_PS_AC_NUM_SHIFT)
#define VCNL36825T_PS_AC_PERIOD_SHIFT 6
#define VCNL36825T_PS_AC_PERIOD_MASK  (0x3 << VCNL36825T_PS_AC_PERIOD_SHIFT)
#define VCNL36825T_PS_AC_PERIOD_3ms   (0x0 << VCNL36825T_PS_AC_PERIOD_SHIFT)
#define VCNL36825T_PS_AC_PERIOD_6ms   (0x1 << VCNL36825T_PS_AC_PERIOD_SHIFT)
#define VCNL36825T_PS_AC_PERIOD_12ms  (0x2 << VCNL36825T_PS_AC_PERIOD_SHIFT)
#define VCNL36825T_PS_AC_PERIOD_24ms  (0x3 << VCNL36825T_PS_AC_PERIOD_SHIFT)
#define VCNL36825T_PS_LPPER_SHIFT   9
#define VCNL36825T_PS_LPPER_MASK    (0x3 << VCNL36825T_PS_LPPER_SHIFT)
#define VCNL36825T_PS_LPPER_40ms    (0x0 << VCNL36825T_PS_LPPER_SHIFT)
#define VCNL36825T_PS_LPPER_80ms    (0x1 << VCNL36825T_PS_LPPER_SHIFT)
#define VCNL36825T_PS_LPPER_160ms   (0x2 << VCNL36825T_PS_LPPER_SHIFT)
#define VCNL36825T_PS_LPPER_320ms   (0x3 << VCNL36825T_PS_LPPER_SHIFT)

// PS_AC_DATA
#define PS_AC_DATA_AC_BUSY          (1 << 15)
#define PS_AC_DATA_AC_SUN           (1 << 14)

// Defaults
#define VCNL36825T_DEFAULT_PS_CONF1 (0x0201 | \
                                     VCNL36825T_PS_ON | \
                                     VCNL36825T_PS_CAL)
#define VCNL36825T_DEFAULT_PS_CONF2 (VCNL36825T_PS_IT_8T | \
                                     VCNL36825T_PS_MPS_1P)
#define VCNL36825T_DEFAULT_PS_CONF3 (0x0008 | \
                                     VCNL36825T_PS_HD | \
                                     VCNL36825T_PS_SC)
#define VCNL36825T_DEFAULT_PS_CONF4 (0x0000)
#define VCNL36825T_DEFAULT_PS_CANC  0x0000
#define VCNL36825T_DEFAULT_PS_THDL  0x0000
#define VCNL36825T_DEFAULT_PS_THDH  0xFFFF

VCNL36825TClass::VCNL36825TClass(TwoWire& wire) :
  _wire(&wire)
{
}

VCNL36825TClass::~VCNL36825TClass(void)
{
  PS_INT(PS_INT_DISABLE);
  writeWord(VCNL36825T_REG_PS_CONF3, 0x0008);
  writeWord(VCNL36825T_REG_PS_CONF1, 0x0201);
}

int VCNL36825TClass::begin(void)
{
  slaveAddress = VCNL36825T_ADDRESS;

  // Prevent I2C bus lockup
  writeWord(VCNL36825T_REG_PS_THDL, 0x0);
  writeWord(VCNL36825T_REG_PS_THDL, 0x0);
  
  uint16_t id;
  if (!readWord(VCNL36825T_REG_ID, &id) || (id & 0xFF) != VCNL36825T_WHO_AM_I)
	  return 0;

  // Power On sequences
  if (// (1). PS_ST = 1
      !writeWord(VCNL36825T_REG_PS_CONF1, 0x0201) ||
      !writeWord(VCNL36825T_REG_PS_CONF2, VCNL36825T_PS_ST) ||
      // (2). PS_ON = 1, PS_CAL = 1
      !writeWord(VCNL36825T_REG_PS_CONF1, 0x0201 | VCNL36825T_PS_ON | VCNL36825T_PS_CAL) ||
      // (3). PS_ST = 0
      !writeWord(VCNL36825T_REG_PS_CONF2, 0x0000))
    return 0;

  // Initialization
  if (writeWord(VCNL36825T_REG_PS_CONF1, VCNL36825T_DEFAULT_PS_CONF1) &&
      writeWord(VCNL36825T_REG_PS_CONF2, VCNL36825T_DEFAULT_PS_CONF2) &&
      writeWord(VCNL36825T_REG_PS_CONF3, VCNL36825T_DEFAULT_PS_CONF3) &&
      writeWord(VCNL36825T_REG_PS_THDL, VCNL36825T_DEFAULT_PS_THDL) &&
      writeWord(VCNL36825T_REG_PS_THDH, VCNL36825T_DEFAULT_PS_THDH) &&
      writeWord(VCNL36825T_REG_PS_CANC, VCNL36825T_DEFAULT_PS_CANC) &&
      writeWord(VCNL36825T_REG_PS_CONF4, VCNL36825T_DEFAULT_PS_CONF4) &&
      set_PS_I_VCSEL(PS_I_VCSEL_10mA))
  {
    delay(10);
    return 1; 
  }
 
  return 0;
}

boolean VCNL36825TClass::readWord(uint8_t reg, volatile uint16_t *data)
{
  uint8_t   wd;

  _wire->beginTransmission(slaveAddress);
  if (_wire->write (reg) != 1)
    goto read_error;
  _wire->endTransmission(false);
  if (_wire->requestFrom(slaveAddress, (uint8_t)2) != 2)
    goto read_error;
  
  wd = 10;
  while (_wire->available()<2 && wd)
    wd--;
  if (!wd)
    goto read_error;
  
  *data = _wire->read();
  *data |= _wire->read() << 8;
  return true;

read_error:
  _wire->endTransmission(true);
  return false;
}

boolean VCNL36825TClass::writeWord(uint8_t reg, uint16_t data)
{
  boolean status = false;
  
  _wire->beginTransmission(slaveAddress);
  if (_wire->write(reg) &&
      _wire->write((uint8_t)(data & 0xFF)) &&
      _wire->write((uint8_t)((data >> 8) & 0xFF)))
    status = true;
  _wire->endTransmission(true);

  return status;
}

boolean VCNL36825TClass::bitsUpdate(uint8_t reg, uint16_t mask, uint16_t update)
{
  uint16_t value;
  
  if (!readWord(reg, &value))
    return false;
  value &= mask;
  value |= update;
  return writeWord(reg, value);
}

boolean VCNL36825TClass::read_PS(uint16_t *ps)
{
  return readWord(VCNL36825T_REG_PS_DATA, ps);
}

boolean VCNL36825TClass::PS_ST(boolean stop)
{
  return bitsUpdate(
    VCNL36825T_REG_PS_CONF2,
    ~VCNL36825T_PS_ST,
    stop ? VCNL36825T_PS_ST : 0);
}

boolean VCNL36825TClass::PS_INT(uint16_t ps_int)
{
  return bitsUpdate(
    VCNL36825T_REG_PS_CONF2,
    ~VCNL36825T_PS_INT_MASK,
    ps_int << VCNL36825T_PS_INT_SHIFT);
}

boolean VCNL36825TClass::PS_INT_with_threshold(uint16_t thdl, uint16_t thdh)
{
  if (PS_INT(PS_INT_DISABLE) &&
      writeWord(VCNL36825T_REG_PS_THDL, thdl) &&
      writeWord(VCNL36825T_REG_PS_THDH, thdh) &&
      PS_INT(PS_INT_ENABLE))
    return true;
    
  return false;
}

boolean VCNL36825TClass::read_INT_FLAG(volatile uint16_t *int_flag)
{
  boolean status = readWord(VCNL36825T_REG_INT_FLAG, int_flag);
  if (status)
    *int_flag &= PS_IF_AWAY | PS_IF_CLOSE | PS_SPFLAG | PS_ACFLAG;
  return status;
}

boolean VCNL36825TClass::set_PS_I_VCSEL(PS_I_VCSEL_t i_vcsel)
{
  return bitsUpdate(
    VCNL36825T_REG_PS_CONF3,
    ~VCNL36825T_PS_I_VCSEL_MASK,
    i_vcsel << VCNL36825T_PS_I_VCSEL_SHIFT);
}

VCNL36825TClass::PS_I_VCSEL_t VCNL36825TClass::get_PS_I_VCSEL(void)
{
  uint16_t conf3; 
  readWord(VCNL36825T_REG_PS_CONF3, &conf3);
  return (PS_I_VCSEL_t)(
    (conf3 & VCNL36825T_PS_I_VCSEL_MASK) >> VCNL36825T_PS_I_VCSEL_SHIFT);
}

boolean VCNL36825TClass::read_PS_with_AC(uint16_t *ps, uint16_t *ps_ac)
{
  uint16_t ps_conf3, ps_conf4;

  if(!readWord(VCNL36825T_REG_PS_CONF3, &ps_conf3) ||
     !readWord(VCNL36825T_REG_PS_CONF4, &ps_conf4))
    return false;

  // Enable PS_AF
  uint16_t conf3 = ps_conf3;
  conf3 &= ~(VCNL36825T_PS_AF | VCNL36825T_PS_TRIG);
  conf3 |= VCNL36825T_PS_AF;
  if(!writeWord(VCNL36825T_REG_PS_CONF3, conf3))
    return false;

  // Enable PS_AC
  uint16_t conf4 = ps_conf4;
  conf4 &= ~(VCNL36825T_PS_AC_NUM_MASK | VCNL36825T_PS_AC_PERIOD_MASK | VCNL36825T_PS_AC | VCNL36825T_PS_AC_TRIG);
  conf4 |= VCNL36825T_PS_AC_NUM_8 | VCNL36825T_PS_AC_PERIOD_24ms | VCNL36825T_PS_AC;
  if(!writeWord(VCNL36825T_REG_PS_CONF4, conf4) ||
     !writeWord(VCNL36825T_REG_PS_CONF4, conf4 | VCNL36825T_PS_AC_TRIG))
    return false;
  do {
    if(!readWord(VCNL36825T_REG_PS_AC_DATA, ps_ac))
      return false;
    if (*ps_ac & PS_AC_DATA_AC_SUN)
      Serial.println("PS_AC_SUN");
  } while (*ps_ac & PS_AC_DATA_AC_BUSY);
  *ps_ac &= 0x0FFF;     // 12-bit

  if(!writeWord(VCNL36825T_REG_PS_CONF3, conf3 | VCNL36825T_PS_TRIG))
    return false;
  delayMicroseconds(9600); // 50us x 8T x 8P x 2 x 1.5 = 9600us
  readWord(VCNL36825T_REG_PS_DATA, ps);

  // Restore PS_CONF3 and PS_CONF4
  if(!writeWord(VCNL36825T_REG_PS_CONF4, ps_conf4) ||
     !writeWord(VCNL36825T_REG_PS_CONF3, ps_conf3))
    return false;

  return true;
}

// https://www.vishay.com/docs/80274/designingvcnl36825t.pdf
// Fig Proximity Value vs. Distance
// (x1, y1) and (x2, y2) are points read from the figure
float VCNL36825TClass::SensorToFloat(uint16_t sensorData, float x1, float y1, float x2, float y2)
{
  const float exp_b = log(x2 / x1) / log(y2 / y1);
  const float a_factor = x1 / pow(y1, exp_b);
  return a_factor * pow(sensorData * 1.0, exp_b);
}

VCNL36825TClass vcnl36825t(Wire);
