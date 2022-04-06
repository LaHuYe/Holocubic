#include "rgb_led.h"


void Pixel::init()
{
	FastLED.addLeds<WS2812, RGB_LED_PIN, GRB>(color_buffers, RGB_LED_NUM);// 初始化光带
	FastLED.setBrightness(200);// 设置光带亮度
}

Pixel& Pixel::setRGB(int id, int r, int g, int b)
{
	color_buffers[id] = CRGB(r, g, b);
	FastLED.show();

	return *this;
}

Pixel& Pixel::setBrightness(float duty)
{
	duty = constrain(duty, 0, 1);
	FastLED.setBrightness((uint8_t)(255 * duty));
	FastLED.show();

	return *this;
}
