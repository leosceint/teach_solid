#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Interface Segregation Principle - ISP
# It's better to have several small interfaces than big one

"""
Interfaces
"""


class IDocument(object):
    """
    Interface of Document
    """
    @property
    def path(self):
        return str()

    def open(self):
        pass

    def close(self):
        pass

    def save(self):
        pass


class IScanner(object):
    """
    Interface of Scanner
    """
    def scan_document(self, doc: IDocument):
        pass

    def scan_image(self, path: str):
        pass


class IPrinter(object):
    """
    Interface of Printer
    """
    def print_document(self, doc: IDocument):
        pass

    def print_image(self, path: str):
        pass


"""
Realisations
"""


class RegularDocument(IDocument):
    """
    Regular Document realisation
    """
    def __init__(self, path: str):
        self.__path = path

    @property
    def path(self):
        return self.__path

    def open(self):
        super().open()
        print(f"{self.__path} opened!")

    def close(self):
        super().close()
        print(f"{self.__path} closed!")

    def save(self):
        super().save()
        print(f"{self.__path} saved!")


class GovernmentDocument(IDocument):
    """
    Government Document Realisation
    """
    def __init__(self, path: str):
        self.__path = path

    @property
    def path(self):
        return self.__path

    def open(self):
        super().open()
        print(f"Government {self.__path} opened!")

    def close(self):
        super().close()
        print(f"Government {self.__path} closed!")

    def save(self):
        super().save()
        print(f"Government {self.__path} saved!")


class RegularScanner(IScanner):
    """
    Regular Scanner realisation
    """
    def __init__(self, devID: int):
        self.__devID = devID

    def scan_document(self, doc: IDocument):
        super().scan_document(doc)
        print(f"Document {doc.path} scanned on {self.__devID}")

    def scan_image(self, path: str):
        super().scan_image(path)
        print(f"Image {path} scanned on {self.__devID}")


class RegularPrinter(IPrinter):
    """
    Regular Printer realisation
    """
    def __init__(self, devID: int):
        self.__devID = devID

    def print_document(self, doc: IDocument):
        super().print_document(doc)
        print(f"Document {doc.path} printed on {self.__devID}")

    def print_image(self, path: str):
        super().print_image(path)
        print(f"Image {path} printed on {self.__devID}")


class MFP(IScanner, IPrinter):
    """
    MFP realisation
    """
    def __init__(self, devID):
        self.__devID = devID

    def scan_document(self, doc: IDocument):
        IScanner.scan_document(self, doc)
        print(f"Document {doc.path} scanned on {self.__devID}")

    def scan_image(self, path: str):
        IScanner.scan_image(self, path)
        print(f"Image {path} scanned on {self.__devID}")

    def print_document(self, doc: IDocument):
        IPrinter.print_document(self, doc)
        print(f"Document {doc.path} printed on {self.__devID}")

    def print_image(self, path: str):
        IPrinter.print_image(self, path)
        print(f"Image {path} printed on {self.__devID}")


if __name__ == "__main__":
    reg_doc = RegularDocument("1.docx")
    reg_doc.open()
    reg_doc.save()
    reg_doc.close()

    gov_doc = GovernmentDocument("1.govx")
    gov_doc.open()
    gov_doc.save()
    gov_doc.close()

    reg_scaner = RegularScanner(10011)
    reg_scaner.scan_document(reg_doc)
    reg_scaner.scan_document(gov_doc)

    reg_printer = RegularPrinter(10012)
    reg_printer.print_document(reg_doc)
    reg_printer.print_document(gov_doc)

    mfp = MFP(10010)
    mfp.scan_document(reg_doc)
    mfp.print_document(reg_doc)
    mfp.scan_document(gov_doc)
    mfp.print_document(gov_doc)


    print("Done!")
