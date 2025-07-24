import re

FUNC_DEF_REGEX = re.compile(r"""
^\s*                                  # Optional leading whitespace
([\w\*\s]+?)                         # Return type (group 1)
\s+                                    # At least one space
([a-zA-Z_]\w*)                         # Function name (group 2)
\s*\(\s*                              # Opening parenthesis
([^\)]*)                               # Arguments (group 3)
\)\s*                                  # Closing parenthesis
(?:\n|\s)*                            # Optional whitespace/newlines
\{                                     # Opening brace (start of function body)
""", re.MULTILINE | re.VERBOSE)

CONTROL_KEYWORDS = {"if", "for", "while", "switch", "else"}

ARG_REGEX = re.compile(r"""
^\s*([\w\*\s]+?)\s+([a-zA-Z_]\w*)\s*$
""", re.VERBOSE)

def parse_arguments(arg_str):
    args = []
    arg_str = arg_str.strip()
    if not arg_str or arg_str == 'void':
        return args
    for arg in arg_str.split(','):
        arg = arg.strip()
        m = ARG_REGEX.match(arg)
        if m:
            arg_type = ' '.join(m.group(1).split())
            arg_name = m.group(2).strip()
            args.append((arg_type, arg_name))
        else:
            args.append(("unknown", arg))
    return args

def extract_functions(code):
    # Remove comments (simple version)
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)  # block comments
    code = re.sub(r'//.*', '', code)  # line comments
    functions = []
    for match in FUNC_DEF_REGEX.finditer(code):
        ret_type = ' '.join(match.group(1).split())
        func_name = match.group(2)
        if func_name in CONTROL_KEYWORDS:
            continue
        arg_str = match.group(3)
        args = parse_arguments(arg_str)
        functions.append({
            'name': func_name,
            'return_type': ret_type,
            'num_args': len(args),
            'args': args
        })
    return functions 