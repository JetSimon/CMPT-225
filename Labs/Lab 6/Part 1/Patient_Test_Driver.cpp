/*
 * Patient_Test_Driver.cpp - Lab 6
 * 
 * Class Description: Test Driver for Patient class
 *
 * Author: AL
 * Date: Last modified: Feb. 2022
 */

#include <iostream>
#include "Patient.h"

using namespace std;

int main() {

	// Variables declaration
	Patient p1234567890("1234567890");
	Patient p3456789012("3456789012");
	Patient p4567890123("4567890123");
   	   	   	   
	cout << endl;

	cout << "Here is Patient 4567890123 : " << endl;
	p4567890123.setName("Marie Poppins");
	p4567890123.setAddress("Somewhere over the hills");
	p4567890123.setPhone("234.987.9256");
	p4567890123.setEmail("mp@gemate.com");
	cout << p4567890123 << endl;

	cout << "Here is Patient 1234567890 : " << endl;
	p1234567890.setName("R2D2");
	p1234567890.setAddress("Somewhere over the sea");
	p1234567890.setPhone("925.236.9876");
	p1234567890.setEmail("r2d2@gemate.com");
	cout << p1234567890 << endl;
    
	cout << "Here is Patient 3456789012 : " << endl;
	p3456789012.setName("Odo");
	p3456789012.setAddress("Somewhere in space");
	p3456789012.setPhone("*^%-#^$-1234");
	p3456789012.setEmail("odo@gemate.com");
	cout << p3456789012 << endl;

	return 0;
}