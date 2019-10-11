/* -*- mode: c; c-file-style: "linux" -*-
 *
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <err.h>

int main(int argc, char **argv)
{
	while (true) {
		// Get a byte from stream
		float sample_float;
		if (fread(&sample_float, sizeof(float), 1, stdin) != 1) {
			// Error checks
			if (feof(stdin)) {
				// Stop gracefully if EOF.
				break;
			} else {
				// Something more evil happened.
				err(1,"Unable to read stdin");
			}
		}
		uint8_t sample_u8 = (sample_float + 1.0)/2.0 * 0xff;
		fwrite(&sample_u8, sizeof(uint8_t),1,stdout);
	}
	return 0;
}
