#include <fo_APDS9930.h>
#include <Wire.h>

fo_APDS9930::fo_APDS9930()
{
}

bool fo_APDS9930::init()
{

    Wire.begin();
    Wire.beginTransmission(APDS9930_ADDR);
    Wire.write(APDS9930_ID);
    Wire.endTransmission();
    Wire.requestFrom(APDS9930_ADDR, 1);
    if (Wire.available())
    {
        uint8_t id = Wire.read();
        if (id == APDS9930_ID)
        {
            return true;
        }
    }
    return false; 
}

bool fo_APDS9930::begin(byte address, TwoWire *myWire)
{
    _wire = myWire;
    _wire -> begin();
    _address = address;
    return writeByte(APDS9930_ID);
}

bool fo_APDS9930::writeByte(byte b)
{
    _wire -> beginTransmission(_address);
    _wire -> write(b);
    return(_wire -> endTransmission() == 0);
}

bool fo_APDS9930::writeWord(word w)
{
    _wire -> beginTransmission(_address);
    _wire -> write(w >> 8);
    _wire -> write(w & 0xFF);
    return(_wire -> endTransmission() == 0);
}

/////////////////////
/*
bool fo_APDS9930::readByte(unsigned char address, unsigned char &value)
	// Reads a byte from a TSL2561 address
	// Address: TSL2561 address (0 to 15)
	// Value will be set to stored byte
	// Returns true (1) if successful, false (0) if there was an I2C error
	// (Also see getError() above)
{
	// Set up command byte for read
	Wire.beginTransmission(_i2c_address);
	Wire.write((address & 0x0F) | TSL2561_CMD);
	_error = Wire.endTransmission();

	// Read requested byte
	if (_error == 0)
	{
		Wire.requestFrom(_i2c_address,1);
		if (Wire.available() == 1)
		{
			value = Wire.read();
			return(true);
		}
	}
	return(false);
}

/////////////////////////////

bool fo_APDS9930::readByte(byte b)
{
    _wire -> beginTransmission(_address);
    b = _wire -> read();
    return(_wire -> endTransmission() == 0);
}
*/
/*
bool fo_APDS9930::readWord(word w)
{
    _wire -> beginTransmission(_address);
    _wire -> read(w >> 8);
    _wire -> read(w & 0xFF);
    return(_wire -> endTransmission() == 0);
}
*/
bool fo_APDS9930::write(byte reg, byte b)
{
    _wire -> beginTransmission(_address);
    _wire -> write(reg);
    _wire -> write(b);
    return(_wire -> endTransmission() == 0);
}

bool fo_APDS9930::read(byte reg, byte &val)
{
    _wire -> beginTransmission(_address);
    _wire -> write(reg);
    _wire -> endTransmission();
    _wire -> requestFrom(_address, 1);
    if (_wire -> available())
    {
        val = _wire -> read();
        return true;
    }
    return false;
}

/* 
 * Public functions
 */

bool fo_APDS9930::powerOn()
{   
    if(write(APDS9930_ENABLE_REG, APDS9930_Enable))
    {
        return true;
    }   
    return false;
}

bool fo_APDS9930::powerOff()
{
    if(write(APDS9930_ENABLE_REG, APDS9930_Disable))
    {
        return true;
    }
    return false;
}

bool fo_APDS9930::enableALS()
{
    return write(APDS9930_AEN, APDS9930_Enable);
} 

bool fo_APDS9930::enableProximity()
{
    return write(APDS9930_PEN, APDS9930_Enable);
}

bool fo_APDS9930::setATime()
{
    return write(APDS9930_ATIME_REG, APDS9930_ATIME);
}

bool fo_APDS9930::setPTime()
{
    return write(APDS9930_PTIME_REG, APDS9930_PTIME);
}


