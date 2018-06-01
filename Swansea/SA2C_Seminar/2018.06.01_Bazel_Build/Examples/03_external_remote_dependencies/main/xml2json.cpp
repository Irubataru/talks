
/*
 * Created: 31-05-2018
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include "tinyxml2.h"
#include "nlohmann/json.hpp"
#include <iostream>

void add_xml_node_to_json(tinyxml2::XMLNode *xml, nlohmann::json &json)
{
  if (xml == nullptr) {
    return;
  }

  auto elem = xml->ToElement();
  if (elem == nullptr) {
    return;
  }

  if (elem->GetText() != nullptr) {
    json[elem->Name()] = std::string{elem->GetText()};
  } else {
    json[elem->Name()] = nlohmann::json::object();
    add_xml_node_to_json(xml->FirstChild(), json[elem->Name()]);
  }

  add_xml_node_to_json(xml->NextSibling(), json);
}

int main(int argc, char**argv)
{
  if (argc < 2) {
    std::cout << "Program takes XML infile as argument\n";
    return 1;
  }

  tinyxml2::XMLDocument doc;
  doc.LoadFile(argv[1]);

  nlohmann::json jsn;

  add_xml_node_to_json(doc.FirstChild(), jsn);

  std::cout << jsn.dump(2) << "\n";
}
