import sys
import os
from c_parser import extract_functions
from summary_printer import print_function_summary

def main():
    if len(sys.argv) != 2:
        print("Usage: python main.py <file.c>")
        sys.exit(1)
    c_file = sys.argv[1]
    if not os.path.isfile(c_file):
        print(f"File not found: {c_file}")
        sys.exit(1)
    with open(c_file, 'r', encoding='utf-8') as f:
        code = f.read()
    functions = extract_functions(code)
    if not functions:
        print("No functions found in the file.")
    else:
        print(f"Found {len(functions)} function(s):\n")
        print_function_summary(functions)

if __name__ == "__main__":
    main()
