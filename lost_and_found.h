//
//  lost_and_found.h
//  Lost_and_Found
//
//  Created by Wonhyeok Choi on 2019/11/30.
//  Copyright © 2019 Wonhyeok Choi. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

enum lost_and_found_name {
	Life_Support_Center = 0,
	Undergraduate_Team,
	E8_Library,
	Serveone
};

class Lost_and_Found{
private:
// member variables
	int size;
    string* m_position;
    string* m_phone_number;
    string* m_lost_and_found_name;
    
public:
    Lost_and_Found(); // constructors
	void push_member(string lost_and_found_name, string phone_number, string position);
	int Size();
    string get_m_lost_and_found_name(int a);
// destructor
    ~Lost_and_Found(); //destructor
    
	string operator[](lost_and_found_name);
};


