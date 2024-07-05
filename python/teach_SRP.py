#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Single Responsibility Principle - SRP
# I do what I am responsible for
class Human(object):
    """
    class Human
    Incapsulate:
        - name
        - age
        - weight
    """
    def __init__(self, inName: str, inAge: int, inWeight: float):
        self.__name = inName
        self.__age = inAge
        self.__weight = inWeight

    def __str__(self):
        return f"Human: {self.__name} | {self.__age} | {self.__weight}"

    def go(self):
        print(f"{self.__name} GO!")

    @property
    def name(self):
        return self.__name

    @property
    def age(self):
        return self.__age

    @property
    def weight(self):
        return self.__weight


if __name__ == "__main__":
    human = Human("Lev Grodzickiy", 32, 111.3)
