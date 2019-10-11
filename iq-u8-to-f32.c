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
		uint8_t sample_u8;
		if (fread(&sample_u8, sizeof(uint8_t), 1, stdin) != 1) {
			// Error checks
			if (feof(stdin)) {
				// Stop gracefully if EOF.
				break;
			} else {
				// Something more evil happened.
				err(1,"Unable to read stdin");
			}
		}
		float sample_float;
		sample_float = (sample_u8 / 127.5) - 1.0;
		fwrite(&sample_float, sizeof(float),1,stdout);
	}
	return 0;
}
