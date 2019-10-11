all: iq-f32-to-u8 iq-u8-to-f32

iq-f32-to-u8: iq-f32-to-u8.o
	gcc -o iq-f32-to-u8 iq-f32-to-u8.c

iq-u8-to-f32: iq-u8-to-f32.o
	gcc -o iq-u8-to-f32 iq-u8-to-f32.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf iq-f32-to-u8 iq-u8-to-f32
