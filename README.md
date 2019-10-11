# iqconvert
Command line utility to convert IQ raw file. This first version supports complex float32 and complex unsigned 8 bits integer. This tool is usefull to play in [**GQRX**](http://gqrx.dk) IQ files recorded with [**rtl-sdr**](https://github.com/osmocom/rtl-sdr).

## /!\ warning /!\
This version does not perform check on the input file. In the case of float 32 input, it assumes that the samples are in the range [-1.0,1.0].

## build

	git clone https://github.com/cdeletre/iqconvert.git
	cd iqconvert
	make

#### mac os x

    cp iq-f32-to-u8 /usr/local/bin/
    cp iq-u8-to-f32 /usr/local/bin/

#### linux

    sudo cp iq-f32-to-u8 /usr/local/bin/
    sudo cp iq-u8-to-f32 /usr/local/bin/

## usage

#### convert complex float 32 to complex unsigned 8 bits integer

	cat iqfile.cfile | iq-f32-to-u8 > iqfile.cu8
	
#### convert complex unsigned 8 bits integer to complex float 32

	cat iqfile.cu8 | iq-u8-to-f32 > iqfile.cfile