

#include <stdio.h>
#include "lost_and_found.h"
#include <string>

using namespace std;

//  constructors
Lost_and_Found::Lost_and_Found() 
	:size{ 0 }, m_position {new string[5]}, m_phone_number{ new string[5] }, m_lost_and_found_name{ new string[5] } {} // default constructor

void Lost_and_Found::push_member(string lost_and_found_name, string phone_number, string position) {
	m_position[size] = position;
	m_phone_number[size] = phone_number;
	m_lost_and_found_name[size] =  lost_and_found_name;
	size++;
}

int Lost_and_Found::Size() { return size; }

string Lost_and_Found::get_m_lost_and_found_name(int a) {return m_lost_and_found_name[a];}

//  destructor
Lost_and_Found::~Lost_and_Found(){
	delete[] m_position, m_phone_number, m_lost_and_found_name;
}

string Lost_and_Found::operator[](lost_and_found_name x) {
	return m_lost_and_found_name[x] + " | phone_num : " + m_phone_number[x] + "| position : " + m_position[x];
}
