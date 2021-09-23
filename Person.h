#ifndef Person_h
#define Person_h


#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string m_name;         // Person's name
	int m_student_number;      // Person's student number if person is student
	long m_phone_number;      // Person's phone number if person has phone
public:
    Person(); // Default Constructor
    Person(string, int, long ); // Person constructor for initialization
    long get_m_phone_number();  // Return m_phone_number
    int get_m_student_number(); // Return m_student_number
    string get_m_name(); // Return m_name
};

class Founder : public Person {
private:
    int m_pick_up_item_num;
public:
    void set_m_pick_up_item_num(int); // Set m_pick_up_item_num to parameter value
    Founder(string, int, long ); // Founder constructor for intialization
};

class Loster : public Person {
private:
    int m_lost_item_num;
public:
    void set_m_lost_item_num(int); // Set m_lost_item_num to parameter value
	Loster(string, int, long); // Loster constructor for intialization
};

class Gainer : public Person {
private:
    int m_pick_up_item_num;
public:
	void set_m_pick_up_item_num(int); // Set m_pick_up_item_num to parameter value
	Gainer(string, int, long);// Gainer constructor for intialization
};

class Administrator : public Person {
private:
	int m_password{ 1234 }; // Password for checking administrator
public:
	Administrator(string, int, long); // Administrator constructor for intialization
    int get_m_password(); // Return m_password
};

#endif /* Person_h */
