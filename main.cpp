
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include "lost_and_found.h"
#include "Lost.h"
#include "Statistics.h"
#include "Person.h"

using namespace std;

int search_lost_item(vector<Lost>& v) {
	int item_type; // item type
	int lost_date; // lost date format of [YYYYMMDD] is recommended for everyone
	string brand_name; // brand name
	int q1 = 0; // if the data for question 1 is typed in switch to 1
	int q2 = 0; // if the data for question 2 is typed in switch to 1
	int q3 = 0; // if the data for question 3 is typed in switch to 1
	int index_looking_for_item;

	cout << "Search Engine Started!\n" << endl;
	for (;;) {
		for (;;) {
			cout << "Please enter your item inormations.\n" << "What kind of information do you have?\n" << endl;
			cout << "0. Back\n" << "1. Item type\n" << "2. Brand name\n" << "3. Lost date\n" << endl; // list of options for search
			int temp1; cin >> temp1; // which question the user is trying to input
			if (temp1 == 0) {
				cout << "Wait..." << endl;
				break;
			} // if 0 is typed, end the search engine

			else if (temp1 == 1) {
				cout << "Please enter your item type...\n" << "1. Clothes\n" << "2. Electronics\n" << "3. Cards\n" << "4. Accessaries\n" << "5. Foods\n" << "0. etc\n" << endl;
				cin >> item_type;
				q1 = 1;
			} // enter the type of the item

			else if (temp1 == 2) {
				cout << "Please enter your item's brand or name...\n";
				cin >> brand_name;
				q2 = 1;
			} // enter the brand name of the item

			else if (temp1 == 3) {
				cout << "Please enter your item's lost date...\n";
				cin >> lost_date;
				q3 = 1;
			} // enter the lost date of the item

			cout << "Do you have any other informations?\n" << "1. Yes\n" << "2. No\n";

			int temp2; cin >> temp2; // if 1 -> go back to question and ask further question, if 0 -> go to the next step start searching

			if (temp2 == 1) {
				cout << "Searching…\n" << endl;
			}

			else if (temp2 == 2) {
				break;
			}
		}

		int item_size = v.size();
		int* ind_vector = new int[item_size]; int ind_vector_size = 0;
		if (q1 == 0) {
			if (q2 == 0) {
				if (q3 == 0) {// q1 == 0; q2 == 0; q3 == 0;
                     cout << "Going back to the previous menu" << endl;
				}

				else {// q1 == 0; q2 == 0; q3 == 1;
					cout << "Finding results within 3 days of the day you lost...\n";
					for (int i = 0; i < item_size; i++) {
						if ((lost_date - 3) <= v.at(i).get_m_found_date() <= (lost_date + 3)) {
							ind_vector[ind_vector_size] = i;
							ind_vector_size++;
						} // by default it checks the date back and forth three days, but ignores it if the month changes.
					}
				}
			}

			else {
				if (q3 == 0) {// q1 == 0; q2 == 1; q3 == 0;
					cout << "Finding results within same brand name...\n";
					for (int i = 0; i < item_size; i++) {
						if (brand_name.compare(v.at(i).get_m_brand()) == 0) { // searching for the same brand type
							ind_vector[ind_vector_size] = i;
							ind_vector_size++;
						}
					}
				}

				else { // q1 == 0; q2 == 1; q3 == 1;
					cout << "Finding results within same brand name...\n";
					for (int i = 0; i < item_size; i++) {
						if (brand_name.compare((v.at(i).get_m_brand())) == 0) { // searching for the same brand type
							ind_vector[ind_vector_size] = i;
							ind_vector_size++;
						}
					}
					cout << "Finding results within 3 days of the day you lost...\n";
					for (int j = 0; j < ind_vector_size; j++) {
						if ((lost_date - 3) <= v.at(ind_vector[j]).get_m_found_date() <= (lost_date + 3)) { // searching for the appropriate found date items among same brand type items

						}
						else {
							ind_vector[j] = -1;
						}
					}
				}
			}
		}

		else {// q1 == 1;
			cout << "Finding results within same item type...\n";
			for (int i = 0; i < item_size; i++) {
				if (item_type == v.at(i).get_m_product_type()) { // m_cloth = 1, m_electronics = 2, m_card = 3, m_accessaries = 4, m_food = 5, m_etc = 0;
					ind_vector[ind_vector_size] = i;
					ind_vector_size++;
				} // searching for the same item type
			}

			if (q2 == 0) {
				if (q3 == 0) {// q1 == 1; q2 == 0, q3 == 0

				} // return items that have same item type

				else {// q1 == 1, q2 == 0, q3 == 1
					for (int j = 0; j < ind_vector_size; j++) {
						if ((lost_date - 3) <= v.at(ind_vector[j]).get_m_found_date() <= (lost_date + 3)) {

						} // searching for the appropriate found date items among same item type items

						else {
							ind_vector[j] = -1;
						}
					}
				}
			}

			else { // q1 == 1; q2 == 1;
				cout << "Finding results within same brand name...\n";
				for (int j = 0; j < ind_vector_size; j++) {
					if ((brand_name.compare(v.at(ind_vector[j]).get_m_brand())) == 0) {

					}

					else {
						ind_vector[j] = -1;
					}
				}

				if (q3 == 0) {// q1 == 1, q2 == 1, q3 == 0

				} // return items that have same item type and brand name

				else {// q1 == 1, q2 == 1, q3 == 1
					cout << "Finding results within 3 days of the day you lost...\n";
					for (int k = 0; k < ind_vector_size; k++) {
						if ((lost_date - 3) <= v.at(ind_vector[k]).get_m_found_date() <= (lost_date + 3)) {

						} // searching for the appropriate found date items among same item type items and same brand name items

						else {
							ind_vector[k] = -1;
						}
					}
				}
			}
		}
        
        if (q1 == 0 && q2 == 0 && q3 == 0){
            return -1;
        }

        else{
            // printing all the item information matching the users information
            for (int k = 0; k < ind_vector_size; k++) {
                if (ind_vector[k] != -1) {
                    cout << ind_vector[k] << ":" << v[ind_vector[k]];
                }
            }

            cout << "Is there any item you are looking for?\n"<<"1. Yes\n"<<"2. Press any key to go back\n";
            int temp1; cin>>temp1;
            if (temp1 == 1){
                cout << "Please enter item number you are looking for\n";
                cin >> index_looking_for_item;
                delete[] ind_vector; // delete index vector containing index information
                ind_vector = nullptr; // change ind_vector pointer to null pointer
                return index_looking_for_item; // return item_to_find index
            }
            else{
                delete[] ind_vector; // delete index vector containing index information
                ind_vector = nullptr; // change ind_vector pointer to null pointer
                return -1;
            }
        }

	}
}




