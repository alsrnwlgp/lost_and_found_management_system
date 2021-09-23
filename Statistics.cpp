
#include "Statistics.h"

using namespace std;

Statistics::Statistics(){
    
}
//default constructor

Statistics::~Statistics(){
    
}
//default destructor

int Statistics::get_m_today_gain_pdt(int count_gain_pdt, vector<Lost> Lost_found){
    int a = 0;
    for (int i=0; i<count_gain_pdt; i++){
        if (m_today_date == Lost_found[i].get_m_pick_up_date()){
                a++;
        }
    }
    m_today_gain_pdt = a;
    return m_today_gain_pdt;
} // Return m_today_gain_pdt

int Statistics::get_m_untiltoday_gain_pdt(int count_gain_pdt){
    m_untiltoday_gain_pdt = count_gain_pdt;
    return m_untiltoday_gain_pdt;
} // Return m_untiltoday_gain_pdt

string Statistics::get_m_found_ratio(int count_gain_pdt, int count_upload_pdt, vector<Lost> Lost_found, vector<Lost> Lost_upload){
    double num_False = 0;
    double num_True = 0;
    for (int i=0; i<count_gain_pdt; i++){
        if (Lost_found[i].get_m_yes_no() == true){
            num_True++;
        }
        else{
            num_False++;
        }
    }
    for (int i=0; i<count_upload_pdt; i++){
        if (Lost_upload[i].get_m_yes_no() == true){
            num_True++;
        }
        else{
            num_False++;
        }
    }
    if (num_False+num_True != 0){
        double num = (num_True / (num_True + num_False))*100;
        auto s = to_string(num);
        m_found_ratio = s+"%";
    }
    else{
        cout<<"There is no lost items in depository."<<endl;
    }        
    return m_found_ratio;
}
 // Return m_found_ration + "%"

int Statistics::get_m_today_upload_pdt(int count_upload_pdt, vector<Lost> Lost_upload){
    int b = 0;
    for (int i=0; i<count_upload_pdt; i++){
        if (m_today_date == Lost_upload[i].get_m_lost_date()){
            b++;
        }
    }
    m_today_upload_pdt = b;
    return m_today_upload_pdt;
} // Return m_today_upload_pdt

int Statistics::get_m_untiltoday_upload_pdt(int count_upload_pdt){
    m_untiltoday_upload_pdt = count_upload_pdt;
    return m_untiltoday_upload_pdt;
} // Return m_untiltoday_upload_pdt

long Statistics::get_m_today_date(){
    return m_today_date;
} // Return m_today_date

void Statistics::set_m_today_date(){
    cout<<"Insert today's date.\n";
    cin>>m_today_date;
} // Set m_today_date

void Statistics::show_file(int count_gain_pdt, int count_upload_pdt, vector<Lost> Lost_found, vector<Lost> Lost_upload){
    ofstream oft("Statistics information.txt", ios::trunc);
    oft<<"Today is "<<get_m_today_date()<<".\n";
    oft<<"The number of lost items that came in today is "<<get_m_today_gain_pdt(count_gain_pdt, Lost_found)<<".\n";
    oft<<"The number of lost items that came until today is "<<get_m_untiltoday_gain_pdt(count_gain_pdt)<<".\n";    oft<<"The number of lost items that uploaded in today is "<<get_m_today_upload_pdt(count_upload_pdt, Lost_upload)<<".\n";
    oft<<"The number of lost items that uploaded until today is "<<get_m_untiltoday_upload_pdt(count_upload_pdt)<<".\n";
	oft << "Until today the percentage of total lost and found by the missing is  " << get_m_found_ratio(count_gain_pdt, count_upload_pdt, Lost_found, Lost_upload) << ".\n";
    oft.close();
} // Print all statistics information to "Statistics.txt" file.

