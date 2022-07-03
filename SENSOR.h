#ifndef fo_APDS9930_H
#define fo_APDS9930_H

#endif

#include <Arduino.h>
#include <Wire.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Wire.h>

/*
 * APDS9930 Registers
 */

enum APDS9930_REGS
{
    APDS9930_ENABLE_REG = 0x00,
    APDS9930_ATIME_REG = 0x01,
    APDS9930_PTIME_REG = 0x02,
    APDS9930_WTIME_REG = 0x03,
    APDS9930_AILTL_REG = 0x04,
    APDS9930_AILTH_REG = 0x05,
    APDS9930_AIHTL_REG = 0x06,
    APDS9930_AIHTH_REG = 0x07,
    APDS9930_PILTL_REG = 0x08,
    APDS9930_PILTH_REG = 0x09,
    APDS9930_PIHTL_REG = 0x0A,
    APDS9930_PIHTH_REG = 0x0B,
    APDS9930_PERS_REG = 0x0C,
    APDS9930_CONFIG_REG = 0x0D,
    APDS9930_PPULSE_REG = 0x0E,
    APDS9930_CONTROL_REG = 0x0F,
    APDS9930_ID_REG = 0x12,
    APDS9930_STATUS_REG = 0x13,
    APDS9930_CH0DATAL_REG = 0x14,
    APDS9930_CH0DATAH_REG = 0x15,
    APDS9930_CH1DATAL_REG = 0x16,
    APDS9930_CH1DATAH_REG = 0x17,
    APDS9930_PDATAL_REG = 0x18,
    APDS9930_PDATAH_REG = 0x19,
    APDS9930_POFFSET_REG = 0x1E,
};

/*
 * APDS9930 Device ID Register (0x12)
 */

enum APDS9930_I2C_Address
{
  APDS9930_ADDR = 0x39
};

enum APDS9930_Toggle
{
  APDS9930_Disable = 0x00,
  APDS9930_Enable = 0x01,
};

/*
 * APDS9930 Enable Register (0x00)
 */

enum APDS9930_Enable
{
    APDS9930_PON = 0x00,
    APDS9930_AEN = 0x01,
    APDS9930_PEN = 0x02,
    APDS9930_WEN = 0x03,
    APDS9930_AIEN = 0x04,
    APDS9930_PIEN = 0x05,
    APDS9930_SAI = 0x06,   
};

/*
 * APDS9930 ALS Timing Register (0x01)
 */

enum APDS9930_ATIME
{
    APDS9930_ATIME_2_73MS = 0xFF,
    APDS9930_ATIME_27_3MS = 0xF6,
    APDS9930_ATIME_101MS = 0xDB,
    APDS9930_ATIME_175MS = 0xC0,
    APDS9930_ATIME_699MS = 0x00,
};   


/*
 * APDS9930 Register set
 */
 
enum APDS9960_Default
{
    APDS9930_ATIME = 0xFF,    
    APDS9930_WTIME = 0xFF,
    APDS9930_PTIME = 0xFF, 
    APDS9930_PPULSE = 0x08,
    APDS9930_PERS = 0x0C,
    APDS9930_CONFIG = 0x0D,
    APDS9930_ID = 0x12,
    APDS9930_STATUS = 0x13,
    APDS9930_POFFSET = 0x1E,
};

/*
 * APDS9930 ALS Interrupt Threshold Register (0x04 - 0x07)
 */
 
enum APDS9930_ALS_Interrupt_Threshold 
{
    APDS9930_AILTL = 0x04,
    APDS9930_AILTH = 0x05,
    APDS9930_AIHTL = 0x06,
    APDS9930_AIHTH = 0x07,
};

/*
 * APDS9930 Proximity Interrupt Threshold Register (0x08 - 0x0B)
 */

enum APDS9930_Proximity_Interrupt_Threshold 
{
    APDS9930_PILTL = 0x08,
    APDS9930_PILTH = 0x09,
    APDS9930_PIHTL = 0x0A,
    APDS9930_PIHTH = 0x0B,
};

/*
 * APDS9930 ALS Data Registers (0x14 - 0x17)
 */

