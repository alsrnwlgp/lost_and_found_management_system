//
//  Lost.h
//  Lost class
//
//  Created by Changmin Lee on 2019/11/30.
//  Copyright © 2019 이창민. All rights reserved.
//

#ifndef Lost_h
#define Lost_h

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

enum lost_type {
   m_etc = 0,
   m_cloth,
   m_electronics,
   m_card,
   m_accessaries,
   m_food
}; // Type of lost products

class Lost{
private:
//    int m_item_num; // Number of products
    long m_pick_up_date; // Date of picked up day
    long m_lost_date; // Date of lost day
    long m_found_date; // Date of found day
    bool m_yes_no = 0; // True or False which returned to loster
    string m_brand; // Name of product's brand name
    lost_type m_product_type; // Product type
    string m_characteristics; // Contents of item's characteristics
    string m_depository; // Current location of products
    string m_founder_name; // Name of the person who found the item
	long m_founder_SID; // Student number of founder
	long m_founder_phonenumber; // Phone number of founder
    string m_loster_name; // Name of the person who lost the item
    string m_gainer_name; // Name of the person who gain the item
public:
    Lost(); // Default Constructor
    Lost(long, string, lost_type, string, string); // Loster Constructor
    Lost(string, long, string, lost_type, string, string); // Gainer COnstructor
    ~Lost(); // Default Destructor
//    int get_m_item_num(); // Return m_item_num
    long get_m_pick_up_date(); // Return m_pick_up_date
    long get_m_lost_date(); // Return m_lost_date
    long get_m_found_date(); // Return m_found_date
    bool get_m_yes_no(); // Return m_yes_no
	void set_m_yes_no();//Set m_yes_no
    string get_m_brand(); // Return m_brand
    lost_type get_m_product_type(); // Return m_product_type
    string get_m_characteristics(); // Return m_characteristics
    string get_m_depository(); // Return m_depository
    string get_m_founder_name(); // Return m_founder_name
	long get_m_founder_SID();
	long get_m_founder_phone_number();
	string set_m_founder_name();//Set m_founder_name
    string get_m_loster_name(); // Return m_loster_name
    string get_m_gainer_name(); // Return m_gainer_name
    void set_founder_information(Founder f);
    void set_m_founder_name(string name);
    friend class Statistics;
    friend class Founder;

	friend ostream& operator<< (ostream& out, const Lost& lost); // Operator<<
};


#endif /* Lost_h */
