//
//  main.cpp
//  hpate59_Project1
//
//  Created by Harshil Patel on 1/23/18.
//  Copyright © 2018 UIC. All rights reserved.
//

/*main.cpp*/

//
// Banking program in modern C++.
//
// <<Name: Harshil Patel>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 01
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>


#include "customer.h"

using namespace std;


int main()
{
    string  customerFilename, transactionsFilename;
    
    cin >> customerFilename;
    cout << customerFilename << endl;
    
    cin >> transactionsFilename;
    cout << transactionsFilename << endl;
    
    ifstream  custFile(customerFilename);
    ifstream  txFile(transactionsFilename);
    
    cout << std::fixed;
    cout << std::setprecision(2);
    
    if (!custFile.good())
    {
        cout << "**ERROR: cannot open customers file: '" << customerFilename << "'" << endl;
        return -1;
    }
    if (!txFile.good())
    {
        cout << "**ERROR: cannot open transactions file: '" << transactionsFilename << "'" << endl;
        return -1;
    }
    
    //intialize the required feilds;
    string line, customerName, customerID, accBal,
    customerID_trans, amt;
    
    /*
     * create a customer vector
     */
    vector<Customer> customers;
    
    /*
     * parse the data and store it into the vector;
     */
    while(getline(custFile, line)){
        stringstream ss(line);
        
        //parse the line,
        getline(ss, customerName, ',');
        getline(ss, customerID, ',');
        getline(ss, accBal, ',');
        
        Customer info(customerName, stoi(customerID), stod(accBal));
        
        //insert in the vector;
        customers.push_back(info);
    }//end of while
    
    /* sort the vector by customer name, here we assume that the names are
     * unique so we further do not require any other comparison.
     */
    sort(customers.begin(), customers.end(),
         [](Customer c1, Customer c2){
             if(c1.getName() < c2.getName()){
                 return true;
             }
             else{
                 return false;
             }
         }
         );//end of sort
    
    /*
     * print the data of the customer vector
     */
    cout << ">> Customers before:" << endl;
    
    for(Customer &cus : customers){
        
        cout << " " << cus.getName() << " (" << cus.getCustomerID() << "): $" << cus.getAccbalance() << endl;
    }
    
    /*
     * Now lets parse the tranctions.csv file and store the data
     * into one more vector.
     */
    
    vector<Transctions> trans;
    
    while(getline(txFile, line)){
        stringstream ss(line);
        
        
        getline(ss, customerID_trans , ',');
        getline(ss, amt, ',');
        
        Transctions info(stoi(customerID_trans), stod(amt), 1);
        
        //insert in the vector;
        trans.push_back(info);
        
    }//end of while
    
    cout<< ">> Processing..." << endl;
    
    /*
     * check for the rejected transctions and together
     * also check for invalid customerIDs
     */
    
    for(Transctions &tx : trans){
        int count = 0;
        for(Customer &c : customers){
            
            /* if the ID exits then it is not invalid
             * but it can be rejected.
             */
            if(tx.getCustomerID() == c.getCustomerID()){
                
                if( tx.getAmount() + c.getAccbalance() >= 0){
                    double total = c.getAccbalance();
                    total = tx.getAmount() + c.getAccbalance();
                    
                    c.setAccBalance(total);
                }
                else if( tx.getAmount() + c.getAccbalance() < 0){
                    cout<< " **Rejected Tx: " << tx.getCustomerID() << ", " << tx.getAmount() << endl;
                }
                break;
            }//end of if
            
            /* check for invalid customers*/
            count++;
            if(count == customers.size() ){
                cout<< " **Invalid Tx: " << tx.getCustomerID() << ", " << tx.getAmount() << endl;
            }
        }
    }//end of for
    
    /* sort the vector by customer account balnce,
     * if balances are equal sort by name.
     */
    sort(customers.begin(), customers.end(),
         [](Customer c1, Customer c2){
             if(c1.getAccbalance() > c2.getAccbalance()){
                 return true;
             }
             if(c1.getAccbalance() == c2.getAccbalance()){
                 return c1.getName() < c2.getName();
             }
             else{
                 return false;
             }
         }
         );//end of sort
    
    /*
     * print the data of the customer vector
     *finally.
     */
    cout << ">> Customers after:" << endl;
    
    for(Customer &cus : customers){
        
        cout << " " << cus.getName() << " (" << cus.getCustomerID() << "): $" << cus.getAccbalance() << endl;
    }
    
    return 0;
}

