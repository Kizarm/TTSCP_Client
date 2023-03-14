#ifndef EPOS_WAV_H
#define EPOS_WAV_H
struct wave_header
{
	char string1[4];
	int  total_length;
	char string2[8];
	//int  fmt_length;
	//short int  datform, numchan, sf1, sf2, avr1, avr2, alignment, samplesize;
	//chaloupka
	int  fmt_length,sf1, avr1;
	short int datform, numchan,alignment, samplesize;
	char string3[4];
	int  buffer_idx;
};			// .wav file header

#endif //  EPOS_WAV_H
