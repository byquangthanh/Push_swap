# ft_printf

Welcome to `ft_printf`, a custom implementation of the classic C library function `printf`. This project is part of the 42 School curriculum, designed to deepen understanding of variadic functions in C and to replicate the functionality of the standard `printf` function with support for several format specifiers.

## Overview

The `ft_printf` function aims to mimic the behavior of the standard C `printf` function, allowing formatted output to the standard output stream. This implementation serves as an excellent learning tool for C programming, focusing on handling variadic arguments, string parsing, and formatted output.

## Features

- **Format Specifiers**: Supports a variety of format specifiers, including `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
- **Width and Precision**: Handles width and precision for numerical values, improving the formatting capabilities.
- **Variadic Function Handling**: Demonstrates the use of variadic functions to accept an undefined number of arguments.

## Usage

To use `ft_printf` in your C projects, follow these steps:

1. **Clone the Repository**: Clone the `ft_printf` repository to your local machine.
   ```sh
   git clone https://github.com/byquangthanh/ft_printf.git
   ```
2. **Compile the Library**: Navigate to the cloned directory and compile the library using `make`.
   ```sh
   cd ft_printf
   make
   ```
   This command generates a `libftprintf.a` library file.
3. **Include in Your Project**: Include the `ft_printf` header in your C files.
   ```c
   #include "ft_printf.h"
   ```
4. **Link the Library**: When compiling your project, link against `libftprintf.a`.
   ```sh
   cc -o your_program your_source_files -L. -lftprintf
   ```

## Contributing

Contributions to `ft_printf` are welcome! Whether it's adding new features, fixing bugs, or improving documentation, here's how you can contribute:

1. Fork the repository on GitHub.
2. Create a new branch for your changes.
3. Commit your improvements to the branch.
4. Push the branch to GitHub.
5. Submit a pull request to the original repository.

## Support

If you have any questions or encounter issues, please open an issue on the GitHub repository, and we'll do our best to address it.
