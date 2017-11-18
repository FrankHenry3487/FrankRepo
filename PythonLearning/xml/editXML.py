#!/usr/bin/python
# coding: utf-8
# author: Zhang Chao 00369842

import lxml.etree as ET

if __name__ == '__main__':
    # Read tree AS ElementTree
    tree = ET.parse("test.xml")
    print(ET.tostring(tree))

    # Using getroot to convert ElementTree to root Element for further operation
    root = tree.getroot()

    # Find subElements
    num1 = root[1]

    # Reading elements' attributes
    attr = num1.attrib
    print(attr["class"])

    # Modify elements' attributes
    attr["class"] = "done"

    # Reading elements' text
    print(num1.text)

    # Output to xml file
    tree.write("test.xml", pretty_print=True, xml_declaration=True, encoding='utf-8')