#include <iostream>
#include <vector>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

class Person
{
private:
    string name;
    string SSNum;
    int age;

public:
    // getter
    string getName() { return name; }
    string getSSNum() { return SSNum; }
    int getAge() { return age; }
    // setter
    void setName(string name) { this->name = name; }
    void setSSNum(string SSNum) { this->SSNum = SSNum; }
    void setAge(int age) { this->age = age; }
    // constructor, destructor
    Person() {}
    Person(string name, string SSNum, int age)
    {
        this->name = name;
        this->SSNum = SSNum;
        this->age = age;
    }
    // print information
    void print()
    {
        cout << "Name: " << this->name << endl;
        cout << "SSNum: " << this->SSNum << endl;
        cout << "Age: " << this->age << endl;
    }
    ~Person() {}
};

class Spouse : public Person
{
private:
    Date AnniversaryDate;

public:
    Date getAnniversaryDate() { return AnniversaryDate; }
    void setAnniversaryDate(Date AnniversaryDate) { this->AnniversaryDate = AnniversaryDate; }

    // constructor
    Spouse(string name, string SSNum, int age, Date AnniversaryDate)
        : Person(name, SSNum, age), AnniversaryDate(this->AnniversaryDate) {}
    ~Spouse() {}
};

class Employee : public Person
{
private:
    string companyID;
    string title;
    Date startDate;

    // Division & JobDescription
    Division *division;
    JobDescription *jobdescription;

public:
    string getCompanyID() { return companyID; }
    string getTitle() { return title; }
    Date getStartDate() { return startDate; }
    void setCompanyID(string companyID) { this->companyID = companyID; }
    void setTitle(string title) { this->title = title; }
    void setStartDate(Date startDate) { this->startDate = startDate; }

    // Constructor
    Employee(string name, string SSNum, int age, string companyID, string title, Date startDate, Division *division, JobDescription *jobDescription) : Person(name, SSNum, age)
    {
        this->companyID = companyID;
        this->title = title;
        this->startDate = startDate;
        this->division = division;
        this->jobdescription = jobDescription;
    }
    Person::print()
    {
        Person::print();
        cout << "Company ID: " << companyId << endl;
        cout << "Title: " << title << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "Job Description: " << jobdescription << endl;
    }
};

class Division
{
private:
    string DivisionName;

public:
    string getDivisionName() { return DivisionName; }
    void setDivisionName(string DivisionName) { this->DivisionName = DivisionName; }

    Division(string DivisionName)
    {
        this->DivisionName = DivisionName;
    }
    ~Division() {}

    void print()
    {
        cout << this->DivisionName << endl;
    }
};

class JobDescription
{
private:
    string description;

public:
    string getDescription() { return description; }
    void setDescription(string description) { this->description = description; }
    JobDescription(string descrpition)
    {
        this->description = description;
    }
    ~JobDescription() {}
    void print()
    {
        cout << this->description << endl;
    }
};

class Child : public Person
{
private:
    string FavoriteToy;

public:
    string getFavoriteToy() { return FavoriteToy; }
    void setFavoriteToy(string FavoriteToy) { this->FavoriteToy = FavoriteToy; }
    Child(string name, string SSNum, int age) : Person(name, SSNum, age), FavoriteToy(this->FavoriteToy) {}
    ~Child();
};

int main()
{
    // Create multiple objects for division and job description.
    Division Finance("Finance");
    Division Research("Research");

    JobDescription Manager("In charge of managing people and company operation");
    JobDescription Assistant("In charge of assisting company operations and meetings");
    JobDescription President("In charge of leading company with clear vision");

    Finance.print();
    Research.print();

    Manager.print();
    Assistant.print();
    President.print();

    Date d1 = {2020, 11, 22}; 

    Employee emp("Bob", "E1", 31, "NUM", "Manager", d1, &Finance, &Manager); 
    emp.print(); 

    return 0;
}