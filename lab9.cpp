#include <iostream>
#include <vector>
using namespace std;

class date {
    int day, month, year;
public:
    void setDate(int d, int m, int y) {
        day = d; month = m; year = y;
    }
    void showDate() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

class person {
protected:
    string name, SSNum;
    int age;
public:
    person() {
        cout << "Constructor of person class" << endl;
    }
    void setName(string n) {
        name = n;
        cout << "Name: " << name << endl;
    }
    void setSSNum(string s) {
        SSNum = s;
        cout << "SSNum: " << SSNum << endl;
    }
    void setAge(int a) {
        age = a;
        cout << "Age: " << age << endl;
    }
    ~person() {
        cout << "Destructor of person class" << endl;
    }
};

class child : public person {
    string favoriteToy;
public:
    child() {
        cout << "Constructor of child class" << endl;
    }
    void setFavoriteToy(string toy) {
        favoriteToy = toy;
        cout << "Favorite Toy: " << favoriteToy << endl;
    }
    ~child() {
        cout << "Destructor of child class" << endl;
    }
};

class spouse : public person {
    date anniversaryDate;
public:
    spouse() {
        cout << "Constructor of spouse class" << endl;
    }
    void setAnniversaryDate(int d, int m, int y) {
        anniversaryDate.setDate(d, m, y);
        cout << "Anniversary Date: ";
        anniversaryDate.showDate();
    }
    ~spouse() {
        cout << "Destructor of spouse class" << endl;
    }
};

class division {
    string divisionName;
public:
    division() {
        cout << "Constructor of division class" << endl;
    }
    void setDivisionName(string d) {
        divisionName = d;
        cout << "Division Name: " << divisionName << endl;
    }
    ~division() {
        cout << "Destructor of division class" << endl;
    }
};

class jobDescription {
    string description;
public:
    jobDescription() {
        cout << "Constructor of jobDescription class" << endl;
    }
    void setDescription(string d) {
        description = d;
        cout << "Job Description: " << description << endl;
    }
    ~jobDescription() {
        cout << "Destructor of jobDescription class" << endl;
    }
};

class employee : public person {
    string companyID, title;
    date startDate;

    division *divisionInfo;                    // 1:1
    vector<jobDescription*> jobDescriptions;   // 1:n
    vector<child*> children;                   // 0..n
    spouse* spouseInfo;                        // 0..1

public:
    employee() {
        cout << "Constructor of employee class" << endl;
        divisionInfo = nullptr;
        spouseInfo = nullptr;
    }
    void setCompanyID(string c) {
        companyID = c;
        cout << "Company ID: " << companyID << endl;
    }
    void setTitle(string t) {
        title = t;
        cout << "Title: " << title << endl;
    }
    void setStartDate(int d, int m, int y) {
        startDate.setDate(d, m, y);
        cout << "Start Date: ";
        startDate.showDate();
    }

    void setDivision(division* d) {
        divisionInfo = d;
    }
    void addJobDescription(jobDescription* jd) {
        jobDescriptions.push_back(jd);
    }
    void addChild(child* c) {
        children.push_back(c);
    }
    void setSpouse(spouse* s) {
        spouseInfo = s;
    }

    ~employee() {
        cout << "Destructor of employee class" << endl;
    }
};

int main() {
    employee emp1;
    emp1.setName("bat ");
    emp1.setSSNum("123-45-6789");
    emp1.setAge(30);
    emp1.setCompanyID("XYZ Corp");
    emp1.setTitle("Software Engineer");
    emp1.setStartDate(15, 8, 2020);

    
    division* div1 = new division();
    div1->setDivisionName("Development");
    emp1.setDivision(div1);

    
    jobDescription* jd1 = new jobDescription();
    jd1->setDescription("Develops backend services.");
    emp1.addJobDescription(jd1);

    
    spouse* spouse1 = new spouse();
    spouse1->setName("zaya");
    spouse1->setSSNum("456-78-9012");
    spouse1->setAge(28);
    spouse1->setAnniversaryDate(10, 6, 2015);
    emp1.setSpouse(spouse1);

    
    child* child1 = new child();
    child1->setName("tugstuguldur");
    child1->setSSNum("987-65-4321");
    child1->setAge(5);
    child1->setFavoriteToy("rubic cube");
    emp1.addChild(child1);

    child* child2 = new child();
    child2->setName("tugs-erdene");
    child2->setSSNum("123-98-7654");
    child2->setAge(3);
    child2->setFavoriteToy("Toy Car");
    emp1.addChild(child2);

    
    delete div1;
    delete jd1;
    delete spouse1;
    delete child1;
    delete child2;

    return 0;
}
