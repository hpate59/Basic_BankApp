//*customer.h*/

//
// Customer class for banking program in modern C++.
//
// <<Name: Harshil>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 01
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

//build a customer class to keep track of the
// the information of the customer
class Customer
{
private:
    string Name;
    int    CustomerID;
    double AccBalance;
    
public:
    Customer(string name, int cID, double accBal)
    :Name(name), CustomerID(cID), AccBalance(accBal)
    {}
    
    //get the name of the customer
    string getName(){
        return Name;
    }
    
    //get the customerID
    int getCustomerID(){
        return CustomerID;
    }
    
    //get the account balance
    double getAccbalance(){
        return AccBalance;
    }
    
    //get set the account balance
    void setAccBalance(double balance){
        AccBalance = balance;
    }
    
}; // end of customer class


//make a transactions class where you keep
//track of the transactions that customer made
class Transctions
{
private:
    int CustomerID;
    double Amount;
    int flag;
    
public:
    Transctions(int cusID, double amt, int f)
    : CustomerID(cusID), Amount(amt), flag(f)
    {}
    
    //get the customerID
    int getCustomerID(){
        return CustomerID;
    }
    
    //get the amount balance
    double getAmount(){
        return Amount;
    }
    
};

