#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class date
{
public:
    int year;
    int month;
    int day;
    date(int y, int m, int d) : year(y), month(m), day(d) {}
};

// Division  класс тодорхойлсон
class Division
{
    // Protected хандалтын түвшинтэй гишүүд
    // divisionName - хэлтсийн нэр
private:
    string divisionName;
    // Public хандалтын түвшинтэй гишүүд
public:
    // Байгуулагч функц
    // Division классыг үүсгэхэд хэлтсийн нэрийг дамжуулна
    Division(string n) : divisionName(n) {};
    // getDivisionName() - хэлтсийн нэрийг авах
    string getDivisionName()
    {
        return divisionName;
    }
    // setDivisionName() - хэлтсийн нэрийг тохируулах
    void setDivisionName(string n)
    {
        divisionName = n;
    }
};

// JobDescription классыг тодорхойлсон
class JobDescription
{
    // Protected хандалтын түвшинтэй гишүүд
    // description - ажлын тодорхойлолт
private:
    string description;
    // Public хандалтын түвшинтэй гишүүд
public:
    // Байгуулагч функц
    // JobDescription классыг үүсгэхэд ажлын тодорхойлолтыг дамжуулна
    JobDescription(string d) : description(d) {};
    // getDescription() - ажлын тодорхойлолтыг авах
    string getDescription()
    {
        return description;
    }
    // setDescription() - ажлын тодорхойлолтыг тохируулах
    void setDescription(string d)
    {
        description = d;
    }
};

// Person классыг тодорхойлсон
class Person
{
    // Protected хандалтын түвшинтэй гишүүд
    // name - нэр
    // SSNum - нийгмийн даатгалын дугаар
    // age - нас
private:
    string name;
    string SSNum;
    int age;
    // Public хандалтын түвшинтэй гишүүд
public:
    // Байгуулагч функц
    // Person классыг үүсгэхэд нэр, нас, нийгмийн даатгалын дугаарыг дамжуулна
    Person(string n, string s, int a) : name(n), SSNum(s), age(a) {};
    // getName() - нэрийг авах
    string getName()
    {
        return name;
    }
    // getSSNum() - нийгмийн даатгалын дугаарыг авах
    string getSSNum()
    {
        return SSNum;
    }
    // getAge() - насыг авах
    int getAge()
    {
        return age;
    }
    // setName() - нэрийг тохируулах
    void setName(string n)
    {
        name = n;
    }
    // setSSNum() - нийгмийн даатгалын дугаарыг тохируулах
    void setSSNum(string s)
    {
        SSNum = s;
    }
    // setAge() - насыг тохируулах
    void setAge(int a)
    {
        age = a;
    }
};

// Spouse классыг тодорхойлсон
class Spouse : public Person
{
    // Protected хандалтын түвшинтэй гишүүд
    // anniversaryDate - хуримын өдөр
private:
    date anniversaryDate;
    // Public хандалтын түвшинтэй гишүүд
public:
    // Байгуулагч функц
    Spouse(string n, string s, int a, date d) : Person(n, s, a), anniversaryDate(d) {};
    // getAnniversaryDate() - хуримын өдрийг авах
    date getAnniversaryDate()
    {
        return anniversaryDate;
    }
    // setAnniversaryDate() - хуримын өдрийг тохируулах
    void setAnniversaryDate(date d)
    {
        anniversaryDate = d;
    }
};

// Child классыг Person  классаас удамшуулсан
class Child : public Person
{
    // Protected хандалтын түвшинтэй гишүүд
    // favoriteToy - дуртай тоглоом
private:
    string favoriteToy;
    // Public хандалтын түвшинтэй гишүүд
public:
    // Байгуулагч функц
    // Child классыг үүсгэхэд нэр, нас, дуртай тоглоомыг дамжуулна
    Child(string n, string s, int a, string t) : Person(n, s, a), favoriteToy(t) {}
    // getFavoriteToy() - дуртай тоглоомыг авах
    string getFavoriteToy()
    {
        return favoriteToy;
    }
    // setFavoriteToy() - дуртай тоглоомыг тохируулах
    void setFavoriteToy(string t)
    {
        favoriteToy = t;
    }
};

class Employee : public Person
{
    // private хандалтын түвшинтэй гишүүд
    //  companyID - компанийн дугаар
private:
    string companyID;
    string title;
    date startDate;
    // public хандалтын түвшинтэй гишүүд
    // sp - эхнэр/нөхөр
    // children - хүүхдүүдийн жагсаалт
    // jds - ажилтны ажлын тодорхойлолтуудын жагсаалт
    // d - хэлтэс
public:
    Spouse *sp;
    vector<Child> children;
    vector<JobDescription *> jds;
    Division d;

