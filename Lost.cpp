//
//  Lost.cpp
//  Lost class
//
//  Created by Changmin Lee on 2019/11/30.
//  Copyright © 2019 이창민. All rights reserved.
//
#include "Lost.h"

using namespace std;

Lost::Lost(){
    
}// Default Constructor

Lost::Lost(long lost_date, string brand, lost_type product_type, string characteristics, string loster_name){
    m_lost_date = lost_date;
    m_brand = brand;
    m_product_type = product_type;
    m_characteristics = characteristics;
    m_loster_name = loster_name;
} // Loster Constructor

Lost::Lost(string depository_if, long pick_up_date, string brand, lost_type product_type, string characteristics, string gainer_name){
    m_depository = depository_if;
    m_pick_up_date = pick_up_date;
    m_brand = brand;
    m_product_type = product_type;
    m_characteristics = characteristics;
    m_gainer_name = gainer_name;
} // Gainer Constructor

Lost::~Lost(){
    
}// Default Destructor

//int Lost::get_m_item_num(Lost* Lost_found); // Return m_item_num

long Lost::get_m_pick_up_date(){
    return m_pick_up_date;
} // Return m_pick_up_date

long Lost::get_m_lost_date(){
    return m_lost_date;
} // Return m_lost_date

long Lost::get_m_found_date(){
    return m_found_date;
} // Return m_found_date

bool Lost::get_m_yes_no(){
    return m_yes_no;
} // Return m_yes_no

void Lost::set_m_yes_no() {
	m_yes_no = 1;
} //Set m_yes_no

string Lost::get_m_brand(){
    return m_brand;
} // Return m_brand

lost_type Lost::get_m_product_type(){
    return m_product_type;
} // Return m_product_type

string Lost::get_m_characteristics(){
    return m_characteristics;
} // Return m_characteristics

string Lost::get_m_depository(){
    return m_depository;
} // Return m_depository

string Lost::get_m_founder_name(){
    return m_founder_name;
} // Return m_founder_name

void Lost::set_m_founder_name(string name) {
	m_founder_name = name;
} // Set m_founder_name

string Lost::get_m_loster_name(){
    return m_loster_name;
} // Return m_loster_name

string Lost::get_m_gainer_name(){
    return m_gainer_name;
} // Return m_gainer_name

long Lost::get_m_founder_SID() {
	return m_founder_SID;
}// Return m_founder_SID

long Lost::get_m_founder_phone_number() {
	return m_founder_phonenumber;
} // Return m_founder_phone_number

void Lost::set_founder_information(Founder f) {
	m_founder_SID = f.get_m_student_number();
	m_founder_phonenumber = f.get_m_phone_number();
	m_founder_name = f.get_m_name();
}

ostream& operator<< (ostream& out, const Lost& lost) {
	out << "Found date: " << lost.m_pick_up_date << "|Gainer name: " << lost.m_gainer_name << "|Characteristics: " << lost.m_characteristics << "|Depository: " << lost.m_depository << "|Collected=1/Not=0: " << lost.m_yes_no << endl;
	return out;
}
