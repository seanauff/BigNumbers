/*
  BigNumbers.h - Library for displaying large numbers on LCD displays using the HD44780 driver.
 
  Copyright (C) 2014 Sean Auffinger
 
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BigNumbers_h
#define BigNumbers_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class BigNumbers
{
  public:
    BigNumbers(LiquidCrystal*);
	void begin();
    void clearLargeNumber(byte);
    void displayLargeNumber(byte, byte);
	void displayLargeInt(int, byte, byte, bool);
  private:
    LiquidCrystal* _lcd;
};

#endif
