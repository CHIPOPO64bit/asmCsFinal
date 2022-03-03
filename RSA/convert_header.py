import regex
OPEN_ASM_FILE = """
IDEAL
MODEL small
STACK 100h

DATASEG

"""
END_ASM_FILE ="""
start:
    mov ax, @data
    mov ds, ax
    
exit:
    mov ax, 4c00h
    int 21h
END start
"""
class Parser():
    def __init__(self, path):
        self.__path = path

        self.__out_path = "out" + path

        with open(path, "r") as f:
            self.__data = f.read()
        self.__result = OPEN_ASM_FILE
        self.__parse_includes()
        self.__parse_macros()
        self.__parse_function_declaration()
        self.__result += END_ASM_FILE

    def __parse_includes(self):
        pattern = "#include [<\"][A-Za-z.]+[>\"]"
        p = regex.compile(pattern)
        m = p.findall(self.__data)
        self.__result += "; headers\n"
        for include in m:
            self.__result += "; " + include + "\n"
        self.__result += "\n"

    def __parse_macros(self):
        pattern = "(#define[ ]+[\w]+[ ]+([\d]+|(\"(.+[\\]*[\n]?)+\")))"
        p = regex.compile(pattern)
        m = p.findall(self.__data)
        self.__result += "; macros\n"
        for define in m:
            line = define[0]
            end = str(define[1]).replace("\\\n", "\\n")
            if end[0] == "\"":
                self.__result += line.split()[1] + " db " + end + ", " \
                                                                  "\"$\"" + "\n"
            else:
                self.__result += line.split()[1] + " equ " + end + "d\n"
        self.__result += "\n"
    """
    /**
     * Find the multiplicative inverse of _ptr mod _base
     * @param _prt number to find its inverse
     * @param _res result stored in _res
     * @param _base modulo base
     * @Complexity O(log^3(n))
     */
    """
    def __parse_function_declaration(self):
        pattern = "((/\*\*([^/]*\n?\*?)*\*/) *\n*((void|int|char|long) +([" \
                  "\w]+)\((" \
                  "([" \
                  "^\(" \
                  "\)]*\n?)*)\))(;|{| ))"
        p = regex.compile(pattern)
        m = p.findall(self.__data)

        for func in m:
            docs = func[1]
            decl = func[3]
            name = func[5]
            self.__result += "; Docs"
            self.__result += docs.replace("/**", "").replace("*/",
                                                             "").replace(
                " *", ";")+"\n"
            self.__result += "; " + decl.replace("\n", "").replace("\t",
                                                                      "")+"\n"
            self.__result += "proc "+name+"\n"+"\tpusha\n\tpopa\n"+"endp "+name
            self.__result += "\n\n"

    def __parse_function_declarations(self):
        pass

    def __str__(self):
        return self.__result


def main():

#     g = "((void|int|char|long) +[\w]+\(([^\(\)]*\n?)*\);)"
#     r = "((void|int|char|long) +[\w]+\(.*\))"
#     str = """
# /**
#  * init number
#  * @param _ptr number pointer
#  * @Complexity O(log(n))
#  */
# void Init(Number *\n\n\n_ptr);
#
#
# /**
#  * prints _ptr
#  * @param _ptr number pointer
#  * @Complexity O(log(n))
#  */
# void _print_number(const Number *_ptr);
#     """
#     t = regex.compile(g)
#     z = t.findall(str)
#     print(z)
    p = Parser("modulo.h")
    print(p)


if __name__ == "__main__":
    main()
