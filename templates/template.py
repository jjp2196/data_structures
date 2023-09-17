#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
    James Pecore
    template.py: 
'''

class MyTemplate:
    # Constructor
    def __init__(self):
        self.variable = 0

    # Informal, printable string representation of the object
    def __str__(self):
        return str(self.variable)

    # Valid Python expression string representation
    def __repr__(self):
        return f'MyTemplate({self.variable})'

    # Define the + operator
    def __add__(self, other):
        if isinstance(other, MyTemplate):
            return MyTemplate(self.variable + other.variable)
        else:
            return MyTemplate(self.variable + other)

    # Define other methods or functions as needed
    def method(self, value):
        self.variable += value

def main():
    # Instantiate the MyTemplate class
    template_instance = MyTemplate()

    # Use and test the class methods
    template_instance.method(5)
    print(f"Variable value: {template_instance}")

if __name__ == '__main__':
    main()
