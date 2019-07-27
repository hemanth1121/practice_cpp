#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

void* operator new(size_t sizeG)
{
    cout << "void* operator new(size_t sizeG)" << endl;
    void *p;
    try{
        p = malloc(sizeG);
    }catch(bad_alloc ba)
    {
        cout << "allocation failure " << endl;
    }
  return p;
}

void operator delete(void* ptr)
{
    cout << " void operator delete(void* ptr)" << endl;
    free(ptr);
}

class House
{
    int len;
    char* houseName;
public:
    House(const char* name , int var = 0):len(var)
    {
        cout << "House(int var)" <<  endl;
        houseName = new char(strlen(name)+1);
        strcpy(houseName, name);
    }

    ~House()
    {
        delete(houseName);
    }
    int getLength() const
    {
        return len;
    }

    House operator+(House obj)
    {
        //House temp;
        //temp.
        len = len + obj.len;
        return *this;
    }

    void display() const
    {
        cout << "len: " << len << endl;
    }

    House(const House& house)
    {
        cout << "House(const House& house)" <<  endl;
        len = house.getLength();
        //cout << strlen(house.houseName) << endl;
        houseName = new char(strlen(house.houseName)+1);
        strcpy(houseName, house.houseName);

    }

    House(House&& house)
    {
        cout << "House(const House&& house)" <<  endl;
        len = house.getLength();
        houseName = house.houseName;
        house.houseName = nullptr;
    }

    House& operator=(const House& house)
    {
        if(this != &house)
        {
            len = house.getLength();
            *houseName = *house.houseName;
        }
        return *this;
    }

    House operator++()
    {
        cout << "operator++" << endl;
        len += 1;
        return *this;
    }

    /*House operator++(int)
    {
        cout << "operator++(int)" << endl;
        len += 1;
        return *this;
    }*/

    friend House operator++(House& house, int x)
    {
        cout << "friend House operator++(House& house, int)" << endl;
        house.len++;
        return house;
    }
};


void utilityDisplay(House&& house)
{
    cout << house.getLength() << endl;
}

class arr
{
    int a[3];
public:
    arr(int x, int y)
    {
        cout << "arr(int x, int y)" << endl;
        a[0] = x;
        a[1] = y;
    }

    int& operator[](int i)
    {
        cout << "int operator[](int i)" << endl;
        if(i>=0 && i<=2)
        {
          return a[i];
        }
        else
        {
            exit(1);
        }
    }
};

class commaOp
{
    int lon, lat;
public:
    //commaOp(){}
    commaOp(int a=0, int b=0):lon(a),lat(b)
    {
        cout << "commaOp(int a, int b)" << endl;
    }

    commaOp operator,(commaOp obj)
    {
        cout << "commaOp operator,(commaOp obj)" << endl;
        commaOp temp;
        temp.lon = obj.lon;
        temp.lat = obj.lat;
        return temp;
    }

    void display() const
    {
        cout << "len: " << lon << " lat: " << lat << endl;
    }


};
int main()
{
    House house1("house1", 10), house2("house2");
    house2.display();
    //cout << strlen(house1.houseName) << endl;
    house2 = house1 + house2;
    house2.display();

    house1.display();
    ++house1;
    house1.display();

    house1++;
    house1.display();

    arr obj(10,20);
    cout << obj[1] << endl;

    obj[2] = 30;
    cout << obj[2] << endl;

    commaOp obj1(15,25), obj2(150,250), obj3;

    obj3.display();

    obj3 = (obj1, obj2);
    obj3.display();
}
