def print_function_summary(functions):
    for i, func in enumerate(functions, 1):
        print(f"Function {i}: {func['name']}")
        print(f"  Return type: {func['return_type']}")
        print(f"  Number of arguments: {func['num_args']}")
        if func['num_args'] > 0:
            print(f"  Arguments:")
            for arg_type, arg_name in func['args']:
                print(f"    - {arg_type} {arg_name}")
        print() 