int main() {

	Lost_and_Found DGIST; // creating depository classes in form of vector
	DGIST.push_member("Life_Support_Center", "0537207882", "333, Techno jungang-daero, Hyeonpung-eup, Dalseong-gun, Daegu, Republic of Korea");
	DGIST.push_member("Undergraduate_Team", "0537856630", "333, Techno jungang-daero, Hyeonpung-eup, Dalseong-gun, Daegu, Republic of Korea");
	DGIST.push_member("E8, Library", "0537851155", "333, Techno jungang-daero, Hyeonpung-eup, Dalseong-gun, Daegu, Republic of Korea");
	DGIST.push_member("Serveone", "0537857119", "333, Techno jungang-daero, Hyeonpung-eup, Dalseong-gun, Daegu, Republic of Korea");

	vector<Lost> item_to_find; // loster (person who lost an item)
	int num_item_to_find = 0; // total number of items posted lost
	vector<Lost> item_lost; // gainer(person who picked up an item)
	int num_item_lost = 0; // Total number of items posted to find

	int today_date; // today’s date

	vector<Founder> founder; // founder vector

	Administrator admin("admin", 201400000, 01000000000);


	cout << "Are you the administrator?" << endl;
	cout << "1. YES\n" << "2. NO\n"; // ask if the person is administrator at the very first of the program

	int administrator_check; cin >> administrator_check;

	if (administrator_check == 1) { // if administrator check for the password for 5 times, default 1234
		for (int i = 0; i < 5; i++) {
			cout << "Please enter the password:";
			int password; cin >> password;
			if (admin.get_m_password() == password) {
				cout << "WELCOME! Please enter today's date(YYYYMMDD)" << endl;
				int temp; cin >> temp;
				for (;;) {
                        int year = temp / 10000; int month = (temp - year * 10000) / 100; int day = (temp - year * 10000 - month * 100);
                        if (month > 12 || month < 1 || day > 31 || day < 0) {
                       cout << "Please enter the date in right format" << endl; // check date format
                        cin>>temp;
					}
					else {
						today_date = temp;
						break;
					}
				}
				break;
			}
			else if (admin.get_m_password() != password && i < 4) {
				cout << "Wrong Password. Please check your password" << endl;
			}

			else {
				cout << "Abnormal Approach. Exiting Program" << endl; // wrong password for 5 time s -> end program
				exit(0);
			}
		}
	}
	else {
		cout << "Contact the administrator to run the program\n" << "Ending Program" << endl;
		exit(0);
	}


	for (;;) {
		int date;
		bool yes_no; // default False, If found True 
		string brand; // 
		string characteristics; // description of item 
		string depository; // where the item is located 
		string name; // name of the person
		lost_type product_type; // product type
		int student_number;
		long phone_number;


		cout << "Please Give Your Information."<<endl;
		cout << "Please Enter Your Name." << endl;
		cin >> name;
		cout << "Please Enter Your Student Number" << endl;
		cin >> student_number;
		cout << "Please Enter Your Phone Number" << endl;
		cin >> phone_number;

		int input;
		cout << "Who Are You?" << endl;
		cout << "1. Loster 2. Gainer  3. Administrator 4. Exit" << endl;
		cin >> input;

		if (input == 1) {									//If User Select '1. Loster'
			Loster loster(name, student_number, phone_number);//Create Loster type instance

			int act;
			cout << "What Do You Want to Do?" << endl;

		LOSTER:
			cout << "1. Search 2. Register" << endl;
			cin >> act;

			if (act == 1) {								//If user select '1. Search' as Loster
				int mine = search_lost_item(item_to_find);
				if (mine > -1) {					//If user choose item in Search Function
					if (item_to_find[mine].get_m_yes_no() == 1) {
						cout << "It Is Already Recovered by Someone. Do You Want to See the Information of The Person?" << endl;
						cout << "1. Yes 2. No" << endl;
						int a;
						cin >> a;
						if (a == 1) {
							cout << item_to_find[mine].get_m_founder_name() << endl;
							cout << item_to_find[mine].get_m_founder_SID() << endl;
							cout << item_to_find[mine].get_m_founder_phone_number() << endl;
						}
                        else{cout<<"Search Engine Ended!\n";}
					} // if someone already recovered the item, User can see the information of the person.
					else if (item_to_find[mine].get_m_yes_no() == 0) {	// take lost item and create Founder
						Founder f_tmp(loster.get_m_name(), loster.get_m_student_number(), loster.get_m_phone_number());
						f_tmp.set_m_pick_up_item_num(mine);
						item_to_find[mine].set_m_yes_no();
						item_to_find[mine].set_founder_information(f_tmp);
					}
                    cout << "Search Engine Ended!\n";
				}
                
				else if (mine < 0) {
                    cout << "Search Engine Ended!\n";
                    goto LOSTER;
                }		//If user couldn't find his item
			}

			if (act == 2) {								//If user select'2. Register' as Loster
				cout << "When Did You Lost It ? [ex) 20191201]" << endl;
				cin >> date;
				int tmp_1;
				cout << "What Kind of Things Have You Lost?\n1. Clothes 2.Electronics 3. Card 4. Accessaries 5. Food 0. Ect" << endl;
				cin >> tmp_1;
				if (tmp_1 == 0) product_type = m_etc;
				if (tmp_1 == 1) product_type = m_cloth;
				if (tmp_1 == 2) product_type = m_electronics;
				if (tmp_1 == 3) product_type = m_card;
				if (tmp_1 == 4) product_type = m_accessaries;
				if (tmp_1 == 5) product_type = m_etc;
				cout << "What Brand Is It? [ex)apple, saumsung, lg]" << endl;
				cin >> brand;
				cout << "Please Describe the Characteristics of It" << endl;
				cin >> characteristics;

				Lost item(date, brand, product_type, characteristics, name); //Create Lost type instance
				item_lost.push_back(item);//Put Lost instance into item_lost Vector
				num_item_lost++;
				loster.set_m_lost_item_num(num_item_lost);
				cout << "Registered.\n";
			}
		}
		else if (input == 2) {//If User Select '2. Gainer'
			Gainer gainer(name, student_number, phone_number);//Create Gainer type instance
			cout << "When Did You Get It ? " << endl;
			cin >> date;
			cout << "What Kind of Things Did You Gain?\n1. Clothes 2.Electronics 3. Card 4. Accessaries 5. Food 0. Ect" << endl;
			int tmp_1;
			cin >> tmp_1;
			product_type = static_cast<lost_type>(tmp_1);
			cout << "What Brand Is It? [ex)apple, saumsung, lg]" << endl;
			cin >> brand;
			cout << "Please Describe the Characteristics of It" << endl;
			cin >> characteristics;
			cout << "Where Do You Want to Keep It?\n1.Life_Support_Center 2.Undergraduate_Team 3.E8_Library 4.Serveone" << endl;
			int tmp_2;
			cin >> tmp_2;
			depository = DGIST[static_cast<lost_and_found_name>(tmp_2 - 1)];

			Lost item(depository, date, brand, product_type, characteristics, name);//Create a Lost type instance
			item_to_find.push_back(item);//Put Lost instance into item_to_find Vector
			num_item_to_find++;
			gainer.set_m_pick_up_item_num(num_item_to_find);
			cout << "Registered" << endl;
		}

		else if (input == 3) {//If User Select '3. Administrator'
			int act;
		STATISTICS:
			cout << "What Do You Want to Do?" << endl;
			cout << "1. Statistics 2. Deleting the Recovered Item " << endl;
			cin >> act;
			if (act == 1) {//If user select '1. Statistics' as Administrator
				Statistics s;//Create Statistics type instance
				s.set_m_today_date();//Set m_today_date in s
				int select;
				cout << "Please Select from the Menu" << endl;//
				cout << "	1. Show Today's Item to Find " << endl;
				cout << "	2. Show Item to Find until Today" << endl;
				cout << "	3. Show Today's Losted Item" << endl;
				cout << "	4. Show Losted Item until Today" << endl;
				cout << "	5. Show the Recovered Item Ratio" << endl;
                cout << "	6. Create a File of Overall Statistics" << endl;
				cin >> select;
                if (select == 1) {cout << s.get_m_today_gain_pdt(num_item_to_find, item_to_find) << endl;}
				//If user select 1.Show Today's Item to Find
				else if (select == 2) { cout << s.get_m_untiltoday_gain_pdt(num_item_to_find) << endl; }
				//If user select 2. Show Item to Find until Today
				else if (select == 3) { cout << s.get_m_today_upload_pdt(num_item_lost, item_lost) << endl; }
				//If user select 3. Show Today's Losted Item1
				else if (select == 4) { cout << s.get_m_untiltoday_upload_pdt(num_item_lost) << endl; }
				//If user select 4. Show Losted Item until Today
				else if (select == 5) { cout << s.get_m_found_ratio(num_item_to_find, num_item_lost, item_to_find, item_lost) << endl; }
				//If user select 5. Show the Recovered Item Ratio
				else if (select == 6) {
					s.show_file(num_item_to_find, num_item_lost, item_to_find, item_lost);
					cout << "Created." << endl;
				}
				//If user select 6. Create a File of Overall Statistics	
				int a;
				cout << "Do You Want to Do Other Works?" << endl;
				cout << "1. Yes 2. No" << endl;
				cin >> a;
				if (a == 1) { goto STATISTICS; }
				else if (a == 2) { break; }
			}
			if (act == 2) {//If user select '2. Deleting the Recovered Item' as Administrator
				cout << "What Do You Want To Delete?" << endl;
				int index = 0;
				for (int i = 0; i < num_item_to_find; i++) { //Show the recovered item list to Administrator
					if (item_to_find[i].get_m_yes_no() == 1) {
						cout << "item" << index << "." << "Depository: " << item_to_find[i].get_m_depository() <<
							"Gainer: " << item_to_find[i].get_m_gainer_name() << endl;
					}
					index++;
				}
                if (index == 0){
                    cout << "There are no recovered items\n" << "Going back to the previous page\n";
                    goto STATISTICS;
                }
				int choice;
				cin >> choice;
				item_to_find.erase(item_to_find.begin() + choice);//Delete the item what admin selected from item_to_find Vector
                num_item_to_find--;
				cout << "Deleted." << endl;
				int a;
				cout << "Do You Want to Do Other Works?" << endl;
				cout << "1. Yes 2. No" << endl;
				cin >> a;
				if (a == 1) { goto STATISTICS; }
				else if (a == 2) { break; }
			}
		}

		else if (input == 4) { //If User Select '4. Exit'
			break;
		}
	}
}
