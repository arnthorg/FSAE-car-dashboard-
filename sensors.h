/*
 * sensors.h
 *
 *  Created on: 30. apr. 2016
 *      Author: Arn��r
 */

#ifndef SENSORS_H_
#define SENSORS_H_
int8_t manifoldTempRef(int8_t value) {
static const int8_t lookup[256] = {
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,109,105,102,99,97,95,93,
		92,91,89,88,86,85,84,83,82,81,80,79,78,77,
		76,75,75,74,73,72,71,71,70,69,69,68,67,66,
		66,65,64,64,63,62,62,61,61,60,60,59,58,58,
		57,57,56,56,55,55,54,54,53,53,52,51,51,50,
		49,49,48,47,47,46,46,45,44,44,43,43,42,42,
		41,41,40,40,39,39,38,38,37,37,36,36,36,35,
		35,34,34,33,33,32,32,32,31,31,30,30,30,29,
		29,28,28,28,27,27,26,26,26,25,25,24,24,24,
		23,23,22,22,22,21,21,20,20,20,19,19,19,18,
		18,17,17,17,16,16,15,15,15,14,14,14,13,13,
		12,12,12,11,11,10,10,9,9,9,8,8,8,7,7,6,6,
		6,5,5,4,4,3,3,3,2,1,1,0,0,-1,-1,-2,-2,-3,
		-3,-4,-4,-5,-5,-5,-6,-6,-7,-7,-8,-9,-9,-10,
		-11,-11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0};
return lookup[value];
}
uint8_t fluidTempRef(uint8_t value) {
  static const  uint8_t lookup[256] = {
  0,0,0,0,0,0,0,0,0,0,0,0,179,175,172,169,166,163,161,
  159,157,155,153,151,149,148,146,144,143,142,140,139,
  138,136,135,134,133,132,131,130,129,128,127,126,125,
  124,123,122,122,121,120,119,118,118,117,116,115,115,
  114,113,113,112,111,111,110,109,109,108,108,107,106,
  106,105,105,104,104,103,103,102,101,101,100,100,99,99,
  98,98,97,97,96,96,95,95,94,94,94,93,93,92,92,91,91,90,
  90,89,89,89,88,88,87,87,86,86,86,85,85,84,84,84,83,83,
  82,82,82,81,81,80,80,79,79,79,78,78,78,77,77,76,76,76,
  75,75,74,74,74,73,73,72,72,72,71,71,70,70,70,69,69,68,
  68,68,67,67,66,66,66,65,65,64,64,64,63,63,62,62,62,61,
  61,60,60,60,59,59,58,58,57,57,57,56,56,55,55,54,54,53,
  53,52,52,52,51,51,50,50,49,49,48,48,47,47,46,45,45,44,
  44,43,43,42,41,41,40,40,39,38,38,37,36,36,35,34,33,33,
  32,31,30,29,28,28,27,26,25,24,22,21,20,19,17,16,0,0,0,
  0,0,0,0,0,0,0,0};
  return lookup[value];
}
uint8_t oilPressureRef(uint8_t value) {
	// It's wise to switch to the internal 1.1 V ref
	// since the resistance of the sender is very low (1-160ohm)
	// and will only output 0-500mV between 0 and 6.5Bar
	// when using a 1k resistor.
	return (0.0802 * value + 0.0062);
}
uint8_t manifoldPressureRef(uint8_t value) {
	return (0.0438 * value + 0.0991);
}


#endif /* SENSORS_H_ */