enum APDS9930_CHData
{
    APDS9930_CH0DATAL = 0x14,
    APDS9930_CH0DATAH = 0x15,
    APDS9930_CH1DATAL = 0x16,
    APDS9930_CH1DATAH = 0x17,
};

/*
 * APDS9930 Proximity Data Registers (0x18 - 0x19)
 */

enum APDS9930_PData
{
    APDS9930_PDATAL = 0x18,
    APDS9930_PDATAH = 0x19,
};


/*
 * APDS9930 Control register (0x0F)
 */

enum APDS9930_PDRIVE
{
    APDS9930_PDRIVE_100MA = 0x00,
    APDS9930_PDRIVE_50MA = 0x01,
    APDS9930_PDRIVE_25MA = 0x02,
    APDS9930_PDRIVE_12MA = 0x03,
};

enum APDS9930_PDIODE
{
    APDS9930_CH1_DIODE = 0x02
};

enum APDS9930_PGain
{
    APDS9930_PGAIN_1X = 0x00,
    APDS9930_PGAIN_2X = 0x01,
    APDS9930_PGAIN_4X = 0x02,
    APDS9930_PGAIN_8X = 0x03,
};

enum APDS9930_AGain
{
    APDS9930_AGAIN_1X = 0x00,
    APDS9930_AGAIN_4X = 0x01,
    APDS9930_AGAIN_16X = 0x02,
    APDS9930_AGAIN_64X = 0x03,
};

/*
 * APDS9930 Status register (0x13)
 */ 

enum APDS9930_Status
{
    APDS9930_STATUS_AVALID = 0x00,
    APDS9930_STATUS_PVALID = 0x01,
    APDS9930_STATUS_AINT = 0x04,
    APDS9930_STATUS_PINT = 0x05,
    APDS9930_STATUS_PSAT = 0x06,
};

extern TwoWire Wire;
class fo_APDS9930
{
public:
    fo_APDS9930();
    bool init();
    bool begin(byte address, TwoWire *myWire = &Wire);
    bool reset();
    bool powerOn();
    bool powerOff();

    /* Enable specific sensors */
    bool enableALS(); //bool enableALS(bool interrupts = false);
    bool disableALS();
    bool enableProximity(); //bool enableProximity(bool interrupts = false);    
    bool disableProximity();

    /* Set sensor parameters */
    bool setATime();
    bool setPTime();

    /* LED drive strength control */
    uint8_t getLEDDrive();
    bool setLEDDrive(uint8_t drive);

    /* Gain control */
    uint8_t getALSGain();
    bool setALSGain(uint8_t gain);
    uint8_t getProximityGain();
    bool setProximityGain(uint8_t gain, uint8_t diode);
    uint8_t getProximityDiode();

    /* Get and set light interrupt thresholds */
    bool getALSLowThreshold(uint16_t &threshold);
    bool setALSLowThreshold(uint16_t threshold);
    bool getALSHighThreshold(uint16_t &threshold);
    bool setALSHighThreshold(uint16_t threshold);
    
    /* Get and set interrupt enables */
    uint8_t getALSInterruptEnable();
    bool setALSInterruptEnable(uint8_t interrupt);
    uint8_t getProximityInterruptEnable();
    bool setProximityInterruptEnable(uint8_t interrupt);

    /* Clear interrupts */  
    bool clearALSInterrupt();
    bool clearProximityInterrupt();
    bool clearAllInterrupts();

    /* Proximity methods */
    bool readProximity(uint16_t &val);

    /* ALS methods */
    bool readALS(float &val);
    bool readALS(unsigned long &val);
    float floatALStoLux(uint16_t Ch0, uint16_t Ch1);
    bool readCh0Light(uint16_t &val);
    bool readCh1Light(uint16_t &val);

private:
    /* Set sensor parameters */

    uint16_t getProximityInterruptLowThreshold();
    bool setProximityInterruptLowThreshold(uint16_t threshold);
    uint16_t getProximityInterruptHighThreshold();
    bool setProximityInterruptHighThreshold(uint16_t threshold);

    /* I2C Commands */
    TwoWire *_wire;
    byte _address;
    bool writeByte(byte b); 
    bool writeWord(word w);
    bool readByte(byte b); 
    bool readWord(word w);
    
    bool write(byte reg, byte b);
    bool read(byte reg, byte &val);
};

