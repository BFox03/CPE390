#include <fstream>
#include "bitmap.hh"
#include <webp/decode.h>
#include <webp/encode.h>
#include <random>
#include <cmath>

using namespace std;
/*

	AUTHOR: Brandon Fox
	CITE: https://www.gormanalysis.com/blog/random-numbers-in-cpp/#:~:text=We%20start%20by%20creating%20a%20default_random_engine%20from%20C%2B%2B%E2%80%99s,can%20use%20myRandomEngine%20to%20generate%20some%20random%20numbers.
		  https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
		  Justin Ferber (Partner)
	I pledge my honor that I have abided by the Stevens Honor System.
*/

/*
	In order to compile you will need to install libwebp, a new graphics
	standard from google. Most image programs won't yet work with webp,
	which is better compression than jpeg in general.

	In order to install under msys2: 
	https://packages.msys2.org/package/mingw-w64-x86_64-libwebp

	In order to access a particular element of this bitmap (x,y) use the
	following equation point(x,y) does this

	y*w + x

	this works because the first point is 0*w+0 = 0, the second would be 0*w+1

	one row down would be 1*w + 0
 */


bitmap::bitmap(uint32_t w, uint32_t h, uint32_t color) : w(w), h(h), rgb(new uint32_t[w*h]) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

bitmap::~bitmap() {
	delete [] rgb;
}

void bitmap::clear(uint32_t color) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
	for (uint32_t i = y * w + x1; i <= y * w + x2; i++) rgb[i] = color;
}

void bitmap::vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color) {
	//TODO: implement this 
	for (uint32_t i = y1 * w + x; i <= y2 * w + x; i+= w) rgb[i] = color;
}

void bitmap::fill_rect(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t color) {
	//TODO: implement this
	for (int i = y0; i <= y0 + rh; i++){
		horiz_line(x0, x0+rw, i, color);
	} 
}

void bitmap::rect(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t color) {
	//TODO: implement this
	for (int i = y0; i <= y0 + rh; i++){
		if (i == y0 or i == y0 + rh) horiz_line(x0, x0+rw, i, color);
		else {
			rgb[i*w+x0] = color;
			rgb[i*w+x0+rw] = color;
		}
	}   
}

void bitmap::grid(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh,
									uint32_t divx, uint32_t divy, uint32_t color) {
	//TODO: implement this  
	rect(x0, y0, rw, rh, color);
	uint32_t x = rh / divy;

	uint32_t y = rw / divx;
	for(int i = x0; i <= x0 + rw; i+=x){
		vert_line(y0, y0 + rh, i, color);
	}
	for(int i = y0; i <= y0 + rh; i+=y){
		horiz_line(x0, x0 + rw, i, color);
	}
}


std::default_random_engine gen;
std::uniform_int_distribution<int> numgen(0x0, 0xf); //1 in 16 chance

//https://stackoverflow.com/questions/22853349/how-to-generate-random-32bit-integers-in-c
void bitmap::random(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh) {
	//TODO: implement this
	for (int i = y0; i <= y0 + rh; i++){
		for (uint32_t j = i * w + x0 + numgen(gen); j <= i * w + x0+rw; j+=numgen(gen)){
			rgb[j] = 0xFFFFFFFF;
		} 
	} 
}


void bitmap::circle(uint32_t x, uint32_t y, uint32_t d, uint32_t color) {
	//TODO: implement this  
	uint32_t r = d/2, dy = d/2, dx = 0;

	while (dx <= dy){
		//cout << "dx: " << dx << "  dy: " << dy << "  f: " << (pow(dx, 2) + pow(dy, 2)) - pow(r, 2) << endl; 
			// f being the discrimanate

		rgb[(y - dx) * w + (x + dy)] = color; // 0°-45°
		rgb[(y - dy) * w + (x + dx)] = color; // 45°-90°
		rgb[(y - dy) * w + (x - dx)] = color; // 90°-135°
		rgb[(y - dx) * w + (x - dy)] = color; // 135°-180°
		rgb[(y + dx) * w + (x - dy)] = color; // 180°-225°
		rgb[(y + dy) * w + (x + dx)] = color; // 225°-270°
		rgb[(y + dy) * w + (x - dx)] = color; // 270°-315°
		rgb[(y + dx) * w + (x + dy)] = color; // 315°-360°
		
		
		if ((pow(dx, 2) + pow(dy, 2)) - pow(r, 2) >= 0) {
			dy--;
		} else{
			dx++;
		}
	}

}

//https://stackoverflow.com/questions/1201200/fast-algorithm-for-drawing-filled-circles
void bitmap::fill_circle(uint32_t x0, uint32_t y0, uint32_t d, uint32_t color) {
	//TODO: implement this  
	rgb[y0*w+x0] = color;
	for (int i = d; i > 1; i--){
		circle(x0,y0,i,color);
	}
}


void bitmap::save(const char filename[]) {
	uint8_t*out;
	size_t s = WebPEncodeRGBA((uint8_t*)rgb, w, h, 4*w, 100, &out);
	ofstream f(filename, ios::binary);
	f.write((char*)out, s);
	WebPFree(out);
}
