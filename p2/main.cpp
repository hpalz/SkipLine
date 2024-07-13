// idea for jsoncpp came from here: https://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html
#include "json/json.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <set>
using namespace std;
void checkInSet(map<string, string> *m, string fileName);

int main() {
  map<string, string> masterMap;
  std::ifstream f("languageFiles/master_enum.json");
  Json::Value root;
  f >> root;
  //iterates through each high level json object
  for (auto a : root) {
    auto enums = a["enums"];
    string screenName = a["name"].asString();
    //iterates through each screen's enum
    for (auto b : enums) {
      //Creating an entry in the map of {key: enumName, value: screenName}
      masterMap.insert({b["name"].asString(),screenName});
    }
  }
  thread t1(checkInSet, &masterMap, "languageFiles/lang_fr.json");
  thread t2(checkInSet, &masterMap, "languageFiles/lang_de.json");
  thread t3(checkInSet, &masterMap, "languageFiles/lang_en-us.json");
  thread t4(checkInSet, &masterMap, "languageFiles/lang_es.json");
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

// puts new language file into set, and iterates through the master map to 
// check if the language file has the same enums
void checkInSet(map<string, string> *m, string fileName){
  set<string> subSet;
  std::ifstream f(fileName);
  Json::Value root;
  f >> root;
  for (auto a : root) {
      string name = a["enum"].asString();
      subSet.insert(name);
  }

  for (auto it = m->begin();
     it != m->end(); ++it){
       if(subSet.count(it->first)==0){
         cout << it->first << "\t" << it->second << "\t" << "("<< fileName<< ")" << endl;
       }
     }
}