#include "pico/stdlib.h"

#include "hardware/pio.h"
#include "i2s.h"

int main() {
	I2S_init(INPUT);
	I2S_setDATA(29);
	I2S_setBCLK(3); // LRCLK = +1
	I2S_setBitsPerSample(24);
	I2S_setFrequency(16000);
	I2S_begin();
	int32_t l, r, sample;

	while(1) {
		I2S_read32(&l, &r);
		sample = l ? l : r;
		printf("%.6x\n", sample);
	}
}
