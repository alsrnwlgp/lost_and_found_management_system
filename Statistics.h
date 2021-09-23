//
//  Statistics.h
//  Statistics class
//
//  Created by Changmin Lee on 2019/11/30.
//  Copyright © 2019 이창민. All rights reserved.
//

#ifndef Statistics_h
#define Statistics_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Lost.h"

using namespace std;

class Statistics{
private:
    int m_today_gain_pdt; //Number of gained product today
    int m_untiltoday_gain_pdt; //Number of gained product until today
    string m_found_ratio; // Percent of found product ration
    int m_today_upload_pdt; // Number of uploaded product today
    int m_untiltoday_upload_pdt; // Number of uploaded product until today
    long m_today_date; // Date of today
public:
    Statistics(); // default Constructor
    ~Statistics(); // default Destructor
    int get_m_today_gain_pdt(int, vector<Lost>); // Return m_today_gain_pdt
    int get_m_untiltoday_gain_pdt(int); // Return m_untiltoday_gain_pdt
    string get_m_found_ratio(int, int, vector<Lost>, vector<Lost>); // Return m_found_ration + "%"
    int get_m_today_upload_pdt(int, vector<Lost>); // Return m_today_upload_pdt
    int get_m_untiltoday_upload_pdt(int); // Return m_untiltoday_upload_pdt
    long get_m_today_date(); // Return m_today_date
    void set_m_today_date(); // Set m_today_date
    void show_file(int, int, vector<Lost>, vector<Lost>); // Print all statistics information to "Statistics information.txt" file.
    friend class Lost;
    friend class Person;
};
#endif /* Statistics_h */

