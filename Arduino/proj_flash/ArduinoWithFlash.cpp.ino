#include <SPI.h>
#include <SPIMemory.h>

SPIFlash flash(10); 

const uint32_t startAddress = 0x000000;

const char textFileContent[] =
  "random.txt\n"
  "----------------------\n"
  "Raindrops tapped gently against the windowpane as the storm rolled in, bringing with it a sense of calm and introspection.\n"
  "Inside, the soft glow of a lamp lit the pages of an open book, untouched tea cooling beside it.\n"
  "Time seemed to slow, allowing the quiet rhythms of the rain to wash over the room like a lullaby.\n";

char readBuffer[512]; 

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Initializing SPI flash...");

  if (!flash.begin()) 
  {
    Serial.println(" Flash initialization failed.");
    while (1);
  }

  Serial.println(" Flash memory detected.");
  Serial.print("JEDEC ID: 0x");
  Serial.println(flash.getJEDECID(), HEX);

  Serial.println("Erasing sector...");
  if (flash.eraseSector(startAddress)) 
  {
    Serial.println(" Sector erased.");
  } else {
    Serial.println(" Erase failed.");
    while (1);
  }

  delay(100);

  Serial.println("Writing .txt content to flash...");
  bool writeOK = flash.writeByteArray(startAddress, (uint8_t*)textFileContent, strlen(textFileContent));

  if (writeOK) {
    Serial.println(" Write successful.");
  } else {
    Serial.println(" Write failed.");
    while (1);
  }

  delay(100);

  memset(readBuffer, 0, sizeof(readBuffer));
  uint16_t bytesToRead = strlen(textFileContent);

  Serial.print("Reading ");
  Serial.print(bytesToRead);
  Serial.println(" bytes from flash...");

  if (flash.readByteArray(startAddress, (uint8_t*)readBuffer, bytesToRead)) 
  {
    Serial.println(" Read successful.");
    Serial.println("----------- BEGIN .TXT CONTENT -----------");
    Serial.println(readBuffer);
    Serial.println("------------- END .TXT CONTENT -----------");
  } 
  else 
  {
    Serial.println(" Failed to read from flash.");
  }
}

void loop() 
{
  
}


/*
#include <SPI.h>
#include <SPIMemory.h>

SPIFlash flash(10); 

char fileName1[16];
char fileName2[16];

void setup() 
{
  Serial.begin(9600);
  while (!Serial);

  if (!flash.begin()) 
  {
    Serial.println("Flash init failed");
    while (1);
  }

  flash.readByteArray(0x000000, (uint8_t*)fileName1, sizeof(fileName1));
  flash.readByteArray(0x000100, (uint8_t*)fileName2, sizeof(fileName2));

  Serial.println("Stored files:");
  Serial.print("- "); Serial.println(fileName1);
  Serial.print("- "); Serial.println(fileName2);
}

void loop() 
{

}
*/