    Employee(string n, string num, int a, string id, string t, date d, Division dd, JobDescription *jd) : Person(n, num, a), companyID(id), title(t), startDate(d), d(dd), sp(nullptr)
    {
        jds.push_back(jd);
    }
    // getCompanyID() - компанийн дугаарыг авах
    string getCompanyID()
    {
        return companyID;
    }
    // getTitle() - албан тушаалыг авах
    string getTitle()
    {
        return title;
    }
    // getStartDate() - ажлын эхлэх өдрийг авах
    date getStartDate()
    {
        return startDate;
    }
    // setCompanyID() - компанийн дугаарыг тохируулах
    void setCompanyId(string id)
    {
        companyID = id;
    }
    // setTitle() - албан тушаалыг тохируулах
    void setTitle(string t)
    {
        title = t;
    }
    // setStartDate() - ажлын эхлэх өдрийг тохируулах
    void setStartDate(date d)
    {
        startDate = d;
    }
    // setSpouse() - эхнэр/нөхрийг тохируулах
    void setSpouse(Spouse *s)
    {
        sp = s;
    }
    // addChild() - хүүхдийг жагсаалтад нэмэх
    void addChild(Child c)
    {
        children.push_back(c);
    }
    // addJobDescription() - ажлын тодорхойлолтыг жагсаалтад нэмэх
    void addJobDescription(JobDescription *jd)
    {
        jds.push_back(jd);
    }
    // print() - ажилтны мэдээллийг хэвлэх
    void print()
    {
        cout << "Ner: " << this->getName() << "\nNas: " << this->getAge() << "\nSSNumber: " << this->getSSNum() << endl;
        cout << "Company ID: " << this->getCompanyID() << "\nAlban tushaal: " << this->getTitle() << endl;
        cout << "Ajild orson ognoo: " << this->startDate.year << "-" << this->startDate.month << "-" << this->startDate.day << endl;
        cout << "Heltes: " << this->d.getDivisionName() << endl;
        cout << "Ajliin todorhoiloltuud: " << endl;
        // Хэлтсийн нэрийг хэвлэх
        for (JobDescription *jd : this->jds)
        {
            if (jd != nullptr)
            {
                cout << "  - " << jd->getDescription() << endl;
            }
        }
        // Хуримын өдөр, эхнэр/нөхөр, хүүхдүүдийн мэдээллийг хэвлэх
        if (this->sp != nullptr)
        {
            cout << "Ehner/Nuhur: " << this->sp->getName()
                 << ", Nas: " << this->sp->getAge()
                 << ", Hurimiin udur: " << this->sp->getAnniversaryDate().year << "-"
                 << this->sp->getAnniversaryDate().month << "-"
                 << this->sp->getAnniversaryDate().day << endl;
        }
        else
        {
            cout << "Ehner/Nuhur baihgui." << endl;
        }
        // Хүүхдүүдийн мэдээллийг хэвлэх
        if (!this->children.empty())
        {
            cout << "Huuhed: " << endl;
            for (int i = 0; i < this->children.size(); i++)
            {
                cout << " - " << this->children[i].getName()
                     << ", Nas: " << this->children[i].getAge()
                     << ", Durtai togloom: " << this->children[i].getFavoriteToy() << endl;
            }
        }
        else
        {
            cout << "Huuhedgui." << endl;
        }
        cout << "----------------------------" << endl;
    }
};
int main()
{
    // Хэлтсийн объект үүсгэх
    Division d1("IT Heltes");
    // Ажлын тодорхойлолтын объект үүсгэх
    JobDescription *jd1 = new JobDescription("Software engineer");
    JobDescription *jd2 = new JobDescription("Database administrator");
    // Ажилтны объект үүсгэх
    // Ажилтны объект үүсгэхэд хэлтсийн объект, ажлын тодорхойлолтын объект дамжуулна
    Employee e("Bat", "AB1232", 35, "E001", "Engineer", date(2020, 5, 10), d1, jd1);
    e.addJobDescription(jd2);
    // Эхнэр/нөхрийн объект үүсгэх
    // Эхнэр/нөхрийн объект үүсгэхэд нэр, нас, хуримын өдрийг дамжуулна
    Spouse *sp = new Spouse("Naran", "BQ3245", 32, date(2015, 6, 20));
    e.setSpouse(sp);
    // Хүүхдийн объект үүсгэх
    // Хүүхдийн объект үүсгэхэд нэр, нас, дуртай тоглоомыг дамжуулна
    Child c1("Temuulen", "JH0989", 5, "Lego");
    Child c2("Anujin", "NA8967", 3, "Barbie");
    // Хүүхдийн объектуудыг ажилтны объект руу нэмэх
    e.addChild(c1);
    e.addChild(c2);
    e.print();

    // Шинэ ажилтны объект үүсгэх
    Division d2("Sanhuu Heltes");
    // Ажлын тодорхойлолтын объект үүсгэх
    JobDescription *jd3 = new JobDescription("Baiguulgiin orlogo zardal hariutsdag.");
    JobDescription *jd4 = new JobDescription("Sanhuugiin udirdlagyn ajiltan.");
    JobDescription *jd5 = new JobDescription("Baga zereg mungu ideh magadlaltai hunii neg.");
    // Ажилтны объект үүсгэх
    // Ажилтны объект үүсгэхэд хэлтсийн объект, ажлын тодорхойлолтын объект дамжуулна
    Employee e2("Munkh", "MN1234", 40, "E002", "Accountant", date(2018, 3, 15), d2, jd3);
    e2.addJobDescription(jd4);
    e2.addJobDescription(jd5);
    // ehnergui salsan
    Child c3("Baatar", "GH5678", 15, "Billiard");
    Child c4("Zolzaya", "JK1234", 21, "Smartphone");
    e2.addChild(c3);
    e2.addChild(c4);
    e2.print();

    delete sp;

    return 0;
}