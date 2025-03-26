#define DC_PIN 22
#define RST_PIN 21


#define SPI_PORT spi0
#define SPI_SCK_PIN 18  // Шина SCK (Serial Clock)
#define SPI_MOSI_PIN 19 // Шина MOSI (Master Out Slave In)

//Display Commands
#define ST7789_SWRESET      _u(0x01) //Software Reset

//Read
#define ST7789_RDDID        _u(0x04) //Read Display ID
#define ST7789_RDDST        _u(0x09) //Read Display Status
#define ST7789_RDDPM        _u(0x0A) //Read Display Power Mode
#define ST7789_RDDMADCTL    _u(0x0B) //Read Display MADCTL
#define ST7789_RDDCOLMOD    _u(0x0C) //Read Display Pixel Format
#define ST7789_RDDIM        _u(0x0D) //Read Display Image Mode
#define ST7789_RDDSM        _u(0x0E) //Read Display Signal Mode
#define ST7789_RDDSDR       _u(0x0F) //Read Display Self-Diagnostic Result

//Sleep
#define ST7789_SLPIN        _u(0x10) //Sleep in
#define ST7789_SLPOUT       _u(0x11) //Sleep out

//Partial mode
#define ST7789_PTLON        _u(0x12) //Partial Display Mode On
#define ST7789_NORON        _u(0x13) //Normal Display Mode On

//Color Inversion
#define ST7789_INVOFF       _u(0x20) //Display Color Inversion Off
#define ST7789_INVON        _u(0x21) //Display Color Inversion On

//Gamma
#define ST7789_GAMSET       _u(0x26) //Gamma Set + Parameter (0x01; 0x02; 0x04; 0x08)

//Display On/Off
#define ST7789_DISPOFF      _u(0x28) //Display Off
#define ST7789_DISPON       _u(0x29) //Display On

//Set Address
#define ST7789_CASET        _u(0x2A) //Column Address Set + Parameter
#define ST7789_RASET        _u(0x2B) //Row Address Set + Parameter

// Memory
#define ST7789_RAMWR        _u(0x2C) //Memory Write + Data
#define ST7789_RAMRD        _u(0x2E) //Memory Read

#define ST7789_PTLAR        _u(0x30) //Partial Area + 4 Parameter

#define ST7789_VSCRDEF      _u(0x33) //Vertical Scrolling Definition + 8 Parameter
#define ST7789_TEOFF        _u(0x34) //Tearing Effect Line OFF
#define ST7789_TEON         _u(0x35) //Tearing Effect Line On + Parameter
#define ST7789_MADCTL       _u(0x36) //Memory Data Access Control + Parametr Page.215

#define ST7789_VSCSAD       _u(0x37) //Vertical Scroll Start Address of RAM + 2 Parameter

#define ST7789_IDMOFF       _u(0x38) //Idle Mode Off
#define ST7789_IDMON        _u(0x39) //Idle mode on

#define ST7789_COLMOD       _u(0x3A) //Interface Pixel Format + Parameter Page.224

#define ST7789_WRMEMC       _u(0x3C) //Write Memory Continue + Data
#define ST7789_RDMEMC       _u(0x3E) //Read Memory Continue

#define ST7789_STE          _u(0x44) //Set Tear Scanline + 2 Parameter
#define ST7789_GSCAN        _u(0x45) //Get Scanline + 2 Parameter

#define ST7789_WRDISBV      _u(0x51) //Write Display Brightness + Parameter
#define ST7789_RDDISBV      _u(0x52) //Read Display Brightness Value + 2 Parameter
#define ST7789_WRCTRLD      _u(0x53) //Write CTRL Display + Parameter
#define ST7789_RDCTRLD      _u(0x54) //Read CTRL Value Display + 2 Parameter

#define ST7789_WRCACE       _u(0x55) //Write Content Adaptive Brightness Control and Color Enhancement + Parameter
#define ST7789_RDCABC       _u(0x56) //Read Content Adaptive Brightness Control + 2 Parameter

#define ST7789_WRCABCMB     _u(0x5E) //Write CABC Minimum Brightness + Parameter
#define ST7789_RDCABCMB     _u(0x5F) //Read CABC Minimum Brightness + 2 Parameter
#define ST7789_RDABCSDR     _u(0x68) //Read Automatic Brightness Control Self-Diagnostic Result + 2 Parameter

