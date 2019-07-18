#include "lcd_ili9341.h"

extern SPI_HandleTypeDef hspi5;

void LCD_WriteCommand(uint8_t command)
{
  uint8_t dummy;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);        //DCX LOW
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);         //CSX LOW
  HAL_SPI_TransmitReceive(&hspi5, &command, &dummy, 1, 0xFFFF);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);           //CSX HIGH
}

void LCD_WriteData(uint8_t data)
{
  uint8_t dummy;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);          //DCX HIGH
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);         //CSX LOW
  HAL_SPI_TransmitReceive(&hspi5, &data, &dummy, 1, 50);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);           //CSX HIGH
}

void LCD_PowerOn(void)
{
  LCD_WriteCommand(0xCA);
  LCD_WriteData(0xC3);
  LCD_WriteData(0x08);
  LCD_WriteData(0x50);
  LCD_WriteCommand(LCD_POWERB);
  LCD_WriteData(0x00);
  LCD_WriteData(0xC1);
  LCD_WriteData(0x30);
  LCD_WriteCommand(LCD_POWER_SEQ);
  LCD_WriteData(0x64);
  LCD_WriteData(0x03);
  LCD_WriteData(0x12);
  LCD_WriteData(0x81);
  LCD_WriteCommand(LCD_DTCA);
  LCD_WriteData(0x85);
  LCD_WriteData(0x00);
  LCD_WriteData(0x78);
  LCD_WriteCommand(LCD_POWERA);
  LCD_WriteData(0x39);
  LCD_WriteData(0x2C);
  LCD_WriteData(0x00);
  LCD_WriteData(0x34);
  LCD_WriteData(0x02);
  LCD_WriteCommand(LCD_PRC);
  LCD_WriteData(0x20);
  LCD_WriteCommand(LCD_DTCB);
  LCD_WriteData(0x00);
  LCD_WriteData(0x00);
  LCD_WriteCommand(LCD_FRC);
  LCD_WriteData(0x00);
  LCD_WriteData(0x1B);
  LCD_WriteCommand(LCD_DFC);
  LCD_WriteData(0x0A);
  LCD_WriteData(0xA2);
  LCD_WriteCommand(LCD_POWER1);
  LCD_WriteData(0x10);
  LCD_WriteCommand(LCD_POWER2);
  LCD_WriteData(0x10);
  LCD_WriteCommand(LCD_VCOM1);
  LCD_WriteData(0x45);
  LCD_WriteData(0x15);
  LCD_WriteCommand(LCD_VCOM2);
  LCD_WriteData(0x90);
  LCD_WriteCommand(LCD_MAC);
  LCD_WriteData(0xC8);
  LCD_WriteCommand(LCD_3GAMMA_EN);
  LCD_WriteData(0x00);
  LCD_WriteCommand(LCD_RGB_INTERFACE);
  LCD_WriteData(0xC2);
  LCD_WriteCommand(LCD_DFC);
  LCD_WriteData(0x0A);
  LCD_WriteData(0xA7);
  LCD_WriteData(0x27);
  LCD_WriteData(0x04);

  /* colomn address set */
  LCD_WriteCommand(LCD_COLUMN_ADDR);
  LCD_WriteData(0x00);
  LCD_WriteData(0x00);
  LCD_WriteData(0x00);
  LCD_WriteData(0xEF);
  /* Page Address Set */
  LCD_WriteCommand(LCD_PAGE_ADDR);
  LCD_WriteData(0x00);
  LCD_WriteData(0x00);
  LCD_WriteData(0x01);
  LCD_WriteData(0x3F);
  LCD_WriteCommand(LCD_INTERFACE);
  LCD_WriteData(0x01);
  LCD_WriteData(0x00);
  LCD_WriteData(0x06);
  
  LCD_WriteCommand(LCD_GRAM);
  HAL_Delay(200);
  
  LCD_WriteCommand(LCD_GAMMA);
  LCD_WriteData(0x01);
  
  LCD_WriteCommand(LCD_PGAMMA);
  LCD_WriteData(0x0F);
  LCD_WriteData(0x29);
  LCD_WriteData(0x24);
  LCD_WriteData(0x0C);
  LCD_WriteData(0x0E);
  LCD_WriteData(0x09);
  LCD_WriteData(0x4E);
  LCD_WriteData(0x78);
  LCD_WriteData(0x3C);
  LCD_WriteData(0x09);
  LCD_WriteData(0x13);
  LCD_WriteData(0x05);
  LCD_WriteData(0x17);
  LCD_WriteData(0x11);
  LCD_WriteData(0x00);
  LCD_WriteCommand(LCD_NGAMMA);
  LCD_WriteData(0x00);
  LCD_WriteData(0x16);
  LCD_WriteData(0x1B);
  LCD_WriteData(0x04);
  LCD_WriteData(0x11);
  LCD_WriteData(0x07);
  LCD_WriteData(0x31);
  LCD_WriteData(0x33);
  LCD_WriteData(0x42);
  LCD_WriteData(0x05);
  LCD_WriteData(0x0C);
  LCD_WriteData(0x0A);
  LCD_WriteData(0x28);
  LCD_WriteData(0x2F);
  LCD_WriteData(0x0F);
  
  LCD_WriteCommand(LCD_SLEEP_OUT);
  HAL_Delay(200);
  LCD_WriteCommand(LCD_DISPLAY_ON);
  /* GRAM start writing */
  LCD_WriteCommand(LCD_GRAM);
}
