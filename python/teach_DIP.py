#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time
import random


# Dependency Inversion Principle - DIP
# Super Modules and Sub Modules depend on interfaces, but not between themselves


from abc import ABC, abstractmethod


class ILogger(ABC):
    """
    Interface of Logger
    """
    @abstractmethod
    def log(self, message: str):
        pass


class Logger(ILogger):
    """Proto of Separated Logger Module"""
    def __init__(self):
        pass

    def log(self, message: str):
        print(f"Just logging {message} ...")


class DataBase(ILogger):
    """
    Proto of DataBase Module
    """
    def __init__(self, name: str):
        self.__name = name
        self.__isReady = False

    @property
    def name(self):
        return self.__name

    def log(self, message: str):
        print(f"<DB> Logging {message} ...")

    def open(self):
        self.__isReady = True
        self.log(f"<DB> {self.__name} opened for transactions!")

    def close(self):
        self.__isReady = False
        self.log(f"<DB> {self.__name} closed for transactions!")

    def do_request(self, request: str):
        if not self.__isReady:
            self.log(f"<DB> {self.__name} is not ready for transactions!")
            return

        time.sleep(0.3)
        self.log(f"<DB> {self.__name} query '{request}' completed!")


class File(ILogger):
    """
    Proto of File Module
    """
    def __init__(self, path: str):
        self.__path = path
        self.__isReady = False

    @property
    def path(self):
        return self.__path

    def log(self, message: str):
        print(f"<FILE> Logging {message} ...")

    def open(self):
        self.__isReady = True
        self.log(f"<FILE> {self.__path} opened for operations!")

    def close(self):
        self.__isReady = False
        self.log(f"<FILE> {self.__path} closed for operations!")

    def read(self) -> str:
        if not self.__isReady:
            self.log(f"<FILE> {self.__path} is not ready for operations!")
            return str()

        time.sleep(0.01)
        self.log(f"<FILE> {self.__path} has been read!")
        return "string"

    def write(self, s: str):
        if not self.__isReady:
            self.log(f"<FILE> {self.__path} is not ready for operations!")
            return

        time.sleep(0.01)
        self.log(f"<FILE> {self.__path} wrote string {s}!")

    def clear(self):
        if not self.__isReady:
            self.log(f"<FILE> {self.__path} is not ready for operations!")
            return

        time.sleep(random.uniform(0.01, 2.5))
        self.log(f"<FILE> {self.__path} was cleared!")


if __name__ == "__main__":
    logger = Logger()
    logger.log("bumbaracha!")

    db = DataBase("Sample")
    db.open()
    db.do_request("create table init")
    db.close()

    f = File("1.docx")
    f.open()
    stroke = f.read()
    print(stroke)
    f.clear()
    f.write(stroke)
    f.close()

    print("Done!")

