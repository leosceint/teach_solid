#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Liskov Substitution Principle - LSP
# SuperClass worked similar as SubClass in code that call them


class BaseHuman(object):
    def __str__(self):
        return "Base Human\n"

    def go(self):
        print("Called BaseHuman method go!")


class Human(BaseHuman):
    def __init__(self, inName: str, inAge: int, inWeight: float):
        self.__name = inName
        self.__age = inAge
        self.__weight = inWeight

    def __str__(self):
        return super().__str__() + f"Human: {self.__name} | " \
                                         f"{self.__age} |" \
                                         f"{self.__weight}"

    def go(self):
        super().go()
        print("Called Human method go!")

    @property
    def name(self):
        return self.__name


def call_testing(h: BaseHuman):
    h.go()


if __name__ == "__main__":
    base_human = BaseHuman()
    print(base_human)
    base_human.go()

    human = Human("Lev Grodzitskiy", 32, 111.3)
    print(human)
    human.go()

    call_testing(base_human)
    call_testing(human)

    print("Done!")
