/*
  BigNumbers.cpp - Library for displaying large numbers on LCD displays using the HD44780 driver.
 
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

#include "BigNumbers.h"

byte leftSide[8] = 
{
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111
};
byte upperBar[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte rightSide[8] =
{
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100
};
byte leftEnd[8] =
{
  B01111,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00111
};
byte lowerBar[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte rightEnd[8] =
{
  B11110,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11100
};
byte middleBar[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte lowerEnd[8] = 
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01111
};

BigNumbers::BigNumbers(LiquidCrystal* lcd)
{
  _lcd = lcd;
  _lcd->createChar(0,leftSide);
  _lcd->createChar(1,upperBar);
  _lcd->createChar(2,rightSide);
  _lcd->createChar(3,leftEnd);
  _lcd->createChar(4,lowerBar);
  _lcd->createChar(5,rightEnd);
  _lcd->createChar(6,middleBar);
  _lcd->createChar(7,lowerEnd);
}

void BigNumbers::clearLargeNumber(byte x) // x is column of upper left corner for large character
{
  _lcd->setCursor(x,0);
  _lcd->print("   ");
  _lcd->setCursor(x,1); 
  _lcd->print("   ");
}

void BigNumbers::displayLargeNumber(byte n, byte x) // n is number to display, x is column of upper left corner for large character
{
  switch (n)
  {
    case 0:
    {
      _lcd->setCursor(x,0);
      _lcd->write(byte(0));
      _lcd->write(1);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 1:
    {
      _lcd->setCursor(x,0);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      _lcd->setCursor(x,1);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      break;
    }
    case 2:
    {
      _lcd->setCursor(x,0);
      _lcd->write(3);
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(4);
      break;
    }
    case 3:
    {
      _lcd->setCursor(x,0);
      _lcd->write(3);
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(7);
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 4:
    {
      _lcd->setCursor(x,0);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      break;
    }
    case 5:
    {
      _lcd->setCursor(x,0);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(5);
      _lcd->setCursor(x, 1);
      _lcd->write(7);
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 6:
    {
      _lcd->setCursor(x,0);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(5);
      _lcd->setCursor(x, 1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 7:
    {
      _lcd->setCursor(x,0);
      _lcd->write(1);
      _lcd->write(1);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(char(254));
      _lcd->write(char(254));
      _lcd->write(2);
      break;
    }
    case 8:
    {
      _lcd->setCursor(x,0);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(byte(0));
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
    case 9:
    {
      _lcd->setCursor(x,0);
      _lcd->write(byte(0));
      _lcd->write(6);
      _lcd->write(2);
      _lcd->setCursor(x, 1);
      _lcd->write(7);
      _lcd->write(4);
      _lcd->write(2);
      break;
    }
  }
}
