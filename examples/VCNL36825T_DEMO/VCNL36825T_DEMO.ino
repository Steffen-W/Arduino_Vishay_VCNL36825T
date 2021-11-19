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

#include <Vishay_VCNL36825T.h>

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println();

  if (!vcnl36825t.begin())
  {
    Serial.println("Failed to initialize vcnl36825t");
    while(1);
  }
  
  // Set VCSEL current to 20mA
  vcnl36825t.set_PS_I_VCSEL(vcnl36825t.PS_I_VCSEL_20mA);

  Serial.println("PS_w_AC");
}

void loop()
{
  uint16_t ps, ps_ac;

  if(vcnl36825t.read_PS_with_AC(&ps, &ps_ac))
    Serial.println(ps);

  delay(100);
}
