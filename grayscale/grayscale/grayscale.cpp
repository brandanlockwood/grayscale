#include <stdio.h>
#include<iostream>
void show_bits(unsigned int x)
{
	int i;
	//Because int is 4 bytes we multiply by 8 (8 bits/byte)
	for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
		(x&(1 << i)) ? printf("1") : printf("0");

	printf("\n");
}

void convert_to_grayscale(unsigned int pixelarr[], unsigned int size) {
	printf("pix 1: %u pix 2: %u \n", pixelarr[0], pixelarr[1]);
	int i;
	unsigned int r, g, b, a, result;
	for (i = 0; i < size;i++)
	{
		//saves alpha,red,green,blue
		a = pixelarr[i] >> 24 & 0xff;
		g = pixelarr[i] >> 8 & 0xff;
		r = pixelarr[i] >> 16 & 0xff;
		b = pixelarr[i] & 0xff;
		//get average of red,green,blue
		result = (r + g + b) / 3;
		//set new r,g,b
		r = result;
		g = result;
		b = result;
		//return a,r,g,b to correct bits
		result = ((a << 24) + (r << 16) + (g << 8) + (b));
		pixelarr[i] = result;
	}
}

int main(int argc, char *argv)
{

	//Two int values as hex A R G B
	unsigned int pixels[] = { 0xAA112233, 0xBB334455 }, m, n, size = 0, p = 0;
	size = 2;

	convert_to_grayscale(pixels, size);

	printf("%u", pixels[1]);
	printf("\n");



	system("PAUSE");
	return 0;
}