#define ST7789_RDID1        _u(0xDA) //Read ID1 + 2 Parameter
#define ST7789_RDID2        _u(0xDB) //Read ID2 + 2 Parameter
#define ST7789_RDID3        _u(0xDC) //Read ID3 + 2 Parameter

#define ST7789_RAMCTRL      _u(0xB0) //RAM Control + 2 Parameter
#define ST7789_RGBCTRL      _u(0xB1) //RGB Interface Control + 3 Parameter
#define ST7789_PORCTRL      _u(0xB2) //Porch Setting + 5 Parameter
#define ST7789_FRCTRL1      _u(0xB3) //Frame Rate Control 1 (In partial mode/ idle colors) + 3 Parameter
#define ST7789_PARCTRL      _u(0xB5) //Partial Control + Parameter
#define ST7789_GCTRL        _u(0xB7) //Gate Control + Parameter
#define ST7789_GTADJ        _u(0xB8) //Gate On Timing Adjustment + 4 Parameter
#define ST7789_DGMEN        _u(0xBA) //Digital Gamma Enable + Parameter

#define ST7789_VCOMS        _u(0xBB) //VCOM Setting + Parameter
#define ST7789_POWSAVE      _u(0xBC) //Power Saving Mode + Parameter
#define ST7789_DLPOFFSAVE   _u(0xBD) //Display off power save + Parameter
#define ST7789_LCMCTRL      _u(0xC0) //LCM Control + Parameter
#define ST7789_IDSET        _u(0xC1) //ID Code Setting + 3 Parameter
#define ST7789_VDVVRHEN     _u(0xC2) //VDV and VRH Command Enable + 2 Parameter
#define ST7789_VRHS         _u(0xC3) //VRH Set + Parameter
#define ST7789_VDVS         _u(0xC4) //VDV Set + Parameter
#define ST7789_VCMOFSET     _u(0xC5) //VCOM Offset Set + Parameter

#define ST7789_FRCTRL2      _u(0xC6) //Frame Rate Control in Normal Mode + Parameter
#define ST7789_CABCCTRL     _u(0xC7) //CABC Control + Parameter
#define ST7789_REGSEL1      _u(0xC8) //Register Value Selection 1 + Parameter
#define ST7789_REGSEL2      _u(0xCA) //Register Value Selection 2 + Parameter

#define ST7789_PWMFRSEL     _u(0xCC) //PWM Frequency Selection + Parameter Page.290
#define ST7789_PWCTRL1      _u(0xD0) //Power Control 1 + 2 Parameter
#define ST7789_VAPVANEN     _u(0xD2) //Enable VAP/VAN signal output + 2 Parameter
#define ST7789_CMD2EN       _u(0xDF) //Command 2 Enable + 4 Parameter

#define ST7789_PVGAMCTRL    _u(0xE0) //Positive Voltage Gamma Control + 14 Parameter Page.295
#define ST7789_NVGAMCTRL    _u(0xE1) //Negative Voltage Gamma Control + 14 Parameter Page.297

#define ST7789_DGMLUTR      _u(0xE2) //Digital Gamma Look-up Table for Red + 64 Parameter
#define ST7789_DGMLUTB      _u(0xE3) //Digital Gamma Look-up Table for Blue + 64 Parameter

#define ST7789_GATECTRL     _u(0xE4) //Gate Control + 3 Parameter

#define ST7789_SPI2EN       _u(0xE7) //SPI2 Enable + Parameter
#define ST7789_PWCTRL2      _u(0xE8) //Power Control 2 + Parameter

#define ST7789_EQCTRL       _u(0xE9) //Equalize time control + 3 Parameter
#define ST7789_PROMCTRL     _u(0xEC) //Program Mode Control + Parameter
#define ST7789_PROMEN       _u(0xFA) //Program Mode Enable + 4 Parameter
#define ST7789_NVMSET       _u(0xFC) //NVM Setting + 2 Parameter
#define ST7789_PROMACT      _u(0xFE) //Program action + 2 Parameter