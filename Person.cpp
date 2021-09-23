#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

long Person::get_m_phone_number() { return m_phone_number; }	//Return m_phone_number
int Person::get_m_student_number() { return m_student_number; }	//Return m_student_number
string Person::get_m_name() { return m_name; }					//Return m_name
Person::Person(string name, int student_number, long phone_number) :m_name{ name }, m_student_number{ student_number }, m_phone_number{ phone_number }{}
// Person constructor for initialization


void Founder::set_m_pick_up_item_num(int a) {m_pick_up_item_num = a;}// Set m_pick_up_item_num to parameter value
Founder::Founder(string name, int student_number, long phone_number) :Person(name, student_number, phone_number) {}
// Founder constructor for intialization

void Loster::set_m_lost_item_num(int a) {m_lost_item_num = a;}		// Set m_lost_item_num to parameter value
Loster::Loster(string name, int student_number, long phone_number) :Person(name, student_number, phone_number) {}
// Loster constructor for intialization



void Gainer::set_m_pick_up_item_num(int a) {m_pick_up_item_num = a;}// Set m_pick_up_item_num to parameter value
Gainer::Gainer(string name, int student_number, long phone_number) :Person(name, student_number, phone_number) {}
// Gainer constructor for intialization


int Administrator::get_m_password() { return m_password; }			// Return m_password
Administrator::Administrator(string name, int student_number, long phone_number) :Person(name, student_number, phone_number) {}
// Administrator constructor for intialization
