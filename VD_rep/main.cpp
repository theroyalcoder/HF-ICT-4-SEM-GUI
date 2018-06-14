#include <iostream>
using namespace std;

#include <list>
#include <vector>
#include <map>

class ArrayUtil{
public:
    static long* multiplyArrayValues(const long *values, const int ARRAY_SIZE);
};

class StringUtil{
public:
    static bool checkUniqueness(string s);
};

bool StringUtil::checkUniqueness(string s) {
    int size = 26;
    int *alphabet = new int[size]{};
    int tmp = 0;

    for (int i = 0; i < s.size(); ++i) {
        alphabet[s[i] - 39] += 1;
    }

    return false;
}

long *ArrayUtil::multiplyArrayValues(const long *values, const int ARRAY_SIZE) {
    long tmp = 1;
    long *result = new long[ARRAY_SIZE]{};

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            if (values[i] != values[j]) {
                tmp *= values[j];

            }
        }
        result[i] = tmp;
        tmp = 1;
    }

    for (int k = 0; k < ARRAY_SIZE; ++k) {
        cout << result[k] << endl;
    }

    return result;
}

//Erste Version
int similaritySearch(string text, string pattern, int maxNumberOfMismatches, int startPosition){
    string match;
    string substring;
    int mismatchCounter = 0;
    bool first = true;

    for (int i = startPosition; i < text.size() - pattern.size(); ++i) {

        //substring gleichgross wie pattern
        for (int j = i; j < pattern.size() + i; ++j) {
            substring += text[j];
        }
        //cout << "substring: " << substring << endl;

        //schauen, ob es ein match gibt
        for (int k = 0; k < pattern.size(); ++k) {
            if (first) {
                //1. substring
                if (substring[k] == pattern[k]) {
                    match += substring[k];
                    first = false;
                }
            } else {
                //ab 2. substring
                if (substring[k] == pattern[k]) {
                    match += substring[k];
                    //cout << substring[k] << " = " << pattern[k] << endl;
                    cout << "match: " << match << endl;
                } else {
                    match += substring[k];
                    mismatchCounter++;
                }

                if(match.size() == pattern.size()){
                    if (mismatchCounter > maxNumberOfMismatches) {
                        cout << "Too many mismatches" << endl;
                        break;
                    }
                }
            }
        }


        substring = "";
        match = "";
        first = true;
    }

    return -1;
}

//Zweite Version
string createSubstring(string text, string pattern, int i) {
    string substring;
    //Bei Position i die grösse von pattern size ausschneiden und in substring reinpacken
    for (int j = 0; j < pattern.size(); ++j) {
        substring += text[j + i];
    }

    //cout << substring << endl;
    return substring;
}
int similaritySearchv2(string text, string pattern, int maxNumberOfMismatches, int startPosition) {
    if (text.empty() || pattern.empty())
        return -999;

    //Für eine saubere Ausgabe

    cout << endl << endl;

    string substring;
    int pos = -1;
    int mismatchCounter = 0;
    int matchCounter = 0;
    string temp;

    for (int i = startPosition; i < text.size() - pattern.size(); ++i) {
        substring = createSubstring(text, pattern, i);

        for (int k = 0; k < pattern.size(); ++k) {
            if(substring[k] != pattern[k])
                mismatchCounter++;

            if(substring[k] == pattern[k])
                matchCounter++;

            if(mismatchCounter + matchCounter == pattern.size()){
                temp = substring;
                pos = i;
                cout << temp << endl;
                break;
            }

            if(mismatchCounter > maxNumberOfMismatches) {
                //cout << substring << endl;
                mismatchCounter = 0;
                matchCounter = 0;
            }
        }
    }

    return pos;
}

class Planet {
private :
    string name; // Name des Planeten
    int x,y,z; // Koordinaten im Raum

public :
// getter und setter Methoden
    const string &getName() const;
    void setName(const string &name);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getZ() const;
    void setZ(int z);
};

const string &Planet::getName() const {
    return name;
}

void Planet::setName(const string &name) {
    Planet::name = name;
}

int Planet::getX() const {
    return x;
}

void Planet::setX(int x) {
    Planet::x = x;
}

int Planet::getY() const {
    return y;
}

void Planet::setY(int y) {
    Planet::y = y;
}

int Planet::getZ() const {
    return z;
}

void Planet::setZ(int z) {
    Planet::z = z;
}

class PlanetUtil {
public :
    static string findNextPlanet(Planet planet, list<Planet> planets);
};

string PlanetUtil::findNextPlanet(Planet planet, list<Planet> planets) {
    //Abbruchbedingungen
    if (planets.empty()) { return "List is emtpy"; }
    if(planets.size() == 1) { for (auto p : planets) { return p.getName(); } }

    int firstPlanetSum = planet.getX() + planet.getY() + planet.getZ();;
    int secondPlanetSum = 0;
    vector<int> planetSum;

    for(auto p : planets){
        if (p.getName() != planet.getName()) {
            secondPlanetSum = p.getX() + p.getY() + p.getZ();
            planetSum.push_back(secondPlanetSum);

        } else {
            planetSum.push_back(99999);
        }
    }

    int pos;
    int count = 0;
    int nearestp = planetSum[0];

    for (int i = 0; i < planetSum.size(); ++i) {
        if (nearestp > planetSum[i]) {
            nearestp = planetSum[i];
            pos = i;
        }
    }

    for(auto p : planets){
        if (count == pos) {
            return p.getName();
        }
        count++;
    }


    return "Fehler im Code";
}

int main() {
    //Exercise sheet 1, task 2: Array Multiplikation
    /*
    int size = 4;
    long *values = new long[size]{12, 4, 7, 3};

    ArrayUtil au;
    //au.multiplyArrayValues(values, size);
    */

    //Exercise sheet 1, task 3: String Check
    /*
    string string1 = "abcdefg";
    StringUtil su;
    su.checkUniqueness(string1);
    */

    //VD 2016
    string text = "GDFGHJDFFGJJGHJTYREYWERWETYDSGF";
    string pattern =     "FFKJJ";
    int maxNumberOfMismatches = 1;
    int startPosition = 0;

    cout << similaritySearch(text, pattern, maxNumberOfMismatches, startPosition);
    cout << similaritySearchv2(text, pattern, maxNumberOfMismatches, startPosition);

    //Aufgabe 3
    /*
    Planet planet, planet2, planet3;
    planet.setName("Erde");
    planet.setX(1);
    planet.setY(1);
    planet.setZ(1);

    planet2.setName("Mars");
    planet2.setX(1);
    planet2.setY(2);
    planet2.setZ(3);

    planet3.setName("Merkur");
    planet3.setX(7);
    planet3.setY(9);
    planet3.setZ(16);

    list<Planet> planets;
    planets.push_back(planet);
    planets.push_back(planet2);
    planets.push_back(planet3);

    PlanetUtil pu;
    cout << pu.findNextPlanet(planet, planets) << endl;
    */
    return 0;
}
