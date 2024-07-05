#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Open-Closed Principle - OCP
# Opened for expansion. Closed for modification

class InterfaceHuman(object):
    def __str__(self):
        pass

    def go(self):
        pass


class Human(InterfaceHuman):
    def __init__(self, inName: str, inAge: int, inWeight: float):
        self.__name = inName
        self.__age = inAge
        self.__weight = inWeight

    def __str__(self):
        InterfaceHuman.__str__(self)
        return f"Human: {self.__name} | {self.__age} | {self.__weight}"

    def go(self):
        InterfaceHuman.go(self)
        print(f"Human {self.__name} GO!")

    @property
    def name(self):
        return self.__name


class Employee(Human):
    def __init__(self, inName: str, inAge: int, inWeight: float, inIdCard: int):
        super().__init__(inName, inAge, inWeight)
        # Human.__init__(self, inName, inAge, inWeight)
        self.__IdCard = inIdCard

    def __str__(self):
        return Human.__str__(self) + f"| {self.__IdCard}"

    def go(self):
        print(f"Employee {self.name} | {self.__IdCard} GOO!!")

    @property
    def IdCard(self):
        return self.__IdCard


if __name__ == "__main__":
    ihuman = InterfaceHuman()
    ihuman.go()

    human = Human("Lev Grodzitskiy", 32, 111.3)
    print(human)
    human.go()

    employee = Employee("Lev Grodzitskiy", 32, 111.3, 45183)
    print(employee)
    employee.go()

